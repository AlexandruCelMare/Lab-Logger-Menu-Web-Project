#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "classes.h"

using namespace std;


// Menu System function prototypes
void administrator();
void student();
void instructor();
void menuReturn();
void studentLogin();

// Student Modification function prototypes
void addStudent();
void deleteStudent();
void editStudent();
void viewStudent();
void studentTable();

// Instructor Modification function prototypes
void addInstructor();
void deleteInstructor();
void editInstructor();
void viewInstructor();
void instructorTable();

// Admin compartmentalization function prototypes
void adminStudents(int);
void adminInstructors(int);

//-----------------FUNCTIONS FOR MENU SYSTEM-------------------

void menuSystem::menu(){
    int initialInput = 0;
    cout << "\n| 1. Student login | 2. Instructor login | "
            "3. Administrator login | 4. Exit Program |" << endl << endl;
    cout << "(Enter a number 1-4)" << endl << endl;
    cin >> initialInput;
    if (initialInput == 1 || initialInput == 2 || initialInput == 3 ||
            initialInput == 4) {
        switch (initialInput){
                case 1: 
                    student();
                    break;
                case 2:
                    instructor();
                    break;
                case 3:
                    administrator();
                case 4:
                    exit(0); 
                default: 
                
                    cout << endl << "Not a number 1-3, try again" << endl << endl;
                    menu();
        }           
    }
    else {
       
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
       cout << "Not a number 1-4, try again" << endl;
       menu();
    } 
 }

void menuSystem::administrator(){
    instructors b;
    students a;
    int viewStudents = 0;
    int viewInstructors = 0;
    int adminInput = 0;
    int studentOrInstructor = 0;
    int studentOrClass = 0;
    int tableInput = 0;
    cout << "\n| 1. View Users | 2. View Results | 3. View Table Elements "
            "| 4. Return to Menu |"
            << endl << endl;
    cout << "(Enter a number 1-4)" << endl << endl;
    cin >> adminInput;
    cout << endl;
    if (adminInput == 1 || adminInput == 2 || adminInput == 3 ||
            adminInput == 4) {
        switch (adminInput){
            case 1: 
                cout << "| 1. View Students | 2. View Instructors | 3. Return to Menu |" << endl << endl;
                cin >> studentOrInstructor;
                if(cin.fail()){
                    cout<<"fail"<<endl;  
                }
                if (studentOrInstructor == 1){
                      adminStudents(viewStudents);
                }
                else if (studentOrInstructor == 2){
                      adminInstructors(viewInstructors);
                }
                else if (studentOrInstructor == 3){
                    menu();
                }
                break;
            case 2:
                cout << "| 1. Filter by student | 2. Filter by class | 3. Return to menu |" << endl << endl;
                cin >> studentOrClass;
                if (studentOrClass == 1){
                    a.viewStudent();
                    }
                else if (studentOrClass == 2){ 
                    cout << "Nice, you found the only missing feature." << endl;
                    menu();
                }               
                else if (studentOrClass == 3){
                    menu();
                }                 
                break;
            case 3:
                cout << "| 1. View student table elements | 2. View instructor table elements | 3. Return to menu |" << endl << endl;
                cin >> tableInput;
                if (tableInput == 1){
                    a.studentTable();
                    adminStudents(viewStudents);
                    }
                else if (tableInput == 2){ 
                    b.instructorTable();
                    adminInstructors(viewInstructors);
                }               
                else if (tableInput == 3){
                    menu();
                }                
                break;
            case 4:
                menu();
            default: 
                cout << "Default path" << endl;
        }
    }
    else {
       
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
       cout << "Not a number 1-4, try again" << endl;
       administrator();
    }   
}

//------FUNCTIONS FOR COMPARTMENTALIZING ADMIN FUNCTION----

void menuSystem::adminStudents(int viewStudents){
    students a;
    cout << "\n| 1. Delete Student | 2. Edit Student | "
            "3. View Only | 4. Return to Menu |" << endl << endl;
    cin >> viewStudents;
    if (viewStudents == 1){
        a.deleteStudent();
    }
    else if (viewStudents == 2){
        a.editStudent();
    }
    else if (viewStudents == 3){
        a.viewStudent();
    }
    else if (viewStudents == 4){
        menu();
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-4, try again" << endl;
        adminStudents(viewStudents);
    }
}

void menuSystem::adminInstructors(int viewInstructors){
    instructors b;
    cout << "\n| 1. Delete Instructor | 2. Edit Instructor | "
            "3. View Only | 4. Return to Menu |" << endl << endl;
    cin >> viewInstructors;
    if (viewInstructors == 1){
        b.deleteInstructor();
    }
    else if (viewInstructors == 2){
        b.editInstructor();
    }
    else if (viewInstructors == 3){
        b.viewInstructor();
    }
    else if (viewInstructors == 4){
        menu();
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-4, try again" << endl;
        adminInstructors(viewInstructors);
    }
}
    
//------LOGIN AND ACCOUNT CREATION FOR STUDENTS-------
void menuSystem::student(){
    students a;
    int studentInput = 0;
    cout << endl << "| 1. Log in | 2. Create account | "
            "3. Return to Menu |" << endl << endl;
    cout << "(Enter a number 1-3)" << endl << endl;
    cin >> studentInput;
    cout << endl;
    if (studentInput == 1 || studentInput == 2 || studentInput == 3) {
        switch (studentInput){
            case 1: 
                a.studentLogin();
                break;
            case 2:
                a.addStudent();
                menuReturn();
                break;
            case 3:
                menu();
            default: 
                cout << "Default path" << endl;
        }
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-3, try again" << endl;
        student();
    }   
}

