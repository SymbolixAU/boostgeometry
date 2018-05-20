context("within")

test_that("within works correctly", {

  x <- c("POINT(0 0)", "LINESTRING(1 1,1 2)")
  y <- c("POLYGON((-1 -1, -1 1, 1 1, 1 -1, -1 -1))", "LINESTRING(0 0, 1 1, 1 2, 2 2)",
         "POLYGON((-2 -2, -2 2, 2 2, 2 -2, -2 -2))")
  expect_equal(bg_within(x, y), matrix(c(T, F, F, T, T, T), ncol = 3) )

  x <- c("POLYGON((-2 -2, -2 2, 2 2, 2 -2, -2 -2))")
  y <- c("POINT(0 0)")
  expect_error(bg_within(x, y))
})

