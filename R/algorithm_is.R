#' BG Is Empty
#'
#' Checks if a geometry is empty
#'
#' @inheritParams bg_area
#'
#' @examples
#' bg_is_empty("MULTILINESTRING((0 0,0 10,10 0),(1 1,8 1,1 8))")
#'
#' @export
bg_is_empty <- function(x) rcpp_wkt_is_empty(x, "cartesian")


#' BG Is Simple
#'
#' Checks if a geometry is simple
#'
#' @inheritParams bg_area
#'
#' @examples
#' bg_is_simple("MULTILINESTRING((0 0,0 10,10 10,10 0,0 0),(10 10,20 20))")
#' bg_is_simple("LINESTRING(0 0,0 10,10 10,10 0,0 0)")
#'
#' @export
bg_is_simple <- function(x) rcpp_wkt_is_simple(x, "cartesian")

#' BG Is Valid
#'
#' Checks if a geometry is valid
#'
#' @inheritParams bg_area
#'
#' @examples
#' bg_is_valid("POLYGON((0 0,0 10,10 10,10 0,0 0),(0 0,9 1,9 2,0 0),(0 0,2 9,1 9,0 0),(2 9,9 2,9 9,2 9))")
#' bg_is_valid("POLYGON((0 0,0 10,10 10,10 0,0 0))")
#'
#' @export
bg_is_valid <- function(x) rcpp_wkt_is_valid(x, "cartesian")