//------LOGIN AND ACCOUNT CREATION FOR INSTRUCTORS-------

void menuSystem::instructor(){
    instructors b;
    int instructorInput = 0;
    cout << endl << "| 1. Log in | 2. Create account | "
            "3. Return to Menu |" << endl << endl;
    cout << "(Enter 1 or 2)" << endl << endl;
    cin >> instructorInput;
    cout << endl;
    if (instructorInput == 1 || instructorInput == 2 || instructorInput == 3 ) {
        switch (instructorInput){
            case 1: 
                b.instructorLogin();
                break;
            case 2:
                b.addInstructor();
                break;
            case 3:
                menu();
            default: 
                cout << "Default path" << endl;
        }
    }
    else {
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
        }
        
        cout << "Not a number 1-3, try again" << endl;
        instructor();
    }   
}

// VIEW STUDENTS

void students::viewStudent(){
    menuSystem c;
    fstream ofile;
    string view;
    int viewInput;
    int counter = 0;
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
    // Course
    string *courseList = new string[accountNum]; // For adding courses
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    
    cout << "\nChoose student username to view (enter #):" << endl << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << endl;
    }
    
    cout << endl;
    cin >> viewInput;
    viewInput--;
    
    // For dates
    for (int i = 0; i < dateList[viewInput].length(); i++){
        if (dateList[viewInput][i] == ' '){
            counter++;
        }    
    }
    
    string *dateDesign = new string[counter + 1];
    stringstream ss(dateList[viewInput]);
    int i = 0;
    while (ss >> dateDesign[i]){
        i++;
    }
    counter = 0;
    // For hours
    for (int i = 0; i < hourList[viewInput].length(); i++){
        if (hourList[viewInput][i] == ' '){
            counter++;
        }    
    }
    string temp;
    int *hourDesign = new int[counter + 1];
    stringstream ss2(hourList[viewInput]);
    i = 0;
    while (ss2 >> temp){
        hourDesign[i] = stoi(temp);
        i++;       
    }
    // For adding the values in the hours array
    int comHours = 0;
    for (int i = 0; i < (counter + 1); i++){
        comHours += hourDesign[i];
    }
    
    
    cout << "\nCumulative Hours: ";
    cout << comHours << endl;
    cout << "\nDates attended:" << endl;
    for (int i = 0; i < (counter + 1); i++){
        cout << dateDesign[i] << endl;
    }

    ofile.close();
    delete []userList;
    delete []passList;
    delete []dateList;
    delete []hourList;
    delete []courseList;
    delete []dateDesign;
    delete []hourDesign;
    
    c.menuReturn();
}

// VIEW INSTRUCTORS

void instructors::viewInstructor(){
    menuSystem c;
    fstream ofile;
    string view;
    int viewInput;
    int counter = 0;
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
    // Course
    string *courseList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }
    
    cout << "\nChoose instructor username to view (enter #):" << endl << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << endl;
    }
    
    cout << endl;
    cin >> viewInput;
    viewInput--;
    
    // For dates
    for (int i = 0; i < dateList[viewInput].length(); i++){
        if (dateList[viewInput][i] == ' '){
            counter++;
        }    
    }
    
    string *dateDesign = new string[counter + 1];
    stringstream ss(dateList[viewInput]);
    int i = 0;
    while (ss >> dateDesign[i]){
        i++;
    }
    counter = 0;
    // For hours
    for (int i = 0; i < hourList[viewInput].length(); i++){
        if (hourList[viewInput][i] == ' '){
            counter++;
        }    
    }
    string temp;
    int *hourDesign = new int[counter + 1];
    stringstream ss2(hourList[viewInput]);
    i = 0;
    while (ss2 >> temp){
        hourDesign[i] = stoi(temp);
        i++;       
    }
    // For adding the values in the hours array
    int comHours = 0;
    for (int i = 0; i < (counter + 1); i++){
        comHours += hourDesign[i];
    }
    
    
    cout << "\nCumulative Hours: ";
    cout << comHours << endl;
    cout << "\nDates attended:" << endl;
    for (int i = 0; i < (counter + 1); i++){
        cout << dateDesign[i] << endl;
    }
    
    ofile.close();
    delete []userList;
    delete []passList;
    delete []dateList;
    delete []hourList;
    delete []courseList;
    delete []dateDesign;
    delete []hourDesign;
    
    c.menuReturn();
}

// Function for viewing table elements of students

void students::studentTable(){
    fstream ofile;
    string view;
   
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
    // Course
    string *courseList = new string[accountNum]; // For adding hours
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }

    cout << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << '\t' << passList[i] << '\t'
                << dateList[i] << '\t' << hourList[i] << '\t' << courseList[i] << endl;
    }
    
    ofile.close();
    delete []userList;
    delete []passList;
    delete []dateList;
    delete []hourList;
    delete []courseList;
    
}

// Function for viewing table elements of students

void instructors::instructorTable(){
    fstream ofile;
    string view;
   
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
    // Course
    string *courseList = new string[accountNum]; // For adding courses
    for (int i = 0; i < accountNum; i++){
        getline(ofile, courseList[i]);
    }

    cout << endl;
    for (int i = 0; i < accountNum; i++){
        cout << (i + 1) << ". " << userList[i] << '\t' << passList[i] << '\t'
                << dateList[i] << '\t' << hourList[i] << '\t' << courseList[i] << endl;
    }
    
    ofile.close();
    delete []userList;
    delete []passList;
    delete []dateList;
    delete []hourList;
    delete []courseList;
}