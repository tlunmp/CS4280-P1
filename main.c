#include "stdio.h"
#include "errno.h"
#include "ctype.h"
#include "token.h"
#include "scanner.h"
#include "testscanner.h"
#include "string.h"
#include "stdlib.h"

int z = 0;
int errorIndex = 0;

int main(int argc, char *argv[]) {
	const int SIZE = 1000;
	char input[SIZE];
	int line = 1;

	createFSATable();

	if (argc > 2) {
		fprintf(stderr, "Error too much argument\n");
		return 0;
	} 
	
	//file input
	if (argc == 2) {

		int size = 0;
		size_t len = strlen(argv[1]);
		FILE *file = fopen(strcat(argv[1], ".fs182"), "r");
		argv[len] = '\0';
	
		tokens = (Token *) malloc(sizeof(Token));	
		//check if the file is NULL
		if (file == NULL) {	
			perror("Error opening file");
			return 0;		
		} else {

			//check if the file is empty shows the error
	 		fseek (file, 0, SEEK_END);

	         	size = ftell (file);
		         rewind(file);
			 if(size == 0) {
				
				fprintf(stderr, "Error: The File is Empty\n");
				return 0;
			}

		}
		
		//parse the word store it in the array
		while(fgets(input, sizeof(input), file)){
			driver(input,line);			
			line++;
		}	
		
		fclose(file);

	}

	//Keyboard input
	if (argc == 1){
		tokens = (Token *) malloc(sizeof(Token));	
		isError = 0;
	
		//if input is empty show error
		int ch = getc(stdin);
		if (ch == EOF){
			fprintf(stderr, "Error: The Input is Empty\n");
   			return 0;
   		} else {
		        ungetc(ch, stdin);
		}

		//read line and store in struct
		while(fgets(input, sizeof(input),stdin)){	
			driver(input,line);			
			line++;
		}
	}
	
	
	//end of file token 
	strcpy(tokens[z].instance,"EndToken");
	tokens[z].lineNum = --line;
	tokens[z].tokenType = EOT;
	z++;

	checkIfKeyword();

	//print tokens
	testScanner();
	free(tokens);
	return 0;
}
