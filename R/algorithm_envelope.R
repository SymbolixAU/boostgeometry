#' BG Envelope
#'
#' Calculates the envelope (bounding box) of a geometry
#'
#' @inheritParams bg_area
#'
#' @examples
#' polygon <- "POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3), (4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))"
#' bg_envelope(polygon)
#'
#' bg_envelope("LINESTRING(144 -37, 145 -36)", "geographic")
#'
#' @export
bg_envelope <- function(x, strategy = c("cartesian", "spherical","geographic")) {
  strategy <- match.arg(strategy)
  switch(
    strategy
    , "cartesian"  = rcpp_wkt_envelope_cartesian(x)
    , "spherical"  = rcpp_wkt_envelope_spherical(x)
    , "geographic" = rcpp_wkt_envelope_geographic(x)
  )
}
