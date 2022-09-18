//	Finn Alessandrino
//	144941
#include <iostream>
#include <conio.h>
#include <string>

#include "Conversion Algorithm.h"

int main()
{
    conversion<char> conv;
    int response; std::string infix;
    do {
        std::cout << "Enter an infix expression" << std::endl;
        std::cout << "Enter expression to test: ";
        std::cin >> infix;
        std::cout << "Infix expression      : " << infix << std::endl;
        std::cout << "Postfix expression    : " << conv.convertToPostfix(infix) << std::endl << std::endl;
        std::cout << "Would you like to test more expressions? (1 = Yes/ 0 = No): ";
        std::cin >> response;
    } while (response == 1);
    std::cout << "Code compiled successfully!" << std::endl;
    std::cout << "Press any key to exit: ";
    _getch();
}
