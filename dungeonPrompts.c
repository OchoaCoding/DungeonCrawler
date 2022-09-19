#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dungeonCrawler.h"

void prompt(int p){

	int i = getRandNum(1,10);

	/* Start */
	if(p == 0){
		printf("\nYou see the outline of the moontowers against the setting crimson sun. Not much longer now.\n");
		printf("You approach the menacing castle and shove the large obsidian black doors open\n50 floors remain...\n");

	/* Entry */
	} else if(p == 1){
		if(i == 1){
			printf("\nAfter a short stroll you enter the next room.\n");
		} else if(i == 2){
			printf("\nA glimmer catches your eye. You pass two stone columns as your boots squeak against the marble \nfloor beneath you. As you approach the metal brazier...\n");
		} else if(i == 3){
			printf("\nThe dazzling staircase catches your attention. Black marbles laced with flakes of gold, you go\nto inspect the exquisite architecture when you hear a screech upstairs...\n");
		} else if(i == 4){
			printf("\nNothing looks particularly important here. You continue on...\n");
		} else if(i == 5){
			printf("\n\"Such a marvelous room, how was it built this far out?\" you wonder. You approach the tall \nwindows to catch a glimpse of outside. The stars twinkle as you assure yourself,\n");
			printf("tonight is the night. You start to turn around when...\n");
		} else if(i == 6){
			printf("\nYou approach a long hallway. Pearl white pristine doors line as far as you can see in contrast \nto the black marble floors. As you go for the first door you hear a screech above...\n");
		} else if(i == 7){
			printf("\nYou enter a grand ballroom. The aroma of the delicious feast fills you nostrils. A dozen hundred \nseated tables are lined with perfectly set utensils. You go in for a bite when...\n");
		} else if(i == 8){
			printf("\nYou approach an elegent statue, and inspect the detail in the fine eloquently sculpted stone.\nAs you touch the stone it becomes alive...\n");
		} else if(i == 9){
			printf("\nThe temperature around you suddenly falls sharply. The cool air travels down your back as you\nreach for your sword. You try to turn but are shoved to the floor...\n");
		} else if(i == 10){
			printf("\nYou walk through the archway into a huge white marble square room. Your challenger awaits...\n");
		}
	/* Fountain / Grotto */
	} else if(p == 2){
		if((i % 5) == 0){
			printf("\nYou stumble into a dazzling room...\n");
		} else if((i % 5) == 1){
			printf("\nWhat's that up ahead? You see a shimmer in the distance...\n");
		} else if((i % 5) == 2){
			printf("\nYou enter an eloboratly designed chamber. A sea of gold and treasures as far as can be seen...\n");
		} else if((i % 5) == 3){
			printf("\nYou're lost, in a loss for options you search door by door...\n");
		}else if((i % 5) == 4){
			printf("\nYou see the staircase to the next room, next to it a gift. It has a message \"A gift from me\nto your doomed soul, you will never return to your world...\"\n");
		}
	/* Start Attack */
	} else if(p == 3){
		if(i == 1){
			printf("\nThe hero lunges in for an attack.\n");
		} else if(i == 2){
			printf("\nLike lightning the hero phase shifts behind it.\n");
		} else if(i == 3){
			printf("\nThe monster swings sending chunks of granite into the air as it smashes the ground.\nThe hero jumps back, finding a ledge as leverage and zooms in.\n");
		} else if(i == 4){
			printf("\nLike a sixth sense you can feel something watching you. It attacks from your blind, exactly as expected.\n");
		} else if(i == 5){
			printf("\nThe monster charges you and swings for your face. You dodge with a roll to the side, jumping and using the back wall to propel yourself forward.\n");
		} else if(i == 6){
			printf("\nYou charge forward at the beast, nothing can stop your onslaught.\n");
		} else if(i == 7){
			printf("\nYou run around, using a large italian stone column to block the monsters view of you.\nYou gather your energy and blow through both objects.\n");
		} else if(i == 8){
			printf("\nThe monster waits eyeing you. It wants to see what you will do. With a quick breath you\nvanish. At the speed of light you approach your attacker.\n");
		} else if(i == 9){
			printf("\nYou roll then dodge then roll again, the monster won't let up. You wait, bidding your\ntime for the perfect oppurtunity. In an instant you see it.\n");
		} else if(i == 10){
			printf("\nThe monster mocks you, it laughs at your puny mortol soul. It taunts you to attack.\n");
		}
	/* Dodge */
	} else if(p == 4){
		if((i % 3) == 0){
			printf("\nThe monster fires energy blasts at you as you phase shift away.\n");
		} else if((i % 3) == 1){
			printf("\nThe monster strikes, but you dematerialize yourself before it can hit you. The monster flies\nthrow you and crashes against a wall.\n");
		} else if((i % 3) == 2){
			printf("\nYou catch the attack.\n");
		}
	}

}

