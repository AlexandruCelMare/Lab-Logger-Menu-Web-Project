#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "classes.h"

using namespace std;

// Menu System function headers
void menuReturn();

//-----------------FUNCTIONS FOR MODIFYING STUDENT STUFF-------------------

void students::addStudent(){
    menuSystem c;
    fstream ofile; // File setup
    string username;
    string password;
    string date;
    string hours;
    string course;
    int accountNum;
    
    bool pass;
    
    ofile.open("student.txt", ios::in); 
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    // User and pass
    string *userList = new string[accountNum]; // For adding usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For adding passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
    // Date and hours
    string *dateList = new string[accountNum]; // For adding dates
    for (int i = 0; i < accountNum; i++){
        getline(ofile, dateList[i]);
    }
    string *hourList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, hourList[i]);
    }
    string *courseList = new string[accountNum]; // For adding courses
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    
    ofile.close();
    cout << "Please enter student username: " << endl << endl;
    getline(cin, username);
    
    cout << "\nPlease enter student password:" << endl << endl;
    getline(cin, password);
    cout << endl;
    do{
        pass = true;
        for (int i = 0; i < password.length(); i++){
            if (password[i] == 32){
                pass = false;
            }
        }
        if (pass == false){
            cout << "\nPassword contains whitespaces." << endl;
            cout << "Please try another password:" << endl << endl;
            getline(cin, password);
        }
    } while (pass == false);
    
    cout << "\nEnter Login Date (ie. 04/09/21):" << endl << endl;
    getline(cin, date);
    while (date.length() != 8){
        cout << "\nError detected." << endl << "Enter Login Date (ie. 4/09/21):" << endl << endl;
        getline(cin, date);
    }
    
    cout << "\nEnter hours logged in: " << endl << endl;
    getline(cin, hours);
    
    cout << "\nEnter course name (no space, ie. CIS-7):" << endl << endl;
    getline(cin, course);
    do{
        pass = true;
        for (int i = 0; i < course.length(); i++){
            if (course[i] == 32){
                pass = false;
            }
        }
        if (pass == false){
            cout << "\nCourse contains whitespaces." << endl;
            cout << "Please try another course:" << endl << endl;
            getline(cin, course);
        }
    } while (pass == false);
    
    ofile.open("student.txt", ios::out);
    accountNum++;
    ofile << accountNum << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    ofile << username << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    ofile << password << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves dates to database
        ofile << dateList[i] << endl;
    }
    ofile << date << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves hours to database
        ofile << hourList[i] << endl;
    }
    ofile << hours << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves course to database
        ofile << courseList[i] << endl;
    }
    ofile << course << endl;
    
    delete []passList;
    delete []userList;
    delete []dateList;
    delete []hourList;
    delete []courseList;
    
    c.menuReturn();
}

