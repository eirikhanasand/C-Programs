//
//  employeeFunctions.c
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#include "employeeFunctions.h"
#include <string.h>

helpStruct help;                //Helpstruct for copying
firstEMP employee;              //1st employee struct
secondEMP employee2;            //2nd employee struct
const int MAXEMP = 10;          //Max employees

void all(void);                 //Show all employees
void mywrite(int structNUM);    //Which struct to print
void otherWay(void);            //Print structs in reverse order

/**
  Main program which initialises function one and asks for input for function 2. Also uses the  reverse
  functions to print in the opposite order.
 */
int main(){
    int structNUM = 0;
    employee.employeeNUM = 1;
    strcpy(employee.name, "bob");
    employee.hourlyRate = 180;
    
    employee2.employeeNUM = 2;
    printf("Name: "); scanf("%s", employee2.name);
    printf("Hourly rate: "); scanf("%f", &employee2.hourlyRate);
    
    mywrite(structNUM);
    all();
    
    otherWay();
    all();
    return 0;
}

//Asks the user which struct they would like to print
void mywrite(int structNUM){
    printf("Which struct would you like to print?\n");
    scanf("%i", &structNUM);
    
    if (structNUM == 1) {
        printf("Employee: %i, ", employee.employeeNUM);
        printf("Name: %s, ", employee.name);
        printf("Hourly rate: %.2f\n", employee.hourlyRate);
    }else{
        printf("Employee: %i, ", employee2.employeeNUM);
        printf("Name: %s, ", employee2.name);
        printf("Hourly rate: %.2f\n", employee2.hourlyRate);
    }

}

//Prints all structs
void all(void){
    printf("\nPrinting all structs:\n");
    printf("Employee: %i, ", employee.employeeNUM);
    printf("Name: %s, ", employee.name);
    printf("Hourly rate: %.2f\n", employee.hourlyRate);
    printf("Employee: %i, ", employee2.employeeNUM);
    printf("Name: %s, ", employee2.name);
    printf("Hourly rate: %.2f\n", employee2.hourlyRate);
}

//Prints all structs in reverse order
void otherWay(void){
    //help.employeeNUM = employee.employeeNUM;
    strcpy(help.name, employee.name);
    help.hourlyRate = employee.hourlyRate;
    
    //employee.employeeNUM = employee2.employeeNUM;
    strcpy(employee.name, employee2.name);
    employee.hourlyRate = employee2.hourlyRate;
    
    //employee2.employeeNUM = help.employeeNUM;
    strcpy(employee2.name, help.name);
    employee2.hourlyRate = help.hourlyRate;
    
}
