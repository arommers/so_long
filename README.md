<img src="https://i.imgur.com/HG66CCx.png?raw=true" alt="CODAM" style="max-width: 50%;">
<div>
  <h1>So Long</h1>
</div>

My very first graphical project! Creating a simple, 2d topdown game in C as part of my coding journey at [CODAM](https://www.codam.nl)/ [NETWORK 42](https://www.42network.org/).

So long introduced me to the basics of window management, event handling, textures, and much more. All areas which were instrumental in helping me improve my programming skills and knowledge. Since starting with programming, every step of the learning progress was as rewarding as it was frustrating. Running code to make something visually appear on screen for the first time however, was nothing short of exhilarating.

To handle the window management and all things graphical during our project we were tasked to use the school graphical library: the MiniLibX or [MLX42](https://github.com/codam-coding-college/MLX42)*. These libraries were developed internally and include basic necessary tools to open a window, create images and deal with keyboard and mouse events. Learning how to navigate this library and properly utilize it was a major part of bringing the project to a succesful end.

<sub>* If you are reading this as a 42 student make sure that your particular school actually allows the use of the MLX42 library.</sub>

<h1></h1>
<div align="center">
  <img src="https://i.imgur.com/Z3sUxUi.gif" alt="Header" style="width: 100%;">
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

The game takes a `.ber` file that contains a map of ascii characters representing the different elements as input.

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
- Initialize a window and create and maintain a loop to mess around in our window.
- Initialize/create the images that we are going to use in our game.
- Render our game map and necessary elements.
- Create an event loop to handle input.
- Play our game!

One of the reasons why I put in the effort to create a somewhat elaborate readme file was to help fellow 42 students out there with what I learned during this project. I wanted to share my experience and help them through the areas where I got stuck and how to prevent them from wasting as much time as I did. I'll do my best to keep your trial and error to a minimum.

More often than not, I found myself stumbling because I failed to use the functions in the MLX42 library properly. Occasionally, I found the documentation to be at fault, but nine of ten times it was the humbling realisation that I apparently still don't know how to read.

Now, I won't be going into every single detail involved in bringing this project to a successful conclusion. But my hope is that this readme file clarifies some points that were unclear to me when I started out and save you some of the frustrations I experienced ;)

## Initializing and Maintaining a Window

In order to show off our game in all its glory, one of the most important things to do is set up a connection between our program and the X window system, which is a windowing system that provides a graphical user interface for Unix-based operating systems.

The `mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize)` function takes care of us for this. This connection is necessary for our program to be able to interact with the windowing system and display graphical elements on the screen. Once the connection is established, our program can create windows, handle user input, and perform other graphical operations using the functions provided by the mlx library. `mlx_init()` returns a pointer to an [opaque structure](https://www.geeksforgeeks.org/opaque-pointer-in-cpp/) that represents the connection. That pointer can then be pased to other MLX42 functions that require a connection to the X server. They'll know exactly what window instance they should be working with. We'll stumble upon some examples in a bit.

In order to display graphics on the screen using MiniLibX, the mlx_init function must be called at the beginning of the program. This function sets up a connection to the X server and returns a pointer to an opaque structure that represents the connection. This pointer is then passed as an argument to other MiniLibX functions that require a connection to the X server.

## Creating Images

To be able to make a 2d game we are going to need a visual representations of all the elements on our provided map. At this point The `1's` representing the walls, the `C's` the collectibles, the `P` the player character, etc are just ASCII symbols stored in a 2d array. The MLX42 library requires either an XPM or PNG file, both file formats to store digital images and generate them in out window. For each element in our map we scoured the internet and selected an appropriate image to use. In our case we opted to use PNG's. However, before MLX42 can use these images to visually render our game, we have to transform the image data of the PNG's into a format that the graphics library can use. To manage this I used the following three MLX42 functions: 

- ```mlx_texture_t* mlx_load_png(const char* path)```
- ```mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture)```
- ```int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y)```

##### MLX_LOAD_PNG

The `mlx_load_png` function is used to load a PNG file into a `mlx_texture_t` struct. This function takes a string that represents the path to the PNG file that you want to load. When this function is called, it reads the file and decodes the pixel data from the PNG format into a format that can be used by the graphics library. This format is an array of bytes that represent the color of each pixel in the image.

Once the `mlx_load_png` function has finished decoding the pixel data, it returns a pointer to an `mlx_texture_t` struct. This struct contains information about the texture, including its dimensions, the format of the pixel data, and a pointer to the pixel data itself. The reason why the pixel data needs to be decoded from the PNG format into a texture struct is that PNG files use a compressed format to store the image data. This compression helps to reduce the size of the file on disk, but it also means that the pixel data cannot be directly used by the graphics library without first being decoded. Take a look at the [MLX42 header file](https://github.com/codam-coding-college/MLX42/blob/master/include/MLX42/MLX42.h) to see what this struct actually contains.

##### MLX_TEXTURE_TO_IMAGE

After loading our PNG file into an mlx_texture_t struct, we can't simply draw it on the screen just yet. This is because the graphics library needs to convert the pixel data stored in the struct into a format that can be rendered on the screen. Therefore, we need to create an mlx_image_t structure to represent the transformed image data that the graphics library can use.

The mlx_image_t struct contains information about the format of the transformed image data, such as its width, height, and other details, along with a pointer to the actual transformed pixel data. To create this struct, we use the mlx_texture_to_image function, which takes a pointer to our currently running window and a pointer to our texture data. This function initializes the image struct so that the graphics library can work with our texture.

It's important to note that the transformation of the pixel data in the texture involves converting it from its original format, such as RGBA, to a format that can be rendered by the graphics library. Once we have our initialized image struct, we can start rendering our images on the screen.

##### MLX_IMAGE_TO_WINDOW

The `mlx_put_image_to_window` function plays a crucial role in rendering the game. It allows us to display an image on the screen by taking a pointer to the specific `mlx_image_t`, a pointer to our current graphics window, and the coordinates where the image should be displayed in the window. However, while we can iterate over our 2D array that stores our ASCII map by just moving 1 index for a new location, the same is not true for our window and image placement.

The PNG images we used in our game are 64 x 64 pixels in size, so whenever we would like to put an image into our window, we have to keep track of our X and Y coordinates. For every subsequent image we place after the first one, we have to increment our X or Y coordinate by the height or width of our image, which is 64. We used a while loop that iterates over our provided ASCII map, and at each index, we called mlx_put_image_to_window to put an image in our current window at the correct coordinates.

Check out our fully rendered map below!

<h1>
</h1>
<div align="center">
  <img src="https://i.imgur.com/wXlRb9T.gif" alt="Game Screenshot">
</div>
<h1>
</h1>

<div>
  <h1>Sources</h1>
</div>

- [MLX42](https://github.com/codam-coding-college/MLX42)
- [ITCH.IO](https://itch.io/)
