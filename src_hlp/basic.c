//
// Created by wahba on 12/05/2016.
//

#include "../helper/basic.h"
#include "../helper/common.h"

char display(char img_in[2500]) {
    int n;
    for (n = 0; n < 2500; n++) {        //treated in 1d for smaller code, less loops
        if (n%50 == 0){ newLine }       //simple check if we after x == 50       puts a /n
        printf("%c", img_in[n]);        //prints the elements in array
    }
    newLine                             // new line at end because loop ends at 2500 new line doesnt happen
}

int calc_area(char img_in[2500]) {
    int n,count = 0;

    for (n = 0; n < 2500; n++) {        //treated in 1d for smaller code, less loops
        if (img_in[n] == '1') { count++; }//count is incremented every time img_in is a 1
    }
    return count;                       //count is returned claner more flexible can be printed from outside
}

int calc_perimeter(char img_in[50][50]) {
    int x, y, count = 0;                // define all variables, count = 0 because we need a start point

    for (y = 0; y < 50; y++) {          //2d because x, y needed
        for (x = 0; x < 50; x++) {      //x axis
            if (img_in[y][x] == '1') {  // check if inside image
                if ((((img_in[y][x + 1])) == '0') || ((img_in[y][x - 1]) == '0') ||
                    ((img_in[y - 1][x]) == '0') || ((img_in[y + 1][x]) == '0')) {   // all the above checks if at edge
                    count++;                                                        //but doesnt tell you how many faces on edge
                }
            }
        }
    }
    return count;                       //count is returned claner more flexible can be printed from outside
}