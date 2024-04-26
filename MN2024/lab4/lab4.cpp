#include<iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

void matrix_multiplication(vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C){
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<B[0].size(); j++){
            C[i][j] = 0;
            for(int k=0; k<A[0].size(); k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_vector_multiplication(vector<vector<double>> &A, vector<double> &B, vector<double> &C){
    for(int i=0; i<A.size(); i++){
        C[i] = 0;
        for(int j=0; j<B.size(); j++){
            C[i] += A[i][j] * B[j];
        }
    }
}

void matrix_transposition(vector<vector<double>> &A, vector<vector<double>> &B){
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[0].size(); j++){
            B[j][i] = A[i][j];
        }
    }
}

double dot_product(vector<double> &A, vector<double> &B){
    double result = 0;
    for(int i=0; i<A.size(); i++){
        result += A[i] * B[i];
    }
    return result;
}

void normalise_vector(vector<double> &A, vector<double> &B){
    double max = -8593241;
    for(int i=0; i<A.size(); i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    for(int i=0; i<A.size(); i++){
        A[i] = A[i] / max;
        B[i] = A[i];
    }
    
}

void matrix_subtraction(vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C){
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[0].size(); j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}



int main(){
    vector<vector<double>> A(7, vector<double>(7));
    vector<vector<double>> W(7, vector<double>(7));

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            A[i][j] = 1 / (sqrt(2 + fabs(i-j)));
            W[i][j] = A[i][j];
            // cout << "A[" << i << "][" << j << "] = " << A[i][j] << ", ";
        }
        // cout << "\n";
    }

    int K_val = 7;

    for(int k=0; k < K_val; k++){

        vector<vector<double>> x_k(7, vector<double>(7));
        for(int j=0; j<7; j++){
            x_k[k].push_back(1);
        }

        vector<vector<double>> lambda_k(12, vector<double>(12));

        int IT_MAX = 12;
        for(int i=0; i<IT_MAX; i++){
            // x_k[i+1] = A * x_k[i];
            matrix_vector_multiplication(W, x_k[i], x_k[i+1]);
            

        //     //lambada calculations :>
            double licznik = dot_product(x_k[i+1], x_k[i]);
            double mianownik = dot_product(x_k[i], x_k[i]);
            lambda_k[i].push_back(licznik / mianownik);
            cout << lambda_k[i][0] << "\n";

        //     // x_k[i+1] = x_k[i+1] / ||x_k[i+1]||

            normalise_vector(x_k[i+1], x_k[i]);
        }
        vector<vector<double>> to_subtract(7, vector<double>(7));
        // matrix_subtraction(W[k])
    }
    return 0;
}