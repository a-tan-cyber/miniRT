# miniRT


# resources
- https://math.libretexts.org/Courses/University_of_California_Davis/UCD_Mat_21C%3A_Multivariate_Calculus/11%3A_Vectors_and_the_Geometry_of_Space/11.6%3A_Cylinders_and_Quadric_Surfaces
- https://www.42evalhub.com/common/minirt


# normalised vector input:

1. pick raw direction e.g. (2,5,1)
2. calc the length: 
$$L = \sqrt{2^2 + 5^2 + 1^2} = \sqrt{4 + 25 + 1} = \sqrt{30} \approx 5.477225$$
3. 
	- X: $2 \div 5.477225 = 0.365148$
	- Y: $5 \div 5.477225 = 0.912871$
	- Z: $1 \div 5.477225 = 0.182574$
4. The .rt File Entry: 0.365148,0.912871,0.182574

## cardinal directions:
0,1,0 ; 0,-1,0 etc

## 2d diagonal:

 $\frac{1}{\sqrt{2}} \approx 0.70710678$

 sample vector: 0.70710678,0.70710678,0.0

## 3d diagonal:
$\frac{1}{\sqrt{3}} \approx 0.57735026$

sample vector: 0.57735026,0.57735026,0.57735026

# notes
compiling with the -flto flag on performance oriented programs
-O3

bump map options: empty, sine, perlin.