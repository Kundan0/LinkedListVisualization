# Doubly Linked List Visualization

## Overview
This is an interactive Doubly Linked List (DLL) visualization application built using C++ and SFML (Simple and Fast Multimedia Library). The application provides a graphical interface to demonstrate fundamental operations on a doubly linked list.

## Features
- Graphical representation of Doubly Linked List
- Interactive node manipulation
- Operations include:
  - Insert nodes at beginning
  - Insert nodes at end
  - Insert nodes at specific positions
  - Delete nodes from beginning
  - Delete nodes from end
  - Delete nodes from specific positions

## Prerequisites

### Dependencies
- SFML Library (version 2.5 or higher)
- C++ Compiler (supporting C++11 or later)
  - Recommended:
    - GCC (MinGW for Windows)
    - Clang
    - MSVC

### Required Files
- `times.ttf` (Font file)
- `Capture.jpg` (Start node image)
- `Arrow1.jpg` (Forward arrow)
- `Arrow2.jpg` (Backward arrow)
- `Null.jpg` (Null pointer representation)
- `S.png` (Startup screen image)

## Installation

### Windows
1. Install SFML:
   - Download from [SFML Official Website](https://www.sfml-dev.org/download.php)
   - Extract the library
   - Set up environment variables

2. Compile the Project:
   ```bash
   g++ -c main.cpp -I<path_to_sfml>/include
   g++ main.o -o DLL_Visualization -L<path_to_sfml>/lib -lsfml-graphics -lsfml-window -lsfml-system
   ```

### macOS
1. Install SFML via Homebrew:
   ```bash
   brew install sfml
   ```

2. Compile the Project:
   ```bash
   g++ -std=c++11 main.cpp -o DLL_Visualization -I/opt/homebrew/opt/sfml/include -L/opt/homebrew/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system
   ```

### Linux
1. Install SFML:
   ```bash
   sudo apt-get install libsfml-dev
   ```

2. Compile the Project:
   ```bash
   g++ -std=c++11 main.cpp -o DLL_Visualization -lsfml-graphics -lsfml-window -lsfml-system
   ```

## Running the Application
1. Ensure all required image and font files are in the same directory
2. Run the executable:
   ```bash
   ./DLL_Visualization
   ```

## User Interface
- Start screen with an interactive button
- Options menu for inserting and deleting nodes
- Graphical representation of node operations
- Visual navigation through the linked list

## Interaction
1. Click "Start" on the initial screen
2. Choose from options:
   - Insert
     - At beginning
     - At end
     - After specific position
   - Delete
     - From beginning
     - From end
     - From specific position

## Troubleshooting
- Ensure all dependencies are correctly installed
- Verify all required image and font files are present
- Check SFML library paths during compilation

## Note
This is an educational project demonstrating doubly linked list operations and visualization techniques.

