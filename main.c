#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dungeonCrawler.h"

int main(int argc, char* argv[]){

		/* Variables */
    Character hero;
    Room *rooms;
    int roomNum, i;
    
    /* Time to rand */
    srand(time(0));
    
    /*  Initialize hero */
    hero.hitPoints = 150;
    hero.expPoints = 0;
    hero.damage = 10;
	hero.mana = 10;
	hero.energy = 10;
	hero.defense = 5;
	hero.sword = getSword(0);
	hero.armor = getArmor(0);

	/* Allocate and fill rooms */
	roomNum = 50;
    rooms = (Room*)malloc(sizeof(Room) * roomNum);
	fillRooms(rooms , roomNum);

	/* Game start */
	prompt(0);
	printCharacter(hero);

	/* GAME LOOP */
	for(i=0;i<roomNum;i++){
		
		if(rooms[i].type == BOSS){
			printf("\nBoss Room");
		}

		printf("\n-----Floor %d of %d-----\n",i+1, roomNum);

		/* Fountain */
		if(rooms[i].type == FOUNTAIN){

			prompt(2);
			printf("\nHero has been restored\n");

			hero.damage = hero.damage + 2;
			hero.defense = hero.defense + 2;
			hero.hitPoints = 150;
			hero.energy = 10;
			hero.mana = 10;

		/* Grotto */
		} else if(rooms[i].type == GROTTO){

			prompt(2);

			int prizeType = getRandNum(1,2);
			int choice = 0;
			int scale = 0;
			int low = 1;

			/* Scale prizes to level */
			if(i < 10){
				scale = 3;
			} else if(i < 20){
				scale = 5;
			} else if(i < 30){
				low = 2;
				scale = 7;
			} else if(i < 40){
				low = 3;
				scale = 9;
			} else{
				low = 4;
				scale = 11;
			}
			choice = getRandNum(low, scale);

			/* Sword */
			if(prizeType == 1){
				Sword s = getSword(choice);
				if(s.damage > hero.sword.damage){
					hero.sword = s;
					printf("\nYou have found the %s\n", s.name);
				} else{
					printf("\nNothing of value was found...\n");
				}

			/* Armor */
			} else{
				Armor a = getArmor(choice);
				if(a.defense > hero.armor.defense){
					hero.armor = a;
					printf("\nYou have found %s\n", a.name);
				} else{
					printf("\nNothing of value was found...\n");
				}
			}

		/* Fight */
		} else if(rooms[i].type == MONSTER || rooms[i].type == BOSS){

			enterRoom(rooms[i], &hero);
		} 

		/* Dies */
		if(hero.hitPoints <= 0){
			break;
		}

		if(rooms[i].type == BOSS){
			
			printBoss(i+1);
		
		}

		printf("\n");
		printCharacter(hero);
	}

	if(hero.hitPoints <= 0){
		printf("\n\n\nFATALITY\n");
	}



	/* Deallocate */
	free(rooms);
}