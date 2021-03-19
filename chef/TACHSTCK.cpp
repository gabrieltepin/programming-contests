#include <iostream>
#include <algorithm>
#define get getchar_unlocked
#define fori(x, y) for(int i = x; i < y; ++i)
#define M 100007
using namespace std;
inline int scan(){
    int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}

int main() { 
    int N, D, L[M], cont =0;
	N=scan();
	D=scan();
	fori(0, N){
		L[i] = scan();
	}
	sort(L, L+N);
	fori(0, N-1){
		if(L[i+1]-L[i]<=D) {
			cont++;
			++i;
		}
	}
	printf("%d\n", cont);
	return 0; 
} 