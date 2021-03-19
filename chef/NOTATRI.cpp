#include <iostream>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, arr[2007];
	while(cin >> N && N){
		int ans=0;
		fori(0, N){
			cin >> arr[i];
		}
		sort(arr, arr+N);
		fori(0, N-2){
			forj(i+1, N-1){
				int a = j+1, b = N-1,s = arr[i]+arr[j], mid;
				while(a<=b){
					mid = (a+b)/2;
					if(arr[mid]<=s){
						a=mid+1;
					}
					else{
						b=mid-1;
					}
				}
				mid = (a+b)/2;
				ans+=(N-1) - mid;
				//cout << arr[i] << " " << arr[j] << " " << arr[mid] << " " << ans << endl;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}