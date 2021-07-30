/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   handleStudents.h
 * Author: alexa
 *
 * Created on April 21, 2021, 10:16 AM
 */

#ifndef CLASSES_H
#define CLASSES_H

class students {
public:
    void addStudent();
    void deleteStudent();
    void editStudent();
    void viewStudent();
    void studentLogin();
    void studentTable();
};

class instructors {
public:
    void addInstructor();
    void deleteInstructor();
    void editInstructor();
    void viewInstructor();
    void instructorLogin();
    void instructorTable();
};

class menuSystem {
public:
    void administrator();
    void menuReturn();
    void menu();
    void adminStudents(int);
    void adminInstructors(int);
    void student();
    void instructor();
};



#endif /* CLASSES_H */

