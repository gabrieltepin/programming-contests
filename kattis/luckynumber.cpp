#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    if (n==1) cout << 9 << "\n";
	else if (n==2) cout << 45 << "\n";
	else if (n==3) cout << 150 << "\n";
	else if (n==4) cout << 375 << "\n";
	else if (n==5) cout << 750 << "\n";
	else if (n==6) cout << 1200 << "\n";
	else if (n==7) cout << 1713 << "\n";
	else if (n==8) cout << 2227 << "\n";
	else if (n==9) cout << 2492 << "\n";
	else if (n==10) cout << 2492 << "\n";
	else if (n==11) cout << 2225 << "\n";
	else if (n==12) cout << 2041 << "\n";
	else if (n==13) cout << 1575 << "\n";
	else if (n==14) cout << 1132 << "\n";
	else if (n==15) cout << 770 << "\n";
	else if (n==16) cout << 571 << "\n";
	else if (n==17) cout << 335 << "\n";
	else if (n==18) cout << 180 << "\n";
	else if (n==19) cout << 90 << "\n";
	else if (n==20) cout << 44 << "\n";
	else if (n==21) cout << 18 << "\n";
	else if (n==22) cout << 12 << "\n";
	else if (n==23) cout << 6 << "\n";
	else if (n==24) cout << 3 << "\n";
	else if (n==25) cout << 1 << "\n";
	else cout << 0 << "\n";
    return 0;
}
/*
WHY THIS SOLUTION DON'T WORK???

#include <iostream>
#include <string>
#define fori(x, y) for(int i = x; i < y; ++i)
#define rfori(x, y) for(int i = x; i >= y; --i)
#define forj(x, y) for(int j = x; j < y; ++j)
using namespace std;
string numlucky(int n, int k){
	string str = "";
	int digit;
	fori(0, n) str+='9';
	//cout << str << endl;
	rfori(k, 2){
		string ans = "";
		int tmp = 0;
		forj(0, str.size()){
			digit = (int)(str[j]-'0');
			tmp = 10*tmp + digit;
			if(j>0||tmp>=i)ans+= (char)(tmp/i + '0');
			tmp = tmp%i;
		}
		str = ans;
		//cout << ans; cout << endl;
	}
	return str;
}
string subtract(string str1, string str2){
	int tam = str2.size(), c=0;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	string ans;
	fori(0, tam){
		if((int)(str1[i])<(int)(str2[i])){
			int diff = (int)(10 + str1[i]-str2[i]-c);
			ans+=diff+'0';
			c=1;
		}
		else{
			int diff = (int)(str1[i]-str2[i]-c);
			ans+=diff+'0';
			c=0;
		}
	}
	fori(tam, str1.size()){
		int diff = (int)(str1[i]-c);
		ans+=diff;
		c=0;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, digit;
	cin >> n;
	string str1, str2;
	str1 = numlucky(n, n);
	str2 = numlucky(n-1, n);
	//cout << str1 << endl;
	//cout << str2 << endl;
	cout << subtract(str1, str2) << endl;
	return 0;
}
*/