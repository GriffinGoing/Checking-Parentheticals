#include <stdio.h>
#include <string.h>

int main() {
	
	int charsInLine = 0; //characters in the line being examined
	int numOpenPars = -1; //number of open parentheses stored
	char* paren = ""; //stores open parentheses 
	char* line; //the line being examined

	charsInLine = getline(&line, &charsInLine, stdin);
	
	//getline returns the number of bytes gotten, as a char is one byte. -1 means no chars, so EOF
	while (charsInLine != -1) {
		
		printf("%s", line);
		char* c = line[0];
		int length = strlen(line); //length of the current line
		
		for (int i = 0; i < length; i++) {
			c = line[i];
			//printf("%c\n", c);
			if(c == '(' | c == '{' | c == '[') {
				printf("IN\n");
				numOpenPars++;
				//strcat(paren, *c); //problem lies here in string conc
				//printf("%s\n", paren);
			}

			if(c == ')' | c == '}' | c == ']') {
				printf("OUT\n");
				numOpenPars--;
			}
		}

		if(numOpenPars == -1) printf("VALID\n");
		
		numOpenPars = -1; //reset count for next line
		charsInLine = getline(&line, &charsInLine, stdin); //get next line
		
	}

}
