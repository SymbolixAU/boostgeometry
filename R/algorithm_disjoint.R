#' bg_disjoint
#'
#' Checks if geometries are spatially disjoint from each other
#'
#' @inheritParams bg_distance
#'
#' @note geographic multipoints are not supported
#' @examples
#'
#' bg_disjoint(
#'   c("LINESTRING(0 0, 1 1)", "LINESTRING(1 1, 2 2)", "POINT(2 2)")
#' )
#'
#' bg_disjoint(
#'   c("LINESTRING(0 0, 1 1)", "LINESTRING(1 1, 2 2)", "POINT(2 2)")
#'   , c("POINT(1 1)")
#' )
#'
#' @export
bg_disjoint <- function(x, y = NULL, strategy = c('cartesian','spherical','geographic')) {

  if (is.null(y)) y <- x

  ## need to switch in R; variants not supported in c++
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_disjoint_cartesian(x, y),
    "spherical"  =  rcpp_wkt_disjoint_spherical(x, y),
    "geographic" =  rcpp_wkt_disjoint_geographic(x, y)
  )
}
