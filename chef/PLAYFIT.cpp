#include <iostream>
#include <algorithm>
#define get getchar_unlocked
#define fori(x, y) for(int i = x; i < y; ++i)
#define rfori(x, y) for(int i = x; i >= y; --i)
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
int main(){
	int T, N, arr[M], minSoFar[M];
	T= scan();
	while(T--){
		N = scan();
		fori(0, N){
			arr[i] = scan();
			if(i==0)minSoFar[i]=arr[i];
			else minSoFar[i]=min(arr[i], minSoFar[i-1]);
		}
		int maxSoFar=0, MAX=0;
		rfori(N-1, 0){
			maxSoFar = max(maxSoFar, arr[i]);
			MAX = max(MAX, maxSoFar-minSoFar[i]);
		}
		if(MAX) printf("%d\n", MAX);
		else printf("UNFIT\n");
	}
}