cmake_minimum_required(VERSION 3.0.0)

project(bigint 
    VERSION 1.0.0
)

enable_language(CXX)

file(GLOB BIGINT_HEADERS "*.hh")
file(GLOB BIGINT_SRC "*.cc")

add_library(bigint STATIC ${BIGINT_HEADERS} ${BIGINT_SRC})



# Quick Commit Local
if(TARGET qcl)

    add_custom_command(qcl
        COMMAND git add .
        COMMAND git commit -m "Quick Commit"
        COMMAND git gc
        VERBATIM
    )

endif()

# Quick Commit
if(TARGET qc)

    add_custom_command(qc
        COMMAND git push 
        VERBATIM
        DEPENDS qcl
    )

endif()


