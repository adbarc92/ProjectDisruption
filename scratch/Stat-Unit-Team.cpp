#include <iostream>
#include <vector>
#include <string>

// Changes:
	// All units' ids are consolidated in a hash table for easy access

// Primary Stats
struct pStats{
	
	int CON, STR, DEX, RES, AGL;
	// Constructors
	pStats(int _CON, int _STR, int _DEX, int _RES, int _AGL):CON(_CON), STR(_STR), DEX(_DEX), RES(_RES), AGL(_AGL){};
	pStats(int arr[]): CON(arr[0]), STR(arr[1]), DEX(arr[2]), RES(arr[3]), AGL(arr[4]){};
	// pStats(int = 10,int = 10,int = 10,int = 10,int = 10);
};

// Secondary Stats
struct sStats{
	int hitPoints, exCap, physDmg, critDmg, critRate, acc, exDef, exRec, init, eva;
	sStats(int CON, int STR, int DEX, int RES, int AGL){
		hitPoints = int(CON*4);
		exCap = int(CON*2);
		physDmg = int(STR*1.25);
		critDmg = float(STR*8);
		critRate = float(DEX*8);
		acc = float(DEX*10);
		exDef = int(RES*5);
		exRec = int(RES*5);
		init = int(AGL*3);
		eva = float(AGL*8);
	}
};

struct Unit{
	std::string name;
	int id;
	pStats s1;
	sStats s2;
	Unit(std::string name, int arr[]): name(name), s1(arr), s2(s1.CON, s1.STR, s1.DEX, s1.RES, s1.AGL){}
	// Overload "==" to compare string to Unit?
};

struct Team{
	bool pc = false;
	std::vector<Unit*> members; // Pointers?
	void addMember(Unit* a){
		members.push_back(a);
	}
	void removeMember(std::string name){
		int len = members.size();
		for(int i = 0; i < len; i++){
			if(name == members[i]->name){
				members.erase(members.begin()+i);
			}
		}
	}
};

// struct Battle{
// 	int field[3][7];
// 	// std::vector
// };

int mainMenu(){
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "Press \'1\' to Fight" << std::endl;
	std::cout << "Press \'2\' to Quit" << std::endl;
	int input = 0;
	std::cin >> input;
	return input;
}

int main(){
	bool mainLoop = true;
	while(mainLoop){
		int input = mainMenu();
		if(input == '2'){
			mainLoop = false;
			return 0;
		}		
	}
}