#include <iostream>
#include <bitset>
#define fori(x, y) for(int i = x; i < y; ++i)
#define TAM 1000007
using namespace std;
void upd (int* arr, int* s, int i, int n){
    if(arr[i]==1) {
        arr[i] = 0;
        while(i<=n){
            s[i]--;
            i+= i&(-i);
        }
    }
    else {
        arr[i] = 1;
        while(i<=n){
            s[i]++;
            i+= i&(-i);
        }
    }
	//fori(0, n) cout << s[i]; cout << endl;
}
int sum (int* s, int i){
    int tmp=0;
	while(i>0){
		tmp+=s[i];
		i-=i&(-i);
	}
	return tmp;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    // the arr vector isn't really neccessary
    //we could use sum(s, x)-sum(s, x-1) to get the current value of that x index
	int n, k, arr[TAM], s[TAM], x, y;
    char c; 
	cin >> n >> k;
    fori(0, n+1) arr[i]=0;
    fori(0, n+1) s[i]=0;
    while (k--){
        cin >> c;
        if(c=='F'){
            cin >> x;
            upd(arr, s, x, n);
        }
        else {
            cin >> x >> y;
            cout << sum(s, y) - sum(s, x-1) << "\n";
        }
    }
	return 0;
}