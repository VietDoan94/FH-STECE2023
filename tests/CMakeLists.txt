add_executable(
  door-tests

  door-tests.cpp
  timespec-tests.cpp

  pressure_mock_unit.cpp
  event-edge-detector-tests.cpp
)
target_link_libraries(
  door-tests

  door
  gtest_main 
)
add_test(
  NAME door-tests 
  COMMAND door-tests
)

if (LIBGPIOD_FOUND)
  add_executable(gpio-read-value-loop gpio-read-value-loop.cpp)
  target_link_libraries(gpio-read-value-loop LIBGPIOD::LIBGPIOD)

  add_executable(push-button-gpio-test push-button-gpio-test.cpp)
  target_link_libraries(
    push-button-gpio-test
    door
    gtest_main
  )

  add_executable(motorLED-tests motorLED-tests.cpp)
  target_link_libraries(
    motorLED-tests
    door
    gtest_main
  )

  add_executable(light-barrier-gpio-tests light-barrier-gpio-tests.cpp)
  target_link_libraries(
    light-barrier-gpio-tests
    door
    gtest_main
  )

  add_executable(
    input-switch-gpio-tests input-switch-gpio-tests.cpp
  )
  target_link_libraries(
    input-switch-gpio-tests
  
    door
    gtest_main
  )

  add_executable(
  input-output-switch-gpio-tests input-output-switch-gpio-tests.cpp
  )
  target_link_libraries(
    input-output-switch-gpio-tests
  
    door
    gtest_main
  )

else()
  message(WARNING "Skip motorLED-tests and gpio-read-value-loop because libgpiod not found")
endif()

add_executable(bmp280_test bmp280-test.cpp)
target_link_libraries(
  bmp280_test

  PRIVATE
  door
  gtest_main
)

add_test(
  NAME bmp280_test
  COMMAND bmp280_test
)
