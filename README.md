# Cub3D

*This project has been created as part of the 42 curriculum by hadia, lebroue.*

## Description

**Cub3D** is a 42 School project that implements a 3D raycasting engine in C, inspired by classic games like **Doom** and **Wolfenstein 3D**. The project demonstrates fundamental computer graphics concepts by rendering a 3D perspective view from a 2D map using raycasting and texture mapping.

### Key Features
- **Raycasting Engine**: Converts a 2D map into a 3D first-person view
- **Texture Mapping**: Applies textures to walls based on direction (North, South, East, West)
- **DDA Algorithm**: Efficient grid traversal to detect wall collisions
- **Player Movement**: 4-directional movement (forward, backward, strafe left/right)
- **Collision Detection**: Prevents walking through walls
- **Bonus Features**: Minimap (when compiled with `make bonus`)

### Project Goal
To understand and implement the core rendering technique used in early 3D games, implementing a complete raycasting pipeline: parsing configuration files, managing textures, calculating ray-wall intersections, and rendering columns based on distance.

## Instructions

### Prerequisites
- **System**: Linux
- **Compiler**: GCC with `-Wall -Wextra -Werror`
- **Libraries**: 
  - X11 (libxext-dev, libx11-dev)
  - Standard C library (libm)
- **Makefile**: Supports standard `make` targets

### Compilation

```bash
make              # Compile mandatory part
make bonus        # Compile with bonus features (minimap)
make clean        # Remove object files
make fclean       # Remove object files and executable
make re           # Recompile from scratch
```

The executable is named `cub3D`.

### Execution

```bash
./cub3D <path_to_map_file>
```

Example:
```bash
./cub3D maps/good/good_map.cub
```

### Controls

| Key | Action |
|-----|--------|
| **W** / **Up Arrow** | Move forward |
| **S** / **Down Arrow** | Move backward |
| **A** | Strafe left |
| **D** | Strafe right |
| **Mouse** | Look around (bonus only) |
| **ESC** | Exit game |

## Technical Concepts

### 1. Parsing the Configuration File (.cub)

The parsing phase loads and validates the game configuration from a `.cub` file. This process has three main stages:

**Phase 1: Metadata Extraction and Validation**

- **Textures (NO/SO/WE/EA)**: Each line specifies a wall texture for a direction
  - Extracted as file paths and loaded into memory
  - Each texture must be defined exactly once
  
- **Colors (F/C)**: Floor and ceiling colors in RGB format
  - Format: `F 255,100,50` or `C 0,0,0`
  - Each component must be an integer between 0-255
  - Each color must be defined exactly once

**Phase 2: Map Accumulation**

- Lines not matching texture or color formats are treated as map data
- Each map line is stored in a temporary linked list
- Empty lines before the first map line are ignored
- Valid map characters: `0` (empty space), `1` (wall), `N/S/E/W` (player position)

**Phase 3: Map Conversion and Validation**

The linked list is converted into a 2D character array with four mandatory validations:

1. **Width Uniformity**: All rows must have the same width (padding with spaces if needed)
2. **Unique Player Position**: Exactly one player spawn point (N, S, E, or W)
3. **Spatial Closure** (Flood-fill):
   - From the player position, verify all reachable spaces are completely surrounded by walls
   - Detects map gaps and unreachable areas
4. **Player Edge Check**: Player cannot spawn on map boundaries

### 2. DDA Algorithm (Digital Differential Analyzer)

The DDA algorithm efficiently traverses a 2D grid to find ray-wall intersections without expensive trigonometry.

**How it works:**

1. **Initialize the ray**: Starting from player position with a specific angle
2. **Calculate step directions**: Determine whether to move horizontally or vertically first
3. **Grid traversal loop**:
   - Compare distances to next horizontal and vertical grid lines (tmax_x and tmax_y)
   - Move in the direction with the smaller distance
   - Continue until a wall is detected
