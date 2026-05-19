*This project has been created as part of the 42 curriculum by amtan, yunguo.* 

[*42*](https://www.42network.org) *is a global tuition-free programming school network built around peer learning and project-based education. This project was completed at *[42 Singapore](https://www.42singapore.sg)*, the Singapore campus of the 42 Network.*

# miniRT

## Description

miniRT is a small ray tracer written in C.

The program reads a `.rt` scene file, parses the scene data, casts camera rays into the scene, finds the closest object intersections, computes lighting and shadows, and displays the rendered image in a MiniLibX/X11 window.

The mandatory part supports:

* Ambient light, camera, and light
* Spheres, planes, and cylinders
* Translation, rotation, and object resizing where applicable
* Ambient and diffuse lighting
* Hard shadows
* Clean error handling for invalid `.rt` files
* Clean exit with `ESC` or the window close button

The bonus part adds:

* Specular highlights
* Checkerboard pattern
* Colored and multiple lights
* Ellipsoid as an additional second-degree object
* Sine and Perlin-style bump mapping

## Instructions

This project is intended to run on Linux with X11.

Required packages include:

```sh
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

The repository includes shared copies of:

```text
libft/
minilibx-linux/
```

MiniLibX is used for window creation and image display.

### Build mandatory

```sh
make
```

or:

```sh
make all
```

This creates:

```text
./miniRT
```

Run with:

```sh
./miniRT tests/parser/valid_minimal.rt
```

### Build bonus

```sh
make bonus
```

This creates:

```text
./miniRT_bonus
```

Run with:

```sh
./miniRT_bonus tests/scenes_bonus_defense/08_all_bonus_combined.rt
```

### Clean

```sh
make clean
make fclean
make re
```

`make clean` removes object files.
`make fclean` removes object files and executables.
`make re` rebuilds the mandatory executable from scratch.

## Scene Format

A valid scene must contain:

```text
A   ambient light
C   camera
L   light
```

Basic example:

```rt
A 0.20 255,255,255
C 0,0,-60 0,0,1 70
L -30,30,-25 0.75 255,255,255
sp 0,0,0 20 180,180,255
```

Mandatory object identifiers:

```text
sp    sphere
pl    plane
cy    cylinder
```

Bonus object and optional tokens:

```text
el       ellipsoid
is_chkr  enable checkerboard
no_chkr  disable checkerboard
sine     sine bump map
perlin   Perlin-style bump map
empty    no bump map
```

Bonus examples:

```rt
sp 0,0,0 20 180,180,255 is_chkr sine
el 0,0,0 24,14,14 180,180,255 no_chkr perlin
```

## Useful Test Scenes

Mandatory:

```sh
./miniRT tests/evalsheet_mandatory/basic_sphere_origin.rt
./miniRT tests/evalsheet_mandatory/complex_shadows.rt
```

Bonus:

```sh
./miniRT_bonus tests/scenes_bonus_defense/01_specular_phong.rt
./miniRT_bonus tests/scenes_bonus_defense/02_checkerboard.rt
./miniRT_bonus tests/scenes_bonus_defense/03_colored_multi_lights.rt
./miniRT_bonus tests/scenes_bonus_defense/04_ellipsoid_quadric.rt
./miniRT_bonus tests/scenes_bonus_defense/05_sine_bump.rt
./miniRT_bonus tests/scenes_bonus_defense/06_perlin_bump.rt
./miniRT_bonus tests/scenes_bonus_defense/08_all_bonus_combined.rt
```

Invalid-scene examples:

```sh
./miniRT_bonus tests/scenes_bonus_defense/09_bad_missing_light.rt
./miniRT_bonus tests/scenes_bonus_defense/10_bad_ellipsoid_zero.rt
```

Invalid scenes should print `Error` with an explanatory message and exit without opening a render window.

## Resources

References used while working on this project:

* 42 miniRT subject
* [MiniLibX Linux source](https://github.com/42Paris/minilibx-linux)
* [Scratchapixel ray tracing lessons](https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/definition-ray.html)
* [Ray Tracing in One Weekend by Peter Shirley](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
* [The Ray Tracer Challenge by Jamis Buck](https://pragprog.com/titles/jbtracer/the-ray-tracer-challenge/)
* [Phong reflection model overview](https://en.wikipedia.org/wiki/Phong_reflection_model)
* [Perlin noise overview](https://en.wikipedia.org/wiki/Perlin_noise)
* [Bump mapping overview](https://en.wikipedia.org/wiki/Bump_mapping)
* [Xlib / X11 documentation](https://www.x.org/releases/current/doc/libX11/libX11/libX11.html)
* [42 Norm](https://github.com/42School/norminette)

MiniLibX Linux is a simple X11 programming API for 42 students and is built locally with `make` or `./configure`. Scratchapixel was used as a reference for the basic ray tracing pipeline: primary rays, object intersections, closest-hit selection, and shading concepts.

### AI Usage

AI assistance was used as a learning, testing, and review tool.

It was used for:

* Explaining ray tracing concepts
* Planning mandatory and bonus test scenes
* Drafting evalsheet-style test checklists
* Investigating parser, lighting, bump mapping, and bonus-object bugs
* Suggesting small patch ideas
* Assisting with Norm-focused refactoring after behavior was tested
* Drafting README text

All final code, compilation, rendering tests, parser tests, Valgrind checks, Norminette checks, and project decisions were manually verified by the authors.
