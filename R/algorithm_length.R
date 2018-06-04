#' BG Length
#'
#' Calculates the length of a geometry
#'
#' @inheritParams bg_area
#'
#' @note
#' points - returns 0
#' lines - returns the length
#' areal - returns 0
#'
#' @examples
#' bg_length("LINESTRING(0 0,1 1,4 8,3 2)")
#' bg_length("LINESTRING(0 0,1 1,4 8,3 2)", "geographic")
#'
#' @export
bg_length <- function(x, strategy = c('cartesian','spherical','geographic')) {

  ## need to switch in R; variants not supported in c++
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_length_cartesian(x),
    "spherical"  =  rcpp_wkt_length_spherical(x),
    "geographic" =  rcpp_wkt_length_geographic(x)
    )
}
