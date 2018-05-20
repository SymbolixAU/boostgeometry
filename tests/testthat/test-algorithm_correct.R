context("correct")

test_that("correct works correctly", {
  expect_equal(bg_correct("POLYGON((0 0, 0 1, 1 1, 1 0))"), "POLYGON((0 0,0 1,1 1,1 0,0 0))")
  expect_equal(
    bg_correct("POLYGON((0 0, 0 1, 1 1, 1 0),(0.25 0.25, 0.25 0.75, 0.75 0.75, 0.75 0.25))"),
    "POLYGON((0 0,0 1,1 1,1 0,0 0),(0.25 0.25,0.75 0.25,0.75 0.75,0.25 0.75,0.25 0.25))"
  )
})
