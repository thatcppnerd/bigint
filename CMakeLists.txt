cmake_minimum_required(VERSION 3.0)

project(bigint 
    VERSION 1.0.0 
)

enable_language(CXX)

file(GLOB BIGINT_HEADERS "*.hh")
file(GLOB BIGINT_SRC "*.cc")



add_library(bigint STATIC ${BIGINT_HEADERS} ${BIGINT_SRC})
