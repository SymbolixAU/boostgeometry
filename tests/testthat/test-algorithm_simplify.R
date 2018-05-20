context("simplify")

test_that("geometries are simplified", {
  polygon <- "POLYGON((0 0, 0 0.2, 0.2 0.2, 0.2 0, 0.3 0, 0.3 0.2, 0.25, 0.5, 0.1 0.4, 0 0.2, 0 0))"
  res <- "POLYGON((0.5 0,0.1 0.4,0 0,0 0.2,0.5 0))"
  expect_equal(bg_simplify(polygon, distance = 0.2), res)
})
