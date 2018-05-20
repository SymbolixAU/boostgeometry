context("distance")

test_that("distances are calcualted", {
  points <- c("POINT(0 0)", "POINT(2 2)")
  expect_equal( bg_distance(points), bg_distance(points, points) )

  lines <- c("LINESTRING(1 1, 1 0, 1 -1)")
  expect_equal( round(bg_distance(points, lines), 2), matrix(c(1, 1.41)) )
  expect_equal( round( bg_distance(points, lines, "geographic"), 0), matrix(c(111314, 156850)) )
})
