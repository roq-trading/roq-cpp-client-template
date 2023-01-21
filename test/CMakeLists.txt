set(TARGET_NAME "${PROJECT_NAME}-test")

set(SOURCES main.cpp)

add_executable("${TARGET_NAME}" ${SOURCES})

target_link_libraries(
  "${TARGET_NAME}"
  PRIVATE ${PROJECT_NAME}
          roq-logging::roq-logging
          Catch2::Catch2)

target_compile_features("${TARGET_NAME}" PUBLIC cxx_std_20)

set_target_properties("${TARGET_NAME}" PROPERTIES LINK_FLAGS_RELEASE -s)

add_test(NAME "${TARGET_NAME}" COMMAND "${TARGET_NAME}")
