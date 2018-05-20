#' BG Clear
#'
#' Removes all points from a geometry. Points remain unchanged
#'
#' @inheritParams bg_area
#'
#' @examples
#' bg_clear("POLYGON((0 0,0 1,1 1,1 0,0 0))")
#' bg_clear("LINESTRING(0 0,1 1)")
#' bg_clear("MULTIPOINT(0 0,1 1)")
#'
#' ## points remain unchanged
#' bg_clear("POINT(0 0)")
#'
#'
#' @export
bg_clear <- function(x) rcpp_wkt_clear(x)
