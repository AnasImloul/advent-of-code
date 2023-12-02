add_subdirectory(day_01)

# Create the 2023 library
add_library(2023 INTERFACE)

# Link the day_01 library with the 2023 library
target_link_libraries(2023 INTERFACE trebuchet)
