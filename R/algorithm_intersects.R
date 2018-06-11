#' bg_intersects
#'
#' Checks if geometries are spatially disjoint from each other
#'
#' @inheritParams bg_distance
#'
#' @note cartesian and spherical strategies supported
#' @examples
#'
#' bg_intersects(
#'   c("LINESTRING(0 0, 1 1)", "LINESTRING(1 1, 2 2)", "POINT(2 2)")
#' )
#'
#' bg_intersects(
#'   c("LINESTRING(0 0, 1 1)", "LINESTRING(1 1, 2 2)", "POINT(2 2)")
#'   , c("POINT(1 1)")
#' )
#'
#' @export
bg_intersects <- function(x, y = NULL, strategy = c('cartesian','spherical')) {

  if (is.null(y)) y <- x

  ## need to switch in R; variants not supported in c++
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_intersects_cartesian(x, y),
    "spherical"  =  rcpp_wkt_intersects_spherical(x, y)
  )
}
