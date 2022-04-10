# fract-ol

## Doubts and Clarification
- I am having trouble with installing Minilibx and how to use it.

## Resources
- https://github.com/qst0/ft_libgfx
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
- https://github.sre.pub/topics/42born2code - I don't know what this is but looks interesting.

## What are Fractals?
Fractals are very complex pictures generated by a computer from a single formula. They are created using iterations. This means one formula is repeated with slightly different values over and over again, taking into account the results from the previous iteration.

## math.h
- The header file math.h provides function prototypes and macros for working with floating point values.
- If you need to perform mathematical operations on complex floating point numbers should consult the man pages for the complex portion of the math library, via "man complex".
- Try man 3 math on terminal for more information.

## MiniLibX - Simple Graphical Interface Library for students
- The MacOSX operating system handle graphical access to the screen (or "display"). On one side, your software wants to draw something on the screen and/or get keyboard & mouse entries. On the other side, the underlying MacOSX graphical framework that handles the screen, the windowing system, keyboard and mouse. A connection between these two entities must be established.
### Installation
- This is a bit tricky part if you are doing it alone.
- download the .tar folder from the project page.
- untar it and rename it to minilibx
- Now go inside the minilibx folder and run make this will create a libmlx.a file.
### Running your first MiniLibX program
- First of all, you need to initialize the connection between your software and the display. Once this connection is established, you'll be able to use other MiniLibX functions to send the graphical orders, like "I want to draw a yellow pixel in this window" or "did the user hit a key?". The mlx_init() function will create this connection. No parameters are needed, and it will return a void* identifier, used for further calls to the library routines.
- https://github.com/qst0/ft_libgfx/blob/master/man_mlx.md
```
void  *mlx_init();
```
- let's run our first program 1-started.c given below.
```
#include "minilibx/mlx.h"

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
}
```
- Now let's create a Makefile to run the above program.
```
NAME		=	1-started
LIBX_DIR	=	minilibx
LIBX		=	libmlx.a
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS = 1-started.c
OBJS		=	$(SRCS:%c=%o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast

%.o : %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
  
$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)
  @rm -f 1-started.o

all : $(NAME)
```
- let's create the object file and executable by running make.
- When you run the 1-started file from the terminal you can't help but notice that nothing pops up and that nothing is being rendered.
- Well, this obviously has something to do with the fact that you are not creating a window yet.
- What you just did is to create a initialized the connection between your software and the display.

### Creating a window.
- The mlx_new_window() function creates a new window on the screen, using the size_x and size_y parameters to determine its size, and title as the text that should be displayed in the window's title bar.
- The mlx_ptr parameter is the connection identifier returned by mlx_init(). mlx_new_window() returns a void * window identifier that can be used by other MiniLibX calls. 
- Note that the MiniLibX can handle an arbitrary number of separate windows.
- mlx_clear_window() and mlx_destroy_window() respectively clear (in black) and destroy the given window. They both have the same parameters: mlx_ptr is the screen connection identifier, and win_ptr is a window identifier.
- Return values : If mlx_new_window() fails to create a new window (for wathever reason), it will return NULL, otherwise a non-null pointer is returned as a window identifier. mlx_clear_window and mlx_destroy_window right now return nothing.
```
void *
mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

int
mlx_clear_window ( void *mlx_ptr, void *win_ptr );

int
mlx_destroy_window ( void *mlx_ptr, void *win_ptr );
```
- Both  X-Window  and MacOSX graphical systems are bi-directionnal.  On one hand, the program sends orders to the screen to display pixels, images, and so on. On the other hand, it  can get information from the keyboard and mouse associated to the screen. To do so, the program receives "events" from the keyboard or the mouse.
- To receive events, you must use mlx_loop (). This function never returns. It is an infinite loop  that  waits for an event, and then calls a user-defined function associated with this event.  A single parameter is needed, the connection identifier mlx_ptr (see the  mlx  manual).
```
int
mlx_loop ( void *mlx_ptr );
```
- Let's create a new window using the above function 2-creating_a_window.c
- To achieve this, we will simply call the mlx_new_window function, which will return a pointer to the window we have just created. We can give the window height, width and a title. We then will have to call mlx_loop to initiate the window rendering. Let’s create a window with a width of 1920, a height of 1080 and a name of “Hello world!”: 
- https://github.com/qst0/ft_libgfx/blob/master/man_mlx_new_window.md
```
#include "minilibx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
```
- here's a make file for the above program.
```
NAME		=	2-creating_a_window
LIBX_DIR	=	minilibx
LIBX		=	libmlx.a
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS = 2-creating_a_window.c
OBJS		=	$(SRCS:%c=%o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast

%.o : %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	
$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)
	@rm -f 2-creating_a_window.o

all : $(NAME)
```
- when you run make from the terminal you will create the executable file and run this executable from the terminal a new empty window will pop up. you have just created you empty first window with the name hello world.

