context("convex_hull")

test_that("test that convex hull calculated correctly", {
  polygon <- "POLYGON((2.0 1.3, 2.4 1.7, 2.8 1.8, 3.4 1.2, 3.7 1.6,3.4 2.0, 4.1 3.0, 5.3 2.6, 5.4 1.2, 4.9 0.8, 2.9 0.7,2.0 1.3))"
  res <- "POLYGON((2 1.3,2.4 1.7,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3))"
  expect_equal(bg_convex_hull(polygon), res)
})
