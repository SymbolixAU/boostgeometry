
[![Travis build
status](https://travis-ci.org/SymbolixAU/boostgeometry.svg?branch=master)](https://travis-ci.org/SymbolixAU/boostgeometry)
[![Coverage
status](https://codecov.io/gh/SymbolixAU/boostgeometry/branch/master/graph/badge.svg)](https://codecov.io/github/SymbolixAU/boostgeometry?branch=master)

**This is / was an experimental package and is no longer actively developped or maintained**

<!-- git clone https://github.com/boostorg/geometry --branch boost-1.67.0 --depth 1 -->

<!-- README.md is generated from README.Rmd. Please edit that file -->

# boostgeometry

R package wrapping v1.67.0 of boost::geometry

## Installation

Install the development version from
[GitHub](https://github.com/SymbolixAU/boostgeometry) with:

``` r
# install.packages("devtools")
devtools::install_github("SymbolixAU/boostgeometry")
```

## Examples

### Area

``` r
library(boostgeometry)
bg_area("POLYGON((0 0,0 1,1 1,1 0,0 0))")
#> [1] 1
bg_area("POLYGON((0 0,0 1,1 1,1 0,0 0))", strategy = "spherical")
#> [1] 0.0003046097
bg_area("POLYGON((0 0,0 1,1 1,1 0,0 0))", strategy = "geographic")
#> [1] 12308777799
```

### Centroid

``` r
wkt <- paste0("POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,",
              "5.4 1.2,4.9 0.8,2.9 0.7,2 1.3),(4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))")
bg_centroid(wkt)
#> [1] "POINT(4.04663 1.6349)"
```

### Clear

``` r
bg_clear("POLYGON((0 0,0 1,1 1,1 0,0 0))")
#> [1] "POLYGON(())"
bg_clear("LINESTRING(0 0,1 1)")
#> [1] "LINESTRING()"
bg_clear("MULTIPOINT(0 0,1 1)")
#> [1] "MULTIPOINT()"
## points remain unchanged
bg_clear("POINT(0 0)")
#> [1] "POINT(0 0)"
```

### Convex Hull

``` r
polygon <- paste0("POLYGON((2.0 1.3, 2.4 1.7, 2.8 1.8, 3.4 1.2, 3.7 1.6,3.4 2.0,",
                  " 4.1 3.0, 5.3 2.6, 5.4 1.2, 4.9 0.8, 2.9 0.7,2.0 1.3))")
bg_convex_hull(polygon)
#> [1] "POLYGON((2 1.3,2.4 1.7,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3))"
```

### Correct

``` r
bg_correct("POLYGON((0 0, 0 1, 1 1, 1 0))")
#> [1] "POLYGON((0 0,0 1,1 1,1 0,0 0))"
bg_correct("POLYGON((0 0, 0 1, 1 1, 1 0),(0.25 0.25, 0.25 0.75, 0.75 0.75, 0.75 0.25))")
#> [1] "POLYGON((0 0,0 1,1 1,1 0,0 0),(0.25 0.25,0.75 0.25,0.75 0.75,0.25 0.75,0.25 0.25))"
```

### Crosses

``` r
x <- "LINESTRING(-1 -1, 0 0, 1 1)"
y <- c("LINESTRING(1 -1, 0 0, -1 1)", "LINESTRING(0 0, 1 1)", "LINESTRING(-1 1, 0 0, 1 -1)")
bg_crosses(x, y)
#>      [,1]  [,2] [,3]
#> [1,] TRUE FALSE TRUE
```

### Densify

``` r
bg_densify("POLYGON((0 0,0 10,10 10,10 0,0 0),(1 1,4 1,4 4,1 4,1 1))", distance = 6)
#> [1] "POLYGON((0 0,0 5,0 10,5 10,10 10,10 5,10 0,5 0,0 0),(1 1,4 1,4 4,1 4,1 1))"
bg_densify("POLYGON((0 0,0 10,10 10,10 0,0 0),(1 1,4 1,4 4,1 4,1 1))", strategy = "spherical", distance = 0.06)
#> [1] "POLYGON((0 0,0 3.33334,0 6.66667,0 10,3.33323 10.0333,6.6668 10.0333,10 10,10 6.66666,10 3.33332,10 0,6.66666 0,3.33333 0,0 0),(1 1,4 1,4 4,1 4,1 1))"
bg_densify("POLYGON((0 0,0 10,10 10,10 0,0 0),(1 1,4 1,4 4,1 4,1 1))", strategy = "geographic", distance = 60000)
#> [1] "POLYGON((0 0,2.58027e-10 0.526362,5.16097e-10 1.05273,7.74254e-10 1.57909,1.03254e-09 2.10545,1.291e-09 2.63179,1.54968e-09 3.15815,1.80862e-09 3.6845,2.06786e-09 4.21083,2.32745e-09 4.73716,2.58743e-09 5.26349,2.84785e-09 5.7898,3.10876e-09 6.3161,3.37019e-09 6.84241,3.63219e-09 7.36869,3.89482e-09 7.89496,4.1581e-09 8.42122,4.4221e-09 8.94746,4.68687e-09 9.47369,0 10,0.526248 10.0075,1.05252 10.0142,1.57881 10.02,2.10512 10.025,2.63144 10.0292,3.15778 10.0326,3.68412 10.0351,4.21048 10.0367,4.73683 10.0376,5.26319 10.0376,5.78955 10.0367,6.3159 10.0351,6.84224 10.0326,7.36858 10.0292,7.89491 10.025,8.42121 10.02,8.94751 10.0142,9.47377 10.0075,10 10,10 6.04223,10 5.71164,10 5.38018,10 5.04791,10 4.71487,10 4.38112,10 4.0467,10 3.71166,10 3.37606,10 3.03994,10 2.70335,10 2.36635,10 2.02898,10 1.69131,10 1.35337,10 1.01523,10 0.676926,10 0.338521,10 0,9.47368 -2.31607e-08,8.94737 -4.63195e-08,8.42105 -6.94743e-08,7.89473 -9.26233e-08,7.36842 -1.15764e-07,6.8421 -1.38896e-07,6.31579 -1.62015e-07,5.78947 -1.85121e-07,5.26315 -2.08211e-07,4.73684 -2.31283e-07,4.21052 -2.54335e-07,3.68421 -2.77366e-07,3.15789 -3.00374e-07,2.63157 -3.23356e-07,2.10526 -3.4631e-07,1.57894 -3.69235e-07,1.05262 -3.92129e-07,0.526308 -4.14989e-07,0 0),(1 1,1.5 1.00019,2.00001 1.00031,2.50001 1.00034,3.00002 1.00031,3.50002 1.00019,4 1,4 1.49999,4 1.99999,4 2.49998,4 2.99997,4 3.49995,4 4,3.50001 4.00076,3.00002 4.00122,2.50002 4.00138,2.00003 4.00122,1.50004 4.00076,1 4,1 2.21955,1 1.90305,1 1.58628,1 1.2693,1 0.952137,1 1))"
```

### Distance

``` r
points <- c("POINT(0 0)", "POINT(2 0)", "POINT(2 2)")
bg_distance(points)
#>          [,1] [,2]     [,3]
#> [1,] 0.000000    2 2.828427
#> [2,] 2.000000    0 2.000000
#> [3,] 2.828427    2 0.000000
bg_distance(points, points)
#>          [,1] [,2]     [,3]
#> [1,] 0.000000    2 2.828427
#> [2,] 2.000000    0 2.000000
#> [3,] 2.828427    2 0.000000

lines <- c("LINESTRING(1 1, 1 0, 1 -1)")
bg_distance(points, lines)
#>          [,1]
#> [1,] 1.000000
#> [2,] 1.000000
#> [3,] 1.414214
bg_distance(points, lines, "geographic")
#>          [,1]
#> [1,] 111314.0
#> [2,] 111314.0
#> [3,] 156850.3
```

### Envelope (bounding box)

``` r
polygon <- paste0("POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3",
                  " 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3), (4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))")
bg_envelope(polygon)
#> [1] "POLYGON((2 0.7,2 3,5.4 3,5.4 0.7,2 0.7))"

bg_envelope("LINESTRING(144 -37, 145 -36)", "geographic")
#> [1] "POLYGON((144 -37,144 -36,145 -36,145 -37,144 -37))"
```

### Is empty / simple / valid

``` r
bg_is_empty("MULTILINESTRING((0 0,0 10,10 0),(1 1,8 1,1 8))")
#> [1] 0
bg_is_simple("MULTILINESTRING((0 0,0 10,10 10,10 0,0 0),(10 10,20 20))")
#> [1] 0
bg_is_simple("LINESTRING(0 0,0 10,10 10,10 0,0 0)")
#> [1] 1
bg_is_valid("POLYGON((0 0,0 10,10 10,10 0,0 0),(0 0,9 1,9 2,0 0),(0 0,2 9,1 9,0 0),(2 9,9 2,9 9,2 9))")
#> [1] 0
bg_is_valid("POLYGON((0 0,0 10,10 10,10 0,0 0))")
#> [1] 1
```

### Length

``` r
bg_length("LINESTRING(0 0,1 1,4 8,3 2)")
#> [1] 15.11275
bg_length("LINESTRING(0 0,1 1,4 8,3 2)", "geographic")
#> [1] 1672139
```

### Number geometries / rings / points / segments

``` r
bg_number_geometries("LINESTRING(0 0, 0 1, 1 1, 1 0, 0 0)")
#> [1] 1
bg_number_geometries("MULTIPOLYGON(((0 0,0 10,10 0,0 0),(1 1,1 9,9 1,1 1)),((10 10,10 7,7 10,10 10)))")
#> [1] 2
bg_number_interior_rings("POLYGON((0 0,0 10,10 0,0 0),(1 1,1 2,2 1,1 1),(3 3,3 4,4 3,3 3))")
#> [1] 2
bg_number_points("MULTIPOLYGON(((0 0,0 10,10 0,0 0),(1 1,1 9,9 1,1 1)),((10 10,10 7,7 10,10 10)))")
#> [1] 12
bg_number_segments("MULTIPOLYGON(((0 0,0 10,10 0),(1 1,8 1,1 8)),((10 10,10 20,20 10)))")
#> [1] 6
```

### Perimeter

``` r
polygon <- "POLYGON((0 0, 0 1, 1 1, 1 0, 0 0))"
bg_perimeter(polygon)
#> [1] 4
bg_perimeter(polygon, "spherical")
#> [1] 0.06981051
bg_perimeter(polygon, "geographic")
#> [1] 443752.7
```

### Reverse

``` r
bg_reverse("POLYGON((0 0,0 1,1 1,1 0,0 0))")
#> [1] "POLYGON((0 0,1 0,1 1,0 1,0 0))"
```

### Simplify

``` r
polygon <- "POLYGON((0 0, 0 0.2, 0.2 0.2, 0.2 0, 0.3 0, 0.3 0.2, 0.25, 0.5, 0.1 0.4, 0 0.2, 0 0))"
bg_simplify(polygon, distance = 0.2)
#> [1] "POLYGON((0.5 0,0.1 0.4,0 0,0 0.2,0.5 0))"
```

### Unique

``` r
bg_unique("LINESTRING(0 0,0 0,1 1,1 1,2 2)")
#> [1] "LINESTRING(0 0,1 1,2 2)"
bg_unique("POLYGON((0 0,0 0,0 5,5 5,5 5,5 5,5 0,5 0,0 0,0 0,0 0,0 0))")
#> [1] "POLYGON((0 0,0 5,5 5,5 0,0 0))"
```

### Within

``` r
x <- c("POINT(0 0)", "LINESTRING(1 1,1 2)")
y <- c("POLYGON((-1 -1, -1 1, 1 1, 1 -1, -1 -1))", "LINESTRING(0 0, 1 1, 1 2, 2 2)",
 "POLYGON((-2 -2, -2 2, 2 2, 2 -2, -2 -2))")
bg_within(x, y)
#>       [,1]  [,2] [,3]
#> [1,]  TRUE FALSE TRUE
#> [2,] FALSE  TRUE TRUE
```
