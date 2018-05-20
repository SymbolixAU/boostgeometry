#' BG Area
#'
#' Calculates the area of a geometry
#'
#' @param x
#' @param strategy
#'
#' @examples
#'
#' @export
bg_area <- function(x, strategy = c('cartesian','spherical','geographic')) {
  strategy <- match.arg(strategy)
  rcpp_wkt_area(x, strategy)
}
