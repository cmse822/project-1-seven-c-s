#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <chrono>
#include <fstream>
#include <vector>

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

vector<vector<double>> matrix_muliply(vector<vector<double>> matrixA, vector<vector<double>> matrixB, int m) {
    vector<vector<double>> C(m, vector<double>(m, 0.0));
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < m; ++k)  {
            for (int j = 0; j < m; ++j)
            {
                C[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return C;
}

// function that returns a vector of vectors (matrix)
vector<vector<double>> generate_matrix(int m) {
    // Initialize M, to be a vector of vectors with entries of 0.0
    /*
    vector<vector<double>> M is creating the empty vector of vectors called M
    M(m, vector<double>(m, 0.0)) initializes the parent vector with entries of vectors
    vector<double>(m,0.0) initializes those child vectors with 0.0
    */
    vector<vector<double>> M(m, vector<double>(m, 0.0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            M[i][j] = static_cast <double> (rand()) / RAND_MAX;
        }
    }
    return M;
}

int main() {
    // make the dimensions of each matrix: A, B, C
    int totalSteps = 31;

    vector<int> N {2, 4, 8,
        10, 20, 30, 40, 50, 60, 70, 80, 90,
        100, 110, 120, 140, 180, 200, 250, 300, 350, 400, 500, 700,
        1000, 1300, 1600, 2000, 3000, 3500, 4000,};


    // Seeding C++'s random numbers
    srand(0);

    ofstream myfile ("data.txt");

    myfile << "# Matrix Size";
    myfile << ", ";
    myfile << "Matrix Multiplication Time (s)";
    myfile << ", ";
    myfile << "Gflops";
    myfile << "\n";

    for(int n=0; n < totalSteps; n++) {
        auto A = generate_matrix(N[n]);
        auto B = generate_matrix(N[n]);  
        
        long long matrixsize = N[n];
        // Starting high_resolution_clock before multiplication
        // Implementation from https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        // multiply A and B to get matrix C
        auto C = matrix_muliply(A, B, N[n]);
        // Stopping timer
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        float duration = std::chrono::duration<float>(end - start).count();

        cout << "Time taken by matrix of size " << N[n] << " = " 
                    << duration << " seconds" << endl;
        
    
        float total_flops = 2*matrixsize*matrixsize*matrixsize-matrixsize*matrixsize;
        float gflops = total_flops/duration;
        cout << N[n] << " " << gflops;

        myfile << matrixsize;
        myfile << ", ";
        myfile << duration;
        myfile << ", ";
        myfile << gflops/1e9;
        myfile << "\n";
    }

    // display table of time taken vs size of matrix:


    return 0;
}