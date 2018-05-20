#' BG Perimeter
#'
#' Calculates the length of the perimeter of a geometry
#'
#' @param x
#' @param strategy
#'
#' @note
#'
#' points and linestrings return zero
#'
#' @examples
#'
#' polygon <- "POLYGON((0 0, 0 1, 1 1, 1 0, 0 0))"
#' bg_perimeter(polygon)
#' bg_perimeter(polygon, "spherical")
#' bg_perimeter(polygon, "geographic")
#'
#' bg_perimeter("POINT(1 1)")
#' bg_perimeter("LINESTRING(0 0, 0 1, 1 1, 1 0, 0 0)")
#'
#' bg_perimeter("MULTIPOLYGON(((0 0, 0 1, 1 1, 1 0, 0 0),(0.25 0.25, 0.25 0.75, 0.75 0.75, 0.75 0.25, 0.25 0.25)))")
#' bg_perimeter("MULTIPOLYGON(((0 0, 0 1, 1 1, 1 0, 0 0),(0.25 0.25, 0.25 0.75, 0.75 0.75, 0.75 0.25, 0.25 0.25)))", "geographic")
#'
#'
#' @export
bg_perimeter <- function(x, strategy = c("cartesian", "spherical", "geographic")) {
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_perimeter_cartesian(x),
    "spherical"  =  rcpp_wkt_perimeter_spherical(x),
    "geographic" =  rcpp_wkt_perimeter_geographic(x)
  )
}
