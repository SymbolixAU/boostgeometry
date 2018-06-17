#' bg join
#'
#' Joins geometries
#'
#'
#' @inheritParams bg_intersects
#'
#'
#' @examples
#'
#' library(googlePolylines) ## for print methods
#'
#' ## vectors
#' wktOne <- c("POINT(0 0)", "LINESTRING(-3 -3, 1 1)", "POLYGON((-1 -1, 1 -1, 1 1, -1 1, -1 -1))")
#' wktTwo <- c("MULTIPOINT(-3 -3)", "MULTIPOLYGON(((-2 -2, 0 -2, 0 0, -2 0, -2 -2)))")
#' bg_join(wktOne, wktTwo, join = "intersects")
#' bg_join(wktOne, wktTwo, join = "within") ## currently only boxes supported
#'
#' library(sf)
#' nc <- st_read(system.file("shape/nc.shp", package="sf"), quiet = T)
#' wkt <- sf::st_as_text(nc$geometry)
#' bg_join(wkt[1:3], wkt[1:5])
#'
#' wkt <- polyline_wkt(encode(nc))
#' bg_join(wkt[1:3, ], wkt[1:5, ])
#'
#' @export
bg_join <- function(x, y, join = c("intersects", "within") ) {

  ## TODO(if x == y, geometries intersecting with themselves?)

  ## TODO(within only allows boxes)

  suffix <- c(".x", ".y")

  x <- normalise_data(x)
  y <- normalise_data(y)

  print(str(x))

  which.x = which(names(x) %in% names(y))
  which.y = which(names(y) %in% names(x))
  if (length(which.x))
    names(x)[which.x] = paste0(names(x)[which.x], suffix[1])
  if (length(which.y))
    names(y)[which.y] = paste0(names(y)[which.y], suffix[2])


  ## TODO(column names)
  wktCol1 <- wkt_column(x)
  wktCol2 <- wkt_column(y)

  if( wktCol1 == wktCol2 ) {
    wktCol1 <- paste0(wktCol1, suffix[1])
    wktCol2 <- paste0(wktCol2, suffix[2])
    attr(x, 'wkt_column') <- wktCol1
    attr(y, 'wkt_column') <- wktCol2
  }


  # print(wktCol1)
  # print(wktCol2)

  ## the return will be a data.frame.
  ## because if x || y are vectors, they need to be combined
  ## therefore, I can also set the wkt class attribute

  xwkt <- normalise_wkt(x)
  ywkt <- normalise_wkt(y)

  print(str(ywkt))

  lst <- rcpp_bg_join_predicate_cartesian(xwkt, ywkt, join)

  idx <- cbind(rep(1:length(lst), sapply(lst, length)), unlist(lst))

  ## TODO(return type)
  ## - which class should the object be returned as?
  ## - wkt (if x && y are wkt)
  ## - df (if ... ?)
  ## -
  ## - if zero results returned?
  df <- cbind(as.data.frame(x[idx[,2], ]),  y[idx[,1],])

  attr(df, "class") <- c("wkt", attr(df, "class"))
  attr(df[[wktCol1]], "class") <- "wkt_column"
  attr(df[[wktCol2]], "class") <- "wkt_column"

  attr(df, "wkt_column") <- c(wktCol1, wktCol2)

  return( df )
}


normalise_data <- function(x) UseMethod("normalise_data")

#' @export
normalise_data.character <- function(x) {
  df <- data.frame('geometry' = x, rowid = 1:length(x), stringsAsFactors = F)
  attr(df, 'class') <- c('wkt', class(df))
  attr(df, 'wkt_column') <- 'geometry'
  attr(df[['geometry']], 'class') <- 'wkt_column'
  df
}

#' @export
normalise_data.default <- function(x) x


wkt_column <- function(x) UseMethod("wkt_column")

#' @export
wkt_column.wkt <- function(x) attr(x, "wkt_column")

#' @export
wkt_column.wkt_column <- function(x) "geometry"




normalise_wkt <- function(x) UseMethod("normalise_wkt")

#' @export
normalise_wkt.wkt <- function(x) x[[attr(x, "wkt_column")]]

#' @export
normalise_wkt.wkt_column <- function(x) x

#' @export
normalise_wkt.character <- function(x) x

#' @export
normalise_wkt.default <- function(x) stop("no wkt found")


