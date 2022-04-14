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
- We are going to look at each part of Minilibx in details. Let's go
	- [Getting started](Minilibx-Getting_started.MD)
	- [More on colors](Minilibx-Colors.MD)
	- [Events](Minilibx-events.MD)
	- [Hooks](Minilibx-hooks.MD)
	- [Loops](Minilibx-Loops.MD)


