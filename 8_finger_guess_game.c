#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	char gesture[3][10] = { "scissor", "stone", "cloth" };
	int player, computer, result, ret;
	int round = 1;
	int select = 1;
	int log[3] = { 0 };
	srand(time(NULL));
	printf
	    ("\n******************************GAME START*****************************\n");
	while (select != 3) {
		computer = rand() % 3;
		printf
		    ("\n***********************ROUND %d***************************\n",
		     round);
		printf("\nplease input your gesture:\n");
		printf("0,scissor    1,stone    2,cloth\n");
		ret = scanf("%d", &player);

		if (ret != 1 || player < 0 || player > 2) {
			printf("please input 0 OR 1 OR 2\n");
			continue;
		}

		printf
		    ("Your gesture is %s, and the computer gesture is %s\n",
		     gesture[player], gesture[computer]);
		result = (player - computer + 4) % 3 - 1;

		if (result > 0) {
			printf("YOU WIN\n");
			log[0]++;
		} else if (result == 0) {
			printf("DRAW\n");
			log[1]++;
		} else {
			printf("YOU LOSE\n");
			log[2]++;
		}
	      selection:printf
		    ("\nWhat do you want to do next?\n");
		printf("1,play again    2,see log    3,exit\n");
		scanf("%d", &select);
		if (select == 2) {
			printf
			    ("\n**************************LOG**********************\n");
			printf
			    (" You have win %d, draw %d and lose %d until %d round\n",
			     log[0], log[1], log[2], round);
			goto selection;
		}
		round++;
	}
	return 0;
}
