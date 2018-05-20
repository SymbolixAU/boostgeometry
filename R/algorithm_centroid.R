#' BG Centroid
#'
#' Calculates the centroid of geometries
#'
#' @param wkt
#' @param strategy
#'
#' @examples
#' wkt <- "POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3),(4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))"
#' bg_centroid(wkt)
#'
#' @export
bg_centroid <- function(wkt) rcpp_wkt_centroid(wkt)
