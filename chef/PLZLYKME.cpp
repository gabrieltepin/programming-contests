#include <iostream>
#include <math.h>
#define get getchar_unlocked
typedef long long ll;
using namespace std;
inline int scan(){
    int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get();}
    return n*s;
}
// S(1+C)^(D-1) >= L  
// S(x)^(n) >= L
//for n big, x would overflow, that is why it is getting WA...
bool res (ll x, ll n, ll L, ll S){
    if(S>=L) return true;
	if (x==1 || n ==0) return S>=L;
	if (n==1) return S*x>=L;
	ll po =1;
	while (n){
		if(n%2==1)
			po = po*x;
		x = x*x;
		n/=2;
		if(x*S >=L) return true;
		if(po*S >=L) return true;
	}
	return false;
}
int main() { 
    int T;
	ll L, D, S, C;
	T = scan();
	while(T--){
		L = scan(); D = scan(); S = scan(); C = scan();
		if(log(C+1.0)*(D-1) >= log(L)-log(S)) printf("ALIVE AND KICKING\n");
		else printf("DEAD AND ROTTING\n");
	}
	return 0; 
} 