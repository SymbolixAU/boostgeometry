#' bg join
#'
#' Joins geometries
#'
#'
#' @inheritParams bg_intersects
#'
#' @export
bg_join <- function(x, y, join = "intersects") {

  ## TODO(if x == y, geometries intersecting with themselves?)

  suffix <- c(".x", ".y")

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

  lst <- rcpp_bg_join_predicate_cartesian(xwkt, ywkt, join)

  idx <- cbind(rep(1:length(lst), sapply(lst, length)), unlist(lst))
  setNames(lst, c(wktCol1, wktCol2))

  ## TODO(return type)
  ## - which class should the object be returned as?
  ## - wkt (if x && y are wkt)
  ## - df (if ... ?)
  df <- cbind(as.data.frame(x[idx[,1], ]),  y[idx[,2],])

  attr(df, "class") <- c("wkt", attr(df, "class"))
  attr(df[[wktCol1]], "class") <- "wkt_column"
  attr(df[[wktCol2]], "class") <- "wkt_column"

  attr(df, "wkt_column") <- c(wktCol1, wktCol2)

  return( df )
}

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


