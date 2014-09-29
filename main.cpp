/* 
 * File:   main.cpp
 * Jacob Smith
 * V00700979
 * CSC 305
 * Assignment 1
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#include "Matrix.h"
#include "Point3d.h"

// Gets and returns bounded integer input from user input
int user_input_int(int low_bound, int high_bound){
   while(true)
   {
       std::cout << "Please enter a number between " << low_bound << " and " << high_bound << ": ";
       std::string str;
       std::getline(std::cin,str);
       char *endp = 0;
       int number = strtol(str.c_str(),&endp,10);
       if(endp!=str.c_str() && !*endp && number >= low_bound && number <= high_bound)
           return number;
       std::cout << "Invalid input!" << std::endl;
   }
}

// Gets and returns any integer from user input
int user_input_int(){
    while(true)
    {
        std::cout << "Please enter a number: ";
        std::string str;
        std::getline(std::cin,str);
        char *endp = 0;
        int number = strtol(str.c_str(),&endp,10);
        if(endp!=str.c_str() && !*endp)
            return number;
        std::cout << "Invalid input!" << std::endl;
    }
}

// Gets and returns any double from user input
double user_input_double(){
    double number;
    std::cin >> number;
    while( std::cin.fail() || (std::cin.peek() != '\r' && std::cin.peek() != '\n'))
    {
        std::cout << "Invalid Input!" << std::endl;
        std::cin.clear();
        while( std::cin.get() != '\n' );
                std::cin >> number;
    }
    return number;
}

// Fills the passed in matrix with user input
void fillMatrix ( Matrix &mx){
    
    int i,j;
    for( i=0; i< mx.yn; i++){
        for( j=0; j< mx.xn; j++){
            std::cout<<"Enter a number for element [" << i << "][" << j << "]: ";
            mx.grid[i][j] = user_input_int();
        }
    }
    
}

// Prints the main menu
void mainMenu (){
    std::cout << "1: transpose a matrix" << std::endl;
    std::cout << "2: equality check 2 matrices" << std::endl;
    std::cout << "3: multiply 2 matrices" << std::endl;
    std::cout << "4: inverse a matrix" << std::endl;
    std::cout << "5: dot product 2 matrices" << std::endl;
    std::cout << "6: cross product 2 matrices" << std::endl;
    std::cout << "7: x-axis, rotate 3d point" << std::endl;
    std::cout << "8: y-axis, rotate 3d point" << std::endl;
    std::cout << "9: z-axis, rotate 3d point" << std::endl;
    std::cout << "10: translate 3d point" << std::endl;
    std::cout << "11: scale of 2 3d point" << std::endl;
    std::cout << "0: exit" << std::endl;
}

// Transpose matrix option
void optTranspose(){
    // get desired row and column size
    int urows, ucolumns;
    std::cout << "Number of rows: ";
    urows = user_input_int(1,100);
    std::cout << "Number of columns: ";
    ucolumns = user_input_int(1,100);

    // create, fill, transpose, and print matrix
    Matrix mx(urows,ucolumns); //= new Matrix(urows,ucolumns);
    fillMatrix(mx);
    Matrix mxT(mx.transposeMatrix());
    std::cout << "\nResult: \n" << mxT.getString();
}

// matrix equality option
void optEquality(){
    // get desired row and column size for matrix 1
    int urows, ucolumns;
    std::cout << "Number of rows for m1: ";
    urows = user_input_int(1,100);
    std::cout << "Number of columns for m1: ";
    ucolumns = user_input_int(1,100);

    // fill matrix 1
    Matrix mx(urows,ucolumns);
    fillMatrix(mx);

    // get desired row and column size for matrix 2
    std::cout << "Number of rows for m2: ";
    urows = user_input_int(1,100);
    std::cout << "Number of columns for m2: ";
    ucolumns = user_input_int(1,100);

    // fill matrix 2
    Matrix mx2(urows,ucolumns);
    fillMatrix(mx2);

    // compare matrices and print result
     if (mx.compareMatrix(mx2)){
        std::cout << "Those matrices are equal" << std::endl;
     } else {
        std::cout << "Those matrices are not equal" << std::endl;
     }
}

// multiply matrices option
void optMultiply(){
    // get desired row and column size for matrix 1
    int urows, ucolumns;
    std::cout << "Number of rows for m1: ";
    urows = user_input_int(1,100);
    std::cout << "Number of columns for m1: ";
    ucolumns = user_input_int(1,100);

    // fill matrix 1
    Matrix mx(urows,ucolumns);
    fillMatrix(mx);

    // get desired row and column size for matrix 2
    std::cout << "Number of rows for m2: ";
    urows = user_input_int(1,100);
    std::cout << "Number of columns for m2: ";
    ucolumns = user_input_int(1,100);

    // fill matrix 2
    Matrix mx2(urows,ucolumns);
    fillMatrix(mx2);

    // multply matrices and print result
    if (mx.xn == mx2.yn){
        Matrix mxM(mx.multiplyMatrix(mx2));
        std::cout << "\nResult: \n" << mxM.getString() << std::endl;
    } else {
        std::cout << "The number of columns of m1 does not equal the number of rows for m2" << std::endl;
    }
}

// inverse matrix option
void optInverse(){
        // get desired row and column size
    int urc;
    std::cout << "Number of rows and columns: ";
    urc = user_input_int(2,3);

        // fill matrix
    Matrix mx(urc,urc);
    fillMatrix(mx);

    
    // attempt inverse matrix and print result
    Matrix mxI(mx.inverse());
    if (mxI.yn == 0){
        std::cout << "No inverse for that matrix!" << std::endl;
    }
    else{
        std::cout << "\nResult: \n" << mxI.getString() << std::endl;
    }
}

// dot product option
void optDot(){

    // create and fill matrix 1
    std::cout << "m1: " << std::endl;
    Matrix mx(3,1);
    fillMatrix(mx);

    // create and fill matrix 2
    std::cout << "m2: " << std::endl;
    Matrix mx2(3,1);
    fillMatrix(mx2);

    // compute dot product and print result
    int dotProduct;
    dotProduct = mx.dotProduct(mx2);
    std::cout << "\nResult: " << dotProduct << std::endl;
}

// cross product option
void optCross(){
    // create and fill matrix 1
    std::cout << "m1: ";  
    Matrix mx(3,1);
    fillMatrix(mx);

    // create and fill matrix 2
    std::cout << "m2: ";
    Matrix mx2(3,1);
    fillMatrix(mx2);

    // take cross product and print result
    mx.crossProduct(mx2);
    std::cout << "\nResult: \n" << mx.getString() << std::endl;
}

// rotate point around x axis option
void optXRotate(){
    // create point
    int px,py,pz;
    std::cout << "x: ";
    px = user_input_int();

    std::cout << "y: ";
    py = user_input_int();

    std::cout << "z: ";
    pz = user_input_int();

    Point3d p1(px,py,pz);

    // get angle to rotate
    int pangle;
    std::cout << "angle to rotate in degrees: ";
    pangle = user_input_int();

    // compute and print result
    p1.rotate_x(pangle);
    std::cout << "\nResult: \n" << p1.getString() << std::endl;
}

// rotate point around y axis option
void optYRotate(){
    // create point
    int px,py,pz;
    std::cout << "x: ";
    px = user_input_int();

    std::cout << "y: ";
    py = user_input_int();

    std::cout << "z: ";
    pz = user_input_int();

    Point3d p1(px,py,pz);

    // get angle to rotate
    int pangle;
    std::cout << "angle to rotate in degrees: ";
    pangle = user_input_int();

    // compute and print result
    p1.rotate_y(pangle);
    std::cout << "\nResult: \n" << p1.getString() << std::endl;
}

// rotate point around z axis option
void optZRotate(){
    // create point
    int px,py,pz;
    std::cout << "x: ";
    px = user_input_int();

    std::cout << "y: ";
    py = user_input_int();

    std::cout << "z: ";
    pz = user_input_int();

    Point3d p1(px,py,pz);

    // get angle to rotate
    int pangle;
    std::cout << "angle to rotate in degrees: ";
    pangle = user_input_int();

    // compute and print result
    p1.rotate_z(pangle);
    std::cout << "\nResult: \n" + p1.getString() << std::endl;
}

// translate point option
void optTranslate(){
    // create point
    int px,py,pz;
    std::cout << "x: ";
    px = user_input_int();

    std::cout << "y: ";
    py = user_input_int();

    std::cout << "z: ";
    pz = user_input_int();

    Point3d p1(px,py,pz);

    // get translation for each coord
    int tx,ty,tz;
    std::cout << "translate x: ";
    tx = user_input_int();

    std::cout << "translate y: ";
    ty = user_input_int();

    std::cout << "translate z: ";
    tz = user_input_int();

    // compute translation and print result
    p1.translate(tx,ty,tz);
    std::cout << "\nResult: \n" << p1.getString() << std::endl;
}

// scale point option
void optScale(){
    // create point
    int px,py,pz;
    std::cout << "x: ";
    px = user_input_int();

    std::cout << "y: ";
    py = user_input_int();

    std::cout << "z: ";
    pz = user_input_int();

    Point3d p1(px,py,pz);

    // get scale factor for each coord
    double sx,sy,sz;
    std::cout << "scale x: ";
    sx = user_input_double();

    std::cout << "scale y: ";
    sy = user_input_double();

    std::cout << "scale z: ";
    sz = user_input_double();

    // compute and print result
    p1.scale(sx,sy,sz);
    std::cout << "\nResult: \n" << p1.getString() << std::endl;
}

/*
 * 
 */
int main(int argc, char** argv) {
    // infinitely return to main menu
    for(;;){
        mainMenu();
        int selection = user_input_int(0, 11);
    
        // switch for each main menu choice
        switch(selection){
            case 0:
                std::cout << "Now exiting...";
                return 0;
            case 1:
                optTranspose();
                break;
            case 2:
                optEquality();
                break;
            case 3:
                optMultiply();
                break;
            case 4:
                optInverse();
                break;
            case 5:
                optDot();
                break;
            case 6:
                optCross();
                break;
            case 7:
                optXRotate();
                break;
            case 8:
                optYRotate();
                break;
            case 9:
                optZRotate();
                break;
            case 10:
                optTranslate();
                break;
            case 11:
                optScale();
        }
    }

    return 0;
}

