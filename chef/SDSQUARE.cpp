#include <iostream>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, indxa, indxb;
	cin >> T;
	vector <ll> v;
	fori(0, 100001){
		v.push_back((ll)i*i);
	}
	while(T--){
		ll a, b, mid;
		cin >> a >> b;
		ll t1=0, t2 = v.size()-1, cont =0;
		//1 <= a <= 10000000000
		while(t1<=t2){
			mid = (t1+t2)/2;
			//cout << mid << " " << v[mid] << endl;
			if(v[mid]>a){
				t2=mid-1;
			}
			else if (v[mid]<a){
				t1=mid+1;
			}
			else{
				t1 = mid + 1;
				t2 = mid - 1;
			}
		}
		// a <= b <=10000000000
		indxa = t1 = mid;
		if(v[indxa]<a)indxa++;
		//cout << indxa << " " << v[indxa] << endl << endl;
		t2 = v.size()-1;
		while(t1<=t2){
			mid = (t1+t2)/2;
			//cout << mid << " " << v[mid] << endl;
			if(v[mid]>b){
				t2=mid-1;
			}
			else if (v[mid]<b){
				t1=mid+1;
			}
			else{
				t1 = mid + 1;
				t2 = mid - 1;
			}
		}
		indxb = mid;
		if(v[indxb]>b)indxb--;
		//cout << indxb << " " << v[indxb] << endl;
		fori(indxa, indxb+1){
			ll tmp = v[i];
			while(tmp){
				if(tmp%10==0 ||tmp%10==1||tmp%10==4||tmp%10==9){
					tmp/=10;
				}
				else{
					break;
				}
				if(tmp==0){
					cont++;
					//cout << v[i] << endl;
				}
			}
		}
		//cout << indxb << " " << v[indxb] << endl << endl;
		cout << cont << "\n";
	}
	return 0;
}