void damageReport(int type, int dmg){

	int i = getRandNum(1, 7);
	if(type == 1){
		if(i == 1){
			printf("\nYou gut the bastard dealing %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nYou thrust your sword forward, turning it into a blazing spear dealing %d damage.\n", dmg);
		} else if(i == 3){
			printf("\nYou slash for %d damage.\n", dmg);
		} else if(i == 4){
			printf("\nYou throw your sword into the creature dealing %d damage.\n", dmg);
		} else if(i == 5){
			printf("\nYou offend the monster for %d damage.\n", dmg);
		} else if(i == 6){
			printf("\nYou teleport behind the creature and go for the head. %d damage dealt.\n", dmg);
		} else if(i == 7){
			printf("\nYou cut the monster for %d damage.\n", dmg);
		}
	} else if(type == 2){
		if(i == 1){
			printf("\nThe monster swats you into a wall for %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nThe monster moves too quick. Instantly youre hit in the chest and fly through a massive\ncolumn. %d damage taken.\n", dmg);
		} else if(i == 3){
			printf("\nYou try to dodge but the monster clips your leg. You get repeatedly slammed into the\nground. %d damage taken.\n", dmg);
		} else if(i == 4){
			printf("\nYou leap at the monster thrusting with your sword. The monster dodges then blindsides\nyou for %d damage.\n", dmg);
		} else if(i == 5){
			printf("\nThe monster explodes. You take %d damage.\n", dmg);
		} else if(i == 6){
			printf("\nYou try to dodge the monsters attack. It's to fast, you get impaled through the chest. %d damage\ntaken.\n", dmg);
		} else if(i == 7){
			printf("You dash towards the monster. Feeling a dark force pulling at your mind you stop. The monster slashes. %d damage taken.\n", dmg);
		}
	}
}

void magicReport(int magic, int dmg){

	int i = getRandNum(1, 5);

	/* Fire */
	if(magic == 1){
		if(i == 1){
			printf("\nYou send a blazing fireball toward the monster dealing %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nYou torch the room for %d damage.\n", dmg);
		} else if(i == 3){
			printf("\nYou incinerate the monster for %d damage. burning embers fall from the ceiling.\n", dmg);
		} else if(i == 4){
			printf("\nYou unleash a massive fireball. This deals %d damage.\n", dmg);
		} else if(i == 5){
			printf("\nYou let out a mighty blaze. %d damage dealt.\n", dmg);
		}
	/* Ice */
	} else if(magic == 2){
		if(i == 1){
			printf("\nThe room goes cold. You send a blizzard at the monster for %d damage\n", dmg);
		} else if(i == 2){
			printf("\nYour hands freeze and you release ice shards forward dealing %d damage\n", dmg);
		} else if(i == 3){
			printf("\nIcicles fire from you fingertips for %d damage\n", dmg);
		} else if(i == 4){
			printf("\nYou start to freeze the room as ice shoots from your hand. %d damage dealt.\n", dmg);
		} else if(i == 5){
			printf("\nYou gather the cold within you, then force it at the monster. %d damage dealt.\n", dmg);
		}
	/* Electric */
	} else if(magic == 3){
		if(i == 1){
			printf("\nThe air vaporizes around you as lightning strikes the monster for %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nPurple lightning flies from your hands, the think purple fills the entire room. You dealt\n%d damage. The room looks seared from all angles\n", dmg);
		} else if(i == 3){
			printf("\nLighting shoots from your hands, bouncing off walls until it meets its target dealing %d damage.\n", dmg);
		} else if(i == 4){
			printf("\nYou slam both wrists together, channeling a continious beam of electricity dealing %d damage.\n", dmg);
		} else if(i == 5){
			printf("\nElectric beams shoot from you eyes for %d damage.\n", dmg);
		}
	/* Dark */
	} else if(magic == 4){
		if(i == 1){
			printf("\nDark mist begins pouring from you eyes as they fade to black. Shadows shoot sucking the creature\nin. %d damage dealt.\n", dmg);
		} else if(i == 2){
			printf("\nA spacial rift forms in your hand. As you enforce it with your dark energy it grows, feeding on\nmatter. You throw it at the monster for %d damage.\n", dmg);
		} else if(i == 3){
			printf("\nDark flames burn from your hand as you run it across your blade drawing blood. With a quick slash\nreality collapses dealing %d damage.\n", dmg);
		} else if(i == 4){
			printf("\nThe demon inside you takes over. It meets the creature in battle. %d damage was dealt.\n", dmg);
		} else if(i == 5){
			printf("\nYou pull the power from the demonic dragon soul bonded to you. In an instant darkness falls over\nthe creature. %d damage dealt.\n", dmg);
		}
	/* Light */
	} else if(magic == 5){
		if(i == 1){
			printf("\nYou pull a meteor from orbit. It collides with this plane of existance for %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nYou lift your right hand up in the air. As you swing it down forward, a beam of light shoots\nfrom the sky through the monster dealing %d damage.\n", dmg);
		} else if(i == 3){
			printf("\nYour body turns to light. In an instant, Supernova. Everything around you takes %d damage.\n", dmg);
		} else if(i == 4){
			printf("\nGolden beams of light shoot from your eyes, deleting everything it touches. The monster took\n%d damage.\n", dmg);
		} else if(i == 5){
			printf("\nYou start to levitate, with divine justice running through you your body turns to light. \"perish\"\nyou utter as everything goes white. You dealt %d damage\n", dmg);
		}
	}
}

