#pragma once
#include <vector>
#include "Technique.h"
#include "Stats.h"
#include "Equipment.h"

class Unit{
    private:
        // Logistics
        static int current_id;
        int id;
        std::string name;
        Stats stat_set;
        std::pair<int,int> position;
        Equipment equip_set;
    public:
        Unit();
};

class Character:Unit{
    private:
        int apotheosis_meter;
        Equipment equip_set;
    public:
        Character();
};
