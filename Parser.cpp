#include <string>
#include <vector>
#include <map>
#include "Token.cpp"
#include "Grammar.cpp"
#include "PST.cpp"
#include "AST.cpp"

using namespace std;


class Parser {
	Grammar gmr;
	PST pst;
	AST ast;

	Parser(PST rPst, AST rAst, Grammar rGmr) {
		pst = rPst;
		ast = rAst;
		gmr = rGmr;
	}

	Parser() {
		pst = new PST();
		ast = new AST();
		gmr = new Grammer();
	}

	/**
	    Parse a token list into an Abstract Syntax Tree

	    @param tokenList a vector list of the tokens to parse
	*/
	void parse(vector<Token> tokenList) {

		// Lexar input to PST
		pstTree pTreeObj = pst.toAST(tokenList);
		pTreeObj.tree.serialize(); // save and print out
		map<Symbol, String> symTable = pTreeObj.symTable; // save and print out

		// PST to AST
		astTree aTree = ast.parse(ptree);
		aTree.serialize(); // save and print out
	}

	/**
	    Overload: Parse a token list from a file into an Abstract Syntax Tree

	    @param the path to the file to parse
	*/
	void parse(String file) {
		vector<Token> tknList = toTokenList(file);
		parse(tknList);
	}

	vector<Token> toTokenList(String file) {
		// TODO: turn file into Token list
	}

 }
