#remove old objects
rm *.o
rm *.out
rm *.list

#compile cpp files
g++ -m64 -c -o Grammar.o Grammar.cpp
g++ -m64 -c -o main.o main.cpp
g++ -m64 -c -o Node.o Node.cpp
g++ -m64 -c -o Parser.o Parser.cpp
g++ -m64 -c -o Symbol.o Symbol.cpp
g++ -m64 -c -o SymTable.o SymTable.cpp
g++ -m64 -c -o token.o token.h
g++ -m64 -c -o token_printer.o token_printer.cpp
g++ -m64 -c -o Tokenizer.o Tokenizer.cpp
g++ -m64 -c -o txt_to_strings.o txt_to_strings.cpp

#link all files
g++ -m64 -o project.out Grammar.o main.o Node.o Parser.o Symbol.o SymTable.o token.o token_printer.o Tokenizer.o txt_to_strings.o

sleep 10s

#call program
./project.out
