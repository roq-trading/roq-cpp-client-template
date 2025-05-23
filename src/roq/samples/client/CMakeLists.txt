set(TARGET_NAME ${PROJECT_NAME}-client)

add_subdirectory(flags)
add_subdirectory(tools)

set(SOURCES application.cpp config.cpp settings.cpp strategy.cpp main.cpp)

add_executable(${TARGET_NAME} ${SOURCES})

add_dependencies(${TARGET_NAME} ${PROJECT_NAME}-flags-autogen-headers)

target_link_libraries(
  ${TARGET_NAME}
  PRIVATE ${PROJECT_NAME}-flags
          ${PROJECT_NAME}-tools
          roq-client::roq-client
          roq-client::roq-client-flags
          roq-market::roq-market
          roq-logging::roq-logging
          roq-logging::roq-logging-flags
          roq-flags::roq-flags
          roq-api::roq-api
          fmt::fmt)

if(ROQ_BUILD_TYPE STREQUAL "Release")
  set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS_RELEASE -s)
endif()

target_compile_definitions(${TARGET_NAME} PRIVATE ROQ_PACKAGE_NAME="${CMAKE_PROJECT_NAME}" ROQ_BUILD_VERSION="${CMAKE_PROJECT_VERSION}")

install(TARGETS ${TARGET_NAME})
