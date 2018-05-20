#' BG Densify
#'
#' Divides segments of a geometry if they are longer than the \code{distance} into
#' smaller segments
#'
#' @inheritParams bg_area
#' @param distance numeric. The distance between segments (sequential coordinates)
#'
#'
#' @examples
#'
#' bg_densify("POLYGON((0 0,0 10,10 10,10 0,0 0),(1 1,4 1,4 4,1 4,1 1))", distance = 6)
#' bg_densify("POLYGON((0 0,0 10,10 10,10 0,0 0),(1 1,4 1,4 4,1 4,1 1))", strategy = "spherical", distance = 0.06)
#' bg_densify("POLYGON((0 0,0 10,10 10,10 0,0 0),(1 1,4 1,4 4,1 4,1 1))", strategy = "geographic", distance = 60000)
#'
#' @export
bg_densify <- function(x, strategy = c("cartesian","spherical","geographic"), distance) {
  strategy <- match.arg(strategy)
  switch(
    strategy
    , "cartesian"  = rcpp_wkt_densify_cartesian(x, distance)
    , "spherical"  = rcpp_wkt_densify_spherical(x, distance)
    , "geographic" = rcpp_wkt_densify_geographic(x, distance)
  )
}
