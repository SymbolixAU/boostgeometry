context("unique")

test_that("unique is working correctly", {
  expect_equal(
    bg_unique("LINESTRING(0 0,0 0,1 1,1 1,2 2)"),
    "LINESTRING(0 0,1 1,2 2)"
  )
  expect_equal(
    bg_unique("POLYGON((0 0,0 0,0 5,5 5,5 5,5 5,5 0,5 0,0 0,0 0,0 0,0 0))"),
    "POLYGON((0 0,0 5,5 5,5 0,0 0))"
  )
})
