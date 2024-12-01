# Füge Test-Executable hinzu
add_executable(${PROJECT_NAME}_test
    # Hier deine Test-Dateien auflisten
    test_main.cpp
)

# Verknüpfe mit GoogleTest und deinem Hauptprojekt
target_link_libraries(${PROJECT_NAME}_test
    PRIVATE
        gtest
        gtest_main
)

# Registriere den Test
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)