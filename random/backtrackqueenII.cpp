#include <iostream>
#define M 10
#define fori(x, y) for(int i = x; i < y; i++)
#define forj(x, y) for(int j = x; j < y; j++)
using namespace std;


void printTab (bool tab[][M], int N){
    fori(0, N){
        forj(0, N){
            cout << tab[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//x is column and y is line of Queen placed, N is tab size
bool isSafe(bool tab[][M], int x, int y, int N){
    //check line
    fori(0, x){
        if(tab[y][i]==1) return false;
    }
    //check diagonal above
    int minLength;
    (x >= y) ? minLength=y : minLength=x;
    fori(1, minLength+1){
        if(tab[y-i][x-i]==1) return false;
    }
    //check diagonal below
    ((N-x)>=(N-y)) ? minLength=N-y : minLength=N-x;
    fori(1, minLength+1){
        if(tab[y+i][x-i]==1) return false;
    }
    return true;
}

bool placeQueen(bool tab[][M], int col, int N){
    bool result = false;
    if(col == N){
        printTab(tab, N);
        return true;
    }
    fori(0,N){
        tab[i][col] = 1;
        if(isSafe(tab, col, i, N)){
            result = placeQueen(tab, col+1,N)||result;
        }
        tab[i][col] = 0;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    bool tab[M][M] = {0};
    if (placeQueen(tab, 0, N));
    else cout << "NOT POSSIBLE" << "\n";
    return 0;
}

