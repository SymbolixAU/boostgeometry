#' BG Nearest
#'
#' Calculates the comparable distance measurement of multiple geometries and returns
#' the nearest
#'
#' @inheritParams bg_distance
#'
#' @return Numeric vector the same length of \code{x}, each element being the index
#' of \code{y} containing the nearest geometry
#'
#' @examples
#' bg_nearest(
#'   x = c("POINT(0 0)", "POINT(-2 -2)", "POINT(2 2)", "POINT(1 1)", "POINT(-1 1)", "POINT(-4 0)"),
#'   y = c("POINT(0 0)", "POINT(-2 -2)","POINT(1 1)")
#'   )
#'
#' bg_nearest(
#'   x = c("LINESTRING(-1 -1, 1 1)","POLYGON((-1 -1, 1 -1, 1 1, -1 1, -1 -1))"),
#'   y = c("LINESTRING(-1 -2, 1 -2)","LINESTRING(0 2, 2 0.5)")
#'  )
#'
#'
#' @export
bg_nearest <- function(x, y, strategy = c("cartesian", "spherical", "geographic")) {
  if (is.null(y)) y <- x
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_comparable_distance_cartesian(x, y),
    "spherical"  =  rcpp_wkt_comparable_distance_spherical(x, y),
    "geographic" =  rcpp_wkt_comparable_distance_geographic(x, y)
  )
}
