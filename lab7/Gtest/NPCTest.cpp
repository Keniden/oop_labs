#include <gtest/gtest.h>
#include "World.h"
#include "ObserverFile.h"
#include "ObserverConsole.h"
#include "Visitor.h"
#include "Bear.h"
#include "Elf.h"
#include "Robber.h"
#include "NPC.h"

TEST(NPCTest, TestCreate){
    std::string name = "Bear";
    Bear bear(name, 123.4, 123.4, 70, 100);
    EXPECT_EQ(bear.Name(), "Bear");
    EXPECT_EQ(bear.GetType(), "Bear");
    ASSERT_EQ(bear.GetPos().x, 123.4);
    ASSERT_EQ(bear.GetPos().y, 123.4);
}

TEST(NPCTest, TestKill){
    Bear bear("Bear", 123.4, 123.4, 60, 70);
    Elf elf("Bear", 123.0, 123.0, 30, 50);
    bear.KillOtherNPC(elf);
    ASSERT_EQ(elf.Alive(), false);
}
