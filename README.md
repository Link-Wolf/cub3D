<div id="top"></div>

<div align="center">
	<a href="https://github.com/Link-Wolf/cub3D" title="Go to GitHub repo"><img src="https://img.shields.io/static/v1?label=Link-Wolf&message=cub3D&color=blue&logo=github&style=for-the-badge" alt="Link-Wolf - cub3D"></a>
	<a href="https://"><img src="https://img.shields.io/badge/42_grade-125_%2F_100-2ea44f?style=for-the-badge" alt="42 grade - 125 / 100"></a>
	<a href="https://"><img src="https://img.shields.io/badge/Year-2022-ffad9b?style=for-the-badge" alt="Year - 2022"></a>
	<a href="https://github.com/Link-Wolf/cub3D/stargazers"><img src="https://img.shields.io/github/stars/Link-Wolf/cub3D?style=for-the-badge&color=yellow" alt="stars - cub3D"></a>
	<a href="https://github.com/Link-Wolf/cub3D/network/members"><img src="https://img.shields.io/github/forks/Link-Wolf/cub3D?style=for-the-badge&color=lightgray" alt="forks - cub3D"></a>
	<a href="https://github.com/Link-Wolf/cub3D/issues"><img src="https://img.shields.io/github/issues/Link-Wolf/cub3D?style=for-the-badge&color=orange" alt="issues - cub3D"></a>
	<a href="https://www.apple.com/macos/" title="Go to Apple homepage"><img src="https://img.shields.io/badge/OS-macOS-blue?logo=apple&logoColor=white&style=for-the-badge&color=9cf" alt="OS - macOS"></a>
</div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a>
    <img src="https://www.42mulhouse.fr/wp-content/uploads/2022/06/logo-42-Mulhouse-white.svg" alt="Logo" width="192" height="80">
  </a>

  <h3 align="center">cub3D</h3>

  <p align="center">
	  <em>42Stein 3D</em><br/>
    First RayCaster project with <a href="https://github.com/laird-ikar">bguyot</a>
    <br />
    <br />
    <a href="https://github.com/Link-Wolf/cub3D/issues">Report Bug</a>
    ·
    <a href="https://github.com/Link-Wolf/cub3D/issues">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li>
          <a href="#bonus-features">Bonus Features</a>
        </li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<div align="center">
  <a>
    <img src="https://cdn.discordapp.com/attachments/453159761639112706/1055477101777666118/image.png" alt="cub3d illustration">
  </a>
</div>
</br>



This project consists of recreating a 3D graphically representation that we could have from inside a maze in a subjective view, using the RayCasting technique, to create a "Wolfenstein 3D" like game.
The program takes a file `.cub` as a parameter and put the player inside the maze represented in the file.

This is a group project, i made it with [bguyot](https://github.com/laird-ikar).

To do this, we're allowed to use our [libft](https://github.com/Link-Wolf/libft), [get next line](https://github.com/Link-Wolf/get_next_line), the C `math` library, and a tiny local graphic library : the [minilibx](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html) (also called mlx).


The given file must contain the following information :
- The texture path for the North, South, East, and West walls
  - `NO`, `SO`, `EA`, `WE` followed by the path to the texture (as a `.xpm` file or a `.png` file)
- The color of the floor and the ceiling
  - `F` followed by the RGB values (0-255) separated by commas
  - `C` followed by the RGB values (0-255) separated by commas
- The map, composed by only 3 possible digits : `0` for an empty space, `1` for a wall, and `N`, `S`, `E`, `W` for the player's start position and spawning orientation. It must be closed/surrounded by walls

Except for the map, each element (textures / colors) must be separated from the rest of the file by an empty line, but the map itself must always be the last element of the file.

This is an example of a valid file :
```
NO textures/imane.xpm
SO textures/abel.xpm
WE textures/yohan.xpm
EA textures/caroline.xpm


F 169,169,169
C 125,0,42

11111111111111111
10S000000000000011
100000000000000101
100011111111111001
100100000000100101
100100000010001101
100100010011111101
110000010000000001
101111111110000001
100000000000000001
100000000000000001
100000000000000001
100000000000000001
100000000000000001
11111111111111111
```



### Bonus features
Lot of bonuses can be added to the program, we describe them as follow :
>- [The bonus that is describe in the subject]
>  - \<How we implemented it\> 
  
- Adding working doors inside the maze
  * By adding a `-` or a `|` in the map, the program will place a door at the given position in the sense of the character
  * The door will be closed by default, but the player can open it (or close it) by pressing `SPACE` in front of it
  * The player can't go nor see through a closed door 
- Adding a minimap
  * The minimap point of view changes to keep the player in the center of the map
  * The minimap is displayed in the top left corner of the screen
  * The player is represented by a hand pointing in the direction he's facing
- Adding animations
  * The minimap is animated
  * The doors are animated
- Adding collisions
  * The player can't go through walls
  * The player can't go through doors if they're closed
- Adding mouse control
  * The player can look around by moving the mouse in a 360° range


Plus, we added some more bonuses ourself :

- Adding the possibility to put enemies inside the maze
  -  By adding a `2` in the map, the program will place an enemy at the given position (plz go meet them, they're nice)
- Adding a visual fog effect
- Adding ambiant music and sounds
- Adding a introduction screen




<div align="center">
  <a>
    <img src="https://cdn.discordapp.com/attachments/453159761639112706/1055469535572004925/image.png" alt="cub3D with bonuses">
  </a>
</div>
</br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

It's a simple C program but
<span style="color:red">/!\\ sadly the mlx used is only available locally on 42 iMacs /!\\</span></br>
**However** you can use the [improved one](https://github.com/codam-coding-college/MLX42), it will *just* need to edit some includes, the [Makefile](https://github.com/Link-Wolf/cub3D/blob/master/Makefile) and maybe some other little things

### Prerequisites

Having a C compiler like cc, gcc or clang</br>
Be on a 42 iMac or get the MLX42 described above

### Installation
Assuming you are on a 42 iMac</br>
If you use the MLX42, use its [documentation](https://github.com/codam-coding-college/MLX42)
1. Clone the repo
   ```sh
   git clone https://github.com/Link-Wolf/cub3D.git
   ```
2. Compile cub3D
   ```sh
   cd cub3D; make
   ```
3. Execute the program with a `.cub` file
   ```sh
   ./[cub3D | cub3D_bonus] {your file}.cub
   ```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Test our version of the mythic Wolfenstein3D with any map you want !</br>
The second picture is the result from this command :
```sh
   ./cub3D_bonus map_bonus.cub
```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [x] Add all bonus features
- [x] Add back to top links

See the [open issues](https://github.com/Link-Wolf/cub3D/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Mail : xxxxxxx@student.42mulhouse.fr

Project Link: [https://github.com/Link-Wolf/cub3D](https://github.com/Link-Wolf/cub3D)

<p align="right">(<a href="#top">back to top</a>)</p>
