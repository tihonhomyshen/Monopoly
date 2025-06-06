#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Monopoly.h"
#include "PlayerInfoPanel.h"
#include "Button.h"
#include "Animation.h"
#include "PurchaseDialog.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1250, 910), "Monopoly");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("./Montserrat-Black.ttf")) {
        return EXIT_FAILURE;
    }

    Board board;
    board.create();

    Player player1(1, "Player 1", sf::Color::Red, { 10, 15 });
    Player player2(2, "Player 2", sf::Color::Green, { 30, 30 });

    player1.set_color();
    player2.set_color();

    sf::Vector2f startPos = board.getCellPosition(0);
    player1.setPosition(startPos);
    player2.setPosition(startPos);
    int currentPlayer = 0;

    Animation player1Anim;
    Animation player2Anim;

    Button button(sf::Vector2f(275, 125), sf::Vector2f(575, 350), "Make turn!", font);
    std::vector<PlayerInfoPanel> playerPanels;
    playerPanels.emplace_back(sf::Vector2f(75, 50), sf::Vector2f(200, 100), &player1);
    playerPanels.emplace_back(sf::Vector2f(75, 200), sf::Vector2f(200, 100), &player2);
    PurchaseDialog purchaseDialog(font);

    bool processingPurchase = false;
    Player* currentPurchasingPlayer = nullptr;
    CompanyField* currentFieldForPurchase = nullptr;

    sf::RectangleShape diceResultBackground(sf::Vector2f(150, 80));
    diceResultBackground.setFillColor(sf::Color(240, 240, 240));
    diceResultBackground.setOutlineColor(sf::Color::Black);
    diceResultBackground.setOutlineThickness(2);
    diceResultBackground.setPosition(100, 320);

    sf::Text diceTitleText;
    diceTitleText.setFont(font);
    diceTitleText.setCharacterSize(20);
    diceTitleText.setFillColor(sf::Color::Black);
    diceTitleText.setPosition(100, 335);
    diceTitleText.setString("Last roll:");

    sf::Text diceResultText;
    diceResultText.setFont(font);
    diceResultText.setCharacterSize(30);
    diceResultText.setFillColor(sf::Color::Red);
    diceResultText.setPosition(100, 360);
    diceResultText.setString("0");

    sf::Text winnerText;
    winnerText.setFont(font);
    winnerText.setCharacterSize(50);
    winnerText.setFillColor(sf::Color::Yellow);
    winnerText.setPosition(400, 400);
    bool gameOver = false;

    button.setOnClick([&]() {
        if (player1Anim.isRunning() || player2Anim.isRunning() || processingPurchase) return;

        if (currentPlayer == 0) {
            int oldPos = player1.pos;
            int diceSum = player1.turn(board);
            diceResultText.setString(to_string(diceSum));
            auto path = board.getMovementPath(oldPos, player1.pos);
            player1Anim.start(path, [&]() {
                if (board.canBuy(player1.pos)) {
                    currentFieldForPurchase = dynamic_cast<CompanyField*>(board.getCell(player1.pos));
                    if (currentFieldForPurchase) {
                        currentPurchasingPlayer = &player1;
                        purchaseDialog.show(currentFieldForPurchase);
                        processingPurchase = true;
                    }
                }
                else {
                    currentPlayer = (currentPlayer + 1) % 2;
                }
                });
        }
        else {
            int oldPos = player2.pos;
            int diceSum = player2.turn(board);
            diceResultText.setString(to_string(diceSum));
            auto path = board.getMovementPath(oldPos, player2.pos);
            player2Anim.start(path, [&]() {
                if (board.canBuy(player2.pos)) {
                    currentFieldForPurchase = dynamic_cast<CompanyField*>(board.getCell(player2.pos));
                    if (currentFieldForPurchase) {
                        currentPurchasingPlayer = &player2;
                        purchaseDialog.show(currentFieldForPurchase);
                        processingPurchase = true;
                    }
                }
                else {
                    currentPlayer = (currentPlayer + 1) % 2;
                }
                });
        }
        });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (gameOver && event.type == sf::Event::KeyPressed) {
                window.close();
            }
            if (processingPurchase) {
                purchaseDialog.update(window);

                if (purchaseDialog.buyButton.isClicked()) {
                    if (currentPurchasingPlayer && currentFieldForPurchase) {
                        if (currentPurchasingPlayer->getMoney() >= currentFieldForPurchase->price) {
                            currentPurchasingPlayer->buyProperty(*currentFieldForPurchase);
                        }
                    }
                    purchaseDialog.hide();
                    processingPurchase = false;
                    currentPlayer = (currentPlayer + 1) % 2;
                }

                if (purchaseDialog.declineButton.isClicked()) {
                    purchaseDialog.hide();
                    processingPurchase = false;
                    currentPlayer = (currentPlayer + 1) % 2;
                }
            }
            else {
                button.handleEvent(event, window);
            }
        }

        player1Anim.update();
        player2Anim.update();

        if (!gameOver) {
            if (player1.getMoney() < 0) {
                gameOver = true;
                winnerText.setString("Player 2 wins!\nPlayer 1 is bankrupt!\nPress any key to exit");
            }
            else if (player2.getMoney() < 0) {
                gameOver = true;
                winnerText.setString("Player 1 wins!\nPlayer 2 is bankrupt!\nPress any key to exit");
            }
        }

        if (player1Anim.isRunning()) {
            player1.setPosition(player1Anim.getCurrentPosition());
        }
        if (player2Anim.isRunning()) {
            player2.setPosition(player2Anim.getCurrentPosition());
        }

        for (auto& panel : playerPanels) {
            panel.update();
        }

        window.clear(sf::Color(38, 44, 47));
        board.render(window);
        player1.draw(window, font);
        player2.draw(window, font);

        for (auto& panel : playerPanels) {
            panel.draw(window, font);
        }
        window.draw(diceResultBackground);
        window.draw(diceTitleText);
        window.draw(diceResultText);

        if (!processingPurchase && !gameOver) {
            button.update(window);
            button.draw(window);
        }

        if (processingPurchase) {
            purchaseDialog.draw(window);
        }

        if (gameOver) {
            window.draw(winnerText);
        }

        window.display();
    }

    return 0;
}