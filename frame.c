//
//  frame.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>

void frame(int height, int width); //Function for creating a frame

int main(){
    int desiredHeight = 0;  //User desired height
    int desiredWidth = 0;   //User desired width
    
    //Asking the user for the frme parameters.
    printf("What height and width would you like the frame to be?\n");
    scanf("%i %i", &desiredHeight, &desiredWidth);
    
    //Getting the frame
    frame(desiredHeight, desiredWidth);
    
    return 0;
    }

/**
 Function for creating a frame, takes two inputs, height and width .
 It then prints a frame using the character (*)
 */
void frame(int height, int width){
    int i = 0;  //Used in loops
    int j = 0;  //Used in loops

//  Printing the top of the frame
    for(i = 0; i < width; i++){
        printf("*");
    }
    printf("\n");

//  Printing the sides of the frame
    for(i = 0; i < height-2; i++){
        printf("*");
            for (j = 0; j < width-2; j++) {
                printf(" ");
            }
            printf("*\n");
    }

//  Printing the bottom of the frame
    for(int i = 0; i < width; i++){
        printf("*");
    }
    printf("\n");
}

