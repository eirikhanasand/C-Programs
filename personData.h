//
//  personData.h
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#ifndef Oppgave_27_h
#define Oppgave_27_h

#include <stdio.h>
const int STRLEN = 80;  //Max text length

//Struct for name age and weight
typedef struct{
    char name[STRLEN];
    int age;
    float weight;
} Person;

#endif /* personData_h */
