//
// Created by wahba on 12/05/2016.
//


#include "helper/readFile.h"//FULLY DOCUMENTED
#include "helper/basic.h"
#include "helper/dependant.h"
#include "helper/common.h"


//pre Define

void enclosed       (char img_in[50][50]);
void outline        (char img_in[50][50]);


int main() {
    //--------the essential part!!-------------
    char img[50][50];           //create place holder
    //readFile(img);          //put image in place holder
    //-----------------------------------------
    printf("Image processing program by M W.");
    menu(img);

    //system("pause");		    //left over from development
    return 0;                   //done
};

int menu_Loop(){
    int choice_sel;		        //place holder for the selection
    printf(				//print the menu text
                    "\n\n"
                    "1) Loadfile\n"
                    "2) Display Image\n"
                    "3) Calculate Area\n"
                    "4) Calculate Perimeter\n"
                    "5) Calculate Shape Factor\n"
                    "6) find minimum enclosing rectangle\n"
                    "7) find centroid\n"
                    "8) Display Outline\n"
                    "9) Exit\n\n\n\n\n"//multiple new lines for looks
                    "Please make a selection: "
    );
    scanf("%d",&choice_sel);	                //scanf  returns user input to choice_sel
    return choice_sel;			                //choice_sel is then returned from the function
}

void menu(char img[50][50]){
    int menu_on;				                //this is used as a program on off switch
    int selection;  			                //place holder for the selection
    int file_read = 0;                          //image loaded token

    while(menu_on) {                            //program is a loop where the condition is the presence of menu_on
        selection = menu_Loop();                //call function menu_Loop which returns an int from choice_sel
        system("cls");                          //clean terminal
        if ( selection > 9 ||selection == 0) { printf("-----invalid selection-----\n"); }    //check for valid selection
        if (selection == 1) {
            if (readFile(img)==1){
                file_read=1;                    //change the status of image read token
            }else {
                printf("-----input valid image-----\n");    // else say no valid image
            }
        }
        if (file_read!=1){ printf("-----no image selected-----\n"); }   //check token and display warning if no image

        if (file_read == 1) {           //check if there is an image loaded through token to allow extended functions
            if (selection == 2) {       // rest of menu select
                display(img);
            }
            if (selection == 3) {
                printf("Area is:%i \n", calc_area(img));
            }
            if (selection == 4) {
                printf("perimeter is:%i \n", calc_perimeter(img));
            }
            if (selection == 5) {
                printf("SF is:%i \n", calc_SF(img));
            }
            if (selection == 6) {
                enclosed(img);
            }
            if (selection == 7) {
                centroid(img);
            }
            if (selection == 8) {
                outline(img);
            }
                                   //this will continue on to the main where the program returns zero and exits
        }
        if (selection == 9) {       //exit function is eperate from the extended function because we can exit in all circumstances
            menu_on = 0;            //menu_on is zero no longer just menu_on
                                    // this results in the while loop stopping
        }
    }
}
