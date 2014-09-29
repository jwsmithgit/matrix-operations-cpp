/* 
 * File:   Matrix.h
 * Author: jacob
 *
 * Created on January 26, 2014, 9:12 AM
 */

#ifndef MATRIX_H
#define	MATRIX_H

#include <string>

class Matrix {
public:
    Matrix();
    Matrix(const Matrix& orig);
    virtual ~Matrix();
    Matrix(int i);
    Matrix(int i, int j);
    int getElement(int i, int j);
    void setElement(int i, int j, int val);
    bool checkRowNum(int a);
    bool checkColNum(int a);
    bool checkSize(int a, int b);
    bool makeIdentity();
    std::string getString();
    bool compareMatrix(Matrix& mx);
    Matrix transposeMatrix();
    Matrix multiplyMatrix(Matrix& mx );
    int determinant2();
    int determinant3();
    Matrix inverse();
    int dotProduct(Matrix& mx);
    Matrix crossProduct(Matrix& mx);
    int **grid;
    int yn;
    int xn;
private:

};

#endif	/* MATRIX_H */

