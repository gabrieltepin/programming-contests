#include "bits/stdc++.h"
using namespace std;

void printTable (char tab[][8]){
    for(int i=0;i<8;i++){
        for(int j=0; j<8;j++){ 
            cout << tab[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(char tab[][8], int n, int m){ //n is column of new queen, m is line of new queen
    for(int i=0;i<n;i++){   //i for column, j for line here
        for(int j=0; j<8;j++){ 
            if(tab[j][i]=='Q'){
                if(i==n || m==j) return false;
                if(abs(n-i)==abs(m-j)) return false;
            }
        }
    }
    return true;
}

void placeQueen(char tab[][8], int n, int &cont){
    if(n==8){
        cout << ++cont << endl;
        printTable(tab);
        return;
    }
    for(int i=0;i<8;i++){
        tab[i][n]='Q';
        if(isSafe(tab, n, i)) {
            placeQueen(tab, n+1, cont);
        }
        tab[i][n]='_';
    }
}

int main () {
    char tab[8][8];
    for(int i=0;i<8;i++){
        for(int j=0; j<8;j++){ 
            tab[i][j]='_';
        }
    }
    int cont =0;
    placeQueen(tab, 0, cont);
    return 0;
}