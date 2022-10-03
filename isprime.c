//
//  isprime.c
//  Basics
//
//  Created by Eirik Hanasand on 26/09/2022.
//
//  Checks if a number is a prime
//

#include <stdio.h>      //Included for printf etc.
#include <stdbool.h>    //Included for bools

int main(void){
    int i, j;           //Used by for loops
    bool isPrime;       //true if prime

        //For every
        for (i = 2; i <= 50; ++i) {
        isPrime = false;
            
            //Loops start at 2 because this is the lowest prime
            for (j = 2; j < i; ++j)
                if (i % j == 0)         //Prime if no rest
                    isPrime = true;     //True if prime

                if (isPrime != true)    //If prime is true
                    printf("%i ", i);   //Prime is printed

        }

    printf("\n"); //Line break
    
    return 0;     //Terminatees the program
}
