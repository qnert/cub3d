cub3D - 3D Maze Renderer
Overview
cub3D is a project that involves creating a realistic 3D graphical representation of the inside of a maze from a first-person perspective. The program uses Ray-Casting principles to render the maze in a window.

Features
Realistic 3D rendering using Ray-Casting
Smooth window management
Display of different wall textures based on the wall's orientation
Customizable floor and ceiling colors
Player movement using arrow keys (look left/right) and W, A, S, D keys (move)
Clean program exit on pressing ESC or clicking the window's close button
Scene description file parsing for maze configuration
Requirements
The program must use the miniLibX library for graphical rendering.
The window management should remain smooth, handling changes to other windows, minimizing, etc.
Display different wall textures for each wall orientation.
Set floor and ceiling colors to two different ones.
Player movement and rotation controlled by keyboard inputs.
Scene description file (.cub) specifying maze configuration.
Usage
To compile the program, use the provided Makefile with the following commands:

bash
Copy code
make          # Compile the program
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile the program
Run the program with a scene description file as the first argument:

bash
Copy code
./cub3D path/to/scene.cub
Scene Description File (.cub)
The map must be composed of only 6 characters: 0 for an empty space, 1 for a wall, and N, S, E, or W for the player's start position and orientation.
The map must be closed/surrounded by walls; otherwise, an error will be returned.
Various elements (textures, colors) are specified using identifiers (NO, SO, WE, EA, F, C) in the scene description file.
Example:

plaintext
Copy code
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
Error Handling
If any misconfiguration is encountered, the program exits with an error message.

Bonus Features (if mandatory part is PERFECT)
Wall collisions
Minimap system
Doors that can open and close
Animated sprite
Rotate the point of view with the mouse
License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
The project was inspired by Ray-Casting principles and the miniLibX library.
Special thanks to the creators of the project requirements and bonuses.