void students::deleteStudent(){   
    menuSystem c;
    fstream ofile; // File setup
    int username;
    int accountNum;
    int delInput;
    
    ofile.open("student.txt", ios::in); 
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    
    string *userList = new string[accountNum]; // For adding usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For adding passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
    // Date and hours
    string *dateList = new string[accountNum]; // For adding dates
    for (int i = 0; i < accountNum; i++){
        getline(ofile, dateList[i]);
    }
    string *hourList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, hourList[i]);
    }
    string *courseList = new string[accountNum]; // For adding courses
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    ofile.close();
    
    cout << "\nChoose student username to delete (enter #):" << endl << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << endl;
    }
    
    cout << endl;
    cin >> delInput;
    delInput--;
    
    for (int i = delInput; i < (accountNum - 1); i++){
        userList[i] = userList[i + 1];
    }
    for (int i = delInput; i < (accountNum - 1); i++){
        passList[i] = passList[i + 1];
    }
    for (int i = delInput; i < (accountNum - 1); i++){
        dateList[i] = dateList[i + 1];
    }    
    for (int i = delInput; i < (accountNum - 1); i++){
        hourList[i] = hourList[i + 1];
    }    
    for (int i = delInput; i < (accountNum - 1); i++){
        courseList[i] = courseList[i + 1];
    }
    ofile.open("student.txt", ios::out);
    --accountNum;
    ofile << accountNum << endl; 
    for (int i = 0; i < (accountNum); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    for (int i = 0; i < (accountNum); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    for (int i = 0; i < (accountNum); i++){ // Saves dates to database
            ofile << dateList[i] << endl;
    }
    for (int i = 0; i < (accountNum); i++){ // Saves hours to database
            ofile << hourList[i] << endl;
    }
    for (int i = 0; i < (accountNum); i++){ // Saves course to database
            ofile << courseList[i] << endl;
    }
    ofile.close();
    
    delete []userList;
    delete []passList;
    delete []hourList;
    delete []dateList;
    delete []courseList;
    
    c.menuReturn();
}

void students::editStudent(){
    menuSystem c;
    fstream ofile;
    int editInput;
    int editOption;
    string newVal;
    int accountNum = 0;

    
    ofile.open("student.txt", ios::in); 
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    // User and pass
    string *userList = new string[accountNum]; // For adding usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For adding passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
    // Date and hours
    string *dateList = new string[accountNum]; // For adding dates
    for (int i = 0; i < accountNum; i++){
        getline(ofile, dateList[i]);
    }
    string *hourList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, hourList[i]);
    }
    string *courseList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    
    ofile.close();
    
    cout << "\nChoose the student username to edit (enter #):" << endl << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << endl; 
    }
    cout << endl;
    cin >> editInput;
    cout << endl << "| 1. Edit User | 2. Edit Password | "
            "3. Edit Dates | 4. Edit Hours | 5. Edit Course |" << endl << endl;
    cin >> editOption;
    if (editOption == 1 || editOption == 2 || editOption == 3 || editOption == 4 || editOption == 5) {
        switch (editOption){
            case 1: 
                cout << "Please enter the new username: " << endl << endl;
                cin >> newVal;
                userList[editInput - 1] = newVal;
                break;
            case 2:
                cout << "Please enter the new password: " << endl << endl;
                cin >> newVal;
                passList[editInput - 1] = newVal;
                break;
            case 3:
                cout << "Please enter the new dates: " << endl << endl;
                cin >> newVal;
                dateList[editInput - 1] = newVal;
                break;
            case 4:
                cout << "Please enter the new hours: " << endl << endl;
                cin >> newVal;
                hourList[editInput - 1] = newVal;
                break;
            case 5:
                cout << "Please enter the new course name (ie. CIS 17B): " << endl << endl;
                cin >> newVal;
                courseList[editInput - 1] = newVal;
                break;
            default: 
                cout << "Default path" << endl;
        }    
    }
    else {
       cout << "Not a number 1-5, try again" << endl;
       editStudent();
       return;
    }   

    ofile.open("student.txt", ios::out);
    ofile << accountNum << endl;
    
    for (int i = 0; i < (accountNum); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves dates to database
            ofile << dateList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves hours to database
            ofile << hourList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves course to database
            ofile << courseList[i] << endl;
    }
    
    ofile.close();
    delete []userList;
    delete []passList;
    delete []dateList;
    delete []hourList;
    delete []courseList;

    c.menuReturn();
}




//-----------------FUNCTIONS FOR MODIFYING INSTRUCTOR STUFF-------------------

