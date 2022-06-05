#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "display.h"
#include "game.h"

void game(player *player1, player *player2)
{
	int i,indice1,indice2,test;

	do
	{
		display_team(*player1);
		display_team(*player2);
		for (i=0;i<size_team;i++)
		{
			player1->team[i].energy += player1->team[i].speed;
			player2->team[i].energy += player2->team[i].speed;
		}
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to use ?",player1->name);
			scanf("%d",&indice1);
				if (player1->team[indice1].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to attack ?",player1->name);
			scanf("%d",&indice2);
			if (player2->team[indice2].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			if (player1->team[indice1].energy >= 100)
			{
				printf("\n******special attack**********\n");
				special_attack(player1,player2,indice1,indice2);
				player1->team[i].energy = 0;
			}
			else {printf("\n/******classic attack**********/\n");
			common_attack(player1,player2,indice1,indice2);
			}
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to use ?",player2->name);
			scanf("%d",&indice1);
				if (player2->team[indice1].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to attack ?",player2->name);
			scanf("%d",&indice2);
			if (player1->team[indice2].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			if (player2->team[indice1].energy >= 100)
			{
			printf("\n******special attack**********\n");
			special_attack(player2,player1,indice1,indice2);
			player1->team[i].energy = 0;
			}
			else {printf("\n/******classic attack**********/\n");
			common_attack(player2,player1,indice1,indice2);}
	// Test if fighters of player 1 and 2 are KO
	test_defeat(player1);
	test_defeat (player2);
	} while (player1->defeated == false || player2->defeated == false);
}


void game_noob(player *player1, player *player2)
{
	int i,indice1,indice2,test;

	do
	{
		display_team(*player1);
		display_team(*player2);
		for (i=0;i<size_team;i++)
		{
			player1->team[i].energy += player1->team[i].speed;
			player2->team[i].energy += player2->team[i].speed;
		}
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to use ?",player1->name);
			scanf("%d",&indice1);
				if (player1->team[indice1].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to attack ?",player1->name);
			scanf("%d",&indice2);
			if (player2->team[indice2].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			if (player1->team[indice1].energy >= 100)
			{
				printf("\n******special attack**********\n");
				special_attack(player1,player2,indice1,indice2);
				player1->team[i].energy = 0;
			}
			else {printf("\n/******classic attack**********/ for player 1\n");
			common_attack(player1,player2,indice1,indice2);
			}
			test=true;
			while (test) {
			indice1=rand()%(nb_fighters+1); // the computer selects a random fighter in its team
				if (player2->team[indice1].alive==false) 
				test=true;
				else {printf("\n Player %s use %s\n",player2->name, player2->team[indice1].name);test=false;}
			};
			test=true;
			while (test) {
			indice2=rand()%(nb_fighters+1); // the computer selects a random fighter in the opponent team
			if (player1->team[indice2].alive==false) 
			test=true;
			else {printf("\nPlayer %s attacks %s\n",player2->name, player1->team[indice2].name);test=false;}
			};
			printf("\n/******classic attack**********/ for player 2\n");
			common_attack(player2,player1,indice1,indice2);
	// Test if fighters of player 1 and 2 are KO
	test_defeat(player1);
	test_defeat (player2);
	} while (player1->defeated == false || player2->defeated == false);
}

void game_easy(player *player1, player *player2)
{
	int i,indice1,indice2,test,loser,loser_ind;

	do
	{
		display_team(*player1);
		display_team(*player2);
		for (i=0;i<size_team;i++)
		{
			player1->team[i].energy += player1->team[i].speed;
			player2->team[i].energy += player2->team[i].speed;
		}
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to use ?",player1->name);
			scanf("%d",&indice1);
				if (player1->team[indice1].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to attack ?",player1->name);
			scanf("%d",&indice2);
			if (player2->team[indice2].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			if (player1->team[indice1].energy >= 100)
			{
				printf("\n******special attack**********\n");
				special_attack(player1,player2,indice1,indice2);
				player1->team[i].energy = 0;
			}
			else {printf("\n/******classic attack**********/\n");
			common_attack(player1,player2,indice1,indice2);
			}
			test=true;
			while (test) {
			indice1=rand()%(nb_fighters+1); // the computer selects a random fighter in its team
				if (player2->team[indice1].alive==false) 
			test=true;
				else {printf("Player %s use %s?",player2->name, player2->team[indice1].name);test=false;}
			};
			loser=player1->team[0].hp;
			loser_ind=0;
			for(i=1;i<nb_fighters;i++)
				{
				if ((player1->team[i].hp < loser) && (player1->team[i].alive==true)) {
					loser=player1->team[i].hp;
					loser_ind=i;
				}
				};
			indice2=loser_ind; // the computer selects fighter of team 1 with the smallest life points
			printf("Player %s attacks %s?",player2->name, player1->team[indice2].name);
			printf("\n/******classic attack**********/\n");
			common_attack(player2,player1,indice1,indice2);
	// Test if fighters of player 1 and 2 are KO
	test_defeat(player1);
	test_defeat (player2);
	} while (player1->defeated == false || player2->defeated == false);
}




void test_defeat(player *player)
{
int cpt=0;
int i;
for (i=0;i<size_team;i++)
	if (player->team[i].hp<=0) 
		cpt ++;
if (cpt==size_team) player->defeated=true;
}

void common_attack(player *player_attack, player *player_defender, int i,int j){
player_defender->team[j].hp-=player_attack->team[i].atk*player_defender->team[j].def;
if (player_defender->team[j].hp <=0) player_defender->team[j].alive=false;

} 

void special_attack(player *player_attack, player *player_defender, int i,int j){
int damage;
damage=player_attack->team[i].atk*2*player_defender->team[j].def;
player_defender->team[j].hp-= damage;
player_attack->team[i].hp += 0.2*damage;
if (player_defender->team[j].hp <=0) player_defender->team[j].alive=false;
}
