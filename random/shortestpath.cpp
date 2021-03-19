#include <bits/stdc++.h>
#define M 10
using namespace std;

void findPath(int tab[M][M], int i, int j, int x, int y, int n, int &m){
    if (i==x && j == y) {
        m = min(m,n);
        //cout << n << endl;
        return;
    }
    if(i<0 || i>M || j<0 || j>M){
        return;
    }
    if(tab[i][j]==0 || tab[i][j]==2){ //if the place was already visited, it becomes 2
        return;
    }
    int aux = tab[i][j];
    tab[i][j]=2;
    //cout << i << j << endl;
    findPath(tab, i, j+1, x, y, n+1, m); 
    findPath(tab, i+1, j, x, y, n+1, m); 
    findPath(tab, i, j-1, x, y, n+1, m);
    findPath(tab, i-1, j, x, y, n+1, m);
    tab[i][j]=aux; //backtracking
    return;
}
int main(){
	int mat[M][M] = 
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 }, //0
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 }, //1
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 }, //2
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 }, //3
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 }, //4
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 }, //5
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 }, //6
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 }, //7
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 }, //8
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 }, //9
	};
    int minimum = 100;
    findPath(mat, 0, 0, 9, 2, 0, minimum);
    cout << minimum << endl;

	return 0;
}