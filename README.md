
[![Travis build
status](https://travis-ci.org/SymbolixAU/boostgeometry.svg?branch=master)](https://travis-ci.org/SymbolixAU/boostgeometry)
[![Coverage
status](https://codecov.io/gh/SymbolixAU/boostgeometry/branch/master/graph/badge.svg)](https://codecov.io/github/SymbolixAU/boostgeometry?branch=master)

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

## Example

``` r
library(boostgeometry)
bg_area("POLYGON((0 0,0 1,1 1,1 0,0 0))")
#> [1] 1
bg_area("POLYGON((0 0,0 1,1 1,1 0,0 0))", strategy = "spherical")
#> [1] 0.0003046097
bg_area("POLYGON((0 0,0 1,1 1,1 0,0 0))", strategy = "geographic")
#> [1] 12308777799
```
