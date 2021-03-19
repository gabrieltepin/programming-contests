#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define fori(x, y) for(int i = x; i<y;i++)
#define forj(x, y) for(int j = x; j<y;j++)
using namespace std;

class Integer{
    int x;
public:
    Integer(){
        x=0;
    }
    Integer(int I){
        x=I;
    }
    Integer operator+ (const Integer &I){
        Integer ans;
        ans.x = x + I.x;
        return ans;
    }
    Integer operator- (const Integer &I){
        Integer ans;
        ans.x = x - I.x;
        return ans;
    }
    Integer operator* (const Integer &I){
        Integer ans;
        ans.x = x - I.x;
        return ans;
    }
    Integer &operator= (int I){
        x = I;
        return *this;
    }
    //this below shouldn't have the & because, as I is a local variable, it ceases to exist when the body function ends
    Integer operator++ (int){
        Integer I;
        I.x = x++;
        return I;
    }
    Integer operator++ (){
        x+=1;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Integer I);
};
ostream &operator<<(ostream &os, const Integer I){
    os << I.x;
    return os;
};

int main(){
    Integer i = 3, j=5, k=3;
    cout << i << endl;
    cout << i++ << endl;
    cout << i + j + k << endl;
    return 0;
}