# cub3D - 3D Ray-Caster

## Overview

**cub3D** is a project that involves creating a realistic 3D graphical representation of the inside of a maze from a first-person perspective. The program uses Ray-Casting principles to render the maze in a window.

## Features

- Realistic 3D rendering using Ray-Casting
- Smooth window management
- Display of different wall textures based on the wall's orientation
- Customizable floor and ceiling colors
- Player movement using arrow keys (look left/right) and W, A, S, D keys (move)
- Clean program exit on pressing ESC or clicking the window's close button
- Scene description file parsing for maze configuration

## Requirements

- The program must use the miniLibX library for graphical rendering.
- The window management should remain smooth, handling changes to other windows, minimizing, etc.
- Display different wall textures for each wall orientation.
- Set floor and ceiling colors to two different ones.
- Player movement and rotation controlled by keyboard inputs.
- Scene description file (.cub) specifying maze configuration.

## Usage

To compile the program, use the provided Makefile with the following commands:

```bash
make                       # Compile the program
make clean                 # Remove object files
make fclean                # Remove object files and executable
make re                    # Recompile the program
make bonus                 # Compile the program with bonus features
./cub3d ./path_to_map_file # Run the programm
```

## Example of a valid map file

- Scene description file (.cub) specifying maze configuration.
- The file must have the ending .cub

```plaintext
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
111111111111
100000000001
100000000001
1000000N0001
111111111111
```

## Bonus Features

- Some bonus features are already implemented in the mandatory part of the program
- Wall collisions
- Minimap system
- Doors that can open and close (key **E** for opening and key **Q** for closing)
- Animated sprite
- Rotate the point of view with the mouse
