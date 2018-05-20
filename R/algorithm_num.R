#' BG Number Geometries
#'
#' Calculates the number of geometries of a multi-geometry
#'
#' @param x
#'
#' @examples
#' bg_number_geometries("LINESTRING(0 0, 0 1, 1 1, 1 0, 0 0)")
#' bg_number_geometries("MULTIPOLYGON(((0 0,0 10,10 0,0 0),(1 1,1 9,9 1,1 1)),((10 10,10 7,7 10,10 10)))")
#'
#'
#' @export
bg_number_geometries <- function(x) rcpp_wkt_num_geometries(x)


#' BG Number Interior Rings
#'
#' Calculates the number of interior rings of a geometry
#'
#' @param x
#'
#' @examples
#' bg_number_interior_rings("POLYGON((0 0,0 10,10 0,0 0),(1 1,1 2,2 1,1 1),(3 3,3 4,4 3,3 3))")
#'
#' @export
bg_number_interior_rings <- function(x) rcpp_wkt_num_interior_rings(x)

#' BG Number Points
#'
#' Calculates the number of points of a geometry
#'
#' @param x
#'
#' @examples
#' bg_number_points("MULTIPOLYGON(((0 0,0 10,10 0,0 0),(1 1,1 9,9 1,1 1)),((10 10,10 7,7 10,10 10)))")
#'
#' @export
bg_number_points <- function(x) rcpp_wkt_num_points(x)


#' BG Number Segments
#'
#' Calculates the number of segments of a geometry
#'
#' @param x
#'
#' @examples
#' bg_number_segments("MULTIPOLYGON(((0 0,0 10,10 0),(1 1,8 1,1 8)),((10 10,10 20,20 10)))")
#'
#' @export
bg_number_segments <- function(x) rcpp_wkt_num_segments(x)
