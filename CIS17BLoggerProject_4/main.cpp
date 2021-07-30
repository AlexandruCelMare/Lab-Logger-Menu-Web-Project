/* 
 * File:   main.cpp
 * Modified by: Alexander Butarita
 * Created on March 19, 2021
 * Professor: Dr. Lehr
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

#include "classes.h"

// Menu function prototype
void menu();

using namespace std;

// Website used for ASCII art: http://patorjk.com/software/taag/#p=display&f=Modular&t=E-Shop
int main(int argc, char** argv) {
    // Main window
    menuSystem c;
cout << " ___      _______  _______    _______  __   __  _______  _______  _______    _______        _______ " << endl;
cout << "|   |    |       ||       |  |       ||  | |  ||       ||       ||       |  |       |      |  _    |" << endl;
cout << "|   |    |   _   ||    ___|  |  _____||  |_|  ||    ___||    ___||_     _|  |____   |      | | |   |" << endl;
cout << "|   |    |  | |  ||   | __   | |_____ |       ||   |___ |   |___   |   |     ____|  |      | | |   |" << endl;
cout << "|   |___ |  |_|  ||   ||  |  |_____  ||       ||    ___||    ___|  |   |    | ______| ___  | |_|   |" << endl;
cout << "|       ||       ||   |_| |   _____| ||   _   ||   |___ |   |___   |   |    | |_____ |   | |       |" << endl;
cout << "|_______||_______||_______|  |_______||__| |__||_______||_______|  |___|    |_______||___| |_______|" << endl;
cout << "THE LAB LOGIN SHEET, BUT LIKE, BETTER.";
cout << endl << endl;

    c.menu();
    
    return 0;
}
