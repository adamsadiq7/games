#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

bool logic(int userChoice, int cpuChoice);
void gameOver(int userScore,int cpuScore);
void youWon(int userScore, int cpuScore);
void youLost (int userScore, int cpuScore);
void youDrew (int userScore, int cpuScore);
bool testing;

//Starts Game
char *startGame(){

//Initialize
    int cpuScore = 0;
    int userScore = 0;
		char moreThan10[3];
    printf("Welcome to Rock Paper Scissors\n");
    char chosenRounds[4];

		printf("Do you want more than 10 games? (y/n)\n\n");

		fgets(moreThan10, 3, stdin);

		printf("How may games do you want with the computer?\n\n");

		if (moreThan10[0] == 'y') {
			printf("How many rounds (more than 10)?\n");
			fgets (chosenRounds, 4, stdin);
		}

		else if (moreThan10[0] == 'n') {
			printf("How many rounds (less than 10)?\n");
			fgets (chosenRounds, 3, stdin);
		}

		else {
	    	return "Invalid";
		}

//Checks for invalid inputs

    if (strcmp(chosenRounds,"") == 0){
        return "Invalid";
				printf("Returned Invalid 1\n");
    }

		printf("%lu\n", strlen(chosenRounds)-1);
		for (int i=0; i< strlen(chosenRounds)-1; i++) {
        if (!isdigit(chosenRounds[i])) {
					printf("Returned Invalid 2\n");
          return "Invalid";
				}
		}

		int checker;
		checker = atoi(chosenRounds);

		printf("chosenRounds = %d\n",checker);


    if (checker > 99) {
        return "Too many games";
    }
    printf("Okay, %d rounds, got it!\n\n", checker);
    int roundsPlayed = 0;

//Loop till game finished
    for (int i=0;i<checker;i++){

        int userChoice;

        printf("Type:\n 1 for Rock\n 2 for Paper\n 3 for Scissors\n\n");
        scanf("%d", &userChoice);

		srand(time(NULL));
        int cpuChoice = ((rand() % 3)+1);
		

        bool userWonPoint = false;
        bool drawnPoint = false;


		
        if (userChoice == 1){
            printf("You picked Rock.\n");
        }

        else if (userChoice == 2){
            printf("You picked Paper.\n");
        }

        else if (userChoice == 3){
            printf("You picked Scissors.\n");
        }

        else{
            printf("Invalid Choice.\n");
            return("Invalid");
        }

        roundsPlayed = roundsPlayed + 1;

        userWonPoint = logic(userChoice, cpuChoice);

        if (userChoice == cpuChoice){
            drawnPoint = true;
        }


        if (drawnPoint == true){
            printf("You drew the point\n");
            printf("The score is %d - %d\n\n", userScore, cpuScore);
            if (checker == roundsPlayed){
                gameOver(userScore, cpuScore);
            }
        }

        if (userWonPoint == true){
            printf("You won the point\n");
            userScore = userScore + 1;
            printf("The score is %d - %d\n\n", userScore, cpuScore);
            if (checker == roundsPlayed){
                gameOver(userScore, cpuScore);
            }
        }
        if (userWonPoint == false){
					if (drawnPoint == false){
                printf("You lost the point\n");
                cpuScore = cpuScore + 1;
                printf("The score is %d - %d\n\n", userScore, cpuScore);
                if (checker == roundsPlayed){
                    gameOver(userScore, cpuScore);
                }
          }
				}

            drawnPoint = false;

        }

    return 0;
}

//Checks to see who wins
void gameOver(int userScore,int cpuScore){

    if (userScore > cpuScore){
        youWon(userScore, cpuScore);
    }
    else if (userScore < cpuScore){
        youLost(userScore, cpuScore);
    }
    else if (userScore == cpuScore){
        youDrew(userScore, cpuScore);
    }
    else{
        printf("Wrong Call - Error");
        exit(1);
    }

}

