#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // make the dimensions of each matrix : A, B, C

    int const rowsA = 2, columnsA = 2;
    int const rowsB = 2, columnsB = 2;
    int const rowsC = rowsA, columnsC = columnsB;

    // ensure every time this code runs, the integers are random

    srand(time(0));

    // fill each matrix with random integers  : A, B

    int matrixA[rowsA][columnsA];
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < columnsA; ++j) {
            matrixA[i][j] = rand() ;
        }
    }

    int matrixB[rowsB][columnsB];
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < columnsB; ++j) {
            matrixB[i][j] = rand() ;
        }
    }


    // display matrices A and B
    cout << "Matrix A with random integers:" << endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < columnsA; ++j) {
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix B with random integers:" << endl;
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < columnsB; ++j) {
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

    // multiply A and B to get matrix C

    int matrixC[rowsC][columnsC];
    for (int i = 0; i < rowsC; ++i) {
        for (int j = 0; j < columnsC; ++j) {
            matrixC[i][j] = 0;

            for (int k = 0; k < columnsA; ++k) 
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }

        }
    }

    // display matrix C

    cout << "Matrix C" << endl;
    for (int i = 0; i < rowsC; ++i) {
        for (int j = 0; j < columnsC; ++j) {
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}