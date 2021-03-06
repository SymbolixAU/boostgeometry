% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/algorithm_touches.R
\name{bg_touches}
\alias{bg_touches}
\title{BG Touches}
\usage{
bg_touches(x, y, strategy = c("cartesian", "spherical", "geographic"))
}
\arguments{
\item{x}{well-known text representation of a geometry}

\item{y}{well-known text representation of a geometry}

\item{strategy}{coordinate strategy}
}
\description{
Checks if two geometries touch
}
\note{
MULTIPOINT not supported
}
\examples{
x <- c("LINESTRING(0 0, 1 1)", "POLYGON((-1 0, -1 1, 1 1, 1 0, -1 0))")
y <- c("POINT(0 0)", "LINESTRING(1 1,2 2)", "MULTILINESTRING((2 2, 2 3),(0 0, -1 0))", "POINT(-2 -2)")
bg_touches(x, y)

}
