#include "lexer.h"
// using namespace std;

static bool lexe(const string &toParse_in, vector<Token*>& v){

	string toParse = toParse_in;
	Token* tmp;

	// for each character
	while(toParse != ""){

		// cout<<toParse<<endl;

		char cur = toParse[0];
		// chack if it has meaning by its own
		if(isBracket(cur)){

			// cout<<"Brackets found! : "<< cur <<endl;

			tmp = new Token;
			tmp->setType("Bracket");
			tmp->setContent(cur);
			toParse.erase(toParse.begin());
			v.push_back(tmp);
		}
		else if(isWhileSpace(cur)){

			// cout<<"White space found! : "<< cur <<endl;

			toParse.erase(toParse.begin());
		} 
		else if(isSemicolon(cur)){

			// cout<<"Semicolon found! : "<< cur <<endl;

			tmp = new Token;
			tmp->setType("Semicolon");
			tmp->setContent(cur);
			toParse.erase(toParse.begin());
			v.push_back(tmp);
		}

		else if(isNumber(cur)){

			// cout<<"Number found! : "<< cur <<endl;

			tmp = new Token;
			tmp->setType("Number");
			tmp->setContent(cur);
			toParse.erase(toParse.begin());
			v.push_back(tmp);
		} 
		else if(isOperator(cur)){

			// cout<<"Operator found! : "<< cur <<endl;

			tmp = new Token;
			tmp->setType("Operator");
			tmp->setContent(cur);
			toParse.erase(toParse.begin());
			v.push_back(tmp);
		}
		else {

			// cout<<"Else found! : "<< cur <<endl;

			// if not iterate till the
			// next white space, beackets or semicolon
			// check whether the string is an identifier or a keyword
			string str = "";
			while(!isBracket(cur) &&
				  !isWhileSpace(cur) &&
				  !isSemicolon(cur) &&
				  !isOperator(cur) /*&&
				  !isNumber(cur)*/ ){
				  str = str + cur;

				  // cout<<"Processing else :"<<endl;
				  // cout<<str<<endl;

				  toParse.erase(toParse.begin());
				  cur = toParse[0];
				}
			
			if(iskeyWord(str)){
				tmp = new Token;
				tmp->setType("keyword");
				tmp->setContent(str);
				v.push_back(tmp);

			} else if(isIdentifier(str)){
				tmp = new Token;
				tmp->setType("Identifier");
				tmp->setContent(str);
				v.push_back(tmp);
			} 
		}


	}

	return true;
}

bool isWhileSpace(char c){
	if ( c == ' '  |
		 c == '\n' |
		 c == '\t' )
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
		c == '9' )
		return true;
	return false;
}

bool isOperator(char c){
	if (c == '+' |
		c == '-' |
		c == '*' |
		c == '/' |
		c == '=')
		return true;
	return false;
}

bool iskeyWord(string s){
	if ( s == "return" |
		 s == "int" )
		return true;
	return false;
}

string makeWS(int l){
	string ws = "";
	for (int i = 0; i < l; i++)
		ws += ' ';
	return ws;
}

int main(){
	string code = "int main(){\n int k = 5;\nreturn k;\n}";
	vector<Token*> tokens;
	lexe(code, tokens);

	for (int i = 0; i <  tokens.size(); i++){
		string type = tokens.at(i)->getType();
		string content = tokens.at(i)->getContent();
		cout<< "\n" << type << makeWS(15 - type.size())
		            << "||\t" << content;
	}

	return 0;
}