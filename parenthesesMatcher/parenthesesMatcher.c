#include "parenthesesMatcher.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

int areParenthesesProper(char* text){
	int length = strlen(text),index;
	Stack* parentheses = createStack(length, 1);
	for(index = 0; index<length; index++){
		switch(text[index]){
			case '{' :
			case '[' :
			case '(' :	
				push(parentheses,&text[index]);
				break;
			case ')' :
				if(!(*(char*)top(parentheses)) == '(')
					return 0;
				pop(parentheses);
				break;
			case ']' :
				if(!(*(char*)top(parentheses)) == '[')
					return 0;
				pop(parentheses);
				break;
			case '}' :
				if(!(*(char*)top(parentheses)) == '{')
					return 0;
				pop(parentheses);
				break;
		}		
	}
	if(parentheses->top != -1) 
		return 0;
	return 1;
}