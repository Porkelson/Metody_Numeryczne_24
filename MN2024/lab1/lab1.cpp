#include<iostream>
using namespace std;

int main(){
    int i,j,k,n;
    cout << "\nPodaj liczbe rownan: ";
    cin >> n;
    
    float mat[n][n+1];
    float wynik[n];

    //first eq
    mat[0][0] = -1;
    mat[0][1] = 2;
    mat[0][2] = 1;
    mat[0][3] = -1;
    //second eq
    mat[1][0] = 1;
    mat[1][1] = -3;
    mat[1][2] = -2;
    mat[1][3] = -1;
    //third eq
    mat[2][0] = 3;
    mat[2][1] = -1;
    mat[2][2] = -1;
    mat[2][3] = 4;

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            
            float f = mat[j][i]/mat[i][i];

            for(k=0; k<n+1; k++){
                mat[j][k] = mat[j][k] - f*mat[i][k];
            }
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n+1; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }


    for(i=n-1; i>=0; i--){
        wynik[i] = mat[i][n];
        
        for(j=i+1; j<n; j++){
            if(i!=j){
                wynik[i]=wynik[i]-mat[i][j]*wynik[j];
            }
        }
            wynik[i] = wynik[i]/mat[i][i];
    }

    for(i=0; i<n; i++){
        cout << "zmienna nr " << i+1 << ": ";
        cout << wynik[i] << endl;
    }
}