# We add a target named "doc" that generates documentation
# with doxygen
add_custom_target(doc)

find_package(Doxygen)
find_package(LATEX)
if(DOXYGEN_FOUND)
    # generate Doxyfile
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

    # add doc target
    add_custom_target(create_doxygen
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
        )
    install(
        DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/html
        DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/latex
        DESTINATION doc
        COMPONENT doc
        OPTIONAL
        )

    add_dependencies(doc create_doxygen)
endif(DOXYGEN_FOUND)

#IF(PDFLATEX_COMPILER)
#    add_custom_target(create_refman
#        COMMAND ${PDFLATEX_COMPILER} refman.tex
#        COMMAND ${PDFLATEX_COMPILER} refman.tex
#        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#        COMMENT "Generating pdf user guide with latex" VERBATIM
#        DEPENDS refman_tex
#        )
#    install(
#        FILES ${CMAKE_CURRENT_BINARY_DIR}/refman.pdf
#        DESTINATION doc
#        COMPONENT create_refman
#        OPTIONAL
#        )
#    add_dependencies(doc create_refman)
#ENDIF(PDFLATEX_COMPILER)

