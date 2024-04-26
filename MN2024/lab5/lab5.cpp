#include <iostream>
#include <cmath>
#include <gsl/gsl_math.h>
#include <gsl/gsl_linalg.h>

double ro(double x, double alpha){
    return 1+4*alpha*x*x;
};

int main(){

    double L = 10;
    double n = 200;
    double N = 1;

    double delta_x = L/(n-1);
    gsl_matrix *A = gsl_matrix_alloc(n, n);
    gsl_matrix *B = gsl_matrix_alloc(n, n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout << A[i][j] << "xd ";
        }
        std::cout << "\n";
    }
}