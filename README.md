# cub3D

A 3D maze game inspired by Wolfenstein 3D, built using raycasting techniques. This project is part of the 42 school curriculum.

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Map Configuration](#map-configuration)
- [Controls](#controls)
- [Gameplay](#gameplay)

## 🎮 About

cub3D is a graphical project that creates a "realistic" 3D representation of a maze from a first-person perspective using raycasting. The project explores the fundamentals of computer graphics, including texture mapping, sprite rendering, and real-time rendering optimization.

## ✨ Features

- **Raycasting engine** for 3D maze rendering
- **Textured walls** with different textures for each cardinal direction
- **Floor and ceiling colors** customization
- **Smooth player movement** and rotation
- **Minimap** (bonus feature)
- **Wall collisions** (bonus feature)
- **Mouse controls** (bonus feature)
- **Sprite rendering** (bonus feature)
- **Doors** (bonus feature)

## 🔧 Requirements

- **Operating System**: Linux
- **Libraries**:
  - Math library (-lm)
  - X11 libraries (on Linux)
  - Xext libraries

## 🚀 Installation

1. Make sure those dependencies are installed 
```bash
sudo apt-get update
sudo apt-get install libx11-dev libxext-dev libbsd-dev
```

2. Clone the repository:
```bash
git clone --recursive https://github.com/seg-fault0/cub3d cub3d
cd cub3d
```

3. Compile the project:
```bash
make
```


## 💻 Usage

Run the program with a map file as argument:

```bash
./cub3D maps/map.cub
```

Example maps are provided in the `maps/` directory.

## 🗺️ Map Configuration

Map files use the `.cub` extension and must follow this format:

```
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm

F 220,100,0
C 225,230,220

111111
100001
101N01
100001
111111
```

### Map Elements:

- **NO, SO, WE, EA**: Paths to wall textures (North, South, West, East)
- **F**: Floor color in RGB format (R,G,B)
- **C**: Ceiling color in RGB format (R,G,B)
- **Map grid**:
  - `0`: Empty space
  - `1`: Wall
  - `N, S, E, W`: Player starting position and orientation
  - `C, O` : door (optional)
  - `D` : animated sprite (optional)

### Map Rules:

- Map must be surrounded by walls (1)
- Only one player starting position
- Valid characters: `0`, `1`, `N`, `S`, `E`, `W`, and spaces
- Map must be properly closed (no gaps in walls)

## 🎮 Controls

### Mandatory:
- **W/A/S/D**: Move forward/left/backward/right
- **E** : opening and closing the door
- **Left/Right Arrows** or **Mouse**: Rotate camera
- **ESC**: Exit game

## 👾 Gameplay
![Gameplay](gameplay.gif)

## 👤 Author

Made by [@seg-fault0](https://github.com/seg-fault0) and [@mohmajd](https://github.com/mohmajd) at 42 School

## 📝 License

This project is part of the 42 school curriculum.

---

**Note**: This project was completed as part of the 42 common core curriculum. It demonstrates proficiency in C programming, graphics programming, and algorithmic thinking.

