#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>      
#include <time.h> 
#include <fstream>

// Part 1 - Multiplying Two Matrices


// CODE TAKEN FROM ANNA AND EDITED BY NICK

using namespace std;

/*void multiplymatrix ( int matrixsize, float matrixA[matrixsize][matrixsize], float matrixB[matrixsize][matrixsize],
float* matrixC[matrixsize][matrixsize] )
{
        for (int i = 0; i < matrixsize; ++i) {
            for (int j = 0; j < matrixsize; ++j) {
                *matrixC[i][j] = 0;
                for (int k = 0; k < matrixsize; ++k) 
                {
                    *matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
}*/


int main() {
    int finishsize = 100;
    float sizes[finishsize];
    float times[finishsize];
    for (int i = 0; i < finishsize; ++i) {
        int matrixsize = i+1;
        
        srand(time(0));
        // fill each matrix with random integers  : A, B

        float matrixA[matrixsize][matrixsize];
        float matrixB[matrixsize][matrixsize];
        for (int i = 0; i < matrixsize; ++i) {
            for (int j = 0; j < matrixsize; ++j) {
                matrixA[i][j] = (rand() % 10) ;
            }
        }
        for (int i = 0; i < matrixsize; ++i) {
            for (int j = 0; j < matrixsize; ++j) {
                matrixB[i][j] = (rand() % 10) ;
            }
        }


        // timing is from 
        // https://stackoverflow.com/questions/56138064/how-do-i-convert-stdchronohigh-resolution-type-to-a-float-type

        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

        float matrixC[matrixsize][matrixsize];
        //multiplymatrix ( matrixsize, matrixA, matrixB, matrixC );
        for (int i = 0; i < matrixsize; ++i) {
            for (int j = 0; j < matrixsize; ++j) {
                matrixC[i][j] = 0;
                for (int k = 0; k < matrixsize; ++k) 
                {
                    matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        float duration = std::chrono::duration<float>(end - start).count();

        sizes[i] = matrixsize;
        times[i] = duration;

    }
    ofstream myfile ("data.txt");

    // below modified from 
    // https://stackoverflow.com/questions/22190048/how-to-write-the-content-of-an-array-into-a-text-file

    for(int i = 0; i < finishsize; i++){
			myfile << sizes[i];
			myfile << ",";
			myfile << times[i];
			myfile << "\n";
		}
	myfile.close();
    
}