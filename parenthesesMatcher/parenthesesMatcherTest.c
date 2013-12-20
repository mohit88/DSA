#include "testUtils.h"
#include "parenthesesMatcher.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_parentheses_are_proper_in_string_having_no_character(){
	char text[256];
	strcpy(text,"");
	ASSERT(areParenthesesProper(text));
}

void test_parentheses_are_proper_in_string_having_only_alphabets_character(){
	char text[256];
	strcpy(text,"abcde");
	ASSERT(areParenthesesProper(text));
}


void test_parentheses_are_proper_in_string_having_opening_and_closing_bracket(){
	char text[256];
	strcpy(text,"[]");
	ASSERT(areParenthesesProper(text));
}

void test_parentheses_are_not_proper_in_string_having_closing_and_opening_bracket(){
	char text[256];
	strcpy(text,"][");
	ASSERT(0==areParenthesesProper(text));
}

void test_parentheses_are_proper_in_string_having_20_character(){
	char text[256];
	strcpy(text,"{(dkjfkj[dfkkn	]d,cvfn	)df}d,mf  v,[]");
	ASSERT(areParenthesesProper(text));
}

void test_parentheses_are_not_proper_in_string_having_20_character(){
	char text[256];
	strcpy(text,"{([()}");
	ASSERT(0 == areParenthesesProper(text));
}
