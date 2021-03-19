#include <iostream>
#include <algorithm>
#define get getchar_unlocked
#define fori(x, y) for(int i = x; i < y; ++i)
#define rfori(x, y) for(int i = x; i >= y; --i)
#define INF 2000000000
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
	int T, N, x;
	T= scan();
	while(T--){
		N = scan();
		int MAX=0, minSoFar=INF;
		fori(0, N){
			x = scan();
			MAX = max(MAX, x-minSoFar);
			minSoFar = min(x, minSoFar);
			//cout << minSoFar << " " << " " << MAX << endl;
		}
		
		if(MAX) printf("%d\n", MAX);
		else printf("UNFIT\n");
	}
}