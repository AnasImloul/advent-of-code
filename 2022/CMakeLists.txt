add_library(2022 INTERFACE)

add_subdirectory(day_19)

target_link_libraries(2022 INTERFACE not_enough_minerals)