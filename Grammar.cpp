#include <list>
#include <map>
#include "Symbol.cpp"

class Rule {
    Symbol lhs;
    list<Symbol> rhs;

    Rule(Symbol rLhs, list<Symbol> rRhs){
        lhs = rLhs;
        rhs = rRhs;
    }
    ~Rule();

    list<Symbol> rhsReversed() {
        list<Symbol> reversed(rhs);
        reversed.reverse();
        return reversed;
    }
    
};

class Grammar {
    static map<string, Symbol> rules;








	static char terminals[] = {
		"kwdprog",
		"kwdinput",
		"kwdprint",
		"kwdwhile",
		"kwdif",
		"kwdelseif",
		"kwdelse",
		"paren1",
		"paren2",
		"brace1",
		"brace2",
		"comma",
		"semi",
		"equal",
		"plus",
		"minus",
		"aster",
		"slash",
		"caret",
		'id',
		'int',
		"float",
		"string",
		'$'
	};

		static map<string, Symbol> mapp = {
			"Pgm",
			"Block",
			"Stmts",
			"Stmt",
			"Astmt",
			"Y",
			"Ostmt",
			"Wstmt",
			"Fstmt",
			"Else2",
			"Elist",
			"Elist2",
			'R',
			'E',
			'S',
			'T',
			'F',
			"Pexpr",
			"Fatom",
			"Opadd",
			"Opmul"
	};

		static const array<Rule,25> rules = {
			"kwdprog",
			"kwdinput",
			"kwdprint",
			"kwdwhile",
			"kwdif",
			"kwdelseif",
			"kwdelse",
			"paren1",
			"paren2",
			"brace1",
			"brace2",
			"comma",
			"semi",
			"equal",
			"plus",
			"minus",
			"aster",
			"slash",
			"caret",
			'id',
			'int',
			"float",
			"string",
			'$'
		};

 void createRules() {
    rules["Opmul"] = Terminal("Opmul");  
    rules["Opadd"] = Terminal("Opadd");  
    rules["Fatom"] =   NonTerminal("Fatom",    );  
    rules["Pexpr"] =   NonTerminal("Pexpr",    );  
    rules['F'] =   NonTerminal("F",    );  
    rules['T'] =   NonTerminal("T",    );  
    rules['S'] =   NonTerminal("S",    );  
    rules['E'] =   NonTerminal("E",    );  
    rules['R'] =   NonTerminal("R",    );  
    rules["Elist2"]    =   NonTerminal("Elist2",   );  
    rules["Elist"] =   NonTerminal("Elist",    );  
    rules["Else2"] =   NonTerminal("Else2",    );  
    rules["Fstmt"] =   NonTerminal("Fstmt",    );  
    rules["Wstmt"] =   NonTerminal("Wstmt",    );  
    rules["Ostmt"] =   NonTerminal("Ostmt",    );  
    rules['Y'] =   NonTerminal("Y",    );  
    rules["Astmt"] =   NonTerminal("Astmt",    );  
    rules["Stmt"]  =   NonTerminal("Stmt", );  
    rules["Stmts"]  =   NonTerminal("Stmts",    );  
    rules["Block"] =   NonTerminal("Block",    );  
    rules["Pgm"]   =   NonTerminal("Pgm",  {Terminal("kwdp"),  NonTerminal("Block")});




    rules['Pgm'] = NonTerminal("Pgm", {Terminal("kwdp"), NonTerminal("Block")});
    rules["Block"] = NonTerminal("Block", );
    rules["Stmts"] = NonTerminal("Stmts", );
    rules["Stmt"] = NonTerminal("Stmt", );
    rules["Astmt"] = NonTerminal("Astmt", );
    rules['Y'] = NonTerminal("Y", );
    rules["Ostmt"] = NonTerminal("Ostmt", );
    rules["Wstmt"] = NonTerminal("Wstmt", );
    rules["Fstmt"] = NonTerminal("Fstmt", );
    rules["Else2"] = NonTerminal("Else2", );
    rules["Elist"] = NonTerminal("Elist", );
    rules["Elist2"] = NonTerminal("Elist2", );
    rules['R'] = NonTerminal("R", );
    rules['E'] = NonTerminal("E", );
    rules['S'] = NonTerminal("S", );
    rules['T'] = NonTerminal("T", );
    rules['F'] = NonTerminal("F", );
    rules["Pexpr"] = NonTerminal("Pexpr", );
    rules["Fatom"] = NonTerminal("Fatom", );
    rules["Opadd"] = NonTerminal("Opadd", );
    rules["Opmul"] = NonTerminal("Opmul", );
 }   

public:
    Grammar() {
        createRules();
    }
    ~Grammar();

    //create

    Rule getRuleAt(string top, string next) {

    }
    
};