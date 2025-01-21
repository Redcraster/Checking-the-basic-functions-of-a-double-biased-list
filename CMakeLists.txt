cmake_minimum_required(VERSION 3.10)

# Имя проекта
project(DemoVendorCatch2)

# Добавляем поддиректорию с Catch2
add_subdirectory(catch2)

# Добавляем исполняемую цель для тестов
add_executable(DemoVendorCatch2 main.cpp)

# Линкуем Catch2 с вашей целью
target_link_libraries(DemoVendorCatch2 PRIVATE Catch2::Catch2WithMain)
