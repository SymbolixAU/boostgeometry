#' BG Touches
#'
#' Checks if two geometries touch
#'
#' @inheritParams bg_area
#' @param y well-known text representation of a geometry
#'
#' @note
#' MULTIPOINT not supported
#'
#' @examples
#' x <- c("LINESTRING(0 0, 1 1)", "POLYGON((-1 0, -1 1, 1 1, 1 0, -1 0))")
#' y <- c("POINT(0 0)", "LINESTRING(1 1,2 2)", "MULTILINESTRING((2 2, 2 3),(0 0, -1 0))", "POINT(-2 -2)")
#' bg_touches(x, y)
#'
#' @export
bg_touches <- function(x, y, strategy = c("cartesian", "spherical", "geographic")) {

  strategy <- match.arg(strategy)
  switch(
    strategy
    , "cartesian"  = rcpp_wkt_touches_cartesian(x, y)
    , "spherical"  = rcpp_wkt_touches_spherical(x, y)
    , "geographic" = rcpp_wkt_touches_geographic(x, y)
  )
}
