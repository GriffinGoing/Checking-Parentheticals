#include <stdio.h>
#include <string.h>

/*
 * This program checks for valid parentheses pairs by storing open parentheses, and then examing the most recently stored type against the next-found closing parentheses. If the types match, the opening parentheses is removed, and if they do not, then the line is not valid. If the end of the line is reached and no opening parentheses remain, the line is valid. If any remain, they were unmatched and the line is thus invalid. 
 *
 */
int main() {
	
	int charsInLine = 0; //characters in the line being examined
	int numOpenPars = 0; //number of open parentheses stored. acts as the char index for paren, so starts at -1 for empty
	//char paren[] = ""; //stores open parentheses 
	char* line; //the line being examined

	charsInLine = getline(&line, &charsInLine, stdin);
	
	//getline returns the number of bytes gotten, as a char is one byte. -1 means no chars, so EOF
	while (charsInLine != -1) {
		
		//printf("%s", line);
		//char c = line[0];
		int length = strlen(line); //length of the current line
		char paren[] = "";	
		for(int i = 0; i < length; i++) {
			char c = line[i];

			//skip new line and terminating characters
			if(c == '\n' || c =='\0') continue;

			printf("%c\n", c);
			
			if(c == '(' | c == '{' | c == '[') {
				printf("IN\n");
				numOpenPars++;
				int lenParen = strlen(paren);
				printf("numOpenPars: %d\n", numOpenPars);

				//add opening parentheses to paren string
				int len = strlen(paren);
				char *newParen = (char*)calloc((lenParen + 1), sizeof(char)); //add space for a char
				strcpy(newParen, paren);
				newParen[lenParen] = c;
				newParen[lenParen+1] = 0;
				printf("newParen: %s\n", newParen);
				//printf("ints of newParen: %d\n", newParen);
				strcpy(paren, newParen); //seg fault here
				free(newParen);
				printf("paren: %s\n", paren);
				for(int j = 0; j < strlen(paren); j++) {
					printf("%d\n", paren[j]);
				}

				//printf("%s\n", paren);
			}
			//printf("%c\n", c);
			switch(c) {
				case ')':
					printf("its a )");
					numOpenPars--;
					break;
				case '}':
					printf("its a }");
					numOpenPars--;
					break;
				case  ']':
					printf("its a ]");
					numOpenPars--;
					break;
				default:
					break;
			}
		}

		if(numOpenPars == 0) printf("VALID\n");
		
		numOpenPars = 0; //reset count for next line
		charsInLine = getline(&line, &charsInLine, stdin); //get next line
		
	}

}
