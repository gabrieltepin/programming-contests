#include <iostream>
#include <string>
#define fori(x, y) for(int i = x; i < y; ++i)
#define rfori(x, y) for(int i = x; i >= y; --i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b, ans="";
	int s=0, carry=0;
	cin >> a >> b;
	fori(1, max(a.size(), b.size())+1){
		if(a.size()>=i) s = (int)(a[a.size()-i] - '0');
		if(b.size()>=i) s += (int)(b[b.size()-i]- '0');
		s += carry;
		if(s>9) carry=1;
		else carry = 0;
		ans+=('0'+(s%10));
		s=0;
	}
	if(carry==1)ans+='1';
	rfori(ans.size()-1, 0){
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}