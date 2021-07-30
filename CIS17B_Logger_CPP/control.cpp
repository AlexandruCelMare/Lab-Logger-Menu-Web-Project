
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "classes.h"

using namespace std;

void menu();

void menuSystem::menuReturn(){
    char menuR = 0;
    cout << endl << "Return to menu? (y/n)" << endl << endl;
    cin >> menuR;
    if (menuR == 'y'){
        menu();
    }
    else if (menuR == 'n'){
        exit(0);
    }
    else {
        menuReturn();
    }
    
}