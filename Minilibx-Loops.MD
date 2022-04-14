# Minilibx : Loops([read more](https://harm-smits.github.io/42docs/libs/minilibx/loops.html))
## Introduction
  - Now that you finally understand the basics of the MiniLibX library, we will start with drawing a tiny animation in the window. 
  For this we will be using two new functions, namely mlx_loop and mlx_loop_hook.
  - Loops are a feature of MiniLibX where it will continue to call your hook registered in mlx_loop_hook to render new frames, which you obviously
  have to pass to the window yourself.
```
  int
  mlx_loop ( void *mlx_ptr );

  int
  mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
```
  - To receive events, you must use mlx_loop (). This function never returns. It is an infinite loop  that  waits for an event, and then calls 
a user-defined function associated with this event.  A single parameter is needed, the connection identifier mlx_ptr (see the  mlx  manual).
  - The syntax for the mlx_loop_hook () function is identical to the  previous  ones,  but  the given function will be called when no event occurs.
## Hooking into loops
  - To initiate a loop, we call the mlx_loop function with the mlx instance as only parameter, take a look:
    ```
      #include <mlx.h>

      int	main(void)
      {
        void	*mlx;

        mlx = mlx_init();
        mlx_loop(mlx);
      }
    ```
  - This will do nothing of course as we have no loop hook registered, therefore we will not be able to write anything to our frame.
  - To do this, you will have to create a new window and use the mutations that we described in the Getting Started chapter. 
  - We assume that your knowledge of that is proficient and that you will be able to pass your parameters accordingly. 
  - An example whiteboarded version of it could look as follows:
    ```
      #include <mlx.h>

      int	render_next_frame(void *YourStruct);

      int	main(void)
      {
        void	*mlx;

        mlx = mlx_init();
        mlx_loop_hook(mlx, render_next_frame, YourStruct);
        mlx_loop(mlx);
      }
    ```
  - Now for each frame it requires, it will call the function render_next_frame with the parameter YourStruct. This will persist through
multiple calls if it is a pointer, so use that to your advantage!

## Examples
### Render a moving rainbow that shifts through all colors (screen turns red, becomes green and then becomes blue, then starts all over again).
```

```
