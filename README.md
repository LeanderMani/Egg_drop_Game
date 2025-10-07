# Egg_drop_Game

Egg Game
Egg Game is a simple C++ console-based game where players try to catch falling eggs using a basket.
It is designed to demonstrate basic game logic, loops, conditionals, randomization, and user input handling in C++.
________________________________________
Gameplay
•	The game allows up to 3 players, one after the other.
•	Each player moves a basket (represented in the console) to catch falling eggs.
•	Score: Each egg caught gives 10 points.
•	The game ends for a player if an egg hits the ground.
•	At the end of all turns, the winner is announced and the scores are stored in a HighScore.txt file.
________________________________________
Code Structure
The project is divided into multiple classes and functions:
•	setup: Initializes game variables, player details, and starting positions.
•	Input: Handles keyboard input for player movement.
•	Logic: Implements game rules like basket movement, egg falling, score calculation, and collision detection.
•	result(): Displays the winner with an animation and stores high scores.
•	details(): Collects player names with a simple typing animation.
•	store(): Displays the score after a player’s turn.
Key features of the implementation:
•	Uses C++ standard libraries (iostream, fstream, conio.h, Windows.h, time.h)
•	Randomized egg positions for dynamic gameplay
•	Supports multiple players with sequential turns
•	Simple text-based animation for credits and winner display
