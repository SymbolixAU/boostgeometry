context("area")

test_that("area calculated correctly", {
  expect_equal(bg_area("POLYGON((0 0,0 7,4 2,2 0,0 0))", "cartesian"), 16)
  expect_equal(round(bg_area("POLYGON((0 0,0 45,45 0,0 0))", "spherical"), 3), 0.340)
})
