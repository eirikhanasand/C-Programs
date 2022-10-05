//
//  employeeFunctions.h
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#ifndef employeeFunctions_h
#define employeeFunctions_h

#include <stdio.h>

const int STRLEN = 80;

//Employee number, name and hourly rate
typedef struct{
    int employeeNUM;
    char name[STRLEN];
    float hourlyRate;
} firstEMP;

//2nd Employee number, name and hourly rate
typedef struct{
    int employeeNUM;
    char name[STRLEN];
    float hourlyRate;
} secondEMP;

//Helpstruct for copying
typedef struct{
    int employeeNUM;
    char name[STRLEN];
    float hourlyRate;
} helpStruct;

#endif /* employeeFunctions_h */
