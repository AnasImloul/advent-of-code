# Create the 2023 library
add_library(2023 INTERFACE)

add_subdirectory(day_01)
add_subdirectory(day_02)

target_link_libraries(2023 INTERFACE trebuchet)
target_link_libraries(2023 INTERFACE cube_conundrum)
