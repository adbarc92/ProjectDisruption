// Next Exercise: Implement string switches

#include <iostream>

#include <string>

class primeStats{
  private:
  int size = 5;
  int con, str, dex, res, agl;
  public:
  primeStats(int _con,int _str,int _dex,int _res,int _agl): con(_con), str(_str), dex(_dex), res(_res), agl(_agl){};
  primeStats(): con(0), str(0), dex(0), res(0), agl(0){};
  int &operator[](int);
  int &operator[](std::string);
};

int &primeStats::operator[](int index){
  if(index >= size){
    std::cout << "Index is out of bounds, exiting" << std::endl;
    exit(0);
  }
  switch(index){
    case 0:
      return con;
    case 1:
      return str;
    case 2:
      return dex;
    case 3:
      return res;
    case 4:
      return agl;
  }
  exit(0);
}

int &primeStats::operator[](std::string index){
  if(index == "con"){
    return con;
  }
  else if(index == "str"){
    return str;
  }
  else if(index == "dex"){
    return dex;
  }
  else if(index == "res"){
    return res;
  }
  else if(index == "agl"){
    return agl;
  }
  else{
    std::cout << "Invalid index" << std::endl;
    exit(0);
  }
}

struct equipmentPiece{
    std::string name;
    primeStats modifiers;
    int id;
    static int currentID;
    std::string description;
    equipmentPiece(std::string, std::string);
    void setMods(int,int,int,int,int);
    void printEquipmentPiece();
};

equipmentPiece::equipmentPiece(std::string _name = "Nameless", std::string _desc = "Words are insufficient"){
  name = _name;
  description = _desc;
  id = currentID++;
}

void equipmentPiece::setMods(int _con, int _str, int _dex, int _res, int _agl){
  modifiers["con"] = _con;
  modifiers["str"] = _str;
  modifiers["dex"] = _dex;
  modifiers["res"] = _res;
  modifiers["agl"] = _agl;
}

void equipmentPiece::printEquipmentPiece(){
  std::cout << "Name: " << name << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "ID: " << id << std::endl;
  std::cout << "Constitution: " << modifiers[0] << std::endl;
  std::cout << "Strength: " << modifiers[1] << std::endl;
  std::cout << "Dexterity: " << modifiers[2] << std::endl;
  std::cout << "Resonance: " << modifiers[3] << std::endl;
  std::cout << "Agility: " << modifiers[4] << std::endl;
  
}

int equipmentPiece::currentID = 0;

struct helmet:equipmentPiece{
  std::string type = "helm";
  int slotNum = 1;
};

struct chestpiece:equipmentPiece{
  std::string type = "chest";
  int slotNum = 2;
};

struct gloves:equipmentPiece{
  std::string type = "hands";
  int slotNum = 3;
};

struct pants:equipmentPiece{
  std::string type = "legs";
  int slotNum = 4;
};

struct boots:equipmentPiece{
  std::string type = "feet";
  int slotNum = 5;
};

struct accessory:equipmentPiece{
  std::string type = "ring";
  int slotNum = 6;
};


int main(){
  helmet helm;
  helm.printEquipmentPiece();
  helm.setMods(1,2,5,6,9);
  helm.printEquipmentPiece();
}
