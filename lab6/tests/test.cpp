#include <gtest/gtest.h>
#include <memory>
#include "../include/npc.hpp"
#include "../include/fight_manager.hpp"
#include "../include/observer.hpp"
#include <fstream>

class TestObserver : public Observer {
public:
    std::vector<std::pair<std::string, std::string>> killEvents;

    void onKill(const std::string& killer, const std::string& victim) override {
        killEvents.emplace_back(killer, victim);
    }
};

TEST(LocationTest, AddNPC_UniqueNames) {
    Location location;

    auto npc1 = NPCFactory::createNPC("Elf", "Elrond", 100, 100);
    auto npc2 = NPCFactory::createNPC("Bear", "Baloo", 200, 200);
    auto npc3 = NPCFactory::createNPC("Bandit", "Rogue", 300, 300);

    EXPECT_TRUE(location.addNPC(npc1));
    EXPECT_TRUE(location.addNPC(npc2));
    EXPECT_TRUE(location.addNPC(npc3));

    auto npcDuplicate = NPCFactory::createNPC("Elf", "Elrond", 150, 150);
    EXPECT_FALSE(location.addNPC(npcDuplicate));
}

TEST(LocationTest, SaveLoadNPC) {
    Location location;
    auto testObserver = std::make_shared<TestObserver>();
    location.attach(testObserver);

    auto npc1 = NPCFactory::createNPC("Elf", "Legolas", 120, 220);
    auto npc2 = NPCFactory::createNPC("Bear", "Yogi", 320, 420);
    location.addNPC(npc1);
    location.addNPC(npc2);

    EXPECT_TRUE(location.saveToFile("test_save.txt"));

    Location loadedLocation;
    auto loadedObserver = std::make_shared<TestObserver>();
    loadedLocation.attach(loadedObserver);
    EXPECT_TRUE(loadedLocation.loadFromFile("test_save.txt"));

    auto npc1_duplicate = NPCFactory::createNPC("Elf", "Legolas", 130, 230);
    auto npc2_duplicate = NPCFactory::createNPC("Bear", "Yogi", 330, 430);
    EXPECT_FALSE(loadedLocation.addNPC(npc1_duplicate));
    EXPECT_FALSE(loadedLocation.addNPC(npc2_duplicate));

    EXPECT_EQ(loadedObserver->killEvents.size(), 0);

    std::remove("test_save.txt");
}

TEST(LocationTest, BattleMode) {
    Location location;
    auto testObserver = std::make_shared<TestObserver>();
    location.attach(testObserver);

    auto npc1 = NPCFactory::createNPC("Elf", "Arwen", 100, 100);
    auto npc2 = NPCFactory::createNPC("Bandit", "Bandit1", 105, 105); // В зоне действия
    auto npc3 = NPCFactory::createNPC("Bear", "Grizzly", 400, 400);
    location.addNPC(npc1);
    location.addNPC(npc2);
    location.addNPC(npc3);

    location.battleMode(10.0);

    ASSERT_EQ(testObserver->killEvents.size(), 1);
    auto event = testObserver->killEvents[0];
    EXPECT_TRUE(
        (event.first == "Arwen" && event.second == "Bandit1") ||
        (event.first == "Bandit1" && event.second == "Arwen")
    );
}

TEST(LocationTest, ObserverNotifications) {
    Location location;
    auto testObserver = std::make_shared<TestObserver>();
    location.attach(testObserver);

    auto npc1 = NPCFactory::createNPC("Elf", "Elrond", 100, 100);
    auto npc2 = NPCFactory::createNPC("Bandit", "Bandit1", 105, 105); // В зоне действия
    location.addNPC(npc1);
    location.addNPC(npc2);

    location.battleMode(10.0);

    ASSERT_EQ(testObserver->killEvents.size(), 1);
    auto event = testObserver->killEvents[0];
    EXPECT_TRUE(
        (event.first == "Elrond" && event.second == "Bandit1") ||
        (event.first == "Bandit1" && event.second == "Elrond")
    );
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
