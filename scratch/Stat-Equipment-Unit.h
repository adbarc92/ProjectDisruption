// #include <map>
#include <string>
#include <vector>

struct primary_stats{
  int constitution, strength, dexterity, resonance, agility;
  primary_stats(int = 10, int = 10, int = 10, int = 10, int = 10);
  primary_stats(int _CON, int _STR, int _DEX, int _RES, int _AGL): constitution(_CON), strength(_STR), dexterity(_DEX), resonance(_RES), agility(_AGL){};
};

struct derived_stats{
  int hitPoints, exCap, physDmg, exDmg, exDef, initiative;
  float critDmg, accuracy, critChance, evasion;
  derived_stats(int constitution, int strength, int dexterity, int resonance, int agility): hitPoints(constitution*5), exCap(constitution*3), physDmg(strength), critDmg(strength), accuracy(dexterity), critChance(dexterity),  exDmg(resonance), exDef(resonance), evasion(agility), initiative(agility){}
};

struct equipmentPiece{
  int slotNum; // Technical means to differentiate between slots
  std::string type; // Literal means to differentiate between slots
  std::string name; // Individual piece name
  int statMod[5]; // 
  std::string description = "";
  equipmentPiece(std::string _type, int _statMod[], std::string _name, std::string _description): type(_type), name(_name), description(_description) {}
};

struct equipmentSet{
  std::vector<equipmentPiece> set;
  equipmentSet(equipmentPiece helm,equipmentPiece chest,equipmentPiece gloves,equipmentPiece boots, equipmentPiece accessory){
    set.push_back(helm);
    set.push_back(chest);
    set.push_back(gloves);
    set.push_back(boots);
    set.push_back(accessory);
  }
};

class Unit{
  private:
    primary_stats p;
    derived_stats d;
  public:
    // createUnit
    Unit* createUnit(int con, int str, int dex, int res, int agl){
      this->p = primary_stats(con,str,dex,res,agl);
      this->d = derived_stats(con,str,dex,res,agl);
      return this;
    };
    // deleteUnit
};

class Character{
  private:
    primary_stats p;
    derived_stats d;
    equipmentSet e;
};