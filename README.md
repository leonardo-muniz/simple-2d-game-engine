# Simple 2D Game Engine

A minimal 2D game engine prototype that demonstrates a basic game loop, keyboard input handling (WASD + arrow keys), and object movement. Built in C++ (SFML) and Python (Pygame) as a learning project.

## Controls

- Move the square: `WASD` or Arrow Keys
- Quit: Close the window

## How to Run

### C++
```bash
cd ./cpp
g++ main.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system
./game
```

### Python
Make sure you have Pygame installed:
```bash
pip install pygame
```
Then, run it:
```bash
cd ./python
python main.py
```