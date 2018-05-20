context("reverse")

test_that("reverse reverses a geometry",{
  expect_equal(bg_reverse("POLYGON((0 0,0 1,1 1,1 0,0 0))"),"POLYGON((0 0,1 0,1 1,0 1,0 0))")
  expect_equal(bg_reverse("LINESTRING(0 0,0 1,1 1,1 0,0 0)"),"LINESTRING(0 0,1 0,1 1,0 1,0 0)")
  expect_equal(bg_area("POLYGON((0 0,0 1,1 1,1 0,0 0))"), 1)
  expect_equal(bg_area(bg_reverse("POLYGON((0 0,0 1,1 1,1 0,0 0))")), -1)
})
