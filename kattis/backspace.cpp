#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	char c;
	string str;
	while(cin >> c){
		if(c=='<') 
		    str.pop_back();
		else
		    str+=c;
	}
	cout << str <<"\n";
	return 0;
}