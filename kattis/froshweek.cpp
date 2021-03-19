#include <iostream>
#define fori(x, y) for(int i = x; i < y; ++i)//
#define forj(x, y) for(int j = x; j < y; ++j)//
#define fork(x, y) for(int k = x; k < y; ++k)//
#define TAM 1000007
using namespace std;
void merge (long* srtd, long* arr, int ini, int end, long& inv){
    int cont = ini, mid = (ini+end)/2, i = ini, j = mid+1;
    while (i<= mid && j <=end){
        if(arr[i]<arr[j]){
            srtd[cont++]=arr[i++];
        }
        else{
            srtd[cont++]=arr[j++];
            inv+= mid - i + 1;
        }
    }
    while (i<= mid){
        srtd[cont++]=arr[i++];
    }
    while (j<= end){
        srtd[cont++]=arr[j++];
    }
    fork(ini, end+1) arr[k]=srtd[k];
}
void mergesort(long* srtd, long* arr, int ini, int end, long &inv){
    if(end<=ini) return;
    int mid = (ini+end)/2;
    mergesort(srtd, arr, ini, mid, inv);
    mergesort(srtd, arr, mid+1, end, inv);
    merge(srtd, arr, ini, end, inv);
}
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    long arr[TAM], srtd[TAM], inv = 0;
    cin >> n;
    fori(0, n){
        cin >> arr[i];
    }
    mergesort(srtd, arr, 0, n-1, inv);
    cout << inv << "\n";
    return 0;
}