#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#define fori(x, y) for(int i = x; i < y; ++i)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N;
	string str, place;
	cin >> T;
	while(T--){
		stack <string> stk, pstk;
		cin >> N;
		cin >> str; //"Begin"
		cin.ignore();
		getline (cin, place); //"on (place)"
		pstk.push(place);
		fori(1, N){
			cin >> str;
			stk.push(str);
			cin.ignore();
			getline (cin, place);
			pstk.push(place);
		}
		cout << "Begin " << pstk.top() << "\n";
		pstk.pop();
		fori(1, N){
			if (stk.top() == "Right") cout << "Left ";
			if (stk.top() == "Left") cout << "Right ";
			stk.pop();
			cout << pstk.top() << "\n";
			pstk.pop();
		}
		cout << "\n";
	}
	return 0;
}