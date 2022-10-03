//
//  calculator.c
//  Basics
//
//  Created by Eirik Hanasand on 02/09/2022.
//
//  Basic Calculator
//

#include <stdio.h>                      //Included for printf etc.
#include <string.h>                     //Included for strcmp etc.

int main(){
    int number1 = 0;                    //Input 1
    int number2 = 0;                    //Input 2
    int result;                         //Result
    char multiply[10] = "multiply";     //Choice multiply
    char divide[10] = "divide";         //Choice divide
    char plus[10] = "plus";             //Choice plus
    char minus[10] = "minus";           //Choice minus
    char null[10] = "0";                //When terminating the program
    char choice[10];                    //Users choice
    
    do{
        //Asks the user what they would lie to do
        printf("What would you like to do? (multiply, divide, plus or minus)\Write 0 end the program\n");
        scanf("%s", choice);
        
        //Checks what the user input
        int mresult = strcmp(multiply, choice);
        int dresult = strcmp(divide, choice);
        int presult = strcmp(plus, choice);
        int miresult = strcmp(minus, choice);
        int nullresult = strcmp(null, choice);
        
        //Multilpy section
        if(mresult == 0){
            printf("What would you like to multiply?\n");
            printf("Number 1:\n");
            scanf("%d", &number1);
            printf("Number 2:\n");
            scanf("%d", &number2);
            result = number1 * number2;
            printf("%d * %d = %d\n", number1, number2, result);
        }
        
        //Divide section
        else if(dresult == 0){
            printf("What would you like to divide?\n");
            printf("Number 1:\n");
            scanf("%d", &number1);
            printf("Number 2:\n");
            scanf("%d", &number2);
            result = number1 / number2;
            printf("%d / %d = %d\n", number1, number2, result);
        
        //Plus section
        }else if(presult == 0){
            printf("What would you like to plus\n");
            printf("Number 1:\n");
            scanf("%d", &number1);
            printf("Number 2:\n");
            scanf("%d", &number2);
            result = number1 + number2;
            printf("%d + %d = %d\n", number1, number2, result);
            
        //Minus section
        }else if(miresult == 0){
            printf("What would you like to subtract?\n");
            printf("Number 1:\n");
            scanf("%d", &number1);
            printf("Number 2:\n");
            scanf("%d", &number2);
            result = number1 - number2;
            printf("%d - %d = %d\n", number1, number2, result);
        
        //Terminating the program
        }else if(number1 != 0 && number2 != 0 && nullresult != 0){
            printf("You wrote %s, and the program was terminated.\n", choice);
            return 2;
        }else{
            printf("You wrote %s, and the program was terminated.\n", choice);
            return 1;
        }
    
    //Checks if any number was 0, terminating if true
    }while(number1 != 0 && number2 != 0);
    
    printf("You wrote 0, and the program was terminated.\n");
    
    return 0;
}
