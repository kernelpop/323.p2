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

	int ln;
	string id;
	int ix;
	string str;
	bool isString;
	double valueDouble;
	string valueString;

public:

	Sym() {}

	Sym(int _ln, string _id, int _ix, string _str, double _valdb, string _valstr) {
		ln = _ln;
		id = _id;
		ix = _ix;
		str = _str;
		valueDouble = _valdb;
		valueString = _valstr;
	}
	
	~Sym() {}

	vector<occurence> occs;

	void add_occ(int _ln, int _ix) {
		occurence a;
		a.lineNum = _ln;
		a.tokenNum = _ix;
		a.isDef = false;
		occs.push_back(a);
	}

	string get_str() {
		return str;
	}

	int get_ln() {
		return ln;
	}

	int get_ix() {
		return ix;
	}

	double get_valdb() {
		return valueDouble;
	}

	string get_valstr() {
		return valueString;
	}

};

class SymTable {
	
	int current_indent_level;
	
	list<Sym> table;
	
	vector<Sym> symbols;

public:
	
	SymTable() {
		current_indent_level = 0;
	};

	~SymTable() {

	};

	void add_symbol(Sym new_sym) {
		bool sym_exists = false;
		bool sym_added = false;
		int sym_loc = 0;
		cout << "Looking for a symtable match" << endl;
		if (symbols.size() == 0) {
			symbols.push_back(new_sym);
			sym_added = true;
		}
		else {
			for (size_t i = 0; i < symbols.size(); i++) {
				if (symbols[i].get_str() == new_sym.get_str()) {
					sym_exists = true;
					sym_loc = i;
				}
			}
		}
		if (sym_exists) {
			symbols[sym_loc].add_occ(new_sym.get_ln(), new_sym.get_ix());
		}
		else {
			if (!sym_added) {
				symbols.push_back(new_sym);
			}
		}
	}

	void print_table() {
		indent();
		cout << ">>> Symbol Table" << endl;
		current_indent_level++;
		if (symbols.size() == 0) {
			indent();
			cout << "0 symbols found." << endl;
		}
		else {
			indent();
			cout << symbols.size() << " symbol(s) found:" << endl;
			current_indent_level++;
			for (size_t i = 0; i < symbols.size(); i++) {
				indent();
				cout << "Symbol: " << symbols[i].get_str();
				indent(1);
				cout << "First Found On Line: " << symbols[i].get_ln();
				indent(1);
				cout << "Index: " << symbols[i].get_ix();
				indent(1);
				cout << "Double Value: " << symbols[i].get_valdb();
				indent(1);
				cout << "String Value: " << symbols[i].get_valstr() << endl;
				current_indent_level++;
				if (symbols[i].occs.size() == 0) {
					indent();
					cout << "This symbol has only 1 occurrence" << endl;
				}
				else {
					indent();
					cout << symbols[i].occs.size() << " additional occurrence(s) found:" << endl;
					current_indent_level++;
					for (size_t j = 0; j < symbols[i].occs.size(); j++) {
						indent();
						cout << "Line: " << symbols[i].occs[j].lineNum;
						indent(1);
						cout << "Index: " << symbols[i].occs[j].tokenNum;
						indent(1);
						cout << "Is definition: " << symbols[i].occs[j].isDef << endl;
					}
					current_indent_level--;
				}
				current_indent_level--;
			}
		}
	}

	void indent() {
		for (int i = 0; i < current_indent_level; i++) {
			cout << "\t";
		}
	}

	void indent(int count) {
		for (int i = 0; i < count; i++) {
			cout << "\t";
		}
	}
	
};