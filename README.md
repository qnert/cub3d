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
make          # Compile the program
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile the program
make bonus    # Compile the program with bonus features

```plaintext
./cub3d ./path_to_map_file # Run the programm
