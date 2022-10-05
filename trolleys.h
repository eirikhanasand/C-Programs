//
//  trolleys.h
//  Basics
//
//  Created by Eirik Hanasand on 05/10/2022.
//

#ifndef trolleys_h
#define trolleys_h

#include <stdio.h>      //Included for printf etc.
#include <stdbool.h>    //Included for bool in struct
#include <stdbool.h>    //Included for bool
#include <ctype.h>      //Included for toupper etc.
#include <string.h>     //Included for strcmp etc.

//Rented status, renttaker and phonenumber for potential renter.
struct Trolley {
    bool rented;
    char name[80];
    int  pNum;
};

#endif /* trolleys_h */
