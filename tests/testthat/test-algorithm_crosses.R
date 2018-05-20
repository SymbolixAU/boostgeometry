context("crosses")

test_that("crosses calculates correctly", {
  x <- "LINESTRING(-1 -1, 0 0, 1 1)"
  y <- c("LINESTRING(1 -1, 0 0, -1 1)", "LINESTRING(0 0, 1 1)", "LINESTRING(-1 1, 0 0, 1 -1)")
  expect_equal(bg_crosses(x, y), matrix(c(T, F, T), ncol = 3))
})
