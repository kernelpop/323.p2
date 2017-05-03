#include "Tokenizer.cpp"
#include "Parser.cpp"
#include <vector>

using namespace std;


//	========  Global Variables  ========
string _Language = "A3";
string Test_File = "test_X.txt";

//	========  Function Prototypes  ========
vector<Token> runTokenizer(string file);
void runParser(vector<Token> tokenList);

int main() {
	
	int x = 0;

	while (true) {
		
		cout << "Please input a test number (1-6) or any negative number to exit: ";
		
		cin >> x;
		
		if (x < 0) {	
			break;
		}

		Test_File = "./tests/test_" + to_string(x) + ".txt";

		if (!cin.fail()) {	

			ifstream f(Test_File.c_str());                       
			
			if (f.good()) {
				
				cout << "========  Start Test - " << Test_File << " ========" << endl;

				vector<Token> tokens = runTokenizer(Test_File);
				runParser(tokens);

				cout << "========  End Test  ========" << endl;
				
			}                                                    
			
			else {
				
				cout << "No such file found in current directory!" << endl;
			
			}
		
		}
		
		else {
			
			cout << "Bad input detected." << endl;
			
			cin.clear();
			
			cin.ignore(INT_MAX, '\n');
		
		}
	
	}
	
	return 0;

}

vector<Token> runTokenizer(string file) {

	cout << ">>> Tokenizer Running" << endl;

	Tokenizer tokenizer(_Language, file);

	vector<Token> t = tokenizer.tokenize();

	tokenizer.printTokens();

	cout << ">>> Tokenizer Done" << endl;

	return t;
}


void runParser(vector<Token> tokenList) {

	cout << endl << ">>> Parser Running" << endl;

	for (int i = 0; i < tokenList.size(); ++i) {
		cout << tokenList[i].id << endl;
	}

	cout << ">>> Parser Done" << endl;
}

