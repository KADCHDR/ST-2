add_executable(${PROJECT_NAME}.test
AllTests.cpp
tests.cpp
../src/tasks.cpp)
target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME} gtest)
target_compile_definitions(${PROJECT_NAME}.test
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

install(TARGETS ${PROJECT_NAME}.test
  DESTINATION "${tool_dest}")
