#ifndef LEXER_H
#define LEXER_H
#include <string>
#include "token.h"
#include <vector> 
#include <regex>
#include <iostream>
using namespace std;
// using std::vector;

static bool lexe(const string &toParse_in, vector<Token*>& v);

bool isWhileSpace(char c);
bool isIdentifier(string s);
bool isBracket(char c);
bool isSemicolon(char c);
bool isNumber(char c);
bool isOperator(char c);
bool iskeyWord(string s);

#endif