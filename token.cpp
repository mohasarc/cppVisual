#include "token.h"

Token::Token():type(""), content(""){}

Token::Token(const Token &toCopy){
	type = toCopy.type;
	content = toCopy.content;
}

Token::~Token(){}

void Token::operator=(const Token &rhs){
	type = rhs.type;
	content = rhs.content;
}

void Token::setType(const string atype){
	type = atype;
}

string Token::getType(){
	return type;
}

void Token::setContent(const string acontent){
	content = acontent;
}

void Token::setContent(const char acontent){
	content += acontent;
}

string Token::getContent(){
	return content;
}