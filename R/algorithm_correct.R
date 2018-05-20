#' BG Correct
#'
#' Corrects a geometry: all rings incorrectly oriented with respect to their expected
#' orientation are reversed. All rings which do not have a closing point
#' and are typsed as they should have one, the first point is appended.
#'
#' @inheritParams bg_area
#'
#' @examples
#' bg_correct("POLYGON((0 0, 0 1, 1 1, 1 0))")
#' bg_correct("POLYGON((0 0, 0 1, 1 1, 1 0),(0.25 0.25, 0.25 0.75, 0.75 0.75, 0.75 0.25))")
#'
#'
#' @export
bg_correct <- function(x) rcpp_wkt_correct(x, "cartesian")
