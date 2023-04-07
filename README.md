<img src="https://i.imgur.com/HG66CCx.png?raw=true" alt="CODAM" style="max-width: 50%;">
<div>
  <h1>So Long</h1>
</div>

My very first graphical project! Creating a 2d topdown game in C as part of my coding journey at [CODAM](https://www.codam.nl)/ [NETWORK 42](https://www.42network.org/).

So long introduced me to the basics of window management, event handling, textures, and much more. All areas which were instrumental in helping me improve my programming skills and knowledge. Since starting with programming, every step of the learning progress was as rewarding as it was frustrating. Running code to make something visually appear on screen for the first time however, was nothing short of exhilarating.

To handle the window management and all things graphical during our project we were tasked to use the school graphical library: the MiniLibX or [MLX42](https://github.com/codam-coding-college/MLX42)*. These libraries were developed internally and include basic necessary tools to open a window, create images and deal with keyboard and mouse events. Learning how to navigate this library and properly utilize it was a major part of bringing the project to a succesful end.

<sub>* If you are reading this as a 42 student make sure that your particular school actually allows the use of the MLX42 library.</sub>

<h1>
</h1>
<div align="center">
  <img src="https://i.imgur.com/Z3sUxUi.gif" alt="Header">
</div>

## Installation

To install the game [download](https://github.com/arommers/so_long/archive/refs/heads/master.zip) and use the command 'cd' to move to the so_long folder.

Run 'make' to compile all the files and run the executable './so_long' followed by the pathway to the Maps folder and a map of your choosing.

```
./so_long ./Maps/map1.ber
```

## The Game

The assignment of so long is to make a 2d game (top down or profile) where the player’s goal is to collect every collectible present on the map, then escape through an exit. The game itself has to adhere to the following rules:

• The `W, A, S, and D` keys must be used to move the main character.\
• The player should be able to move in these 4 directions: up, down, left, right.\
• The player should not be able to move into walls.\
• At every move, the current number of movements must be displayed in the shell.

#### Map

The game takes a`.ber. file that contains a map of ascii characters representing the different elements as input.

`0` for an empty space\
`1` for a wall\
`C` for a collectible\
`E` for a map exit\
`P` for the player’s starting position

Example of a valid map:

`1111111111111111111`\
`1C10000C000001C0011`\
`101001111000C001111`\
`1010001111100011111`\
`1C100111110C0111111`\
`1000111111110001111`\
`10000000PE000000C01`\
`1111100000000111111`\
`100C00000000000C001`\
`1111111111111111111`

The map has to adhere to the following requirements:

• The map must contain 1 exit, at least 1 collectible and 1 starting position to be valid.\
• The map must be rectangular.\
• The map must be closed/surrounded by walls.\
• You have to check if there’s a valid path in the map.\
• You must be able to parse any kind of map, as long as it respects the above rules.

If a file is provided that doesn't follow these rules then error handling has to be according to the specific fault.
Most of these aren't too complicated, but I would like to invite you to take a look at the concept of [flood fill](https://www.youtube.com/watch?v=VuiXOc81UDM) that I used to check if there is a valid path available on the map.

## Approach

- Parsing the map into data, mostly in one big struct.
- Use this data to check the validity of the provided map.
- Initialize/create the images that we are going to use in our game.
- Initialize a window and create and maintain a loop to mess around in our window.
- Render our game map and necessary elements.
- Create an even loops to handle input.
- Play our game!

One of the reasons why I decided to make a somewhat elaborate readme file was to help others with what I learned during this project. More specifically, where I got stuck and how to prevent others from wasting as much time as I did. Practically every time I stumbled could be derived from not using the functions in MLX42 library correctly. Occasionally this was due to the somewhat ambiguous wording of the documentation, but frequently because I apparently still don't know how to read.

## Creating Images

<h1>
</h1>
<div align="center">
  <img src="https://i.imgur.com/wXlRb9T.gif" alt="Game Screenshot">
</div>

<div>
  <h1>Sources</h1>
</div>

- [MLX42](https://github.com/codam-coding-college/MLX42)
- [ITCH.IO](https://itch.io/)
