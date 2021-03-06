
## how to deal with operations which fail to compile?
## can I switch on the 'type'?
## store in a 'geometries' map?
## - and if it's one that isn't valid, store an empty valid one/ default one?


# wktOne <- c("POINT(0 0)", "LINESTRING(-3 -3, 1 1)", "POLYGON((-1 -1, 1 -1, 1 1, -1 1, -1 -1))")
# wktTwo <- c("MULTIPOINT(-3 -3)", "MULTIPOLYGON(((-2 -2, 0 -2, 0 0, -2 0, -2 -2)))")
#
# boostgeometry:::rcpp_crosses_predicate_cartesian(wktOne, wktTwo)

# boostgeometry:::rcpp_bg_join_predicate_cartesian(wktOne, wktTwo, "intersects")

# wktTwo <- "BOX(-3 -3, 1 1)"
# boostgeometry:::rcpp_within_predicate_cartesian(wktOne, wktTwo)
## this is testing for wktOne is within wktTwo


# pt <- sf::st_sfc(sf::st_point(c(0, 0)))
# poly <- sf::st_sfc(sf::st_polygon(x = list(matrix(c(-1,-1,1,-1,1,1,-1,1,-1,-1), ncol = 2, byrow = T))))
#
# sf::st_within(pt, poly)
# sf::st_within(poly, pt)


## using a wkt object?
## or an wkt column?
# library(googlePolylines)
#
# wkt <- polyline_wkt(encode(nc))
#
# attr(wkt, 'wkt_column')
#
# str(wkt$geometry)

## in each function the x and y can be character vectors, or wkt objects, or wkt_column

## expanding data by list values
# lst <- list(c(1,2,3), c(3,4))
#
# df <- data.frame(id = 1:2, val = c("a","b"))
#
# df[c(1,1),]
#
# lapply(lst, function(x) {  })
#
# lst

# idx <- cbind(rep(1:length(lst), sapply(lst, length)), unlist(lst))
# cbind(nc[idx[,1], ],  nc[idx[,2],])

## INDEX

# geoms <- c(
#   "LINESTRING(0 0, 1 1, 2 2)"
#   , "POINT(0 0)"
#   , "POLYGON((-1 -1, 1 -1, 1 1, -1 1, -1 -1))"
#   , "POINT(4 4)"
# )

# boostgeometry:::rtreetest( geoms )


# geoms2 <- c(
#   "POINT(2 2)"
#   , "POINT(0 0)"
# )
#
# boostgeometry:::rtreetest3( geoms, geoms2 )


# ## Benchmarking
# library(microbenchmark)
# library(googlePolylines)
# library(sf)
# nc <- st_read(system.file("shape/nc.shp", package="sf"))
# wkt <- sf::st_as_text(nc$geometry)
#
# wkt <- polyline_wkt(encode(nc))
# microbenchmark(
#   bg_idx = {
#     lst <- bg_join(wkt, wkt)
#   },
#   # bg = {
#   #   bg_intersects(wkt$geometry, wkt$geometry)
#   # },
#   sf = {
#     sf_res <- sf::st_join(nc, nc)
#   },
#   times = 5
# )
#
# Unit: milliseconds
#   expr       min        lq      mean    median        uq       max neval
# bg_idx  47.28265  48.85397  49.05106  49.42246  49.78631  49.90989     5
#     bg 403.55095 404.08965 412.19424 405.47150 421.60882 426.25028     5
#     sf  12.83821  12.89330  13.43513  13.54708  13.73450  14.16259     5


# microbenchmark(
#   bg = {
#     bg_disjoint(x = wkt)
#   },
#   sf = {
#     sf::st_disjoint(nc)
#   },
#   times = 3
# )
#
# Unit: milliseconds
# expr        min         lq      mean     median        uq       max neval
# bg 432.578161 433.916356 437.41059 435.254551 439.82681 444.39906     3
# sf   9.168647   9.376831  10.26191   9.585014  10.80853  12.03205     3

## TODO(distance)
## - re-write the distnace .cpp to just read and compare MULTIPOLYGONS (the `nc` obj)
## - to see if it speeds up
## - if it's quicker, then my 'read_wkt' variant stuff may be slow

#
# bg_touches(wkt, wkt)
#
# pred <- sf::st_touches(nc)

# microbenchmark(
#   bg = {
#     d <- bg_distance(wkt, strategy = "geographic")
#   },
#   bg_test = {
#     d <- boostgeometry:::rcpp_distance_test(wkt, wkt)
#   },
#   sf = {
#     d <- sf::st_distance(nc)
#   },
#   times = 3
# )

# Unit: seconds
# expr      min       lq      mean    median        uq       max neval
#   bg 13.99757 14.15848 14.319665 14.319391 14.480715 14.642039     3
#   sf  8.04796  8.16323  8.254405  8.278499  8.357628  8.436756     3

# microbenchmark(
#   sf = {
#     sf::st_buffer(nc, dist = 0.0025)
#   },
#   bg = {
#     bg_buffer(wkt, distance = 0.0025)
#   }
# )


# microbenchmark(
#   sf = {
#     sf::st_area(nc$geometry)
#   },
#   bg = {
#     bg_area(wkt)
#   }
# )
# Unit: milliseconds
# expr       min        lq      mean    median        uq       max neval
# sf   12.335568 15.184881 18.774818 17.142446 19.742249 103.63335   100
# bg    5.307456  5.821789  7.391984  6.822984  8.333742  13.99982   100

# microbenchmark(
#   sf = {
#     sf::st_centroid(nc$geometry)
#   },
#   bg = {
#     bg_centroid(wkt)
#   }
# )
# Unit: milliseconds
# expr      min       lq     mean   median       uq      max neval
#   sf 4.744055 5.387979 7.001568 6.398643 8.094730 14.25318   100
#   bg 5.663525 6.345227 8.004384 7.380280 8.894669 17.30937   100

# microbenchmark(
#   sf = {
#     sf::st_convex_hull(nc$geometry)
#   },
#   bg = {
#     bg_convex_hull(wkt)
#   }
# )
# Unit: milliseconds
# expr       min        lq      mean    median        uq       max neval
#   sf  4.818773  5.538763  6.820961  5.971989  7.688148  24.95045   100
#   bg 75.340870 83.598393 92.156792 89.384417 94.490072 158.18313   100


