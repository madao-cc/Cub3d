# Cub3D

> **Objective:** Develop a 3D game using the Raycasting technique, inspired by the classic game Wolfenstein 3D, to deepen understanding of graphics rendering, mathematical concepts, and game development fundamentals.

## Table of Contents

- [Project Overview](#project-overview)
- [Key Features](#key-features)
- [Mathematical Concepts](#mathematical-concepts)
  - [Raycasting](#raycasting)
  - [Vectors and Angles](#vectors-and-angles)
  - [Projection and Field of View](#projection-and-field-of-view)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Understanding the Code](#understanding-the-code)
  - [Initialization](#initialization)
  - [Game Loop](#game-loop)
  - [Rendering](#rendering)
  - [Controls](#controls)
- [Learning Outcomes](#learning-outcomes)
- [Acknowledgments](#acknowledgments)

## Project Overview

**Cub3D** is a project that challenges you to create a basic 3D game using the Raycasting technique. This project is inspired by the classic game Wolfenstein 3D and serves as an introduction to 3D programming, graphics rendering, and game development.

## Key Features

- **2D Map Parsing:** Reads and interprets a 2D map layout from a file.
- **Raycasting Engine:** Implements a Raycasting algorithm to render a 3D view from a 2D map.
- **Texture Mapping:** Applies textures to walls for a more immersive experience.
- **Player Movement:** Allows player navigation through the 3D environment with collision detection.

## Mathematical Concepts

Understanding the following mathematical concepts is crucial for implementing the Raycasting technique in this project:

### Raycasting

Raycasting is a rendering technique used to create a 3D perspective in a 2D game environment. The core idea involves casting rays from the player's viewpoint and calculating the distance to the first obstacle (e.g., a wall) that each ray encounters. This distance information is then used to draw vertical slices of the scene, creating the illusion of depth.

### Vectors and Angles

In the context of Raycasting, vectors represent directions and positions in the 2D plane. The player's orientation can be represented as a directional vector, and the concept of angles is used to determine the direction in which rays are cast relative to the player's viewpoint.

### Projection and Field of View

The Field of View (FOV) determines the extent of the observable game world that is seen at any given moment. In Raycasting, the FOV is divided into discrete rays, and each ray's intersection with the environment is calculated. The projection of these intersections onto the screen creates the 3D effect.

## Project Structure

The repository is organized as follows:

- `includes/`: Contains header files with function prototypes and macros.
- `source/`: Houses the main source files for the game, including initialization, rendering, and control handling.
- `maps/`: Includes `.cub` files that define the game maps.
- `textures/`: Contains texture files used for rendering walls and other surfaces.
- `minilibx-linux/`: Includes the MiniLibX library for handling graphics rendering.
- `Makefile`: Automates the compilation process.

## Installation

To set up and run **Cub3D**:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/madao-cc/Cub3d.git
   ```

2. **Navigate to the Project Directory:**
   ```bash
   cd Cub3d
   ```

3. **Compile the Project:**
   ```bash
   make
   ```
   This will generate the `cub3D` executable.

## Usage

To start the game, run the executable with a map file as an argument:

```bash
./cub3D maps/map.cub
```


Replace `maps/map.cub` with the path to your desired map file.

## Understanding the Code

### Initialization

The initialization phase involves setting up the game environment:

- **Parsing the Map:** The map file is read to construct the 2D representation of the game world.
- **Setting Up the Player:** The player's starting position and orientation are established based on the map data.
- **Loading Textures:** Texture files are loaded into memory for rendering.

### Game Loop

The game operates within a continuous loop that handles:

- **Event Handling:** Captures user inputs for movement and actions.
- **Updating Game State:** Adjusts the player's position and orientation based on inputs and checks for collisions.
- **Rendering:** Calls the Raycasting function to draw the current view of the game world.

### Rendering

Rendering is performed using the Raycasting technique:

- **Casting Rays:** For each column of the screen, a ray is cast from the player's position in the direction corresponding to that column.
- **Calculating Intersections:** The point where each ray first intersects a wall is determined.
- **Drawing Vertical Slices:** Based on the distance to the intersection point, a vertical slice of the wall is drawn, with the height inversely proportional to the distance, creating the 3D effect.

### Controls

The game typically includes the following controls:

- **W:** Move forward.
- **S:** Move backward.
- **A:** Strafe left.
- **D:** Strafe right.
- **Left Arrow:** Turn left. 
