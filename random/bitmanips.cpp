#include "bits/stdc++.h"
using namespace std;

//retorna 1 se ímpar, 0 se par
bool parityBit(int x){ 
    return x&1;
}
//imprime o inteiro em base binaria
void printBin(int x){ 
    cout << bitset<8>(x)<<endl;
}
//checa se um numero eh uma potencia de 2
bool checkPowertwo(int x){
    return ~(x&(x-1));
}
//conta o numero de bits '1' na base binaria de um inteiro n
int countSetBits(int n){
    int count = 0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}
//troca o valor de inteiros sem precisar de criar espaco extra
void swapInts (int &x, int &y){
    x = x^y;
    y = x^y;
    x = x^y;
}
//calcula o numero de bits necessarios da representacao binaria de um inteiro
int sizeBit(int n){
    int size = 0;
    while (n){
        n=n>>1;
        size++;
    }
    return size;
}
//inverte a representacao binaria de um inteiro
int reverseBit(int n){
    int tmp = n;
    int size = sizeBit(tmp);
    int rev = 0;
    while (n){
        if(n&1)rev = rev | 1<<size;
        size--;
        n = n>>1;
    }
    return rev;
}
//calcula exponencial em O(log n)
int power(int x, int n){ 
    int pow = 1;
    while (n){
        if (n&1) 
            pow*= x; //se n eh impar, multiplica por x
        n=n>>1;
        x*=x; //se n eh par multiplica por x*x
    }
    return pow;
}

//imprime em letras maiusculas e minusculas
void printUpperCase(){
    // Convert lowercase character to uppercase usando &
    for (char ch = 'a'; ch <= 'z'; ch++)
	    cout << char(ch & '_'); // prints ABCDEFGHIJKLMNOPQRSTUVWXYZ
    cout << endl;
    //Agora, o caso mais geral, usando xor
    // Convert lowercase alphabet to uppercase
    for (char ch = 'a'; ch <= 'z'; ch++)
	    cout << char(ch ^ ' '); // prints ABCDEFGHIJKLMNOPQRSTUVWXYZ
    cout << endl;
    // Convert uppercase alphabet to lowercase
    for (char ch = 'A'; ch <= 'Z'; ch++)
	    cout << char(ch ^ ' '); // prints abcdefghijklmnopqrstuvwxyz
    cout << endl;
}

int main(){
    cout << parityBit(32);
    printBin(17);
    printUpperCase();
    cout << checkPowertwo(16) << endl;
    cout << countSetBits(31) << endl;
    int x = 10, y=100;
    swapInts(x,y);
    int n=19;
    cout << bitset<6>(n) << endl;
    cout << bitset<6>(reverseBit(n)) << endl;
    cout << x << " " << y << endl;
    cout << power(6,3) << endl;
    //understand why printUppercase works
    int z = '_';
    int w = 'A';
    cout << z << " "<< w << endl;
    cout << (char)z << " " << (char)(z+2) << endl;
    cout << bitset<7>(z) << endl;
    cout << bitset<7>(z+2) << endl;
    cout << bitset<7>(z & (z+1)) << endl;
    cout << bitset<7>(z & (z+2)) << endl;

    cout << bitset<7>(37) << " " << bitset<7>(-37);

    int a = 10, b=2, c=(~(a)&b) | (a&(~(b)));
    cout << c<< endl;

    return 0;
}