void instructors::addInstructor(){
    menuSystem c;
    fstream ofile; // File setup
    string username;
    string password;
    string date;
    string hours;
    string course;
    int accountNum;
    
    bool pass;
    
    ofile.open("instructor.txt", ios::in); 
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    // User and pass
    string *userList = new string[accountNum]; // For adding usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For adding passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
    // Date and hours
    string *dateList = new string[accountNum]; // For adding dates
    for (int i = 0; i < accountNum; i++){
        getline(ofile, dateList[i]);
    }
    string *hourList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, hourList[i]);
    }
    string *courseList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    ofile.close();
    cout << "Please enter instructor username: " << endl << endl;
    getline(cin, username);
    
    cout << "\nPlease enter instructor password:" << endl << endl;
    getline(cin, password);
    
    do{
        pass = true;
        for (int i = 0; i < password.length(); i++){
            if (password[i] == 32){
                pass = false;
            }
        }
        if (pass == false){
            cout << "\nPassword contains whitespaces." << endl;
            cout << "Please try another password:" << endl << endl;
            getline(cin, password);
        }
    } while (pass == false);
    
    cout << "\nEnter Login Date (ie. 04/09/21):" << endl << endl;
    getline(cin, date);
    while (date.length() != 8){
        cout << "\nError detected." << endl << "Enter Login Date (ie. 4/09/21):" << endl << endl;
        getline(cin, date);
    }
    
    cout << "\nEnter hours logged in: " << endl << endl;
    getline(cin, hours);
    
    cout << "\nEnter course name (ie. CIS-7):" << endl << endl;
    getline(cin, course);
    do{
        pass = true;
        for (int i = 0; i < course.length(); i++){
            if (course[i] == 32){
                pass = false;
            }
        }
        if (pass == false){
            cout << "\nCourse contains whitespaces." << endl;
            cout << "Please try another course:" << endl << endl;
            getline(cin, course);
        }
    } while (pass == false);
    ofile.open("instructor.txt", ios::out);
    accountNum++;
    ofile << accountNum << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    ofile << username << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    ofile << password << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves dates to database
        ofile << dateList[i] << endl;
    }
    ofile << date << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves hours to database
        ofile << hourList[i] << endl;
    }
    ofile << hours << endl;
    
    for (int i = 0; i < (accountNum - 1); i++){ // Saves hours to database
        ofile << courseList[i] << endl;
    }
    ofile << course << endl;
    
    delete []passList;
    delete []userList;
    delete []dateList;
    delete []hourList;
    delete []courseList;
    
    c.menuReturn();
}

