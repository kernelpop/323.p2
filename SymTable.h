#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <string>
#include <list>

#include "Sym.h"

class SymTable {
private:
	int currentIndentLevel;
	std::list<Sym> table;
	std::vector<Sym> symbols;

	void indent();
	void indent(int count);

public:
	SymTable();
	~SymTable();

	void addSymbol(Sym newSym);
	void printTable();
};

#endif
