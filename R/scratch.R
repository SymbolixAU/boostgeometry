
# library(googlePolylines)
#
# line <- "LINESTRING(0 0,4 5,7 4,10 6)"
# buff <- bg_buffer(line, distance = 0.1)
#
# sf_buff <- sf:::CPL_sfc_from_wkt(buff)
# attr(sf_buff, 'bbox') <- c(xmin = 0, ymin = 0, xmax = 0, ymax = 0)
# attr(sf_buff, 'precision') <- 0
# sf_buff <- sf::st_sf(geometry = sf_buff)
#
# sf_line <- sf:::CPL_sfc_from_wkt(line)
# attr(sf_line, 'bbox') <- c(xmin = 0, ymin = 0, xmax = 0, ymax = 0)
# attr(sf_line, 'precision') <- 0
# sf_line <- sf::st_sf(geometry = sf_line)
#
# plot(sf_line)
# plot(sf_buff)
#
#
# library(googleway)
#
# set_key(read.dcf("~/Documents/.googleAPI", fields = "GOOGLE_MAP_KEY"))
#
# google_map() %>%
#   add_polylines(sf_line) %>%
#   add_polygons(sf_buff)
