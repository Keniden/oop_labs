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

// Функция для создания NPC с нужными параметрами
static NPC createNPC(const std::string& type, const std::string& name, double x, double y) {
    NPC npc;
    npc.type = type;
    npc.name = name;
    npc.x = x;
    npc.y = y;
    npc.alive = true;
    // Параметры движения и убийства:
    if (type == "Elf") {
        npc.moveRange = 10.0;
        npc.killRange = 50.0;
    } else if (type == "Bear") {
        npc.moveRange = 5.0;
        npc.killRange = 10.0;
    } else {
        // Bandit
        npc.moveRange = 10.0;
        npc.killRange = 10.0;
    }
    return npc;
}

TEST(LocationTest, AddNPC_UniqueNames) {
    Location location;

    auto npc1 = createNPC("Elf", "Elrond", 100, 100);
    auto npc2 = createNPC("Bear", "Baloo", 200, 200);
    auto npc3 = createNPC("Bandit", "Rogue", 300, 300);

    EXPECT_TRUE(location.addNPC(npc1));
    EXPECT_TRUE(location.addNPC(npc2));
    EXPECT_TRUE(location.addNPC(npc3));

    // Дубликат по имени "Elrond"
    auto npcDuplicate = createNPC("Elf", "Elrond", 150, 150);
    EXPECT_FALSE(location.addNPC(npcDuplicate));
}

TEST(LocationTest, ObserverNotificationsOnKill) {
    Location location;
    auto testObserver = std::make_shared<TestObserver>();
    location.attach(testObserver);

    auto npc1 = createNPC("Elf", "Legolas", 120, 220);
    auto npc2 = createNPC("Bear", "Yogi", 320, 420);

    location.addNPC(npc1);
    location.addNPC(npc2);

    // Убиваем "Yogi" от имени "Legolas"
    location.killNPC("Yogi", "Legolas");

    // Проверяем, что наблюдатель получил уведомление
    ASSERT_EQ(testObserver->killEvents.size(), 1);
    auto event = testObserver->killEvents[0];
    EXPECT_EQ(event.first, "Legolas");
    EXPECT_EQ(event.second, "Yogi");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
