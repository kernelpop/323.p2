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
	Sym() {}
	~Sym() {}
};

class SymTable {
	list<Sym> table;
	int SYMcount;	//Number of symbols the table is holding
	int OCCcount;	//Total number of all occurences from all symbols 
	int width;
public:
	SymTable() {
		SYMcount = 2;
		OCCcount = 2;
		width = 30;
	};
	~SymTable() {

	};
	void print_table() {
		
		// Print top of table
		print_line();
		
		// Print all symbols in the table
		print_table_header("Symbols");
		for (int i = 0; i < SYMcount; i++) {		//	Will be rewritten once table is filled with content
			cout << '|';
			for (int i = 0; i < width; i++) {
				cout << ' ';
			}
			cout << '|' << endl;
		}

		// Divide the table
		print_line();
		
		// Print all occurences
		print_table_header("Occurences");
		for (int i = 0; i < OCCcount; i++) {		//	Will be rewritten once table is filled with content
			cout << '|';
			for (int i = 0; i < width; i++) {
				cout << ' ';
			}
			cout << '|' << endl;
		}
		
		// Print bottom of table
		print_line();
	}
	
	void print_line() {
		cout << '+';
		for (int i = 0; i < width; i++) {
			cout << '-';
		}
		cout << '+' << endl;
	}

	void print_table_header(string section_type) {
		int space = (width - section_type.length()) / 2;
		cout << '|';
		for (int i = 0; i < space; i++) {
			cout << ' ';
		}
		cout << section_type;
		for (int i = 0; i < space; i++) {
			cout << ' ';
		}
		// If space is odd, print an extra ' '
		if ((space % 2) != 0) {
			cout << ' ';
		}
		cout << '|' << endl;
		print_line();
	}
};