add_subdirectory(lib/googletest)

add_executable(npc_Test
    NPCTest.cpp
    ../src/Bear.cpp
    ../src/Elf.cpp
    ../src/NPC.cpp
)


target_link_libraries(npc_Test
    PUBLIC
    gtest
    gtest_main
)


set(${CXX_FLAGS} ${CXX_FLAGS} -fsanitize=address)

target_include_directories(npc_Test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

add_test(NAME npcTEST COMMAND npc_Test)
