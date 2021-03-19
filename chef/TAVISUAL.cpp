#include <iostream>
#define get getchar_unlocked
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
    int T, N, C , Q, L, R, k;
	T = scan();
	while(T--){
		N = scan(); C = scan(); Q = scan();
		while(Q--){
			L = scan(); R = scan();
			if(C>=L && C<=R){
				k=C-L;
				C=R-k;
			}
		}
		printf("%d\n", C);

	}
	return 0; 
} 