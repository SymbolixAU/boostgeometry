context("densify")

test_that("densify inserts points",{
  expect_equal(
    bg_densify("POLYGON((0 0,0 10,10 10,10 0,0 0),(1 1,4 1,4 4,1 4,1 1))", distance = 6),
    "POLYGON((0 0,0 5,0 10,5 10,10 10,10 5,10 0,5 0,0 0),(1 1,4 1,4 4,1 4,1 1))"
  )
  expect_equal(
    bg_densify("POLYGON((0 0,0 10,10 10,10 0,0 0))", strategy = "spherical", distance = 0.1),
    "POLYGON((0 0,0 5,0 10,5.00001 10.0374,10 10,10 4.99999,10 0,5 0,0 0))"
  )
})
