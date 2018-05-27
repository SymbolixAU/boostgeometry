#' BG Buffer
#'
#' @inheritParams bg_area
#' @param distance
#'
#' @examples
#'
#' bg_buffer("LINESTRING(0 0, 1 1, 2 2)", distance = 1.0)
#'
#'
#' @export
bg_buffer <- function(x, distance = 1.0) {
  rcpp_wkt_buffer_cartesian(x, distance)
}
