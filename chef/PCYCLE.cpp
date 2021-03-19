#include <iostream>
#include <vector>
#define fori(x, y) for(int i = x; i < y; ++i)
#define M 1001
using namespace std; 
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int arr[M];
	bool isvisited[M] = {0};
	fori(0, N){
		cin >> arr[i];
	}
	int cont = 0;
	vector < vector <int> > v;
	fori(0, N){
		vector <int> cycle;
		if(isvisited[i]==0) cont++;
		while(isvisited[i]==0){
			cycle.push_back(i+1);
			isvisited[i] = 1;
			i = arr[i]-1;
            //sem esse if aqui, o v poderia receber um cycle completamente vazio
            //e na hora de imprimir o cycle, daria segmentation fault
			if(isvisited[i]==1) v.push_back(cycle);
		}
	}
	cout << cont << "\n";
	vector<int>:: iterator it;
	fori(0, cont){
		for(it=v[i].begin();it!=v[i].end();it++){
			cout << *it << " ";
		}
		it = v[i].begin();
		cout << *it;
		cout << "\n";
	}
	return 0; 
} 