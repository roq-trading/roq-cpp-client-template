set(TARGET_NAME "${PROJECT_NAME}-benchmark")

set(SOURCES simple.cpp main.cpp)

add_executable("${TARGET_NAME}" ${SOURCES})

target_link_libraries(
  "${TARGET_NAME}" PRIVATE "${PROJECT_NAME}-tools" benchmark::benchmark)

target_compile_features("${TARGET_NAME}" PUBLIC cxx_std_20)

set_target_properties("${TARGET_NAME}" PROPERTIES LINK_FLAGS_RELEASE -s)

install(TARGETS ${TARGET_NAME})
