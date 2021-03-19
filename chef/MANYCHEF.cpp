#include <iostream>
#include <string>
#define forj(x, y) for(int j = x; j < y; ++j)
#define rfori(x, y) for(int i = x; i >= y; --i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, M, N, ans;
	string str;
	cin >> N;
	forj(0, N){
		cin >> str;
		rfori(str.size()-1, 0){
            //in this case, as we want the lexicography smaller output, then we must iterate in reverse
			if((str[i]=='F' || str[i]=='?') && (str[i-1]=='E' || str[i-1]=='?') && (str[i-2]=='H' || str[i-2]=='?') && (str[i-3]=='C' || str[i-3]=='?')){
				str[i] = 'F';
				str[i-1] = 'E';
				str[i-2] = 'H';
				str[i-3] = 'C';
			}
			else{
				if(str[i]=='?') str[i] = 'A';
			}
		}
		cout << str << "\n";
	}
	return 0;
}