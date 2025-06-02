#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Monopoly.h"
#include "Button.h"
#include "Animation.h"
#include "PurchaseDialog.h"  // Добавляем новый заголовочный файл
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    // Создаем окно
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
    PurchaseDialog purchaseDialog(font);

    bool processingPurchase = false;
    Player* currentPurchasingPlayer = nullptr;
    CompanyField* currentFieldForPurchase = nullptr;

    button.setOnClick([&]() {
        if (player1Anim.isRunning() || player2Anim.isRunning() || processingPurchase) return;

        if (currentPlayer == 0) {
            int oldPos = player1.pos;
            player1.turn(board);
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
            player2.turn(board);
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

        if (player1Anim.isRunning()) {
            player1.setPosition(player1Anim.getCurrentPosition());
        }
        if (player2Anim.isRunning()) {
            player2.setPosition(player2Anim.getCurrentPosition());
        }
        window.clear(sf::Color(38, 44, 47));
        board.render(window);
        player1.draw(window, font);
        player2.draw(window, font);

        if (!processingPurchase) {
            button.update(window);
            button.draw(window);
        }

        if (processingPurchase) {
            purchaseDialog.draw(window);
        }

        window.display();
    }

    return 0;
}