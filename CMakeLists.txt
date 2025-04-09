cmake_minimum_required(VERSION 3.0.0)

project(bigint 
    VERSION 1.0.0
)

enable_language(CXX)

file(GLOB BIGINT_HEADERS "*.hh")
file(GLOB BIGINT_SRC "*.cc")

add_library(bigint STATIC ${BIGINT_HEADERS} ${BIGINT_SRC})



# Quick Commit Local
if(NOT TARGET qcl)

    add_custom_target(qcl
        COMMAND git commit -a -m "Quick Commit"
        COMMAND git gc
        VERBATIM
        COMMENT "Committing all changes" 
    )

endif()

# Quick Commit
if(NOT TARGET qc)

    add_custom_target(qc
        COMMAND git push 
        VERBATIM
        DEPENDS qcl
        COMMENT "Pushing commits"
    )

endif()


