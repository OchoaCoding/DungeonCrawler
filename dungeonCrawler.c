#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dungeonCrawler.h"

/* Get rand num method */
int getRandNum(int min, int max){
	int num;
	num = (rand() % (max - min + 1)) + min;
	return num;
}

void fillRooms(Room* rooms, int length){
	int i, type;

	for(i=0;i<length;i++){
		
		/* Setup Bosses */
		if(i == 9 || i == 19 || i == 24 || i == 29 || i == 39 || i == 44 || i == 49){
			rooms[i].type = BOSS;
			
			int dmg = getRandNum(i, i + 5);
        	int hp = getRandNum(i + 5, (i * 5) + 5);
        	int deff = getRandNum(1, 12);
			rooms[i].monster.damage = dmg;
        	rooms[i].monster.hitPoints = hp;
        	rooms[i].monster.defense = deff;
			rooms[i].monster.expPoints = i;
			strcpy(rooms[i].monster.name, getBoss(i));
		} else{

			/*Setup other rooms */
			type = getRandNum(1, 18);

			if(type == 1 || type == 2){
				rooms[i].type = FOUNTAIN;
				int p = getRandNum(5, 15);
				rooms[i].prize.points = p;

			} else if(type > 2 && type <6){
				rooms[i].type = GROTTO;

			} else if(type >= 6){
				rooms[i].type = MONSTER;
				int hp = getRandNum(i+5, (i*4) + 10);
				int dmg = getRandNum(type, type + 5);
				int deff = getRandNum(1, 8);
				int exp = getRandNum(1, type);
				rooms[i].monster.hitPoints = hp;
				rooms[i].monster.damage = dmg;
				rooms[i].monster.expPoints = exp;
				rooms[i].monster.defense = deff;
				strcpy(rooms[i].monster.name, getName());
			}
		}

	} // for loop
}



void enterRoom(Room room, Character *player){

	//entry
	prompt(1);

	do{
		/* Variables */
		int play = 0;
		int dmg = 0;

		printf("\n%s     HP: %d XP: %d\n", room.monster.name, room.monster.hitPoints, room.monster.expPoints);
		
		/* Get Play */
		do{
			printf("\nWhat will you do?\n");
			printf("1) Attack\n2) Magic\n3) Special\n4) Dodge\n");
			scanf("%d", &play);
		}while(play < 0 || play > 4);

		/* Attacks */
		if(play == 1){

			prompt(3); // start attack

			dmg = (player->damage + player->sword.damage) - room.monster.defense;
			if(dmg <= 0){
				dmg = 1;
			}
			damageReport(1, dmg);
			room.monster.hitPoints = room.monster.hitPoints - dmg;

		/* Magic */
		} else if(play == 2){

			if(player->mana > 0){
				int magic = 0, round = 0;
				do{
					printf("\nMAGIC\n1 MP: Incinerate\n2 MP: Frost bite\n3 MP: Electroshock\n4 MP: Dark Phasma\n5 MP: Divine Light\n");
					scanf("%d", &magic);
				}while(magic < 0 || magic > 5);

				/* Incinerate */
				if(magic == 1 && player->mana > 0){
					dmg = (player->sword.damage * 5) - room.monster.defense;
					player->mana = player->mana - 1;
					round++;
				/* Frost bite */
				} else if(magic == 2 && player->mana > 1){
					dmg = (player->armor.defense * 5) - room.monster.defense;
					player->mana = player->mana - 2;
					round++;
				/* Electroshock */
				} else if(magic == 3 && player->mana > 2){
					dmg = (player->mana * 7) - room.monster.defense;
					player->mana = player->mana - 3;
					round++;
				/* Dark Phasma */
				} else if(magic == 4 && player->mana > 3){
					dmg = ((player->sword.damage * 4) + (player->armor.defense * 4)) - room.monster.defense;
					player->mana = player->mana - 4;
					round++;
				/* Divine Light */
				} else if(magic == 5 && player->mana > 4){
					dmg = (room.monster.hitPoints / 2);
					player->mana = player->mana - 5;
					round++;
				} else{
					printf("Not enough mana\n");	
				}

				/* Stops strong monsters */
				if(dmg <= 0){
					dmg = 1;
				}

				if(round > 0){
					magicReport(magic, dmg);
					room.monster.hitPoints = room.monster.hitPoints - dmg;
				}
			} else{
				printf("\nYou are out of mana\n");
			}

		/* Special */
		} else if(play == 3){

			if(player->energy > 0){
				
				dmg = ((player->damage + player->sword.damage) - room.monster.defense) * 2;
				if(dmg <= 0){
					dmg = 1;
				}
				player->energy = player->energy - 2;
				
			} else{
				printf("\nYou are out of energy\n");
			}

			//print fight
			specialReport(dmg, player->sword); 
			room.monster.hitPoints = room.monster.hitPoints - dmg;

		/* Dodge */
		} else if(play == 4){
			prompt(4);
			continue;
		}


		/* Damage */
		if(room.monster.hitPoints > 0){
			/* Attack / Magic */
			if(play == 1 || play == 2){
				dmg = room.monster.damage - (player->defense + player->armor.defense);
				if(dmg < 2){
					dmg = 2;
				}
				damageReport(2, dmg);
				player->hitPoints = player->hitPoints - dmg;
			/* Special */
			} else if(play == 3){
				dmg = room.monster.damage - player->defense;
				if(dmg < 5){
					dmg = 5;
				}
				damageReport(2, dmg);
				player->hitPoints = player->hitPoints - dmg;
			} else if(play == 4){
				room.monster.defense = room.monster.defense - 1;
				room.monster.damage = room.monster.damage - 1;
			}
		}

	}while(room.monster.hitPoints > 0 && player->hitPoints > 0);

}

