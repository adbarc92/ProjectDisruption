#pragma once
#include <string>
#include "Stats.h"

struct Equipment
{
    int slot_number;
    std::string name;
    std::string description;
    Stats equip_stats;
    Equipment(std::string name, std::string description, int _con, int _str, int _dex, int _res, int _agl, int slot_num);
};

Equipment::Equipment(std::string _name, std::string _description, int _con, int _str, int _dex, int _res, int _agl, int slot_num){
    slot_number = slot_num;
    name = _name;
    description = _description;
    equip_stats = Stats(_con,_str,_dex,_res,_agl);
}

struct Head : Equipment
{
    Head(std::string _name, std::string _description, int _con, int _str, int _dex, int _res, int _agl): Equipment(_name, _description, _con, _str, _dex, _res, _agl, 1){};
};

struct Chest : Equipment
{
    Chest(std::string _name, std::string _description, int _con, int _str, int _dex, int _res, int _agl): Equipment(_name, _description, _con, _str, _dex, _res, _agl, 2){};
};

struct Hands : Equipment
{
    Hands(std::string _name, std::string _description, int _con, int _str, int _dex, int _res, int _agl): Equipment(_name, _description, _con, _str, _dex, _res, _agl, 3){};
};

struct Legs : Equipment
{
    Legs(std::string _name, std::string _description, int _con, int _str, int _dex, int _res, int _agl): Equipment(_name, _description, _con, _str, _dex, _res, _agl, 4){};
};

struct Feet : Equipment
{
    Feet(std::string _name, std::string _description, int _con, int _str, int _dex, int _res, int _agl): Equipment(_name, _description, _con, _str, _dex, _res, _agl, 5){};
};

struct Ring : Equipment
{
    Ring(std::string _name, std::string _description, int _con, int _str, int _dex, int _res, int _agl): Equipment(_name, _description, _con, _str, _dex, _res, _agl, 6){};
};

struct Amulet : Equipment
{
    Amulet(std::string _name, std::string _description, int _con, int _str, int _dex, int _res, int _agl): Equipment(_name, _description, _con, _str, _dex, _res, _agl, 7){};
};