//Logic of Game
bool logic(int userChoice, int cpuChoice){

        //Check for invalid inputs
        if (isdigit(userChoice)){
            return "Invalid";
        }
        if (userChoice > 3){
            return "Invalid";
        }
        if (userChoice < 1){
            return "Invalid";
        }
        if (cpuChoice > 3){
            return "CPU Error";
        }
        if (cpuChoice < 1){
            return "CPU Error";
        }

        bool userWonPoint;
        bool drawnPoint;

        //Checks for tie
        if (userChoice == cpuChoice){

                userWonPoint = false;
                drawnPoint = true;
                if (!testing){
                    printf("Tie!\n\n");
                }
        }
        //Rock vs Paper
        if (userChoice == 1){
            if (cpuChoice == 2){
                userWonPoint = false;
                if (!testing){
                    printf("Your Rock is smothered by the Computers Paper!\n\n");
                }
            }

        }

        //Rock vs Scissors
        if (userChoice == 1){
            if (cpuChoice == 3){
                userWonPoint= true;
                if (!testing){
                    printf("Your Rock destroys the Computers Scissors!\n\n");
                }
            }
        }

        //Paper vs Rock
        if (userChoice == 2){
            if (cpuChoice == 1){
                userWonPoint= true;
                if (!testing){
                    printf("Your Paper smothers the Computers Paper!\n\n");
                }
            }
        }

        //Paper vs Scissors
        if (userChoice == 2){
            if (cpuChoice == 3){
                userWonPoint = false;
                if (!testing){
                    printf("Your Paper is sliced up by the Computers Scissors!\n\n");
                }
            }
        }

        //Scissors vs Rock
        if (userChoice == 3){
             if (cpuChoice == 1){
                userWonPoint = false;
                if (!testing){
                printf("Your Scissors is sent packing by the Computers Rock!\n\n");
                }
            }
        }

        //Scissors vs Paper
        if (userChoice == 3){
            if(cpuChoice == 2){
                userWonPoint = true;
                if (!testing){
                    printf("Your Scissors slices the Computers Paper!\n\n");
                }
            }
        }


    //Return if user won point

    return(userWonPoint);
}


//Quick function notifying a win
void youWon(int userScore, int cpuScore){

    printf("You've won the game with a score of %d - %d !\n", userScore, cpuScore);
    exit(1);
}
//Quick function notifying a loss
void youLost (int userScore, int cpuScore){

    printf("You've lost the game with a score of %d - %d !\n", userScore, cpuScore);
    printf("Better Luck Next time!\n");
    exit(1);
}

//Quick function notifying a draw
void youDrew (int userScore, int cpuScore){

    printf("You've drawn the game with a score of %d - %d !\n", userScore, cpuScore);
    printf("Come back to prove your worth!\n");
    exit(1);
}

//Tests

enum type { CHAR, BOOL };

int booleq(int n, bool actual, bool expected){
    n++;
    if (actual != expected){
        fprintf(stderr, "Test %d fails\n", n);
        exit(1);
    }
    return n;
}


int chareq(int n, const char *actual, const char *expected) {
    n++;
    if (strcmp(actual, expected) != 0) {
        fprintf(stderr, "Test %d fails\n", n);
        fprintf(stderr, "result: %s\n", actual);
        fprintf(stderr, "instead of: %s\n", expected);
        exit(1);
    }
    return n;
}

int eqb(int n, bool x, bool y) { return booleq(n, x, y); }
int eqs(int n, char *x, char *y) { return chareq(n, x, y); }

void test() {
    int n = 0;

    n = eqb(n, logic(2,1), true);
        n = eqb(n, logic(2,3), false);
        n = eqb(n, logic(1,2), false);
        n = eqb(n, logic(1,3), true);
        n = eqb(n, logic(1,1), false);
        n = eqb(n, logic(3,1), false);
        n = eqb(n, logic(3,2), true);
        n = eqb(n, logic(3,3), false);
        /*n = eqs(n, logic('5','s'), "Invalid");
        n = eqs(n, logic('s','7'), "Invalid");
        n = eqs(n, logic('s','s'), "Invalid");
        n = eqs(n, logic('s','f'), "Invalid");
*/
    printf("Tests passed: %d\n\n", n);
        testing = false;

        startGame();
}


int main(){
    setbuf(stdout, NULL);

    testing = true;
    test();

    return 0;
}