void specialReport(int dmg, Sword s){

	int i = getRandNum(1,3);

	/* Splinter */
	if(strcmp(s.name, "Wooden Sword") == 0){
		if(i == 1){
			printf("\nYou hold your wooden sword firmly in your hands. You rush foward and unleash your splinter\nfor %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nYou rush foward throwing your wooden sword at the monster to splinter for %d damage.\n", dmg);
		} else if(i == 3){
			printf("\nThe monster swings for you. With a swipe of the wooden sword you splinter the monster for %d damage.\n", dmg);
		}
	/* Prick */
	} else if(strcmp(s.name, "Rusty Sword") == 0){
		if(i == 1){
			printf("\nYou use your rusty sword to prick the monster for %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nWith a quick foward rush you out speed the monster. You prick your rusty sword through its neck\nfor %d damage.\n", dmg);
		} else if(i == 3){
			printf("\nYou throw your rusty sword and prick the monster dealing %d damage.\n", dmg);
		}
	/* Cleave */
	} else if(strcmp(s.name, "Iron Sword") == 0){
		if(i == 1){
			printf("\nYou use your iron sword to cleave the monster for %d damage\n", dmg);
		} else if(i == 2){
			printf("\nThe monster lunges at you. You dodge back then spin and cleave the monster for %d damage.\n", dmg);
		} else if(i == 3){
			printf("\nYou flash forward, instantly you cleave the monster for %d damage.\n", dmg);
		}
	/* Cresendo */
	} else if(strcmp(s.name, "Gold Sword") == 0){
		if(i == 1){
			printf("\nYou grip your gold sword. As the monster lunges at you you pick your sword up, cresendo.\nThe monster took %d damage", dmg);
		} else if(i == 2){
			printf("\nYou slash with your golden sword, cresendo. The monster took %d damage.\n", dmg);
		} else if(i ==3){
			printf("\nYou teleport beneath the monster and go for the jugular, cresendo. The monster took %d damage.\n", dmg);
		}
	/* Gorge */
	} else if (strcmp(s.name, "Glass Sword") == 0){
		if(i == 1){
			printf("\nYou thrust your glass sword forward and gorge the monster for %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nThe monster tries to attack but you dodge to the side, jumping forward you gorge for %d damage.\n", dmg);
		} else if(i == 3){
			printf("\nYou flash forward, instantly you gorge the monster for %d damage.\n", dmg);
		}
	/* Lacerate */
	} else if(strcmp(s.name, "Obsidian Sword") == 0){
		if(i == 1){
			printf("\nYou flash forward, instantly you lacerate the monster for %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nYou lacerate with your obsidian sword. The monster took %d damage.\n", dmg);
		} else if(i ==3){
			printf("\nThe monster lunges at you. You dodge back then spin and lacerate the monster for %d damage.\n", dmg);
		}
	/* Decimate */
	} else if(strcmp(s.name, "Executioner") == 0){
		if(i == 1){
			printf("\nYou rush foward throwing your executioner sword to decimate the monster for %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nYou decimate with your executioner sword. The monster took %d damage.\n", dmg);
		} else if(i ==3){
			printf("\nYou flash forward, instantly you decimate the monster for %d damage.\n", dmg);
		}
	/* Dimensional Slash */
	} else if(strcmp(s.name, "Infinity Blade") == 0){
		if(i == 1){
			printf("\nYou hold your infinity blade to the skies, as a beam of light strikes the tip. You slash causing a rip in the\ndimension for %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nYou slash the dimension with your infinity blade for %d damage.\n", dmg);
		} else if(i ==3){
			printf("\nIn a swift slash the dimension tears, ripping the monster fo %d damage.\n", dmg);
		}
	/* Universal Rift */
	} else if(strcmp(s.name,"Cosmic Slasher") == 0){
		if(i == 1){
			printf("\nStriking an X into the monster, the universe implodes for %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nYou hold you cosmic slasher tight. With a quick slash a rift in the universe appears causing shockwaves for %d damage.\n", dmg);
		} else if(i ==3){
			printf("\nYou slash, causing the universe to dematerialize rapidly causing a rift dealing %d damage.\n", dmg);
		}
	/* Super Nova */
	} else if(strcmp(s.name,"The Sword of a Thousand Exploding Suns") == 0){
		if(i == 1){
			printf("\nYou slash with your sword of a thousand exploding suns, Super Nova. The monster took %d damage.\n", dmg);
		} else if(i == 2){
			printf("\nYour sword heats up rapidly, changing colors as it does. Red, Orange, Yellow, White, Blue. The sword beaming with\nso much intensity causes the room to flash blue and white.\n");
			printf("In an instant you strike the monster, Super Nova. %d damage dealt.\n", dmg);
		} else if(i ==3){
			printf("\nYou grip your sword as you feel the heat of all the stars trapped inside. You slash the air infront of you,\nSuper Nova. %d damage dealt.", dmg);
		}
	/* Divine Justice */
	} else if(strcmp(s.name, "Light Bringer") == 0){
		if(i == 1){
			printf("\nYour sword turns a bright white as your eyes turn gold, and you start to ascend. You glance down with empathy,\nnothing can stop you now. You strike with divine justice. %d damage dealt.", dmg);
		} else if(i == 2){
			printf("\nYour sword burns white in its holster. The cosmic energy pulsates through you as you unsheathe its power unleashing divine justice for %d damage.\n", dmg);
		} else if(i == 3){
			printf("\nYou gather all your divine energy into a singular point and explode causing %d damage.\n", dmg);
		}
	}
}

