context("num")

test_that("num_ are calculated correctly", {
  expect_equal(bg_number_points("MULTIPOLYGON(((0 0,0 10,10 0,0 0),(1 1,1 9,9 1,1 1)),((10 10,10 7,7 10,10 10)))"), 12)
  expect_equal(bg_number_segments("MULTIPOLYGON(((0 0,0 10,10 0),(1 1,8 1,1 8)),((10 10,10 20,20 10)))"), 6)
  expect_equal(bg_number_geometries("MULTIPOLYGON(((0 0,0 10,10 0,0 0),(1 1,1 9,9 1,1 1)),((10 10,10 7,7 10,10 10)))"), 2)
  expect_equal(bg_number_interior_rings("MULTIPOLYGON(((0 0,0 10,10 0,0 0),(1 1,1 9,9 1,1 1)),((10 10,10 7,7 10,10 10)))"), 1)
})
