#pragma once
#include <vector>
#include "Technique.h"
#include "Stats.h"
#include "Equipment.h"

class Unit{
    private:
        int id;
        std::string name;
        static int current_id;
        Stats stat_set;
        std::pair<int,int> position;
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
