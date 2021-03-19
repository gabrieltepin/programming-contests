#include <iostream>
#define fori(x, y) for(int i =x; i<y ; i++)
using namespace std;
//Euclideans' algorithm
int gcd(int a, int b){
    cout << a << " " << b << endl;
    if (a==0) return b;
    return gcd(b%a, a);
}

int phi_noob(int n){
    int result = 0;
    fori(2, n){
        if (gcd(i, n)==1) result++;
    }
    return result;
}

int phi(int n) { 
    int result = n;
    for (int p = 2; p * p <= n; ++p) { 
        if (n % p == 0) { 
            while (n % p == 0) 
                n /= p; //retira todos os fatores p de n para garantir
                //que seja feito o produto com um numero primo
            result -= result / p; 
        } 
    } 
    //pode haver um primo depois de raiz(n)
    //mas apenas um unico primo
    //como, por exemplo, phi(10), cujos primos sao: 2 e 5, em que 5>3
    //phi(10) == 10(1-1/2)(1-1/5) == 4
    if (n > 1) 
        result -= result / n; 
    return result; 
} 
int powmod(int x, int y, int M){
    if(M==0) return -1;
    if(x==0 || y==1) return x%M;
    if(x==1) return 1;
    int pow = 1;
    while(y){
        if(y%2==1) pow = (pow%M)*(x%M);
        y/=2; 
        x=(x%M)*(x%M);
    }
    return pow%M;
}
int main(){
    cout << gcd(154, 896) << endl;
    cout << endl;
    cout << phi(10) << endl;
    cout << endl;
    cout << powmod(3, 4, 4) << endl;
    return 0;
}