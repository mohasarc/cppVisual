#ifndef TOKEN_H
#define TOKEN_H
class Token(){
public:
	Token();
	Token(Token &toCopy);
	~Token();
	void setType(string atype);
	string getType();
	void setComment(string acomment);
	string getComment();
private:
	string type;
	string content;
};
#endif