#include<iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

int main(){

    ofstream file1("output_x_3.txt");
    ofstream file2("output_t.txt");

    if (!file1.is_open() || !file2.is_open()) {
        std::cout << "Unable to open file";
        return 1;  // Exit if unable to open the file
    }

    //x[-1] i x[-2]
    vector<double> x = {1, 1};
    vector<double> t;

    //stale
    double w = 1;
    int n = 1000;
    double h = 0.02;

    przypadek 1
    double beta = 0.0;
    double F0 = 0.0;
    double omega = 0.8;

    przypadek 2
    double beta = 0.4;
    double F0 = 0.0;
    double omega = 0.8;

    // przypadek 3
    double beta = 0.4;
    double F0 = 0.1;
    double omega = 0.8;

    //wypelniacze macierzy
    double a1 = 1;
    double a2 = w*w*h*h - 2 - beta*h;
    double a3 = 1 + beta*h;

    vector<double> b_i = {1, 0};
    for(int i=2; i<n; i++){
        b_i.push_back(F0*sin(omega*h*i)*h*h);
    }

    vector<double> d0 = {1,1};
    vector<double> d1 = {0,-1};
    vector<double> d2 = {0,0};

    for(int i=0; i<n; i++){
        d0.push_back(a3);
        d1.push_back(a2);
        d2.push_back(a1);
        t.push_back(h*i);
    }

    for(int i=2; i<n; i++){
        double temp = (b_i[i]-d1[i]*x[i-1]-d2[i]*x[i-2])/(d0[i]);
        x.push_back(temp);
        file1 << x[i] << ",";
        file2 << t[i] << ",";
    }

    return 0;
}