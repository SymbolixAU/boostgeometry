#' BG Simplify
#'
#' Simplifies a geometry
#'
#' @param x
#' @param distance
#' @param strategy
#'
#' @note
#'
#' Uses the Douglas-Peucker algorithm
#'
#' Supported geometries
#' - polygon
#'
#' @examples
#'
#' polygon <- "POLYGON((0 0, 0 0.2, 0.2 0.2, 0.2 0, 0.3 0, 0.3 0.2, 0.25, 0.5, 0.1 0.4, 0 0.2, 0 0))"
#' bg_simplify(polygon, distance = 0.2)
#'
#'
#' @export
bg_simplify <- function(x, distance = 0.5, strategy = c("cartesian", "spherical")) {
  strategy <- match.arg(strategy)
  switch(
    strategy
    , "cartesian"  = rcpp_wkt_simplify_cartesian(x, distance)
    , "spherical"  = rcpp_wkt_simplify_spherical(x, distance)
    #, "geographic" = rcpp_wkt_simplify_geographic(x, distance)
  )
}
