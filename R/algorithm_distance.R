#' BG Distance
#'
#' Calculates the distances between two sets of geometries
#'
#' @notes geogrpahic multiponts not supported
#'
#' @inheritParams bg_area
#' @param y if null, each element of \code{x} is assessed against every other element of \code{y}
#'
#' @return logical matrix where the rows are the geometries in \code{x} and the columns
#' are the geometries in \code{y}
#'
#' @examples
#' points <- c("POINT(0 0)", "POINT(2 0)", "POINT(2 2)")
#' bg_distance(points)
#' bg_distance(points, points)
#'
#' lines <- c("LINESTRING(1 1, 1 0, 1 -1)")
#' bg_distance(points, lines)
#' bg_distance(points, lines, "geographic")
#'
#' @export
bg_distance <- function(x, y = NULL, strategy = c('cartesian','spherical','geographic')) {

  if (is.null(y)) y <- x

  ## need to switch in R; variants not supported in c++
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_distance_cartesian(x, y),
    "spherical"  =  rcpp_wkt_distance_spherical(x, y),
    "geographic" =  rcpp_wkt_distance_geographic(x, y)
  )
}
