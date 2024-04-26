#include<iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int calc_ro(int x){
    float Xb=2, Xa=0.5;
    if((x >= -Xb && x < Xa) || (x==0) || (x > Xa && x <= Xb)){
        return 0;
    }
    if(x >= -Xa && x < 0){
        return 1;
    }
    if(x > 0 && x <= Xa){
        return -1;
    }
    return -32;
}

// vector<double> thomasAlgorithm(vector<double>& a, vector<double>& d, vector<double>& c, vector<double>& ro) {
//     int N = d.size();

//     vector<double> u(N), l(N), y(N), x(N);

//     // Forward sweep
//     u[0] = d[0];
//     y[0] = ro[0];

//     for (int i = 1; i < N; i++) {
//         l[i] = a[i] / u[i - 1];
//         u[i] = d[i] - l[i] * c[i - 1];
//         y[i] = ro[i] - l[i] * y[i - 1];
//     }

//     // Back substitution
//     x[N - 1] = y[N - 1] / u[N - 1];

//     for (int i = N - 2; i >= 0; i--) {
//         x[i] = (y[i] - c[i] * x[i + 1]) / u[i];
//     }

//     return x;
// }
double V(double x) {
    float Xb=2, Xa=0.5;
    if (x >= -Xb && x <= -Xa) {
        return x/16 + 1/8;
    } else if (x > -Xa && x <= 0) {
        return (-x*x)/2-7*x/16;
    } else if (x > 0 && x <= Xa) {
        return (x*x)/2-7*x/16;
    } else if (x > Xa && x <= Xb) {
        return x/16 - 1/8;
    } else {
        // Handle the case where x is outside the defined intervals
        return 0;
    }
}

int main(){     

    ofstream file1("output1.txt");
    ofstream file2("output2.txt");
    if(!file1.is_open()){
        cout << "Error opening file" << endl;
        return 1;
    }
    double Xb=2;
    double Xa=0.5;
    int N = 500;

    vector<double> a,d,c,ro,tabX, tabX_wyniki;

    double h = 2*Xb/(double(N)-1);

    //wyliczanie wektora ro
    for(int i=1; i<=N; i++){
        double _x = -Xb + h*(i-1);
        tabX.push_back(_x);
        double _y = V(_x);
        tabX_wyniki.push_back(_y);
        ro.push_back(-1*calc_ro(_x));
    }

    //wyliczanie wektorow a,d,c (sa to stale wektory???)
    for(int i=1; i<=N; i++){
        a.push_back(1/(h*h));
        c.push_back(1/(h*h));
        d.push_back(-2/(h*h));
    }

    //warunki brzegowe
    //d_1 = 1, c_1 = 0, ro_1 = 0
    d[0] = 1;
    c[0] = 0;
    ro[0] = 0;

    //d_n = 1, a_n = 0, ro_n = 0
    d[N-1] = 1;
    a[N-1] = 0;
    ro[N-1] = 0;

    vector<double> u, l;

    //u1 = d1
    u.push_back(d[0]);

    //i = 2,3...,N
    for(int i=1; i < N; i++){
        l.push_back(a[i]/u[i-1]);
        u.push_back(d[i]-l[i]*c[i-1]);
    }

    //Ly = b (b to ro!!!)
    vector<double> y;
    //y_1 = b_1
    y.push_back(ro[0]);

    for(int i=1; i < N; i++){
        y.push_back(ro[i]-l[i]*y[i-1]);
    }

    // tu od KONCA
    vector<double> v(N);
    v[N-1] = y[N-1]/u[N-1];

    for(int i=N-2; i >= 0; i--){
        v[i] = (y[i]-c[i]*v[i+1])/u[i];
    }
    
    if (file1.is_open()) {
        // Write the tabX_wyniki vector to the file.
        for (double val : tabX_wyniki) {
            file1 << val << "\n";
        }

        // Close the file.
        file1.close();
    }

    if (file2.is_open()) {
        // Write the v vector to the file.
        for (double val : v) {
            file2 << val << "\n";
        }

        // Close the file.
        file2.close();
    }
    
    return 0;
}