void instructors::deleteInstructor(){    
    menuSystem c;
    fstream ofile; // File setup
    int username;
    int accountNum;
    int delInput;
    
    ofile.open("instructor.txt", ios::in); 
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    
    string *userList = new string[accountNum]; // For adding usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For adding passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
    // Date and hours
    string *dateList = new string[accountNum]; // For adding dates
    for (int i = 0; i < accountNum; i++){
        getline(ofile, dateList[i]);
    }
    string *hourList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, hourList[i]);
    }
    string *courseList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    ofile.close();
    
    cout << "\nChoose instructor username to delete (enter #):" << endl << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << endl;
    }
    
    cout << endl;
    cin >> delInput;
    delInput--;
    
    for (int i = delInput; i < (accountNum - 1); i++){
        userList[i] = userList[i + 1];
    }
    for (int i = delInput; i < (accountNum - 1); i++){
        passList[i] = passList[i + 1];
    }
    for (int i = delInput; i < (accountNum - 1); i++){
        dateList[i] = dateList[i + 1];
    }    
    for (int i = delInput; i < (accountNum - 1); i++){
        hourList[i] = hourList[i + 1];
    }    
    for (int i = delInput; i < (accountNum - 1); i++){
        courseList[i] = courseList[i + 1];
    }
    ofile.open("instructor.txt", ios::out);
    --accountNum;
    ofile << accountNum << endl; 
    for (int i = 0; i < (accountNum); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    for (int i = 0; i < (accountNum); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    for (int i = 0; i < (accountNum); i++){ // Saves dates to database
            ofile << dateList[i] << endl;
    }
    for (int i = 0; i < (accountNum); i++){ // Saves hours to database
            ofile << hourList[i] << endl;
    }
    for (int i = 0; i < (accountNum); i++){ // Saves course to database
            ofile << courseList[i] << endl;
    }
    ofile.close();
    
    delete []userList;
    delete []passList;
    delete []hourList;
    delete []dateList;
    delete []courseList;
    
    c.menuReturn();
}   

void instructors::editInstructor(){
    menuSystem c;
    fstream ofile;
    int editInput;
    int editOption;
    string newVal;
    int accountNum = 0;

    
    ofile.open("instructor.txt", ios::in); 
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    // User and pass
    string *userList = new string[accountNum]; // For adding usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For adding passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
    // Date and hours
    string *dateList = new string[accountNum]; // For adding dates
    for (int i = 0; i < accountNum; i++){
        getline(ofile, dateList[i]);
    }
    string *hourList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, hourList[i]);
    }
    string *courseList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    
    ofile.close();
    
    cout << "\nChoose the instructor username to edit (enter #):" << endl << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << endl; 
    }
    cout << endl;
    cin >> editInput;
    cout << endl << "| 1. Edit User | 2. Edit Password | "
            "3. Edit Dates | 4. Edit Hours | 5. Edit Course |" << endl << endl;
    cin >> editOption;
    if (editOption == 1 || editOption == 2 || editOption == 3 || editOption == 4 || editOption == 5) {
        switch (editOption){
            case 1: 
                cout << "\nPlease enter the new username: " << endl << endl;
                cin >> newVal;
                userList[editInput - 1] = newVal;
                break;
            case 2:
                cout << "\nPlease enter the new password: " << endl << endl;
                cin >> newVal;
                passList[editInput - 1] = newVal;
                break;
            case 3:
                cout << "\nPlease enter the new dates: " << endl << endl;
                cin >> newVal;
                dateList[editInput - 1] = newVal;
                break;
            case 4:
                cout << "\nPlease enter the new hours: " << endl << endl;
                cin >> newVal;
                hourList[editInput - 1] = newVal;
                break;
            case 5:
                cout << "\nPlease enter the new course name (ie. CIS 17B): " << endl << endl;
                cin >> newVal;
                courseList[editInput - 1] = newVal;
                break;
            default: 
                cout << "Default path" << endl;
        }    
    }
    else {
       cout << "Not a number 1-5, try again" << endl;
       editInstructor();
       return;
    }   

    ofile.open("instructor.txt", ios::out);
    ofile << accountNum << endl;
    
    for (int i = 0; i < (accountNum); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves dates to database
            ofile << dateList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves hours to database
            ofile << hourList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves course to database
            ofile << courseList[i] << endl;
    }
    
    ofile.close();
    delete []userList;
    delete []passList;
    delete []dateList;
    delete []hourList;
    delete []courseList;

    c.menuReturn();
}

// Function for logging in as student

void students::studentLogin(){
    menuSystem c;
    fstream ofile;
    string username;
    string password;
    string date;
    string hours;
    int accountNum;
    int userLocation;
    
    bool userValid = false;
    bool passValid = false;
    
    ofile.open("student.txt", ios::in);
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    
    string *userList = new string[accountNum]; // For grabbing usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For grabbing passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
        // Date and hours
    string *dateList = new string[accountNum]; // For adding dates
    for (int i = 0; i < accountNum; i++){
        getline(ofile, dateList[i]);
    }
    string *hourList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, hourList[i]);
    }
    string *courseList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    
    
    ofile.close();
    cout << "Please enter student username: " << endl << endl;
    getline(cin, username);
    
    do{
        for (int i = 0; i < (accountNum); i++){
            if (userList[i] == username){
                userValid = true;
                userLocation = i;
            }
        }
        if (userValid == false){
            cout << "\nUsername does not exist, try again:" << endl << endl;
            getline(cin, username);
        }
    } while (userValid == false);
    
    cout << "\nPlease enter password: " << endl << endl;
    getline(cin, password);
    
    do{
        if (passList[userLocation] == password){
                passValid = true;
            }
    
        if (passValid == false){
            cout << "\nIncorrect password, try again:" << endl << endl;
            getline(cin, password);
        }
    } while (passValid == false);
    
    cout << "\nEnter Login Date (ie. 04/09/21):" << endl << endl;
    getline(cin, date);
    while (date.length() != 8){
        cout << "\nError detected." << endl << "Enter Login Date (ie. 4/09/21):" << endl << endl;
        getline(cin, date);
    }
    
    cout << "\nEnter hours logged in: " << endl << endl;
    getline(cin, hours);
   
    ofile.open("student.txt", ios::out);
    ofile << accountNum << endl;
    
    for (int i = 0; i < (accountNum); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves dates to database
        if (i == userLocation){
            dateList[i] += ' ' + date;
        }
            ofile << dateList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves hours to database
        if (i == userLocation){
            hourList[i] += ' ' + hours;
        }
            ofile << hourList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves course to database
        ofile << courseList[i] << endl;
    }
    
    ofile.close();
    
    delete []passList;
    delete []userList;
    delete []dateList;
    delete []hourList;
    delete []courseList;
    
    c.menuReturn();
}

