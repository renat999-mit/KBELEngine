# Create library for Login
add_library(LoginLib STATIC

  Logger.cpp

)

# Include current directory for header files
target_include_directories(LoginLib PUBLIC ${CMAKE_CURRENT_DIRECTORY})
