# Create library for Login
add_library(Login STATIC

  Logger.cpp

)

# Include current directory for header files
target_include_directories(Login PUBLIC ${CMAKE_CURRENT_DIRECTORY})
