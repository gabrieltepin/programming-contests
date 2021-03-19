#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define fori(x, y) for(int i = x; i<y;i++)
#define forj(x, y) for(int j = x; j<y;j++)
using namespace std;

char** matrizPixel;

void printMatriz(int N, int M){
   fori(0 , N){
            forj(0, M){
               cout << matrizPixel[i][j];
            }
            cout << endl;
         }
}

char** alocarMatriz(int Linhas, int Colunas){
     matrizPixel = (char**)malloc(Linhas*sizeof(int*));
     for(int i = 0; i < Linhas; i++){
         matrizPixel[i] = (char*)malloc(Colunas*sizeof(int));
     }
     for(int i = 0; i < Linhas; i++){
         for(int j = 0; j < Colunas; j++){
             matrizPixel[i][j] = 'O';
         }
     }
     return matrizPixel;
}

void funcaoFill(int x, int y, char d, char c, int n, int m){
   if(y>m || y<0 || x>n || x<0) return;
   if(matrizPixel[y][x] != d) return; 
   matrizPixel[y][x]=c;
   funcaoFill(y-1, x, d, c, n, m);
   funcaoFill(y+1, x, d, c, n, m);
   funcaoFill(y, x-1, d, c, n, m);
   funcaoFill(y, x+1, d, c, n, m);
}

int main(){
   char name[12];
   char comando, C, D, tmp;
   int M, N, X, Y, Y1, Y2, X1, X2;
   while(scanf("%c", &comando) && comando!='X'){
      switch(comando){
         case 'I':
            //M colunas, N linhas
            scanf("%d%d", &M, &N);
            alocarMatriz(N, M);
            break;
         case 'C':
            for(int i = 0 ; i < N; i++){
               for(int j = 0 ; j < M; j++){
                  matrizPixel[i][j] = 'O';
               }
            }
            break;
         case 'L':
            scanf("%d%d%c%c", &X, &Y, &tmp, &C);
            matrizPixel[Y-1][X-1] = C;
            break;
         case 'V':
            scanf("%d%d%d%c%c", &X, &Y1, &Y2, &tmp, &C);
            for(int i = Y1 - 1 ; i < Y2; i++){
               matrizPixel[i][X-1] = C;
            }
            break;
         case 'H':
            scanf("%d%d%d%c%c", &X1, &X2, &Y, &tmp, &C);
            for(int j = X1 - 1 ; j < X2; j++){
                  matrizPixel[Y-1][j] = C;
            }
            break;
         case 'K':
            scanf("%d%d%d%d%c%c", &X1, &Y1, &X2, &Y2, &tmp, &C);
            for(int i = Y1 - 1 ; i < Y2; i++){
               for(int j = X1 - 1 ; j < X2; j++){
                  matrizPixel[i][j] = C;
               }
            }
            break;
         case 'F':
            scanf("%d%d%c%c", &X, &Y, &tmp, &C);
            D = matrizPixel[Y][X];
            if(Y > 0 && Y <= N && X >= 0 && X <= M)
               funcaoFill(Y-1, X-1, D, C, N, M);
            break;
         case 'S':
            scanf("%s", name);
            printf("%s\n", name);
            for(int i = 0; i < N; i++){
               for(int j = 0; j < M; j++){
                  printf("%c", matrizPixel[i][j]);
               }
               printf("\n");
            }
            break;
      }
   }
   return 0;
}