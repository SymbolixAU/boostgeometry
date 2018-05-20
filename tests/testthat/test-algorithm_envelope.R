context("envelope")

test_that("envelope calulcated correctly", {
  expect_equal(
    bg_envelope("POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3),(4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))", "cartesian")
    , "POLYGON((2 0.7,2 3,5.4 3,5.4 0.7,2 0.7))"
  )
  expect_equal(
    bg_envelope("LINESTRING(144 -37, 145 -36)", "geographic")
    , "POLYGON((144 -37,144 -36,145 -36,145 -37,144 -37))"
  )
})
