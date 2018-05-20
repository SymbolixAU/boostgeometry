context("perimeter")

test_that("perimeter calculated correctly", {
  expect_equal(bg_perimeter("POINT(90 0)"), 0)
  expect_equal(round(bg_perimeter("POLYGON((0 0, 1 1, 2 2, 0 0))"), 2), 5.66)
  expect_equal(round(bg_perimeter("POLYGON((0 0, 1 1, 2 2, 0 0))", "spherical"), 2), 0.10)
  expect_equal(round(bg_perimeter("POLYGON((0 0, 1 1, 2 2, 0 0))", "geographic"), 0), 627517)
})
