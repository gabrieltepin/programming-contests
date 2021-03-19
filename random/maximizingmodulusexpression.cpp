#include <iostream>
#define fori(x, y) for(int i = x; i < y; i++)
#define rfori(x, y) for(int i = x; i >= y; i--)
#define M 100001
#define mx(x, y) (x>=y)?x:y
#define mn(x, y) (x<=y)?x:y
#define abs(x) (x>=0)?x:-x //obs, operator ? is lower precedence than <<
typedef long long ll;
using namespace std; 
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while (T--){
		cin >> N;
		int MAX=0, max1=0, max2=0, min1 =M, min2=M, A[M];
		fori(0, N){
			cin >> A[i];
			//cout <<i << ":" << max1 << " " << max2 << " "  << min1 << " "  << min2 << " " << endl;
			if(A[i]+i>max1)
				max1=A[i]+i;
			if(A[i]-i>max2)
				max2=A[i]-i;
			if(A[i]+i<min1)
				min1=A[i]+i;
			if(A[i]-i<min2)
				min2=A[i]-i;
		}
		MAX = mx(max1-min1, max2 - min2);
		cout << MAX << "\n";
	}
	return 0; 
} 