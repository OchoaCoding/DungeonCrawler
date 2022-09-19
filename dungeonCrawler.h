#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

typedef enum TYPE {FOUNTAIN, GROTTO, MONSTER, BOSS} TYPE;

typedef struct Monster{
	char name[50];
	int hitPoints;
	int expPoints;
	int damage;
	int defense;
}Monster;

typedef struct Sword{
	char name[50];
	int damage;
	int special;
}Sword;

typedef struct Armor{
	char name[50];
	int defense;
	int health;
}Armor;

typedef struct Prize{
	int points;
}Prize;

typedef struct Room{
	TYPE type;
	Monster monster;
	Prize prize;
}Room;

typedef struct Character{
	int hitPoints;
	int expPoints;
    int damage;
	int energy;
	int mana;
	int defense;
	Sword sword;
	Armor armor;
}Character;

const char* getBoss(int i);
const char* getName();
int getRandNum(int min, int max);
void fillRooms(Room* rooms, int len);
void prompt(int p);
void damageReport(int type, int dmg);
void printBoss(int i);
void magicReport(int magic, int dmg);
void specialReport(int dmg, Sword s);
Sword getSword(int i);
Armor getArmor(int i);
void enterRoom(Room room, Character *player);
void printCharacter(Character c);

#endif

