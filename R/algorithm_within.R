#' BG Within
#'
#' Checks if the first geometry (\code{x}) is completely inside the second (\code{y}) geometry
#'
#' @param x
#' @param y
#' @param strategy
#'
#' @examples
#' point <- "POINT(4 1)"
#' poly <- "POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3), (4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))"
#' bg_within(point, poly, "cartesian")
#'
#' x <- c("POINT(0 0)", "LINESTRING(1 1,1 2)")
#' y <- c("POLYGON((-1 -1, -1 1, 1 1, 1 -1, -1 -1))", "LINESTRING(0 0, 1 1, 1 2, 2 2)",
#'   "POLYGON((-2 -2, -2 2, 2 2, 2 -2, -2 -2))")
#' bg_within(x, y)
#'
#' @return logical matrix returning \code{TRUE} if \code{x} is within \code{y}
#'
#' @note
#' supported geometries for \code{x}
#' - point
#' - linestring
#'
#' supported geometries for \code{y}
#' - linestring
#' - multilinestring
#' - polygon
#' - multipolygon
#'
#' @export
bg_within <- function(x, y, strategy = c("cartesian", "spherical", "geographic")) {
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_within_cartesian(x, y),
    "spherical"  =  rcpp_wkt_within_spherical(x, y),
    "geographic" =  rcpp_wkt_within_geographic(x, y)
  )
}
