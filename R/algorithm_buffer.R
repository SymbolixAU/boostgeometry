#' BG Buffer
#'
#' @inheritParams bg_area
#' @param distance
#' @param points_per_circle
#'
#' @examples
#'
#' bg_buffer("LINESTRING(0 0,4 5,7 4,10 6)", distance = 1.0)
#'
#'
#' @export
bg_buffer <- function(x, distance = 1.0, points_per_circle = 90) {
  rcpp_wkt_buffer_cartesian(x, distance, points_per_circle)
}
