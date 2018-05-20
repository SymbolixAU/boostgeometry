#' BG Area
#'
#' Calculates the area of a geometry
#'
#' @param x well-known text representation of a geometry
#' @param strategy coordinate strategy
#'
#' @examples
#'
#' @export
bg_area <- function(x, strategy = c('cartesian','spherical','geographic')) {
  strategy <- match.arg(strategy)
  rcpp_wkt_area(x, strategy)
}
