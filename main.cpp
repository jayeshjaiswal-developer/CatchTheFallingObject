#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <string>

int main()
{
    // Random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Create game window
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Catch the Falling Object");

    // ---------------- BASKET ----------------
    sf::RectangleShape basket({120.f, 30.f});
    basket.setFillColor(sf::Color::Green);
    basket.setPosition({340.f, 520.f});

    // Basket movement speed
    float basketSpeed = 0.5f;

    // ---------------- GROUND ----------------
    sf::RectangleShape ground({800.f, 20.f});
    ground.setFillColor(sf::Color(80, 80, 80));
    ground.setPosition({0.f, 580.f});

    // ---------------- FALLING OBJECT ----------------
    sf::CircleShape object(20.f);
    object.setFillColor(sf::Color::Red);
    object.setPosition({380.f, 50.f});

    // Object falling speed
    float objectSpeed = 0.25f;

    // ---------------- GAME VARIABLES ----------------
    int score = 0;
    int lives = 10;

    bool gameStarted = false;
    bool gameOver = false;

    // ---------------- FONT ----------------
    sf::Font font;

    if (!font.openFromFile("assets/font.ttf"))
    {
        return 1;
    }

    // ---------------- SOUND BUFFERS ----------------

    sf::SoundBuffer catchBuffer;
    sf::SoundBuffer missBuffer;
    sf::SoundBuffer gameOverBuffer;

    if (!catchBuffer.loadFromFile("assets/catch.wav"))
    {
        return 1;
    }

    if (!missBuffer.loadFromFile("assets/miss.wav"))
    {
        return 1;
    }

    if (!gameOverBuffer.loadFromFile("assets/gameover.wav"))
    {
        return 1;
    }

    // ---------------- SOUNDS ----------------

    sf::Sound catchSound(catchBuffer);
    sf::Sound missSound(missBuffer);
    sf::Sound gameOverSound(gameOverBuffer);

    // ---------------- GAME TITLE ----------------

    sf::Text titleText(
        font,
        "CATCH THE FALLING OBJECT",
        28);

    titleText.setFillColor(sf::Color::Yellow);
    titleText.setPosition({250.f, 10.f});

    // ---------------- START SCREEN TEXT ----------------

    sf::Text startText(
        font,
        "CATCH THE FALLING OBJECT\nPress ENTER to Start",
        36);

    startText.setFillColor(sf::Color::White);
    startText.setPosition({170.f, 250.f});

    // ---------------- SCORE TEXT ----------------

    sf::Text scoreText(
        font,
        "Score: 0",
        24);

    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({20.f, 50.f});

    // ---------------- LIVES TEXT ----------------

    sf::Text livesText(
        font,
        "Lives: 10",
        24);

    livesText.setFillColor(sf::Color::White);
    livesText.setPosition({650.f, 50.f});

    // ---------------- GAME OVER TEXT ----------------

    sf::Text gameOverText(
        font,
        "GAME OVER\nPress R to Restart",
        40);

    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition({220.f, 250.f});

    // ================= GAME LOOP =================

    while (window.isOpen())
    {
        // ---------------- EVENT HANDLING ----------------

        while (auto event = window.pollEvent())
        {
            // Close window
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            // Keyboard events
            if (const auto* keyPressed =
                    event->getIf<sf::Event::KeyPressed>())
            {
                // Start game
                if (!gameStarted &&
                    keyPressed->scancode ==
                        sf::Keyboard::Scan::Enter)
                {
                    gameStarted = true;
                }

                // Restart game
                if (gameOver &&
                    keyPressed->scancode ==
                        sf::Keyboard::Scan::R)
                {
                    score = 0;
                    lives = 10;
                    gameStarted = true;
                    gameOver = false;

                    // Reset object speed
                    objectSpeed = 0.25f;

                    // Reset text
                    scoreText.setString("Score: 0");
                    livesText.setString("Lives: 10");

                    // Reset positions
                    basket.setPosition({340.f, 520.f});
                    object.setPosition({380.f, 50.f});
                }
            }
        }

        // ================= GAME UPDATE =================

        if (gameStarted && !gameOver)
        {
            // -------- SMOOTH BASKET MOVEMENT --------

            if (sf::Keyboard::isKeyPressed(
                    sf::Keyboard::Key::Left))
            {
                basket.move({-basketSpeed, 0.f});
            }

            if (sf::Keyboard::isKeyPressed(
                    sf::Keyboard::Key::Right))
            {
                basket.move({basketSpeed, 0.f});
            }

            // -------- BASKET BOUNDARIES --------

            if (basket.getPosition().x < 0.f)
            {
                basket.setPosition({0.f, 520.f});
            }

            if (basket.getPosition().x > 680.f)
            {
                basket.setPosition({680.f, 520.f});
            }

            // -------- MOVE FALLING OBJECT --------

            object.move({0.f, objectSpeed});

            // -------- OBJECT MISSED --------

            if (object.getPosition().y > 600.f)
            {
                // Decrease life
                lives--;

                // Play miss sound
                missSound.play();

                // Update lives text
                livesText.setString(
                    "Lives: " + std::to_string(lives));

                // Generate random X position
                float randomX =
                    static_cast<float>(
                        20 + std::rand() % 760);

                // Reset object
                object.setPosition({randomX, 50.f});

                // Check Game Over
                if (lives <= 0)
                {
                    gameOver = true;

                    // Play game over sound
                    gameOverSound.play();
                }
            }

            // -------- COLLISION DETECTION --------

            if (object.getGlobalBounds().findIntersection(
                    basket.getGlobalBounds()))
            {
                // Increase score
                score++;

                // Play catch sound
                catchSound.play();

                // Increase difficulty every 5 points
                if (score % 5 == 0)
                {
                    objectSpeed += 0.05f;
                }

                // Update score text
                scoreText.setString(
                    "Score: " + std::to_string(score));

                // Generate random X position
                float randomX =
                    static_cast<float>(
                        20 + std::rand() % 760);

                // Reset object
                object.setPosition({randomX, 50.f});
            }
        }

        // ================= DRAW =================

        // Dark blue background
        window.clear(sf::Color(20, 25, 45));

        // -------- START SCREEN --------

        if (!gameStarted)
        {
            window.draw(startText);
        }
        else
        {
            // Draw title
            window.draw(titleText);

            // Draw score
            window.draw(scoreText);

            // Draw lives
            window.draw(livesText);

            // Draw basket
            window.draw(basket);

            // Draw ground
            window.draw(ground);

            // Draw falling object
            if (!gameOver)
            {
                window.draw(object);
            }

            // Draw Game Over screen
            if (gameOver)
            {
                window.draw(gameOverText);
            }
        }

        // Display everything
        window.display();
    }

    return 0;
}