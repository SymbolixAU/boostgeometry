#' BG Reverse
#'
#' Reverses the points in a geometry
#'
#' @inheritParams bg_area
#'
#' @examples
#' bg_reverse("POLYGON((0 0,0 1,1 1,1 0,0 0))")
#'
#' @export
bg_reverse <- function(x) rcpp_wkt_reverse(x, "cartesian")
