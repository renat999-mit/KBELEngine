# Executable for DummyApp
add_executable( DummyApp dummyApp.cpp)
target_link_libraries(DummyApp PRIVATE KBELEngine)
target_include_directories(DummyApp PRIVATE

  ${CMAKE_SOURCE_DIR}/src

)