4. **Collision type determination**: Was the collision on a horizontal or vertical surface?

**Advantages:**
- No expensive trigonometric calculations
- Fast grid traversal with simple additions and comparisons
- Accurate collision detection

### 3. Raycasting Rendering

Raycasting converts the 2D map into a 3D first-person view by casting 800 rays (one per screen column).

**Rendering pipeline for each column:**

1. **Cast ray**: Send a ray from player position at a specific angle
2. **Find collision**: Use DDA to locate the nearest wall
3. **Calculate distance**: Compute perpendicular distance (prevents fisheye distortion)
4. **Determine wall height**: `wall_height = screen_height / distance`
5. **Texture mapping**: Calculate UV coordinates to fetch the correct texture pixel
6. **Render column**: Fill screen column with textured wall data

**Fisheye Correction:**
Without correction, rays at screen edges would be longer, causing the image to bulge. Using perpendicular distance instead of direct ray distance fixes this.

## Architecture

The project is organized into modular components respecting the 42 Norminette constraints (max 5 functions per file, max 25 lines per function):

### Core Modules

| Module | Purpose |
|--------|---------|
| **raycasting/** | 3D rendering engine (DDA, raycasting, wall rendering) |
| **parsing/** | Configuration file parsing and validation |
| **textures/** | Texture loading and management |
| **render_3d/** | Floor and ceiling rendering |
| **player/** | Player position and collision handling |
| **keyboard/** | User input handling |
| **window/** | Window creation and display management |
| **game/** | Main game context and loop |
| **minimap/** | Minimap display (bonus) |

### Key Raycasting Files

- `raycasting.c`: Main orchestrator (loops through 800 rays)
- `raycasting_utils_init_ray.c`: Ray initialization
- `raycasting_utils_dda_algo_utils_calculate_step.c`: DDA step calculations
- `raycasting_utils_dda_algo.c`: DDA grid traversal
- `raycasting_utils_calculate_wall_distance.c`: Perpendicular distance calculation
- `raycasting_utils_draw_vertical_line.c`: Screen column rendering

## Resources

### Raycasting and DDA Algorithm References

1. **DDA - Interactive Explanation**
   https://aaaa.sh/creatures/dda-algorithm-interactive/
   
2. **DDA Line Generation Algorithm - GeeksforGeeks**
   https://www.geeksforgeeks.org/computer-graphics/dda-line-generation-algorithm-computer-graphics/

3. **Raycasting Tutorial - LoDevInfo**
   https://lodev.org/cgtutor/raycasting.html

4. **Raycasting Game Tutorial - YouTube**
   https://www.youtube.com/watch?v=G9i78WoBBIU

5. **Raycasting: From Doom to Wolfenstein**
   https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/

6. **Raycasting - Wikipedia**
   https://fr.wikipedia.org/wiki/Raycasting

7. **Cub3D Implementation Reference - Nathaan**
   https://nathaan.me/projects/cub3d

### AI Usage

AI was used for code review and documentation purposes only:
- **Code structure review**: Validating function organization against 42 Norminette
- **Function naming clarity**: Ensuring descriptive names that explain purpose (e.g., `raycasting_utils_dda_algo_utils_calculate_step.c`)
- **README documentation**: Structuring technical explanations for clarity
- **Parsing logic explanation**: Documenting the three-phase parsing process

No AI was used for core algorithm design or implementation logic.

## Compilation Status

- **Binary size**: ~327KB (optimized: `-O3`)
- **Norminette compliance**: Raycasting module 100% compliant (10/10 files)
- **Warnings**: None
- **Tested maps**: Library, classic, and edge cases all functional

## Summary

Cub3D demonstrates a working 3D raycasting engine that implements:
- **DDA algorithm** for efficient ray-grid intersection
- **Raycasting** to convert 2D maps to 3D perspectives
- **Texture mapping** for realistic wall rendering
- **Modular architecture** compliant with strict coding standards

