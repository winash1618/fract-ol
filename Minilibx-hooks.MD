# Minilibx : hooks ([read more](https://harm-smits.github.io/42docs/libs/minilibx/hooks.html))
-  In computer programming, the term hooking covers a range of techniques used to alter or augment the behaviour of an operating system, 
of applications, or of other software components by intercepting function calls or messages or events passed between software components. 
Code that handles such intercepted function calls, events or messages is called a hook.

## Introduction
- Hooking is used for many purposes, including debugging and extending functionality. Examples might include intercepting keyboard or mouse 
event messages before they reach an application, or intercepting operating system calls in order to monitor behavior or modify the function 
of an application or another component. It is also widely used in benchmarking programs, for example to measure frame rate in 3D games, where 
the output and input is done through hooking.
- Simply put, it is therefore not weird that hooking is the backbone of MiniLibX.

## Hook functions
- Hooking into events is one of the most powerful tools that MiniLibX provides. It allows you to register to any of the aforementioned 
events with the call of a simple hook registration function.
### mlx_hook
  -  mlx_hook is the general function that can be used for all the hooking events in Minilibx.
  -  The below program has a key event function "check_key" which will be activated if you press ESC key.
  ```
  void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
  ```
  -  Here the parameter "int (*f)()" is a pointer to the function you want to be called when an event occurs. you can define your 
own key event funciton according to your needs.
  - The param  adress  will be passed to the function everytime it is called, and should be used to store the parameters it might need.
  - Here's an implementation for the mlx_hook program.
  ```
    #include <mlx.h>

    typedef struct	s_vars {
      void	*mlx;
      void	*win;
    }				t_vars;

    int	key_check(int keycode, t_vars *vars)
    {
      if (keycode == 53) // here 53 represent ESC key
        mlx_destroy_window(vars->mlx, vars->win);
      return (keycode);
    }

    int	main(void)
    {
      t_vars	vars;

      vars.mlx = mlx_init();
      vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
      mlx_hook(vars.win, 2, 1L<<0, key_check, &vars);
      mlx_loop(vars.mlx);
    }
  ```
### Hooking alias
  - Minilibx api has some alias hooking function
  - The difference between mlx-hook and alias is that they can be used for only specific purposes. For example mlx_key_hook is only used for key
up event (3). 
  - You can assign different functions to the three following events:
    - A key is pressed
    - The mouse button is pressed
    - A part of the window should be re-drawn (this is called an "expose" event, and it is your program's job to handle it).
  - mlx_expose_hook function is an alias of mlx_hook on expose event (12).
    ```
      int mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
    ```
  - mlx_key_hook function is an alias of mlx_hook on key up event (3).
    ```
      int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
    ```
  - mlx_mouse_hook function is an alias of mlx_hook on mouse down event (4).
    ```
      int mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
    ```
### Prototype of event functions
  -  When  it catches an event, the MiniLibX calls the corresponding function with fixed parameters:
    - ON_KEYDOWN :	2	: int (*f)(int keycode, void *param)
    - ON_KEYUP :	3	: int (*f)(int keycode, void *param)
    - ON_MOUSEDOWN : 4 :	int (*f)(int button, int x, int y, void *param)
    - ON_MOUSEUP : 5 : int (*f)(int button, int x, int y, void *param)
    - ON_MOUSEMOVE	: 6	: int (*f)(int x, int y, void *param)
    - ON_EXPOSE : 12 : int (*f)(void *param)
    - ON_DESTROY	: 17	: int (*f)(void *param)
  -  These function names are arbitrary. They here are used to distinguish parameters  according to the event. These functions are NOT part of the MiniLibX.
  - ( x , y ) are the coordinates of the  mouse click in the window, and button tells you which mouse button was pressed.

### Hooking into mouse events
  - Also, you can hook mouse events.
  ```
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
  ```
  - Mouse code for MacOS:
    - Left click: 1
    - Right click: 2
    - Middle click: 3
    - Scroll up: 4
    - Scroll down : 5
       
       <img width="279" alt="Screen Shot 2022-04-14 at 9 02 55 AM" src="https://user-images.githubusercontent.com/51042907/163317033-775504e1-5b8d-4718-a048-514f63de6d27.png">

## Examples
### A key is pressed, it will print the key code in the terminal
  ```
  #include "minilibx/mlx.h"
  #include <math.h>
  #include <stdio.h>
  #include "ft_putnbr_fd.c"
  typedef struct	s_vars {
    void	*mlx;
    void	*win;
  }	t_vars;

  typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
  }	t_data;

  int	key_check(int keycode, t_vars *vars)
  {
    printf("%d", keycode);
    fflush(stdout);
    if (keycode == 53)
      mlx_destroy_window(vars->mlx, vars->win);
    return (keycode);
  }

  void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
  {
    char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
  }

  int	main(void)
  {
    t_vars	new;
    t_data	img;

    new.mlx = mlx_init();
    new.win = mlx_new_window(new.mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(new.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(new.mlx, new.win, img.img, 0, 0);
    mlx_hook(new.win, 2, 0, key_check, &new);
    mlx_loop(new.mlx);
  }
```

### The mouse if moved, it will print the current position of that mouse in the terminal
```
  #include "minilibx/mlx.h"
  #include <math.h>
  #include <stdio.h>
  typedef struct	s_vars {
    void	*mlx;
    void	*win;
  }	t_vars;

  typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
  }	t_data;

  int	key_check(int keycode, t_vars *vars)
  {
    printf("%d", keycode);
    fflush(stdout);
    if (keycode == 53)
      mlx_destroy_window(vars->mlx, vars->win);
    return (keycode);
  }

  int	mouse_move(int x, int y, t_vars *vars)
  {
    printf("%d %d \n", x, y);
    fflush(stdout);
    (void)vars;
    return (0);
  }

  void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
  {
    char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
  }

  int	main(void)
  {
    t_vars	new;
    t_data	img;

    new.mlx = mlx_init();
    new.win = mlx_new_window(new.mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(new.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(new.mlx, new.win, img.img, 0, 0);
    mlx_hook(new.win, 2, 0, key_check, &new);
    mlx_hook(new.win, 6, 0, mouse_move, &new);
    mlx_loop(new.mlx);
  }
```

### A mouse is pressed, it will print the angle at which it moved over the window to the terminal
```
  
```
