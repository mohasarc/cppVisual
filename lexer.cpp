#include "lexer.h"
#include <vector> 
#include <regex>
using namespace std;

vector<Token> lex(const string &toParse_in){

	string toParse = toParse_in;
	vector<Token> v;
	Token tmp;

	// for each character
	while(toParse != ""){
		char cur = toParse[0];
		// chack if it has meaning by its own
		if(isBracket(cur)){
			tmp = new Token;
			tmp.setType("Bracket");
			tmp.setComment(cur);
			toParse.erase(toParse.begin());
			v.push_back(tmp);
		}
		else if(isWhileSpace(cur)){
			toParse.erase(toParse.begin());
		} 
		else if(isSemicolon(cur)){
			tmp = new Token;
			tmp.setType("Semicolon");
			tmp.setComment(cur);
			toParse.erase(toParse.begin());
			v.push_back(tmp);
		}

		else if(isNumber(cur)){
			tmp = new Token;
			tmp.setType("Number");
			tmp.setComment(cur);
			toParse.erase(toParse.begin());
			v.push_back(tmp);
		} 
		else {
			// if not iterate till the
			// next white space, beackets or semicolon
			// check whether the string is an identifier or a keyword
			string str = "";
			while(!isBracket(cur) &&
				  !isWhileSpace(cur) &&
				  !isSemicolon(cur) &&
				  /*!isNumber(cur)*/ ){
				  str = str + cur;
				  toParse.erase(toParse.begin());
				}
			
			if(iskeyWord(str)){
				tmp = new Token;
				tmp.setType("keyword");
				tmp.setComment(str);
				toParse.erase(toParse.begin());
				v.push_back(tmp);

			} else if(isIdentifier(str)){
				tmp = new Token;
				tmp.setType("Identifier");
				tmp.setComment(str);
				toParse.erase(toParse.begin());
				v.push_back(tmp);
			} 
		}
	}
	
	
	

}

bool isWhileSpace(char c){
	if ( c == " "  |
		 c == "\n" |
		 c == "\t" |)
		return true;
	return false;
}

bool isIdentifier(string s){
	regex r("[a-zA-Z]\\w*"); 

	if (regex_match(s, r)){
		return true;
	}

	return false;
}

bool isBracket(char c){
	if( c == '(' | c == ')' | 
		c == '[' | c == ']' | 
		c == '{' | c == '}')
		return true;

	return false;
}

bool isSemicolon(char c){
	if ( c == ';')
		return true;
	return false;
}

bool isNumber(char c){
	if (c == '0' |
		c == '1' |
		c == '2' |
		c == '3' |
		c == '4' |
		c == '5' |
		c == '6' |
		c == '7' |
		c == '8' |
		c == '9' |)
		return true;
	return false;
}

bool iskeyWord(string s){
	if ( s == "return" |
		 s == "int" |)
		return true;
	return false;
}