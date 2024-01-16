#include <iostream>
#include <cstdlib>
#include <ctime>

// Part 1 - Multiplying Two Matrices
// Ian's Processor information:
/*
11th Gen Intel i7 (2.80 GHz)

Sockets:    1
Cores:      4
L1 cache:   320  kB
L2 cache:   5.0  MB
L3 cache:   12.0 MB
*/

using namespace std;

int main() {

    // make the dimensions of each matrix: A, B, C
    int N = 10;
    double A[N][N], B[N][N], C[N][N];

    // Seeding C++'s random numbers
    srand(0);

    // fill each matrix with random floats
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = static_cast <double> (rand()) / RAND_MAX;
            B[i][j] = static_cast <double> (rand()) / RAND_MAX;
        }
    }
    // display matrices A and B
    cout << "Matrix A with random uniform floats:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix B with random uniform floats:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    // multiply A and B to get matrix C
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }

        }
    }

    // display matrix C

    cout << "Matrix C" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}