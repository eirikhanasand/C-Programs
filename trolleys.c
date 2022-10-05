//
//  trolleys.c
//  Basics
//
//  Created by Eirik Hanasand on 05/10/2022.
//

/**
 * This file contains a system for renting trolleys, view status for all trolleys, available trolleys, give back
 * trolleys, view all renttakers and terminate the program
 *
 *  @file       trolleys.c
 *  @date       5. Okt 2022
 *  @version    1
 *  @author     Eirik Hanasand
 */

#include "trolleys.h"                   //H file for struct and libraries used

const int MAXTROLLEYS =  30;            //Max amount of trolleys
const int STRLEN = 80;                  //Renters name
struct Trolley gTrolley[MAXTROLLEYS];   //Rentname, trolleynum, structnum
int gTrolleysRented   =   0;            //Trolleys rented out

void available(void);                   //View all available trolleys
void empty(void);                       //All trolleys to not rented
void findRenter(void);                  //Search renters by name
void handIn(void);                      //Hand in trolleys
void menu(void);                        //Writes menu and choice
void overView(void);                    //Trolleys already rented
char readChar(void);                    //Read char
int  readInt(void);                     //Read int
void rentOut(void);                     //Rent out trolley

/**
 * Main program  contains a system for renting trolleys, view status for all trolleys, available trolleys, give back
 * trolleys, view all renttakers and terminate the program
 */
int main(){
    char choice = 0;
    empty();
    do {
        menu();
        choice = readChar();
        getchar();
        switch (choice) {
            case 'O': overView();                         break;  //See rented
            case 'A': available();                        break;  //See available
            case 'R': rentOut();                          break;  //Rent out
            case 'H': handIn();                      break;  //Hand in
            case 'F': findRenter();                       break;  //Find renter
            case 'Q': printf("Terminated  '%c'", choice); break;  //Quit program
            default : printf("Not allowed '%c'", choice); break;  //Illegal input
        }
    } while (choice != 'Q');
    return 0;
}

//View all available trolleys, error if all or none are available
void available(){
    if(gTrolleysRented == 0){
        printf("All trolleys are available!\n");
    }else if (gTrolleysRented == 30) {
        printf("All trolleys are rented!\n");
    }else{
        printf("Available:\n");
        for(int i = 0; i < MAXTROLLEYS; i++){
            if (gTrolley[i+1].rented == 0) {
                printf("Trallenr: %i\n", i+1);
            }
        }
    }
}

//Sets all trolleys to available
void empty(){
    for (int i = 0; i < MAXTROLLEYS; i++) {
        gTrolley[i].rented = 0;
    }
}

/**
 * Find renttaker based on name. Error if no trolleys are rented or no match was found.
 * Every match listed if match is found.
 */
void findRenter(){
    int funn = 0;
    if (gTrolleysRented == 0) {
        printf("No trolleys rented!\n");
    }else{
        char person[STRLEN];
        printf("Searching for person:\n");
        fgets(person, STRLEN, stdin);
        person[strlen(person)-1] = '\0';
        for(int i = 0; i <= MAXTROLLEYS; i++){
            if (!strcmp(gTrolley[i].name, person)) {
                funn++;
            }
        }
       
        if(funn > 0){
            printf("Results:\n");
            for(int i = 0; i <= MAXTROLLEYS; i++){
                if (!strcmp(gTrolley[i].name, person)) {
                    printf("TrolleyNUM: %i, Renter name: %s, Phone number: %i\n",
                           i, gTrolley[i].name, gTrolley[i].pNum);
                }
            }
        }else{
            printf("This person is not renting any trolleys.\n");
        }
    }
}

//Hand in trolleys, error if none or said trolley is not rented by anyone
void handIn(){
    int i = 0;
    if (gTrolleysRented == 0) {
        printf("No trolleys are rented!\n");
    }else{
        printf("Which trolley would you like to hand in?\n");
        i = readInt();
        if (gTrolley[i].rented == 1) {
            getchar();
            gTrolleysRented--;
            strcpy(gTrolley[i].name, "0");
            gTrolley[i].rented = 0;
            gTrolley[i].pNum = 0;
            printf("Trolley %i handed in!\n", i);
        }else{
            printf("This trolley is not rented!\n");
            getchar();
        }
    }
}

//Writes menu
void menu(){
    printf("The choice is yours.. (O, L, U, I, F, Q)\n");
    printf("O - Overview\n");
    printf("A - Available\n");
    printf("R - Rent out\n");
    printf("H - Hand in\n");
    printf("F - Find renter\n");
    printf("Q - Quit program\n");
}

//View status for all trolleys, error if all are available
void overView(){
    if (gTrolleysRented == 0) {
        printf("All trolleys are available!\n");
    }else{
        printf("Rented trolleys:\n");
        for(int i = 0; i <= MAXTROLLEYS; i++){
            if (gTrolley[i].rented == 1) {
                printf("TrolleyNUM: %i, Renters name: %s, Phone number: %i\n",
                       i, gTrolley[i].name, gTrolley[i].pNum);
            }
        }
    }
}

//Read chars
char readChar(){
    char choice = 0;
    choice = getchar();
    choice = toupper(choice);
    return choice;
}

//Read integers
int readInt(void){
    int trolleynum = 0;
    scanf("%i", &trolleynum);
    return trolleynum;
}

/**
 * Function to rent out trolleys, error if none are available or said trolley is not available at the moment
 * If its available takes trolleynumber, name and phone number which are then stored in arrays
 */
void rentOut(){
    int i = 0;
    if (gTrolleysRented == MAXTROLLEYS) {
        printf("All trolleys are rented!\n");
    }else{
        printf("Which trolley would you like to rent?\n");
        i = readInt();
        
        if (gTrolley[i].rented == 1) {
            printf("Trolley already rented!\n");
        }else{
            gTrolleysRented++;
            gTrolley[i].rented = 1;
            printf("Renters name        : ");
            getchar();
            fgets(gTrolley[i].name, STRLEN, stdin);
            gTrolley[i].name[strlen(gTrolley[i].name)-1] = '\0';
            printf("Renters phone number: ");
            gTrolley[i].pNum = readInt();
            getchar();
            printf("TrolleyNUM %i rented to %s, Phone number: %i\n",
                   i, gTrolley[i].name, gTrolley[i].pNum);
        }
    }
}
