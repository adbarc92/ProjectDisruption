#pragma once
#include <string>
#include <vector>
#include "Stats.h"

class Equipment{
    private:
        static std::vector<Equipment*> compendium;
        static int current_id;
        int id;
        int slot_number;
        std::string name;
        std::string tooltip;
        Stats modifiers;
        int defense;
        bool is_device;
    public:
        Equipment(std::string _name, std::string _tooltip, int _con, int _str, int _dex, int _res, int _agl, int _slot_number, int _def);
        // Debugging
        void print_equipment_piece();
        void print_all_equipment();
};