Armor getArmor(int i){
	Armor armor;

	if(i==0){
		strcpy(armor.name,"Dirty Rags");
		armor.health = 0;
		armor.defense = 0;
	} else if(i==1){
		strcpy(armor.name,"Fur Robes");
		armor.defense = 3;
		armor.health = 0;
	} else if(i==2){
		strcpy(armor.name,"Ironclad Armor");
		armor.defense = 5;
		armor.health = 0;
	} else if(i==3){
		strcpy(armor.name,"Golden Armor");
		armor.defense = 8;
		armor.health = 1;
	} else if(i==4){
		strcpy(armor.name,"Ancient Dwemer Armor");
		armor.defense = 10;
		armor.health = 3;
	} else if(i==5){
		strcpy(armor.name,"Dragonbone Armor");
		armor.defense = 12;
		armor.health = 5;
	} else if(i==6){
		strcpy(armor.name,"Bloodmist Armor");
		armor.defense = 13;
		armor.health = 15;
	} else if(i==7){
		strcpy(armor.name,"Conqueror Armor");
		armor.defense = 15;
		armor.health = 8;
	} else if(i==8){
		strcpy(armor.name,"Mythic Dusk Armor");
		armor.defense = 16;
		armor.health = 10;
	} else if(i==9){
		strcpy(armor.name,"Sunforged Armor");
		armor.defense = 18;
		armor.health = 12;
	} else if(i==10){
		strcpy(armor.name,"Divine Cosmic Armor");
		armor.defense = 20;
		armor.health = 15;
	} 
	return armor;
}

Sword getSword(int i){
	Sword sword;

	if(i==0){
		strcpy(sword.name,"Wooden Sword");
		sword.damage = 1;
		sword.special = 1;
	} else if(i==1){
		strcpy(sword.name,"Rusty Sword");
		sword.damage = 2;
		sword.special = 2;
	} else if(i==2){
		strcpy(sword.name,"Iron Sword");
		sword.damage = 4;
		sword.special = 3;
	} else if(i==3){
		strcpy(sword.name,"Gold Sword");
		sword.damage = 6;
		sword.special = 4;
	} else if(i==4){
		strcpy(sword.name,"Glass Sword");
		sword.damage = 7;
		sword.special = 5;
	} else if(i==5){
		strcpy(sword.name,"Obsidian Sword");
		sword.damage = 9;
		sword.special = 6;
	} else if(i==6){
		strcpy(sword.name,"Executioner");
		sword.damage = 10;
		sword.special = 7;
	} else if(i==7){
		strcpy(sword.name,"Infinity Blade");
		sword.damage = 12;
		sword.special = 8;
	} else if(i==8){
		strcpy(sword.name,"Cosmic Slasher");
		sword.damage = 14;
		sword.special = 9;
	} else if(i==9){
		strcpy(sword.name,"The Sword of a Thousand Exploding Suns");
		sword.damage = 15;
		sword.special = 10;
	} else if(i==10){
		strcpy(sword.name,"Light Bringer");
		sword.damage = 20;
		sword.special = 11;
	}
	return sword;
}

	
void printCharacter(Character h){
    printf("\nChampion (HP: %d +%d DMG: %d +%d MANA: %d ENERGY: %d XP: %d)\n", h.hitPoints, h.armor.health, h.damage, h.sword.damage, h.mana, h.energy, h.expPoints);
    printf("Weapon (%s : DMG: +%d)\n", h.sword.name, h.sword.damage);
    printf("Armor (%s : AMR: %d HP: +%d)\n", h.armor.name, h.armor.defense, h.armor.health);
}

