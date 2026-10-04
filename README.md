# Catch the Falling Object

Catch the Falling Object is a simple event-driven 2D game developed in C++ using SFML.

In the game, the player controls a basket at the bottom of the screen and tries to catch a falling object. Each successful catch increases the score, while missing an object reduces the player's lives. The falling object becomes faster as the score increases.

## Project Overview

This project was developed as a B.Tech Semester 1 mini project to demonstrate basic C++ programming and event-driven game development concepts.

The project includes:

- Keyboard input handling
- A continuous game loop
- Collision detection
- Score management
- Lives management
- Game Over condition
- Random object positions
- Increasing game difficulty
- Basic sound effects
- Start and restart functionality

## Objectives

1. To understand event-driven programming in C++.
2. To handle keyboard input using SFML.
3. To implement a basic game loop.
4. To implement collision detection.
5. To implement score and lives.
6. To implement a Game Over condition.
7. To use random number generation.
8. To add basic sound effects.
9. To understand basic graphics programming using SFML.

## Game Description

The player controls a basket using the left and right arrow keys.

A red object continuously falls from the top of the screen.

- If the basket catches the object, the score increases by 1.
- If the object reaches the bottom without being caught, one life is lost.
- The player starts with 10 lives.
- Every 5 successful catches, the falling object becomes slightly faster.
- When all lives are lost, the game enters the Game Over state.
- The player can press R to restart the game.

## Controls

| Key         | Action                  |
| ----------- | ----------------------- |
| ENTER       | Start the game          |
| LEFT Arrow  | Move the basket left    |
| RIGHT Arrow | Move the basket right   |
| R           | Restart after Game Over |

## Technologies Used

| Technology | Purpose                   |
| ---------- | ------------------------- |
| C++        | Main programming language |
| SFML       | Graphics, input and audio |
| Clang++    | C++ compiler              |
| Git        | Version control           |
| GitHub     | Source code hosting       |

## Project Structure

```text
CatchTheFallingObject/
|
├── main.cpp
├── assets/
│   ├── font.ttf
│   ├── catch.wav
│   ├── miss.wav
│   └── gameover.wav
├── .gitignore
└── README.md
```

## Game Flow

```text
Start Screen
     |
     | Press ENTER
     v
Game Starts
     |
     v
Object Falls
     |
     v
Check Collision
     |
     +------------------+
     |                  |
   Caught             Missed
     |                  |
     v                  v
 Score + 1           Life - 1
     |                  |
     +---------+--------+
               |
               v
       Reset Object Position
               |
               v
        Continue Game
               |
               v
          Lives = 0?
          /        \
        No          Yes
        |            |
        v            v
   Continue       Game Over
                     |
                     | Press R
                     v
                  Restart
```

## Game Logic

1. Handle window and keyboard events.
2. Move the basket according to keyboard input.
3. Move the falling object downward.
4. Check for collision between the object and basket.
5. Increase the score if the object is caught.
6. Decrease a life if the object is missed.
7. Reset the object to a new random horizontal position.
8. Increase the falling speed after every 5 points.
9. Draw the updated game screen.
10. Continue until the game is closed or all lives are lost.

## Collision Detection

Collision detection is used to determine whether the falling object touches the basket.

If the object and basket boundaries intersect:

```text
Score = Score + 1
```

If the object reaches the bottom without being caught:

```text
Lives = Lives - 1
```

## Score and Difficulty

The player starts with:

```text
Score = 0
Lives = 10
Object Speed = 0.25
```

The falling object becomes faster after every 5 successful catches.

```text
Score 0  -> Speed 0.25
Score 5  -> Speed 0.30
Score 10 -> Speed 0.35
Score 15 -> Speed 0.40
```

## Game States

### Start State

The player sees the start screen and must press ENTER to begin.

### Playing State

The player controls the basket, catches falling objects, earns points and manages lives.

### Game Over State

When all lives are lost, the game displays the Game Over screen. The player can press R to restart.

## Sound Effects

The game uses three sound effects:

- Catch sound when an object is successfully caught.
- Miss sound when an object is missed.
- Game Over sound when all lives are lost.

## Testing

| Test           | Expected Result       |
| -------------- | --------------------- |
| Press ENTER    | Game starts           |
| Press LEFT     | Basket moves left     |
| Press RIGHT    | Basket moves right    |
| Catch object   | Score increases       |
| Miss object    | Life decreases        |
| Reach 5 points | Object becomes faster |
| Lose all lives | Game Over appears     |
| Press R        | Game restarts         |
| Close window   | Game closes           |

## Installation

### Requirements

- C++ compiler
- SFML 3.x
- Git
- Terminal or Command Prompt

### macOS

If Homebrew is installed:

```bash
brew install sfml
```

### Compile

From the project directory:

```bash
clang++ -std=c++17 main.cpp -o game \
-I/opt/homebrew/include \
-L/opt/homebrew/lib \
-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```

### Run

```bash
./game
```

The required asset files must remain inside the `assets` folder.

## Windows

The project can also be configured on Windows using a C++ compiler and SFML.

The required SFML components are:

```text
sfml-graphics
sfml-window
sfml-system
sfml-audio
```

The exact compiler and library configuration may differ depending on the Windows development environment.

## Screenshots

Add screenshots of the actual game here after final testing.

Suggested screenshots:

- Start screen
- Gameplay screen
- Gameplay with score and lives
- Game Over screen

Example:

```markdown
![Start Screen](screenshots/start.png)
![Gameplay](screenshots/gameplay.png)
![Game Over](screenshots/gameover.png)
```

## Learning Outcomes

Through this project, we learned:

- Basic C++ programming
- Event-driven programming
- Game loop implementation
- Keyboard input handling
- Collision detection
- Random number generation
- Basic graphics programming
- Audio integration
- Debugging and testing
- Git and GitHub

## Future Improvements

Possible future improvements include:

- Multiple types of falling objects
- Different difficulty levels
- High-score system
- Pause and resume functionality
- Improved animations
- Background music
- Power-ups
- More advanced graphics
- Multiple player modes

## Team

### Team Members

- Mohit Jaiswal

### Project Details

Project Type: B.Tech Semester 1 Mini Project

Project Title: Catch the Falling Object

Programming Language: C++

Library: SFML

## License

This project is developed for educational and academic purposes.
