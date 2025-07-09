# cub3d Project

## Overview
The cub3d project is a 3D game engine that implements a raycasting algorithm to render a 3D view of a game world based on a 2D map. The project is structured into several modules, each responsible for different aspects of the game, including parsing, rendering, game logic, and utility functions.

## Project Structure
```
cub3d
├── src
│   ├── main.c
│   ├── parsing
│   │   ├── map_parsing.c
│   │   ├── texture_parsing.c
│   │   └── validation.c
│   ├── rendering
│   │   ├── raycasting.c
│   │   ├── textures.c
│   │   └── drawing.c
│   ├── game
│   │   ├── player.c
│   │   ├── movement.c
│   │   └── events.c
│   └── utils
│       ├── error.c
│       ├── cleanup.c
│       └── math_utils.c
├── inc
│   └── cub3d.h
├── maps
│   ├── valid.cub
│   └── test.cub
├── textures
│   ├── north.xpm
│   ├── south.xpm
│   ├── east.xpm
│   └── west.xpm
├── libft
│   ├── libft.h
│   └── src
├── minilibx
├── Makefile
└── README.md
```

## Setup Instructions
1. **Clone the Repository**
   ```bash
   git clone <repository-url>
   cd cub3d
   ```

2. **Build the Project**
   Use the provided Makefile to compile the project:
   ```bash
   make
   ```

3. **Run the Game**
   After building, you can run the game with:
   ```bash
   ./cub3d maps/valid.cub
   ```

## Usage
- The game reads map data from `.cub` files located in the `maps` directory.
- Textures for the walls are stored in the `textures` directory and are loaded at runtime.
- Player movement and interactions are handled through keyboard inputs.

## Features
- Raycasting for 3D rendering.
- Support for multiple textures.
- Basic player movement and event handling.
- Error handling and resource cleanup.

## Contributing
Contributions are welcome! Please submit a pull request or open an issue for any enhancements or bug fixes.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.