void printBoss(int i){

	if(i == 10){
		printf("\n\n\n\nThere once was a story told around caverns across the lands, one day a hero would return. A hero from a land\n");
		printf("to the north would once again push back the forces of Markerth and the people of the land would forever sing his\n");
		printf("name.\n\n\n\n");
	} else if(i == 20){
		printf("\n\n\n\nThe land was in peril, all the kingdoms of man we're being broken like sticks under a giant beast. Markerth's\n");
		printf("unstoppable onslaught have left the remaining questioning if this is the end\n\n\n\n");
	} else if(i == 25){
		printf("\n\n\n\nYou remeber the feeling of the heat inside your burning house like it just happened. Markerth's minions swarming\n");
		printf("the tiny village. Roofs and houses collapse as you hear the screams coming from those getting slaughtered. You\n");
		printf("grab your lover and hold them tight, as long as you two are together everything feels like it will be ok. A large\n");
		printf("thud comes from the door before the crash it makes as it hits the ground. Three large figures enter. In an instant\n");
		printf("you're thrown to the ground, before a large club smashes and breaks your kneecap. Immobile, you can't do anything\n");
		printf("As they rush your lover, grabbing her by the throat with a wicked grin across its face. \"Noooooo\" you scream as you\n");
		printf("are unable to think of anything else to muster. Is this what you want the monster asks repeatedly dancing in circles.\n");
		printf("Enjoy this the monster utters as it shoves its hand through her chest and rips her beating heart out. Her body\n");
		printf("goes limp as the minion drops her corpse to the ground. \"Your fear enlightens me\" the monster spits out before it eats\n");
		printf("her heart. Suddenly you see a range of snowy mountain tops, your back at Shenagova palace the day it was attacked. As the\n");
		printf("last users of hidden ki, mankind deamed the monks a danger to the people and had them all executed, or what they thought\n");
		printf("Was all of them. Moments before the raid entered the walls, you remeber the last words Master Shifu told you before sending\n");
		printf("The sole survivor down a hidden escape. \"Mankind knows not what they are doing, the meaning of true power is to protect\n");
		printf("those unable to protect themselves. There is a darkness brewing, one that can not be seen, and someone must be there to\n");
		printf("stop it. You flash back to the raid on your village, as the pain rushes your body and you take one last look at your lover.\n");
		printf("You call the light and a beam comes from the heavens empowering you.\n\n\n\n");
	} else if(i == 30){
		printf("\n\n\n\nLike a seed the hero grew, into something Markerth could no longer dismiss. The hero gathered all the forces of man\n");
		printf("and fought Markerth back eventually defeating him to become a legend\n\n\n\n");
	} else if(i == 40){
		printf("\n\n\n\nThe land is once again in peril, all the kingdoms in the south and west from the bushworks to the iron coast have\n");
		printf("formed a union in a last ditch effort to stop Markerth's advance. All the kingdoms that formed the west now lay in\n");
		printf("ruin as the people to the north starve. The central kingdoms takes the assult, with village after village being\n");
		printf("setup in flames. You remeber the feeling as your family was slain. The look on your brothers face as his eyes popped\n");
		printf("out of his head from a monsters hand squeeze. Minions were storming castle Venmonth as your father rushed with gaurds\n");
		printf("to defend the throne room. The kings defense held no match for the attack. You, the sole survivor changed that union\n");
		printf("into the force it needed to be. You with the latent power still in your blood from the legend king of old, was the\n");
		printf("spark humanity once again needed. Pushing back Marketh's forces you reach the final fortress.\n\n\n\n");
	} else if(i == 45){
		printf("\n\"Why then?, why has this evil returned? The first king who established the new golden age already won and defeated\n");
		printf("Markerth long ago. So who is this?\"\n");
		//necro fallen hero
	} else if(i == 50){
		printf("\n\n\n\n\"You fool, you know not what you do, I have been keeping the darkness back all this time. When I defeated Markerth\n");
		printf("the power consumed me as the new strongest being it possesd. Long ago an ancient dark force \"Ruin\" was formed, this\n");
		printf("Omnipotent being is as old as time itself. It sent down some of its energy to wreak havok on our planet. It controls\n");
		printf("My mind and my actions. In my subconscious I was starting to build a strength to maybe use the forces of Markerth to\n");
		printf("defeat ruin and save mankind. But no the power flows to you\" Markerth/The Legend hero utters with his dying\n");
		printf("breath. Just then streakes of light shine from the dead body to you as your mind is ripped from your possesion. You\n");
		printf("Hear a voice \"In time you will be ready\"\n\nThe cycle continues.....\n");
		// new necro / cycle continues
	}
}

