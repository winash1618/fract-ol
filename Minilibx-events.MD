# Minilibx : Events [read more](https://harm-smits.github.io/42docs/libs/minilibx/events.html)
## Introduction
  - Events are the foundation of writing interactive applications in MiniLibX. It is therefore of essence that you fully comprehend this chapter
  as this will be of use in your future graphical projects.
  - All hooks in MiniLibX are nothing more than a function that gets called whenever a event is triggered. Mastering all these events won’t be
  neccessary, however, we will quickly go over each X11 event accordingly.
## MacOS version
  - On MacOS - Cocoa (AppKit) and OpenGL - version, minilibx has partial support of X11 events and doesn’t support X11 mask (x_mask argument of 
  mlx_hook is useless, keep it at 0).
## Supported events:
```
  enum {
    ON_KEYDOWN = 2,
    ON_KEYUP = 3,
    ON_MOUSEDOWN = 4,
    ON_MOUSEUP = 5,
    ON_MOUSEMOVE = 6,
    ON_EXPOSE = 12,
    ON_DESTROY = 17
  };

  // usage:
  mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
```
- If you can’t figure out what some events are, don’t worry, because you probably won’t need them. If you do, 
[go read the documentation of each X11 events](https://tronche.com/gui/x/xlib/events/).
