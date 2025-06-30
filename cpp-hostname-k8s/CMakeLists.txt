cmake_minimum_required(VERSION 3.5)
project(cpp-hostname-k8s)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Используем правильные имена для поиска пакетов
find_package(Drogon CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

# Используем правильные имена целей для линковки
target_link_libraries(${PROJECT_NAME} PRIVATE
    Drogon::Drogon
    JsonCpp::JsonCpp)  # Исправлено имя цели
