context("length")

test_that("length calculations are correct", {
  expect_equal(round(bg_length("LINESTRING(0 0,1 1,4 8,3 2)"), 2), 15.11)
  expect_equal(round(bg_length("LINESTRING(0 0,1 1,4 8,3 2)", "spherical"), 2), 0.26)
  expect_equal(round(bg_length("LINESTRING(0 0,1 1,4 8,3 2)", "geographic"), 0), 1672139)
})
