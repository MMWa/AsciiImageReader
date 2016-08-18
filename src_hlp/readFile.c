//
// Created by wahba on 12/05/2016.
//

#include "../helper/readFile.h"
#include "../helper/common.h"

int readFile(char c[2500]) {    			//character array with MAXIMUM size of file
    FILE *fptr;     						//file pointer
    char Filename[250];                    //var to hold filename
    printf("Enter filename with filetype: ");
    scanf("%s",Filename);                   //scan user input put in variable

    //check for file existance
    if ((fptr=fopen(Filename,"r"))==NULL){  //use scaned user input to find file
        printf("Error! opening file %s\n",Filename);	//simple error message and a return out of funtion with code 99
		return 99;
    }
    printf("Opening File %s\n",Filename);
    printf("Reading Image....\n");
    char Pin;
    char tmp [8];
    fscanf(fptr, "%c", tmp);				//used to test the waters
    int ic = 0;								//counter to run through arrays
    int ip = 0;

    //custom scan loop
    while (ip < 2550) {						//2550 to account for new line character
        Pin = fptr-> _base[ip];				//file is loaded into the file pointer into _base[] by fscanf
                                            // also takes permanent pixel definitions if needed
        if (Pin == '0' ||Pin ==  '1') {		//now we can ignore the /n
            c[ic] = fptr->_base[ip];        // set c to what ever is in the file pointer
            //printf("%c",c[ic]);				//printed just for test
            ic++;							//counters are needed to progress through both arrays
            ip++;							//but in the presence of Pin!= 1||0 we will not want 
        } else {							//to count throught our internal buffer
            ip++;							//thus ip is incremented and not ic, ic is the full counter goes to 2550
        }                                   //--- they both count but at different rates
    }
    fclose(fptr);							//close file pointer this destroies _base[]
    printf("Done Reading Image!\n");		//message 
	system("pause");
    return 1;								//on succes return 1 !99
}