#' BG Equals
#'
#' Checks if geometries are spatially equal
#'
#' @inheritParams bg_area
#' @param y well-known text representation of a geometry
#'
#' @examples
#'
#' bg_equals(x = "POINT(0 0)", y = "POINT(0 0)")
#' bg_equals(x = "LINESTRING(0 0,1 1,2 2)", y = "LINESTRING(0 0,1 1,2 2)")
#' bg_equals(
#'   x = c("POLYGON((0 0,0 1,1 1,1 0,0 0))", "MULTILINESTRING((0 0,2 2))")
#'   , y = c("POINT(1 1)", "LINESTRING(0 0,2 2)", "MULTIPOLYGON(((0 0,0 1,1 1,1 0,0 0)))")
#'   )
#'
#' @return Logical matrix returning \code{TRUE} if \code{x} equals \code{y}
#'
#' @export
bg_equals <- function(x, y) rcpp_wkt_equals_cartesian(x, y)
