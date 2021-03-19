#include <iostream>
#include <bitset>
#define get getchar_unlocked
#define fori(x, y) for(int i = x; i < y; ++i)
#define abs(x) (x<0)?-x:x
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
int main() { 
    int T, N;
	ll A, B;
	T = scan();
	while(T--){
		N = scan();	
		A = scan();
		B = scan();
		int setA=0, setB=0;
		while(A){
			A= A&(A-1);
			setA++;
		}
		while(B){
			B= B&(B-1);
			setB++;
		}
		int zeros = N - (setA + setB);
		zeros = abs(zeros);
		ll result = (1<<N)-1;
		while(zeros--){
			result = (result&(result-1));
		}
		printf("%lld\n", result);
	}
	return 0; 
} 