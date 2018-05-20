# BG Unique
#
# Calculates the minimal set (where duplicate consecutive points are removed) of a geometry.
#
# @param x
#
# @examples
# bg_unique("POLYGON((0 0,0 0,0 5,5 5,5 5,5 5,5 0,5 0,0 0,0 0,0 0,0 0))")
#
# @note
#
# Supported geometries
# - linestring
# - multilinestring
# - polygon
# - multipolygon
#
#
#bg_unique <- function(x) rcpp_wkt_unique_cartesian(x)
  # strategy <- match.arg(strategy)
  # switch(
  #   strategy
  #   , "cartesian"  = rcpp_wkt_unique_cartesian(x)
  #   , "spherical"  = rcpp_wkt_unique_spherical(x)
  #   , "geographic" = rcpp_wkt_unique_geographic(x)
  # )
# }
