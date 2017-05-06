#pragma once

//#include "symbol.h"

#include <string>
#include <list>

using namespace std;

struct occurence {
	int lineNum;
	int tokenNum;
	bool isDef;
};

class Sym {
	int ix;
	string printName;
	bool isString;
	double valueDouble;
	string valueString;
	list<occurence> occurences;
public:
	Sym() {
	
	};

	~Sym() {

	};
};

class SymTable {
	list<Sym> table;
	int height;	//Number of symbols the table is holding
	int width;
public:
	SymTable() {
		height = 1;
		width = 30;
	};
	~SymTable() {

	};
	void print_table() {
		print_row();	//Print top of table
		
		for (int i = 0; i < height; i++) {		//	Will be rewritten once table is filled with content
			cout << '|';
			for (int i = 0; i < width; i++) {
				cout << ' ';
			}
			cout << '|' << endl;
		}
		
		print_row();	//Print bottom of table
	}
	void print_row() {
		cout << '+';
		for (int i = 0; i < width; i++) {
			cout << '-';
		}
		cout << '+' << endl;
	}
};