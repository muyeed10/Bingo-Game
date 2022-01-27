/*GROUP MEMBERS: 
m85hossa, Hossain, Muyeed, 501035079, Section 8
zmdawood, Dawood, Zakir, 501022529, Section 5
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "list.h"

//This function will check the columns of the marked array given to it. If a winner is detected, it will return 1.
int checkcol(int arr[5][5]) {
	
	if (arr[0][0] == 1 && arr[1][0] == 1 && arr[2][0] == 1 && arr[3][0] && arr[4][0] == 1) {
                return 1;
        }
	if (arr[0][1] == 1 && arr[1][1] == 1 && arr[2][1] == 1 && arr[3][1] && arr[4][1] == 1) {
                return 1;
        }
	if (arr[0][2] == 1 && arr[1][2] == 1 && arr[2][2] == 1 && arr[3][2] && arr[4][2] == 1) {
                return 1;
        }
	if (arr[0][3] == 1 && arr[1][3] == 1 && arr[2][3] == 1 && arr[3][3] && arr[4][3] == 1) {
                return 1;
        }
	if (arr[0][4] == 1 && arr[1][4] == 1 && arr[2][4] == 1 && arr[3][4] && arr[4][4] == 1) {
                return 1;
        }
	return 0;
}

//This function will check the rows of the marked array given to it. If a winner is detected, it will return 1.
int checkrow(int arr[5][5]) {

	if (arr[0][0] == 1 && arr[0][1] == 1 && arr[0][2] == 1 && arr[0][3] && arr[0][4] == 1) {
		return 1;
	}
	if (arr[1][0] == 1 && arr[1][1] == 1 && arr[1][2] == 1 && arr[1][3] && arr[1][4] == 1) {
        	return 1;
        }
	if (arr[2][0] == 1 && arr[2][1] == 1 && arr[2][2] == 1 && arr[2][3] && arr[2][4] == 1) {
                return 1;
        }
	if (arr[3][0] == 1 && arr[3][1] == 1 && arr[3][2] == 1 && arr[3][3] && arr[3][4] == 1) {
                return 1;
        }
	if (arr[4][0] == 1 && arr[4][1] == 1 && arr[4][2] == 1 && arr[4][3] && arr[4][4] == 1) {
                return 1;
        }

	return 0;
}

//This array will check the corners of the marked array given to it. If a winner is detected, it will return 1.
int checkcorners(int arr[5][5]) {

	int index, jdex;
	if (arr[0][0] == 1 && arr[0][4] == 1 && arr[4][0] == 1 && arr[4][4] == 1) {
		return 1;//1 means winner through corners
	}
}

//This array will use the above three functions to check for a winner. If detected, will print Winner and return 1.
int checkwinner(int arr[5][5]) {

	if (checkrow(arr) == 1 || checkcorners(arr) == 1 || checkcol(arr) == 1) {
                        return 1;
        }
	return 0;
}

int main (int argc , char *argv[]) {
	
	//This will check if the two arguments were passed. If not, exit 1.
	if (argc != 3) {
		fprintf(stderr, "Usage: %s seed cardFile\n", argv[0]);
		exit(1);
	}

	//This will check that first argument is an integer for the seed number. If not, exit 2.
	char *cb = argv[1];
	while (*cb != '\0') {
		if (isdigit(*cb)==0) {
			fprintf(stderr, "Expected Integer seed, but got %s\n", argv[1]);
			exit(2);
		}
		cb++;
	}

	//This converts given argument to an integer to use as a seed number.
	int seednum = atoi(argv[1]);

	//This checks that seed number is a positive integer as srand expects it to be. If not, exit 2.
	if (seednum < 0) {
		fprintf(stderr, "Expected Integer seed, but got %s\n", argv[1]);
		exit(2);
	}

	//Will call srand to declare unique random calling according to seed number provided.
	srand(seednum);


	//This checks that the file is existent and readable. If not, exit 3.
	FILE *fp;
	if ((fp=fopen(argv[2], "r")) == NULL){
		fprintf(stderr, "%s is nonexistent or unreadable\n", argv[2]);
		exit(3);
	}
	
	int ch;
	int count=0;
	int lines=0;

	//Checks for correct number of characters in a line. If not, exit 4.
	while ((ch=fgetc(fp)) != EOF){ 
		
		count ++;
				
		if (ch == '\n') {
			if (count != 15) {
				fprintf(stderr, "%s has bad format\n", argv[2]);
				exit(4);
			}
			count=0;
		}
		lines ++;		
	}

	//Checks for correct number of lines in the file. If not, exit 4.
	if ((lines/15) > 5) {
		fprintf(stderr, "%s has bad format\n", argv[2]);
		exit(4);
	}

	//Done so that we can read file again.
	rewind(fp);

	//Reading the numbers from file and putting them into an array.
	int arr[5][5];
	int duparr[25];
	int a;
	int z=0;
	count = 0;
	int count1=0;
	while (count !=5) {
		while (z != 5) {
			fscanf(fp, "%d", &a);
	                arr[count][z]= a;
			duparr[count1]=a;
        	        z++;
			count1++;
		}	
		count++;
		z=0;
	}		

	//This will check to ensure that the middle number is 00. If not, exit 4.
	if (arr[2][2]!=0){
		fprintf(stderr, "%s has bad format\n", argv[2]);
		exit(4);
	}

	//This will check for duplicates or missing numbers. If so, exit 4.
	int index, jdex;
	for (index=0; index < 25; index ++) {
		for (jdex=0; jdex < 25; jdex ++) {
			if (index != jdex && duparr[index]==duparr[jdex]) {
				fprintf(stderr, "%s has bad format\n", argv[2]);
				exit(4);
			}
		}
	}

	//This will check to make sure each number is in the correct range. If not, exit 4.
	for( index = 0; index < 5; index++){
                for( jdex = 0; jdex < 5; jdex++){

                        switch (jdex) {
                        case 0:
                                if (arr[index][jdex] < 1 || arr[index][jdex] > 15) {
                                	fprintf(stderr, "%s has bad format\n", argv[2]);
                                	exit(4);
				}
                                break;
                        case 1:
                                if (arr[index][jdex] < 16 || arr[index][jdex] > 30) {
                                	fprintf(stderr, "%s has bad format\n", argv[2]);
                                	exit(4);        
                                }
                                break;
                        case 2:
                                if ((arr[index][jdex] < 31 || arr[index][jdex] > 45) && index != 2) {
                                	fprintf(stderr, "%s has bad format\n", argv[2]);
                                	exit(4);
				}
                                break;
                        case 3:
                                if (arr[index][jdex] < 46 || arr[index][jdex] > 60) {
                                	fprintf(stderr, "%s has bad format\n", argv[2]);
                                	exit(4);
				}
                                break;
                        case 4:
                                if (arr[index][jdex] < 61 || arr[index][jdex] > 75) {
                                	fprintf(stderr, "%s has bad format\n", argv[2]);
                                	exit(4);
				}
                                break;
                        }
                }
        }


	system("clear");

	//Create ADT here
	ADT call;
	//Initialize ADT here
	INITIALIZE(75, &call);
	
	int bool = 0;

	//The following array is used to check for marked numbers. 1 means the number has been called.
	//0 means that the number has yet to be called.
	int checkarr[5][5] = { 0 };

	//We make sure to start with 00 marked as it will not be called but needs to be marked.
	checkarr[2][2] = 1;

	
	while (bool == 0) {

		printf("CallList: ");
		
		//We use PRINT function from list.c to print the call list.
		PRINT(&call);
		printf("\n\n");
		printf("L   I   N   U   X\n");

		for( index = 0; index < 5; index++) {
   			for( jdex = 0; jdex < 5; jdex++) {
					if (CHECK(arr[index][jdex], &call) == 0) {
						printf( "%02dm ", arr[index][jdex]);
						checkarr[index][jdex] = 1;
					}
					else if (index == 2 && jdex == 2) {
						printf( "%02dm ", arr[index][jdex]);
                                                checkarr[index][jdex] = 1;
					}
					else {
						printf( "%02d  ", arr[index][jdex]);
					}

			}
			printf("\n");
		}

		int randnum = 0;
		
		//Checks winner for when only one character is inputted by user.
		if (checkwinner(checkarr) == 1) {
			printf("WINNER\n");
			exit(0);
		}

		//Collects user input.
		char input[75];
		printf("enter any non-enter key for Call (q to quit): ");
		
		//fgets is used to take input including just enter. Allows us to identify enter 
		//in comparison to using scanf	
		fgets(input, sizeof input, stdin);

		
		//This loop controls display depending on how many characters are inputted.
		for (int a = 0; a < strlen(input) - 1; a ++) {
			//If q is detected, program will display final marked card before exiting.
			if (input[a] == 'q') {
				system("clear");
				printf("CallList: ");
                                PRINT(&call);
                                printf("\n\n");
                                printf("L   I   N   U   X\n");

				//This will print marked card and uses list.c function CHECK for it.
                                for( index = 0; index < 5; index++) {
                          		for( jdex = 0; jdex < 5; jdex++) {
                        	                if (CHECK(arr[index][jdex], &call) == 0) {
                                                	printf( "%02dm ", arr[index][jdex]);
                                                        checkarr[index][jdex] = 1;
                                                }
                                                else if (index == 2 && jdex == 2) {
                               				printf( "%02dm ", arr[index][jdex]);
                                                    	checkarr[index][jdex] = 1;
                                                }
                                                else {
                                               		printf( "%02d  ", arr[index][jdex]);
                                                }
                                     	}
                                        printf("\n");
                            	}
				printf("Program exited\n");
				exit(0);
			}
			else {

				//This generates random number. Seed has already been declared earlier.
				//Range is 1-75 inclusive.
				randnum= (rand() % (75 - 1 + 1)) + 1;

				//Uses CHECK function in list.c to check if call list already has the number.
				//If so, it will keep calling a random number until it does not repeat.
				while (CHECK(randnum, &call) == 0) {
					randnum= (rand() % (75 - 1 + 1)) + 1;
				}
				
				//This nested loop will check if number has been called. If so, it will mark 
				//that same index as 1 in the checkarr array.
				for( index = 0; index < 5; index++) {
   					for( jdex = 0; jdex < 5; jdex++) {
						if (CHECK(arr[index][jdex], &call) == 0) {
							checkarr[index][jdex] = 1;
						}
						else if (index == 2 && jdex == 2) {
                            				checkarr[index][jdex] = 1;
						}
					}
				}

				//Checks for winner after each character is multi-character input. If winner
				//detected, displays card before exiting with 0.
		        	if (checkwinner(checkarr) == 1) {
					
					printf("CallList: ");
					PRINT(&call);
					printf("\n\n");
					printf("L   I   N   U   X\n");

					//This loop will print marked card.
					for( index = 0; index < 5; index++) {
   						for( jdex = 0; jdex < 5; jdex++) {
							if (CHECK(arr[index][jdex], &call) == 0) {
								printf( "%02dm ", arr[index][jdex]);
								checkarr[index][jdex] = 1;
							}
							else if (index == 2 && jdex == 2) {
								printf( "%02dm ", arr[index][jdex]);
                                				checkarr[index][jdex] = 1;
							}
							else {
								printf( "%02d  ", arr[index][jdex]);
							}
						}
						printf("\n");
					}
	
					//As winner has been detected, WINNER is printed before exiting with 0.
                			printf("WINNER\n");
                    		exit(0);
					}		
				//If winner not detected, will use ADD function in list.c to add to call list.
				else {
					ADD(randnum, &call);
					system("clear");
				}
			}
			
		}
		//In case enter is called without typing any other characters, system clears before going ot next call.
		system("clear");
	}
	
}
