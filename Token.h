#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
private:
	int _ln;				// line number
	std::string _id;		// id based on grammar
	int _ix;				// optional; index number
	std::string _str;	// optional; actual string

public:
	Token();
	Token(std::string rId);
	Token(int ln, std::string id, int ix, std::string str);

    void setLn(int ln);
    void setId(std::string id);
    void setIx(int ix);
    void setStr(std::string str);
    int getLn();
    std::string getId();
    int getIx();
    std::string getStr();



	friend bool operator==(const Token& lhs, const Token& rhs);
};

#endif
