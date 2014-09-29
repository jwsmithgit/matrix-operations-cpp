/* 
 * File:   Matrix.cpp
 * Jacob Smith
 * V00700979
 * CSC 305
 * Assignment 1
 */

#include "Matrix.h"
#include <sstream>
#include <iostream>

// constructors
// default matrix is 3x3
Matrix::Matrix() {
    grid = new int*[3]; 
    for (int i = 0; i < 3; i++) {
      grid[i] = new int[3]; 
    }
    
    for (int i=0; i< 3; i++){
        for (int j=0; j< 3; j++){
            grid[i][j] = 0;
        }
    }
    
    yn = 3;
    xn = 3;
}

Matrix::Matrix(const Matrix& orig) {
    grid = new int*[orig.yn]; 
    for (int i = 0; i < orig.yn; i++) {
      grid[i] = new int[orig.xn]; 
    }
    
    for (int i = 0; i < orig.yn; i++) {
        for (int j=0; j<orig.xn; j++){
            
            grid[i][j] = orig.grid[i][j]; 
        }
    }
    
    yn = orig.yn;
    xn = orig.xn;
}

Matrix::~Matrix() {
    for (int i=0; i<yn; i++){
        delete []grid[i];
    }
    delete [] grid;
    grid = 0;
}

// make matrix with same number of rows and columns
Matrix::Matrix(int a){
    grid = new int*[a]; 
    for (int i = 0; i < a; i++) {
      grid[i] = new int[a]; 
    }
    
    for (int i=0; i< a; i++){
        for (int j=0; j< a; j++){
            grid[i][j] = 0;
        }
    }
    
    yn = a;
    xn = a;
}

// make matrix with different number of rows and columns
Matrix::Matrix(int a, int b){
    grid = new int*[a]; 
    for (int i = 0; i < a; i++) {
      grid[i] = new int[b]; 
    }
    
    for (int i=0; i< a; i++){
        for (int j=0; j< b; j++){
            grid[i][j] = 0;
        }
    }
    
    yn = a;
    xn = b;
}

// get element from matrix
int Matrix::getElement(int i, int j){
   int element;
   element = grid[i][j];
   return element;
}

// set element in matrix
void Matrix::setElement(int i, int j, int val){
    grid[i][j] = val;
}

// size checkers
// checks if matrix has desired number of rows
bool Matrix::checkRowNum(int a){
    if ( yn != a ){
        return false;
    }
    else {
        return true;
    }
}

// check if matrix has desired number of columns
bool Matrix::checkColNum(int a){
    if ( xn != a ){
        return false;
    }
    else {
        return true;
    }
}

// check if matrix has desired size a rows and b columns
bool Matrix::checkSize(int a, int b){
    if ( yn != a || xn != b ){
        return false;
    }
    else {
        return true;
    }
}

// turn matrix into identity matrix
bool Matrix::makeIdentity(){
    // matrix is not able to turn into identity matrix
    if (yn != xn){
        return false;
    }
    // reset all elements to 0
    int i, j;
    for (i=0; i<yn; i++){
        for (j=0; j<xn; j++){
            grid[i][j] = 0;
        }
    }
    // fill in the 1's
    int k;
    for (k=0; k<yn; k++){
        grid[k][k] = 1;
    }
    return true;
}


// returns a string with matrix in printable format
std::string Matrix::getString(){
    std::stringstream sstr;

    int i, j; // counters
    for (i=0; i<yn; i++){
        for (j=0; j<xn; j++){
            sstr << "[" << grid[i][j] << "]";
        }
        sstr << "\n";
    }

    std::string str = sstr.str();
    return str;
}

// compares matrix to other matrix for equality
bool Matrix::compareMatrix(Matrix& mx){
    //compare size
    if( this->yn != mx.yn || this->xn != mx.xn ){
        return false;
    }
    // same size, test each value
    int i, j;
    for (i=0; i< this->yn; i++){
        for (j=0; j< this->xn; j++){
            if ( this->grid[i][j] != mx.grid[i][j] ){ 
                return false; 
            }
        }
    }
    // compared each value to be equal, matrix is equal
    return true;
}


// transposes the matrix
Matrix Matrix::transposeMatrix(){
    // new matrix for transpose
    Matrix mx(this->xn, this->yn );
    // mx = new Matrix(yn, xn );
    //mx = new Matrix(this->xn, this->yn );
    // go through every value and transpose
    int i, j;
    for (i=0; i< this->yn; i++){
        for (j=0; j< this->xn; j++){
            mx.grid[j][i] = this->grid[i][j];
        }
    }

    // transpose of matrix is now in mx
    return mx;
}

// multiply the matrix with another matrix
Matrix Matrix::multiplyMatrix( Matrix& mx ){
    Matrix result(this->yn, mx.xn);
    int i, j, k;
    for (i=0; i< result.yn; i++){
        for (j=0; j< result.xn; j++){
            // how many numbers to add in each grid element
            for(k=0; k< this->xn; k++){
                result.grid[i][j] += (this->grid[i][k] * mx.grid[k][j]);
            }
        }
    }

    return result;
}

