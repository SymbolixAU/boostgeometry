context("is")

test_that("is tests are correct", {

  expect_equal(bg_is_empty("POINT(0 0)"), 0)
  ## TODO(is_empty TRUE test)
  expect_equal(bg_is_simple("MULTILINESTRING((0 0,0 10,10 10,10 0,0 0),(10 10,20 20))"), 0)
  expect_equal(bg_is_simple("LINESTRING(0 0, 0 1, 0 2)"), 1)
  expect_equal(bg_is_valid("POLYGON((0 0,0 10,10 10,10 0,0 0),(0 0,9 1,9 2,0 0),(0 0,2 9,1 9,0 0),(2 9,9 2,9 9,2 9))"), 0)
  expect_equal(bg_is_valid("LINESTRING(0 0, 0 1, 0 2)"), 1)
})
