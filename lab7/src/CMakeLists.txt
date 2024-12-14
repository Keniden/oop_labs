add_library(NPC_library STATIC
        Bear.cpp
        Elf.cpp
        Robber.cpp
        NPC.cpp
        Factory.cpp
        ObserverFile.cpp
        ObserverConsole.cpp
        Visitor.cpp
        World.cpp
)
target_include_directories(NPC_library PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_executable(7_lab_oop main.cpp)
target_link_libraries(7_lab_oop PRIVATE NPC_library)

