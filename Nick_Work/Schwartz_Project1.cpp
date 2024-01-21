#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>      
#include <time.h> 
#include <fstream>
#include <chrono>

// Part 1 - Multiplying Two Matrices

// CODE TAKEN FROM ANNA AND EDITED BY NICK

using namespace std;

// Jared provided me this code snippet because I was struggling with properly doing double pointer
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
            matrix[i][j] =  (float)rand();
        }
    }
    return matrix;
}
// end code provided by Jared

float** multiplymatrix ( int matrixsize, float** matrixA, float** matrixB, float** matrixC )
// 
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
    int finishsize = 15000;

    ofstream myfile ("data.txt");

    myfile << "# Matrix Size";
    myfile << ", ";
    myfile << "Create Matrix Time (s)";
    myfile << ", ";
    myfile << "Matrix Multiplication Time (s)";
    myfile << ", ";
    myfile << "Gflops";
    myfile << "\n";

    for (int i = 2, increment = 1 ; i < finishsize; increment += 1, i+=increment) {
        float matrixsize = i;

        std::chrono::steady_clock::time_point start_create = std::chrono::steady_clock::now();

        float** matrixA = generate_matrix(matrixsize);
        float** matrixB = generate_matrix(matrixsize);
        float** matrixC = generate_matrix(matrixsize);

        std::chrono::steady_clock::time_point end_create = std::chrono::steady_clock::now();

        float duration_creation = std::chrono::duration<float>(end_create - start_create).count();

        // timing is from 
        // https://stackoverflow.com/questions/56138064/how-do-i-convert-stdchronohigh-resolution-type-to-a-float-type

        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

        multiplymatrix ( matrixsize, matrixA, matrixB, matrixC );
     
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        
        delete matrixA;
        delete matrixB;
        delete matrixC;

        float duration = std::chrono::duration<float>(end - start).count();

        float total_flops = 2*matrixsize*matrixsize*matrixsize-matrixsize*matrixsize;
        float gflops = total_flops/duration;

        myfile << matrixsize;
        myfile << ", ";
        myfile << duration_creation;
        myfile << ", ";
        myfile << duration;
        myfile << ", ";
        myfile << gflops/1e9;
        myfile << "\n";

        std::cout << matrixsize << "\t" << duration << "\t" << gflops/1e9 << std::endl;

    }

    // below modified from 
    // https://stackoverflow.com/questions/22190048/how-to-write-the-content-of-an-array-into-a-text-file

	myfile.close();
    
}