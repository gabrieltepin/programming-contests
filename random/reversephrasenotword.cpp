#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#define fori(x, y) for (int i = x; i< y; i++)
#define sz(arr) (*(&arr+1) - arr)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "word another world";
    string tmp;
    //stringstream class check (check is the class name)
    stringstream ss (str); 
    stack <string> stk;
    while( getline(ss, tmp, ' ') ){
        stk.push(tmp);
    }
    while (!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    
    return 0;
}
//if one couldnt't use sstream, reverse all the str and begin indexing the ' ' 
//and printing the words from the i+1 ' ' to the i ' '
