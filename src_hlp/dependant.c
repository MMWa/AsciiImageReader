//
// Created by wahba on 12/05/2016.
//

#include "../helper/dependant.h"
#include "../helper/basic.h"
#include "../helper/common.h"


void centroid(char img_in[50][50]) {
    float area;
    int x, y, Xt = 0, Y_cent = 0, X_cent = 0, Yt;
	//standard loop through
    for (y = 0; y < 50; y++) {
        for (x = 0; x < 50; x++) {
            if (img_in[x][y] == '1') {
                X_cent = x + X_cent;	//sum the x values with 1
            }
        }
    }
	//standard loop through
    for (y = 0; y < 50; y++) {
        for (x = 0; x < 50; x++) {
            if (img_in[x][y] == '1') {
                Y_cent = y + Y_cent;	//sum the y values with 1
            }
        }
    }

    area = calc_area(img_in);			//get value of area

    Xt = ((1 / area * X_cent));			//calculate position using center equation
    Yt = ((1 / area * Y_cent));

    printf("The Centroid is: (%i,%i)\n", Xt, Yt);
}

int calc_SF(char img_in[50][50]) {			//this funtion does the shapefactor
											//sf is how circular or elipttical a shape is
    int per, area, SF_val;					//create a place for all the used variables

    per = calc_perimeter(img_in);			//per takes the return from the perimeter function
    area = calc_area(img_in);				//area take the return from the area function

    SF_val = (int) ((per * per) / (area));	//using the variables its simply doing the shapefunction equation
											//also there is a change of renainder thus we force the result to int
    return SF_val;
}



//edge operations.

void enclosed(char img_in[50][50]) {
    int y, x, maxX = 0, maxY = 0, minX = 100, minY = 100;
	//standard loop through
    for (y = 0; y < 50; y++) {
        for (x = 0; x < 50; x++) {
            if (img_in[x][y] == '1') {		//if in shape , 1
                if (y > maxY) { maxY = y; } //find biggest y value
            }
        }
    }

	//standard loop through
    for (y = 0; y < 50; y++) {
        for (x = 0; x < 50; x++) {
            if (img_in[x][y] == '1') {		//if in shape , 1
                if (y < minY) { minY = y; } //find smallest y value
            }
        }
    }

    //standard loop through
    for (y = 0; y < 50; y++) {
        for (x = 0; x < 50; x++) {
            if (img_in[x][y] == '1') 		//if in shape , 1
                if (x > maxX) { maxX = x; } //find biggest x value
            }
        }
    //standard loop through
    for (y = 0; y < 50; y++) {
        for (x = 0; x < 50; x++) {
            if (img_in[x][y] == '1') {		//if in shape , 1
                if (x < minX) { minX = x; } //find smallest x value
            }
        }
    }
    // now we print the cordinates of the extre edge points
    printf("the enclosing rectangle points are (%i,%i) and (%i,%i)\n", minX,minY,maxX,maxY);
    //end of all
}

void outline(char img_in[50][50]) {
    int x, y;							//initilasise x and y for loop through
	//standard loop through
    for (x = 0; x < 50; x++) {
        for (y = 0; y< 50; y++) {
            if (img_in[x][y] == '1') {	//check if we are looking at a one then we check if its on an edge
                if ((((img_in[x + 1][y])) == '0') || ((img_in[x - 1][y]) == '0') || ((img_in[x][y - 1]) == '0') || ((img_in[x][y + 1]) == '0')) {
                    printf("*");		//print * if we are on a edge
                } else {
					printf(" ");		//space if 1 but not on edge
					}
            } else {
				printf(" ");			//space if 0
				}
        }
        printf("\n");					//newline at the end of Y iteration,  for every x line 1 \n
    }		
}
