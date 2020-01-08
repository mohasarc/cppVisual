#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using namespace std;

class Token{
public:
	Token();
	Token(const Token &toCopy);
	~Token();
	void operator=(const Token &rhs);
	void setType(const string atype);
	string getType();
	void setContent(const string acontent);
	void setContent(const char acontent);
	string getContent();
private:
	string type;
	string content;
};
#endif