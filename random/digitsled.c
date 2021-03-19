#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Matriz[23][103];
 
void inicializarMatriz(int m, int n){
     for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            Matriz[i][j] = ' '; 
        }
     }
}
 //a size, b number (digito da vez), c eh cont(tamanho da string)
 void printCalculadora(int a, char* b, int c){
   inicializarMatriz(2*a + 3, (a + 2)*c + c - 1);
   int mult = 0;
   char N;
   int numLinhas = 2*a+3;
   while((N = *b) != '\0'){
      int primeira = (a+2)*mult; //primeira coluna do digito da vez
      int ultima = primeira + a + 2; //ultima coluna do digito da vez
      if(N == '0'){
         for(int i = 0; i<=numLinhas; i++){
            for(int j = primeira; j<ultima; j++){
               if(i==0 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(i==numLinhas-1 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(j==ultima-1 && i!=0 && i !=a+1 && i !=numLinhas-1)
                  Matriz[i][j]='|';
               if(j==primeira && i!=0 && i !=a+1 && i !=numLinhas-1)
                  Matriz[i][j]='|';
            }
         }
         
      }
      if(N == '1'){
         for(int i = 0; i<=numLinhas; i++){
            for(int j = primeira; j<ultima; j++){
               if(j == ultima-1 && i != 0 && i!=a+1 && i!=numLinhas-1)
                  Matriz[i][j]='|';
            }
         }
      }
      if(N == '2'){
           for(int i = 0; i < numLinhas; i++){
            for(int j = primeira; j < ultima; j++){
               if(i==0 && j!= primeira && j!= ultima - 1)
                  Matriz[i][j]='-';
               if(i==numLinhas-1 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(i==(numLinhas-1)/2 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(j==ultima-1 && i!=0 && i < a+1)
                  Matriz[i][j]='|';
               if(j==primeira && i > a+1 && i < numLinhas-1)
                  Matriz[i][j]='|';
            }
         }
         
      }
      if(N == '3'){
         for(int i = 0; i<=numLinhas; i++){
            for(int j = primeira; j<ultima; j++){
               if(i==0 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(i==numLinhas-1 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(i==a+1 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(j==ultima-1 && i!=0 && i !=a+1 && i !=numLinhas-1)
                  Matriz[i][j]='|';
            }
         }
      }
      if(N == '4'){
         for(int i = 0; i<=numLinhas; i++){
            for(int j = primeira; j<ultima; j++){
               if(i==a+1 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(j==ultima-1 && i!=0 && i !=a+1 && i !=numLinhas-1)
                  Matriz[i][j]='|';
               if(j==primeira && i!=0 && i <a+1)
                  Matriz[i][j] = '|';
            }  
         }
      }
      if(N == '5'){
         for(int i = 0; i < numLinhas; i++){
            for(int j = primeira; j < ultima; j++){
               if(i==0 && j!= primeira && j!= ultima - 1)
                  Matriz[i][j]='-';
               if(i==numLinhas-1 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(i==(numLinhas-1)/2 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(j==ultima-1 && i > a+1 && i < numLinhas-1)
                  Matriz[i][j]='|';
               if(j==primeira && i!=0 && i < a+1)
                  Matriz[i][j]='|';
            }
         }
         
      }
      if(N == '6'){
         for(int i = 0; i < numLinhas; i++){
            for(int j = primeira; j < ultima; j++){
               if(i==0 && j!= primeira && j!= ultima - 1)
                  Matriz[i][j]='-';
               if(i==numLinhas-1 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(i==(numLinhas-1)/2 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(j==ultima-1 && i!=0 && i !=a+1 && i !=numLinhas-1)
                  Matriz[i][j]='|';
               if(j==primeira &&  i > a+1 && i < numLinhas-1)
                  Matriz[i][j]='|';
            }
         }
      }
      if(N == '7'){
         for(int i = 0; i < numLinhas; i++){
            for(int j = primeira; j < ultima; j++){
               if(i==0 && j!= primeira && j!= ultima - 1)
                  Matriz[i][j]='-';
               if(j==ultima-1 && i!=0 && i !=a+1 && i !=numLinhas-1)
                  Matriz[i][j]='|';
            }
         }
         
      }
      if(N == '8'){
         for(int i = 0; i < numLinhas; i++){
            for(int j = primeira; j < ultima; j++){
               if(i==0 && j!= primeira && j!= ultima - 1)
                  Matriz[i][j]='-';
               if(i==numLinhas-1 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(i==(numLinhas-1)/2 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(j==ultima-1 && i!=0 && i !=a+1 && i !=numLinhas-1)
                  Matriz[i][j]='|';
               if(j==primeira && i!=0 && i !=a+1 && i !=numLinhas-1)
                  Matriz[i][j]='|';
            }
         }
         
      }
      if(N == '9'){
         for(int i = 0; i < numLinhas; i++){
            for(int j = primeira; j < ultima; j++){
               if(i==0 && j!= primeira && j!= ultima - 1)
                  Matriz[i][j]='-';
               if(i==numLinhas-1 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(i==(numLinhas-1)/2 && j!=primeira && j!=ultima-1)
                  Matriz[i][j]='-';
               if(j==ultima-1 && i!=0 && i !=a+1 && i !=numLinhas-1)
                  Matriz[i][j]='|';
               if(j==primeira &&  i!=0 && i < a+1)
                  Matriz[i][j]='|';
            }
         }
         
      }
      mult++;
      b++;
   }

 }
 
void printMatriz(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%c", Matriz[i][j]);
        }
        printf("\n");
    }
}
 
int main(){
   char* number;
   int size, cont;
   while(scanf("%d%s", &size, number) && size != 0){
      getchar();
      
      cont = strlen(number);
      printCalculadora(size, number, cont);
      
      printMatriz(2*size + 3, (size + 2)*cont + cont - 1);
      printf("\n");
   }
   return 0;
}