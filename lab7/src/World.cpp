#include "World.h"

World::World(int size) {
    worldSize = size;
}


void World::AddNPC(const std::string& type, const std::string& name, double x, double y, int damage, int health) {
    NPC_.push_back(Factory::CreateNPC(type, name, x, y, damage, health));
}

void World::AllNPC() const {
    for (const auto& c : NPC_) {
        std::cout << c->GetType() << " '" << c->Name() << "' ("
            << c->GetPos().x << ", " << c->GetPos().y << ", " << c->GetDamage() << ", " << c->GetHealth() << ")\n";
    }
}

void World::Serialize(const std::string& filename) const {
    std::ofstream fs(filename);
    for (const auto& c : NPC_) {
        if (c->Alive()) {
            fs << c->GetType() << " " << c->Name() << " "
                << c->GetPos().x << " " << c->GetPos().y << " " << c->GetDamage() << ", " << c->GetHealth() << "\n";
        }
    }
}

void World::Deserialize(const std::string& filename) {
    std::ifstream fs(filename);
    std::string type, name;
    double x, y, damage, health;
    while (fs >> type >> name >> x >> y >> damage >> health) {
        AddNPC(type, name, x, y, damage,  health);
    }
}

void World::Engage(Visitor& visitor) {
    visitor.Engage(NPC_);
}


void World::MoveNPC() {
    for (auto c : NPC_) {
        double x, y;
        if (c->GetType() == "Bear") {
            x = (rand() % 100);
            y = (rand() % 100);
            x = (x - 50) / 10;
            y = (y - 50) / 10;
        } else {
            x = (rand() % 200);
            y = (rand() % 200);
            x = (x - 100) / 10;
            y = (y - 100) / 10;
        }

        position NewCoords;
        NewCoords.x = c->GetPos().x + x;
        NewCoords.y = c->GetPos().y + y;

        c->move(NewCoords);
    }
}

void World::PrintMap() const {
    int xSize = int(worldSize);
    int ySize = int(worldSize);

    for (int i = 0; i <= xSize + 2; ++i) {
        std::cout << '-';
    }
    std::cout << '\n';

    for (int i = 0; i <= ySize; ++i) {
        std::cout << '|';
        for (int j = 0; j <= xSize; ++j) {
            bool printed = false;
            for (auto c : NPC_) {
                if (!c->Alive())
                    continue;

                printed = true;
                if ((int)c->GetPos().x == j && (int)c->GetPos().y == i) {
                    if (c->GetType() == "Bear") {
                        std::cout << '@';
                        break;
                    }
                    else if (c->GetType() == "Elf") {
                        std::cout << '/';
                        break;
                    }
                    else if (c->GetType() == "Robber") {
                        std::cout << '*';
                        break;
                    }
                }
                else {
                    printed = false;
                }
            }
            if (!printed) {
                std::cout << ' ';
            }
        }
        std::cout << '|';
        std::cout << '\n';
    }

    for (int i = 0; i <= xSize + 2; ++i) {
        std::cout << '-';
    }
    std::cout << '\n';
}