const char* getName(){
	char *name = malloc(sizeof(char)* 20);
	int i = getRandNum(1, 12);

	if(i==0){
		strcpy(name,"Spider");
	} else if(i==1){
		strcpy(name,"Zombie");
	} else if(i==2){
		strcpy(name,"Skeleton");
	} else if(i==3){
		strcpy(name,"Druid");
	} else if(i==4){
		strcpy(name,"Android");
	} else if(i==5){
		strcpy(name,"Titan");
	} else if(i==6){
		strcpy(name,"Ghost");
	} else if(i==7){
		strcpy(name,"Ghoul");
	} else if(i==8){
		strcpy(name,"Demon");
	} else if(i==9){
		strcpy(name,"Wyvern");
	} else if(i==10){
		strcpy(name,"Blaze");
	} else if(i==11){
		strcpy(name,"Pheonix");
	} else if(i==12){
		strcpy(name,"Cyborg");
	}
	return name;
}

const char* getBoss(int i){
	char *name = malloc(sizeof(char)*25);

	if(i==9){
		strcpy(name,"Cyclops");
	} else if(i==19){
		strcpy(name,"Minataur");
	} else if(i==24){
		strcpy(name,"Phil");
	} else if(i==29){
		strcpy(name,"Elder Dragon");
	} else if(i==39){
		strcpy(name,"Hydra");
	} else if(i==44){
		strcpy(name,"Colossus");
	} else if(i==49){
		strcpy(name,"Ancient Necromancer");
	}
	return name;
}