### Writing pixels to image
- Now that we have basic window management, we can get started with pushing pixels to the window. How you decide to get these pixels is up to you, however some optimized ways of doing this will be discussed. First of all, we should take into account that the mlx_pixel_put function is very, very slow. This is because it tries to push the pixel instantly to the window (without waiting for the frame to be entirely rendered). Because of this sole reason, we will have to buffer all of our pixels to a image, which we will then push to the window. All of this sounds very complicated, but trust me, its not too bad.
- First of all, we should start by understanding what type of image mlx requires. If we initiate an image, we will have to pass a few pointers to which it will write a few important variables. The first one is the bpp, also called the bits per pixel. As the pixels are basically ints, these usually are 4 bytes, however, this can differ if we are dealing with a small endian (which means we most likely are on a remote display and only have 8 bit colors).
- Now we can initialize the image with size 1920×1080 as follows: 3-Writing_pixels_to_image.c
```
#include "minilibx/mlx.h"

int	main(void)
{
	void	*img;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
}
```
- Here's the makefile for the above program.
```
NAME		=	3-Writing_pixels_to_image
LIBX_DIR	=	minilibx
LIBX		=	libmlx.a
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS = 3-Writing_pixels_to_image.c
OBJS		=	$(SRCS:%c=%o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast

%.o : %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)
	@rm -f 3-Writing_pixels_to_image.o

all : $(NAME)
```
- mlx_new_image() creates a new image in memory.
- It returns a void * identifier needed to manipulate this image later.
- It only needs the size of the image to be created, using the width and height parameters, and the mlx_ptr connection identifier (see the mlx manual). 
- https://github.com/qst0/ft_libgfx/blob/master/man_mlx_new_image.md
```
void *
mlx_new_image ( void *mlx_ptr, int width, int height );
```
### Getting address to mutate
- That wasn’t too bad, was it? Now, we have an image but how exactly do we write pixels to this? For this we need to get the memory address on which we will mutate the bytes accordingly. We retrieve this address as follows:
- 4-Getting_memory_address_to_mutate.c
```
#include "minilibx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
}
```
- here's a simple make file for the above program.
```
NAME		=	4-Getting_memory_address_to_mutate
LIBX_DIR	=	minilibx
LIBX		=	libmlx.a
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS = 4-Getting_memory_address_to_mutate.c
OBJS		=	$(SRCS:%c=%o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast

%.o : %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)
	@rm -f 4-Getting_memory_address_to_mutate.o

all : $(NAME)
```
- here we use the mlx_get_data_addr function and save the return address value in to img.addr variable.
```
char *
mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
```
- mlx_get_data_addr() returns information about the created image, allowing a user to modify it later.
- The img_ptr parameter specifies the image to use.
- The three next parameters should be the addresses of three different valid integers.
- bits_per_pixel will be filled with the number of bits needed to represent a pixel color (also called the depth of the image).
- size_line is the number of bytes used to store one line of the image in memory. This information is needed to move from one line to another in the image.
- endian tells you wether the pixel color in the image needs to be stored in: little (endian == 0), or big (endian == 1).
- mlx_get_data_addr returns a char * address that represents the begining of the memory area where the image is stored.
- From this adress, the first bits_per_pixel bits represent the color of the first pixel in the first line of the image.
- The second group of bits_per_pixel bits represent the second pixel of the first line, and so on.
- Add size_line to the adress to get the begining of the second line. You can reach any pixels of the image that way.
- mlx_destroy_image destroys the given image (img_ptr).




