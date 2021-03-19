#include <iostream>
#define get getchar_unlocked
inline int scan(){
    int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get();}
    return n*s;
}

int main(){
	int T;
	double M, N;
	T=scan();
	while(T--){
		N=scan(); M=scan();
		printf("%.6f\n", M+N-1);
	}
	return 0;
}