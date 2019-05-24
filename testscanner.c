#include "token.h"
#include "scanner.h"
#include "stdio.h"
#include "stdlib.h"
#include "testscanner.h"

//test scanner
void testScanner(){
	int i,j;
	
	if (isError == 1) {

		for(j=0; j < errorIndex; j++){
			printf("%s\n", error[j]);
		}

	} else {

		//since my token type is enum i print it manually
		for(i=0; i < z; i++){
		
			if(tokens[i].tokenType == IDENTIFIER){
				printf("Line: %-3d | Token: %-8s | Token Type: Identifier Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == NUMBER){	
				printf("Line: %-3d | Token: %-8s | Token Type: Number Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == EQUAL){	
				printf("Line: %-3d | Token: %-8s | Token Type: Equal Token\n", tokens[i].lineNum, tokens[i].instance);	
			}  else if(tokens[i].tokenType == LESS_THAN){	
				printf("Line: %-3d | Token: %-8s | Token Type: Less Than Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == GREATER_THAN){	
				printf("Line: %-3d | Token: %-8s | Token Type: Greather Than Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == COLON){	
				printf("Line: %-3d | Token: %-8s | Token Type: Colon Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == PLUS){	
				printf("Line: %-3d | Token: %-8s | Token Type: Plus Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == MINUS){	
				printf("Line: %-3d | Token: %-8s | Token Type: Minus Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == STAR){	
				printf("Line: %-3d | Token: %-8s | Token Type: Star Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == SLASH){	
				printf("Line: %-3d | Token: %-8s | Token Type: Slash Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == PERCENT){	
				printf("Line: %-3d | Token: %-8s | Token Type: Percent Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == DOT){	
				printf("Line: %-3d | Token: %-8s | Token Type: Dot Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == LEFT_PARENT){	
				printf("Line: %-3d | Token: %-8s | Token Type: Left Parenthesis Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == RIGHT_PARENT){	
				printf("Line: %-3d | Token: %-8s | Token Type: Right Parenthesis Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == COMMA){	
				printf("Line: %-3d | Token: %-8s | Token Type: Comma Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == LEFT_BRACE){	
				printf("Line: %-3d | Token: %-8s | Token Type: Left Brace Token\n", tokens[i].lineNum, tokens[i].instance);	
			}  else if(tokens[i].tokenType == RIGHT_BRACE){	
				printf("Line: %-3d | Token: %-8s | Token Type: Right Brace Token\n", tokens[i].lineNum, tokens[i].instance);	
			}  else if(tokens[i].tokenType == SEMICOLON){	
				printf("Line: %-3d | Token: %-8s | Token Type: Semicolon Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == LEFT_BRACKETS){	
				printf("Line: %-3d | Token: %-8s | Token Type: Left Brackets Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == RIGHT_BRACKETS){	
				printf("Line: %-3d | Token: %-8s | Token Type: Right Brackets Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == START_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: start Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == STOP_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: stop Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == LOOP_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: loop Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == VOID_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: void Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == VAR_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: var Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == RETURN_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: return Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == SCAN_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: scan Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == OUT_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: out Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == PROGRAM_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: program Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == IF_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: if Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == THEN_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: then Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == LET_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: let Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == EOT){		
				printf("Line: %-3d | Token: %-8s | Token Type: EOF Token\n", tokens[i].lineNum, tokens[i].instance);
			}

		}
	}

}
