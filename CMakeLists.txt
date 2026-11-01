cmake_minimum_required(VERSION 3.16)
project(MyCursesApp C)

# Указываем стандарт C (например, C11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. Ищем установленную библиотеку Curses / NCurses
find_package(Curses REQUIRED)

# 2. Создаем исполняемый файл
add_executable(app src/main.c)

# 3. Подключаем заголовочные файлы ncurses (include path)
target_include_directories(app PRIVATE ${CURSES_INCLUDE_DIR})

# 4. Линкуем библиотеку ncurses к нашему исполняемому файлу
target_link_libraries(app PRIVATE ${CURSES_LIBRARIES})
