# Main engine library
add_library(KBELEngine STATIC

  KBELMain.cpp

)
target_link_libraries(KBELEngine PRIVATE LoginLib)

# Add subdirectories
add_subdirectory(Login)