// Function for logging in as instructor

void instructors::instructorLogin(){
    menuSystem c;
    fstream ofile;
    string username;
    string password;
    string date;
    string hours;
    int accountNum;
    int userLocation;
    
    bool userValid = false;
    bool passValid = false;
    
    ofile.open("instructor.txt", ios::in);
    cin.ignore();
    ofile >> accountNum;
    ofile.ignore();
    
    string *userList = new string[accountNum]; // For grabbing usernames
    for (int i = 0; i < accountNum; i++){
        getline(ofile, userList[i]);
    }
    string *passList = new string[accountNum]; // For grabbing passwords
    for (int i = 0; i < accountNum; i++){
        getline(ofile, passList[i]);
    }
        // Date and hours
    string *dateList = new string[accountNum]; // For adding dates
    for (int i = 0; i < accountNum; i++){
        getline(ofile, dateList[i]);
    }
    string *hourList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, hourList[i]);
    }
    string *courseList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    
    ofile.close();
    cout << "Please enter instructor username: " << endl << endl;
    getline(cin, username);
    
    do{
        for (int i = 0; i < (accountNum); i++){
            if (userList[i] == username){
                userValid = true;
                userLocation = i;
            }
        }
        if (userValid == false){
            cout << "\nUsername does not exist, try again:" << endl << endl;
            getline(cin, username);
        }
    } while (userValid == false);
    
    cout << "\nPlease enter password: " << endl << endl;
    getline(cin, password);
    
    do{
        if (passList[userLocation] == password){
                passValid = true;
            }
    
        if (passValid == false){
            cout << "\nIncorrect password, try again:" << endl << endl;
            getline(cin, password);
        }
    } while (passValid == false);
    
    cout << "\nEnter Login Date (ie. 04/09/21):" << endl << endl;
    getline(cin, date);
    while (date.length() != 8){
        cout << "\nError detected." << endl << "Enter Login Date (ie. 04/09/21):" << endl << endl;
        getline(cin, date);
    }
    
    cout << "\nEnter hours logged in: " << endl << endl;
    getline(cin, hours);

    ofile.open("instructor.txt", ios::out);
    ofile << accountNum << endl;
    
    for (int i = 0; i < (accountNum); i++){ // Saves username to database
        ofile << userList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves password to database
        ofile << passList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves dates to database
        if (i == userLocation){
            dateList[i] += ' ' + date;
        }
            ofile << dateList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves hours to database
        if (i == userLocation){
            hourList[i] += ' ' + hours;
        }
            ofile << hourList[i] << endl;
    }
    
    for (int i = 0; i < (accountNum); i++){ // Saves username to database
        ofile << courseList[i] << endl;
    }    
    
    ofile.close();
    
    delete []passList;
    delete []userList;
    delete []dateList;
    delete []hourList;
    delete []courseList;
    
    c.menuReturn();
}