// calculates determinant for 2x2 matrix, size must be checked before
int Matrix::determinant2(){
    int determinant;
    determinant = ((grid[0][0]*grid[1][1]) - (grid[1][0]*grid[0][1]));

    return determinant;
}

// calculates determinant for 3x3 matrix, size must be checked before
int Matrix::determinant3(){
    int dtrmnt1, dtrmnt2, dtrmnt3, determinant;
    int a11,a12,a13,a21,a22,a23,a31,a32,a33;
    a11 = grid[0][0];
    a12 = grid[0][1];
    a13 = grid[0][2];
    a21 = grid[1][0];
    a22 = grid[1][1];
    a23 = grid[1][2];
    a31 = grid[2][0];
    a32 = grid[2][1];
    a33 = grid[2][2];

    dtrmnt1 = a11 * ((a22*a33) - (a23*a32));
    dtrmnt2 = -a12 * ((a21*a33) - (a23*a31));
    dtrmnt3 = a13 * ((a21*a32) - (a22*a31));

    determinant = dtrmnt1 + dtrmnt2 + dtrmnt3;
    return determinant;
}

// calculates and returns inverse for 2x2 or 3x3 matrix
Matrix Matrix::inverse(){
    //2x2 matrix inverse
    if( yn == 2 && xn == 2){
        int determinant;
        determinant = this->determinant2();
        //std::cout << determinant;
        if( determinant == 0 ){
            
            return 0;
        }

        Matrix mx(2,2);
        
        //std::cout << mx.getString();
        mx.grid[0][0] = this->grid[1][1] / determinant;
        //std::cout << this->grid[1][1] / determinant;
        mx.grid[1][1] = this->grid[0][0] / determinant;
        //std::cout << this->grid[1][1] / determinant;
        mx.grid[0][1] = -this->grid[0][1] / determinant;
        //std::cout << -this->grid[0][1] / determinant;
        mx.grid[1][0] = -this->grid[1][0] / determinant;
        //std::cout << -this->grid[1][0] / determinant;

        //std::cout << mx.getString();
        return mx;
    }
    //3x3 matrix inverse
    if( yn == 3 && xn == 3){
        // get the determinant
        int determinant;
        determinant = this->determinant3();
        
        if( determinant == 0 ){
            return false;
        }

        // turn into transpose
        Matrix mxT(this->transposeMatrix());
        

        // find determinant of 2x2 matrices
        // will hold 2x2 matrix for every spot
        //Matrix **matrixArr = new Matrix*[3];
        //for (int i = 0; i < 3; ++i)
        //        matrixArr[i] = new Matrix[3];
        Matrix* matrixArr[3][3];

        // create matrices for each determinant
        int i, j;
        for( i=0; i< 3; i++){
            for( j=0; j< 3; j++){
                matrixArr[i][j] = new Matrix(2);

                // put values into each matrix
                int k,l,m;
                m = 0;
                for( k=0; k< 3; k++){
                    for( l=0; l< 3; l++){
                        if(i != k && j != l){
                            switch(m){
                                case(0): matrixArr[i][j]->grid[0][0] = mxT.grid[k][l];
                                case(1): matrixArr[i][j]->grid[0][1] = mxT.grid[k][l];
                                case(2): matrixArr[i][j]->grid[1][0] = mxT.grid[k][l];
                                case(3): matrixArr[i][j]->grid[1][1] = mxT.grid[k][l];
                            }
                            m++;
                        }
                    }
                }
            }
        }

        // apply determinants to our matrix
        for( i=0; i< 3; i++){
            for( j=0; j< 3; j++){
                // get determinant value and store in determinant array
                mxT.grid[i][j] = matrixArr[i][j]->determinant2();
                    
                // apply negative
                if ((i+j)%2 == 1){ mxT.grid[i][j] = -mxT.grid[i][j]; }

                mxT.grid[i][j] = mxT.grid[i][j]/determinant;
            }
        }
        
        
        return mxT;
    }

    // not a 2x2 or 3x3 matrix
    return 0;
}

// compute dot product, size will be enforced before function call
int Matrix::dotProduct( Matrix& mx){
    int i, result;
    result = 0;
    for( i=0; i<this->yn; i++){
        result += this->grid[i][0]*mx.grid[i][0];
    }
    return result;
}


// compute cross product, size must be enforced before function call
Matrix Matrix::crossProduct( Matrix& mx){
    int e1, e2, e3;
    e1 = (this->grid[1][0]*mx.grid[2][0]) - (this->grid[2][0]*mx.grid[1][0]);
    e2 = (this->grid[2][0]*mx.grid[0][0]) - (this->grid[0][0]*mx.grid[2][0]);
    e3 = (this->grid[0][0]*mx.grid[1][0]) - (this->grid[1][0]*mx.grid[0][0]);

    this->grid[0][0] = e1;
    this->grid[1][0] = e2;
    this->grid[2][0] = e3;
}

