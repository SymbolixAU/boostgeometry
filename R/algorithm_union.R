# BG Union
#
# @param x
#
# @examples
# poly1 <- "POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3),(4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))"
# poly2 <- "POLYGON((4.0 -0.5 , 3.5 1.0 , 2.0 1.5 , 3.5 2.0 , 4.0 3.5 , 4.5 2.0 , 6.0 1.5 , 4.5 1.0 , 4.0 -0.5))"
# bg_union(c(poly1, poly2))
#
# @export
# bg_union <- function(x) rcpp_wkt_union(x)
#
# mp <-  "MULTIPOLYGON(((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3),(4 2,4.2 1.4,4.8 1.9,4.4 2.2,4 2)),((2.15 1.45,2 1.5,2.3 1.6,2.4 1.7,2.8 1.8,2.825 1.775,3.42 1.97333,3.4 2,3.59091 2.27273,4 3.5,4.175 2.975,5.3 2.6,5.36341 1.7122,6 1.5,5.39302 1.29767,5.4 1.2,4.9 0.8,4.42542 0.776271,4 -0.5,3.58852 0.734426,2.9 0.7,2 1.3,2.15 1.45),(4.8 1.9,4.44444 2.16667,4.5 2,4.8 1.9)))"
#
# df <- data.frame(wkt = c(poly1, poly2, mp), stringsAsFactors = F)
#
# attr(df, "class") <- c("sfencoded", "data.frame")
# attr(df, "wkt_column") <- "wkt"
# attr(df$wkt, "class") <- "wkt_column"
# df
#
# wkt <- googlePolylines::wkt_polyline(df)
#
#
# library(googlePolylines)
# library(sf)
# library(googleway)
#
# set_key(read.dcf("~/Documents/.googleAPI", fields = "GOOGLE_MAP_KEY"))
#
# google_map() %>%
#   add_polygons(data = df)
#
# poly1 <- rgeos::readWKT(df$wkt[1])
# poly2 <- rgeos::readWKT(df$wkt[2])
# mp <- rgeos::readWKT(df$wkt[3])
#
# poly1 <- sf::st_as_sf(poly1)
# poly2 <- sf::st_as_sf(poly2)
# mp <- sf::st_as_sf(mp)
#
# plot(poly1)
# plot(poly2)
# plot(mp)
#
# # library(wellknown)
# # wellknown::wkt2geojson(df$wkt[1])
#
#
# nc <- sf::st_read(system.file("shape/nc.shp", package="sf"))
# enc <- encode(nc)
# wkt <- polyline_wkt(enc)
# enc2 <- wkt_polyline(wkt)




