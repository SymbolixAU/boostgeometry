context("clear")

test_that("clear clears goemetries",{
  expect_equal(bg_clear("POLYGON((0 0,0 1,1 1,1 0,0 0))"), "POLYGON(())")
  expect_equal(bg_clear("LINESTRING(0 0,1 1)"), "LINESTRING()")
  expect_equal(bg_clear("MULTIPOINT(0 0,1 1)"), "MULTIPOINT()")
  expect_equal(bg_clear("POINT(0 0)"), "POINT(0 0)")
})
