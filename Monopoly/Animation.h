using namespace std;
class Animation {
private:
    bool isAnimating = false;
    vector<sf::Vector2f> path;
    size_t currentSegment = 0;
    float progress = 0.0f;
    float speed = 0.15f;
    std::function<void()> onComplete;

public:
    void start(const vector<sf::Vector2f>& movementPath, std::function<void()> callback = nullptr) {
        if (movementPath.empty()) return;

        path = movementPath;
        currentSegment = 0;
        progress = 0.0f;
        isAnimating = true;
        onComplete = callback;
    }

    void update() {
        if (!isAnimating) return;

        progress += speed;
        if (progress >= 1.0f) {
            progress = 0.0f;
            currentSegment++;

            if (currentSegment >= path.size() - 1) {
                isAnimating = false;
                if (onComplete) onComplete();
            }
        }
    }

    sf::Vector2f getCurrentPosition() const {
        if (!isAnimating || path.empty()) return path.back();
        if (currentSegment >= path.size() - 1) return path.back();

        return path[currentSegment] + (path[currentSegment + 1] - path[currentSegment]) * progress;
    }

    bool isRunning() const { return isAnimating; }
};