
cmake_minimum_required(VERSION 3.12)

project(libftprintf)

set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_library(${PROJECT_NAME} STATIC "")

target_compile_options(    ${PROJECT_NAME} PUBLIC -Wall -Wextra -Werror)
target_include_directories(${PROJECT_NAME} PUBLIC include)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/ft_printf.c
        src/read_modifiers.c
        src/read_modifiers2.c
        src/read_arguments.c
        src/read_arguments2.c
        src/clean_description.c
        src/useful_things.c
        src/processing.c
        src/processing_percent.c
        src/processing_x.c
        src/processing_s.c
        src/processing_ls.c
        src/processing_c.c
        src/processing_o.c
        src/processing_di.c
        src/processing_u.c
        src/processing_p.c
        src/wchar.c
)

