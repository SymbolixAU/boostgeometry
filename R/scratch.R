
# library(sf)
# library(googlePolylines)
# nc <- sf::st_read(system.file("shape/nc.shp", package="sf"))
# nce <- encode(nc)
# wnce <- polyline_wkt(nce)
#
# boostgeometry:::wkt_centroid(wnce$geometry)

# boostgeometry::bg_area(wnce$geometry)
# boostgeometry::bg_centroid(wnce$geometry)
#
# sf::st_area(nc)

## Benchmarking
## Assumes the input data is in the correct format alread:
## - bost :: wkt
## - sf :: st_geometry
##
# nc <- sf::st_read(system.file("shape/nc.shp", package="sf"))
# nce <- encode(nc)
# wnce <- polyline_wkt(nce)
#
# library(microbenchmark)
#
# microbenchmark(
#   boost = {
#     bg_area(wnce$geometry, "geographic")
#   },
#   sf = {
#     sf::st_area(nc)
#   }
# )
# # Unit: milliseconds
# #  expr       min        lq      mean    median        uq      max neval
# # boost  6.637465  6.801843  7.655177  7.241235  8.087696 15.79231   100
# #    sf 10.929847 11.742310 13.545155 12.649218 14.515820 24.43847   100

