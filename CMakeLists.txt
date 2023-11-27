add_library(pico_pct2075 INTERFACE)

target_sources(pico_pct2075 INTERFACE 
  ${CMAKE_CURRENT_LIST_DIR}/src/pico_pct2075.cpp
)

target_include_directories(pico_pct2075 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(pico_pct2075 INTERFACE pico_stdlib hardware_i2c)