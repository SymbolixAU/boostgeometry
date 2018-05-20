#' BG Unique
#'
#' Calculates the minimal set (where duplicate consecutive points are removed) of a geometry.
#'
#' @inheritParams bg_area
#'
#' @examples
#' bg_unique("LINESTRING(0 0,0 0,1 1,1 1,2 2)")
#' bg_unique("POLYGON((0 0,0 0,0 5,5 5,5 5,5 5,5 0,5 0,0 0,0 0,0 0,0 0))")
#'
#' @note
#'
#' Supported geometries
#' - linestring
#' - multilinestring
#' - polygon
#' - multipolygon
#'
#' @export
bg_unique <- function(x, strategy = c("cartesian","spherical","geographic")) {
 strategy <- match.arg(strategy)
 switch(
   strategy
   , "cartesian"  = rcpp_wkt_unique_cartesian(x)
   , "spherical"  = rcpp_wkt_unique_spherical(x)
   , "geographic" = rcpp_wkt_unique_geographic(x)
 )
}
