#
#
# library(sf)
# nc <- st_read(system.file("shape/nc.shp", package="sf"))
#
# library(googlePolylines)
# library(boostgeometry)
#
# enc <- encode(nc)
# wkt <- polyline_wkt(encode(nc))
# sfwkt <- sf::st_as_text(nc$geometry)
#
# bg_area(wkt$geometry, strategy = "geographic")
# sf::st_area(nc)
# bg_area(sfwkt, strategy = "geographic")
#
#
# bg_area(wkt[100, 'geometry'], strategy = "geographic")
# bg_area(bg_reverse(wkt[100, 'geometry']), strategy = "geographic")
# # bg_area(bg_correct(wkt[100, 'geometry']), strategy = "geographic")
#
# bg_area(sfwkt[100], strategy = "geographic")
# bg_area(bg_reverse(sfwkt[100]), strategy = "geographic")
# sf::st_area(nc[100,])
#
# sfwkt[100]
# wkt[100, 'geometry']
#
# plot(nc[100,])
#
# sfwkt[100]
# wkt[100, 'geometry']
#
# bg_number_points(wkt[100, 'geometry'])
# bg_number_points(sfwkt[100])
#
#
# df_100 <- data.frame(matrix(unlist(nc[100, 'geometry'][[1]]), ncol = 2))
# df_100$row <- 1:nrow(df_100)
#
# df_98 <- data.frame(matrix(unlist(nc[98, 'geometry'][[1]]), ncol = 2))
# df_98$row <- 1:nrow(df_98)
# df_98$colour <- "blue"
#
# library(googleway)
# set_key(read.dcf("~/Documents/.googleAPI", fields = "GOOGLE_MAP_KEY"))
#
# google_map() %>%
#   add_markers(
#     data = df_100
#     , lat = "X2"
#     , lon = "X1"
#     , info_window = "row"
#     , close_info_window = T
#     ) %>%
#   add_markers(
#     data = df_98
#     , lat = "X2"
#     , lon = "X1"
#     , info_window = "row"
#     , colour = "colour"
#     , close_info_window = T
#   ) %>%
#   add_polygons(
#     nc[c(98,100), ]
#   )
#
# sfwkt[100]


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
