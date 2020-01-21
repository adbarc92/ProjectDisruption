#pragma once
#include <vector>
#include <string>
#include "Equipment.h"

struct Consumable{
    std::string name;
    std::string description;
};

class Inventory{
    private:
        std::vector<Consumable*> consumables;
        std::vector<Equipment*> equipment;
        int owner_id;
        int party_id;
    public:
        Inventory();
};

