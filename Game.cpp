#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>


//Code pour s'assurer que la case choisi n'a pas ete deja utilise
bool boardcheck(char board[], int input, char player) {


	return (board[input] == 'X' || board[input] == 'O' || input > 8 || input < 0);

}

//Code pour montrer la grille du jeu
void grid(char board[]) {



	system("cls");
	printf("                                 TIK-TAK-TOE\n\n");
	printf("                                 |          |\n");
	printf("                           %c     |    %c     |    %c\n", board[0], board[1], board[2]);
	printf("                       __________|__________|________\n");
	printf("                                 |          |\n");
	printf("                           %c     |    %c     |    %c\n", board[3], board[4], board[5]);
	printf("                       __________|__________|________\n");
	printf("                                 |          |\n");
	printf("                           %c     |    %c     |    %c\n", board[6], board[7], board[8]);
	printf("                                 |          |\n");


}

//Code pour verifier si un joueur a gagne
bool victory(char board[], bool game, int counter, char player, int turn) {





	//Ligne 1 Horizontal 'X'
	if (board[0] == player && board[1] == player && board[2] == player) {
		game = false;
	}

	//Ligne 2 Horizontal 'X'
	else if (board[3] == player && board[4] == player && board[5] == player) {
		printf("Player %d won!", turn);
		game = false;

	}

	//Ligne 3 Horizontal 'X'
	else if (board[6] == player && board[7] == player && board[8] == player) {
		printf("Player %d won!", turn);
		game = false;
	}

	//Ligne 3 Diagonal 'X'
	else if (board[0] == player && board[4] == player && board[8] == player) {
		printf("Player %d won!", turn);
		game = false;
	}

	//Ligne 1 Diagonal 'X'
	else if (board[6] == player && board[4] == player && board[2] == player) {
		printf("Player %d won!", turn);
		game = false;
	}

	//Ligne 1 Vertical 'X'
	else if (board[0] == player && board[3] == player && board[6] == player) {
		printf("Player %d won!", turn);
		game = false;
	}

	//Ligne 2 Vertical 'X'
	else if (board[1] == player && board[4] == player && board[7] == player) {
		printf("Player %d won!", turn);
		game = false;
	}

	//Ligne 3 Vertical 'X'
	else if (board[2] == player && board[5] == player && board[8] == player) {
		printf("Player %d won!", turn);
		game = false;
	}



	else if (counter == 8 && game == true)
	{

		printf("Draw!");
		game = false;

	}

	else {
		game = true;


	}

	return game;
}

//Code pour faire fonctionner le jeu
void play(int player, char board[], int input) {



	bool verify = true;

	while (verify == true) {

		scanf_s("%d", &input);


		//Pour verifier si la case choisi est vide, si oui la case change si non le joueur fait un autre essai
		if (!boardcheck(board, input, player)) {

			board[input] = player;
			verify = false;
		}
		else {

			printf("\n\nInvalid!\n\n");

		}
	}
	grid(board);
}

//code to choose singleplayer or multiplayer
void gamemode() {


	int mode;
	printf("Choose a game mode\n:");

	scanf_s("%d", &mode);

	if (mode == 1) {

		printf("Singleplayer\n\n");



	}
	else if (mode == 2) {

		printf("Multiplayer\n\n");

	}

	else {

		printf("\n\nInvalid\n\n");

	}
}