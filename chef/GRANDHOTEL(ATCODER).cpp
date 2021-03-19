#include <iostream>
#define fori(x, y) for(int i = x; i<y; i++)
typedef long long ll;
using namespace std;
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, op=0;
	cin >> N;
	int arr[107];
	fori(0, N)
		cin >> arr[i];
	bool iswatering = 1;
	while(iswatering){
		int m = 1000, numzeros=0;
		fori(0, N){
			while(i < N && arr[i]==0){
				i++;
				numzeros++;
			}
			int l =i ;
			while(i < N && arr[i]!=0){
				if(m>arr[i])
					m=arr[i];
				i++;
			}
			int r = i;
			//fori(0, N) cout << arr[i] << " ";
			//cout << endl << m << " " << op << endl;
			if(m<1000) op+=m;
			fori(l, r) arr[i]-=m;
			i=N;
		}
		if(numzeros==N) iswatering =0;
	}
	cout << op << "\n";
	
	return 0; 
} 