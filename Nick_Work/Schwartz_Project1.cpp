#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>      
#include <time.h> 
#include <fstream>

// Part 1 - Multiplying Two Matrices


// CODE TAKEN FROM ANNA AND EDITED BY NICK

using namespace std;


// Jared Provided me this code snippet because I was struggling with properly doing double pointer
// and using malloc
float** generate_matrix(int size) {
    float** matrix = (float**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (float*)malloc(size * sizeof(int));
    }
    // Random seed for number generation
    srand(time(0));
    // Fill the matrix with random numbers
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // matrix[i][j] = rand() % 100; // Adjust the range
            matrix[i][j] =  (float)rand()/(float)(RAND_MAX);
        }
    }
    return matrix;
}
// end code provided by Jared

float** multiplymatrix ( int matrixsize, float** matrixA, float** matrixB,
float** matrixC )
{
    for (int i = 0; i < matrixsize; ++i) {
        for (int k = 0; k < matrixsize; ++k)  {
            for (int j = 0; j < matrixsize; ++j)
            {
            matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return matrixC;
}


int main() {
    int finishsize = 1;
    ofstream myfile ("data.txt");

    for (int i = 0; i < finishsize; ++i) {
        int matrixsize = 2000;

        float** matrixA = generate_matrix(matrixsize);
        float** matrixB = generate_matrix(matrixsize);
        float** matrixC = generate_matrix(matrixsize);

        // timing is from 
        // https://stackoverflow.com/questions/56138064/how-do-i-convert-stdchronohigh-resolution-type-to-a-float-type

        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

        multiplymatrix ( matrixsize, matrixA, matrixB, matrixC );
        /*for (int i = 0; i < matrixsize; ++i) {
            for (int j = 0; j < matrixsize; ++j) {
                matrixC[i][j] = 0;
                for (int k = 0; k < matrixsize; ++k) 
                {
                    matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }*/
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        float duration = std::chrono::duration<float>(end - start).count();

        myfile << matrixsize;
        myfile << ",";
        myfile << duration;
        myfile << "\n";

    }

    // below modified from 
    // https://stackoverflow.com/questions/22190048/how-to-write-the-content-of-an-array-into-a-text-file

	myfile.close();
    
}