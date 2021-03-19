#include <iostream>
#include <algorithm>
#define fori(x, y) for(int i = x; i < y; ++i)
#define forj(x, y) for(int j = x; j < y; ++j)
#define TAM 1002
#define LIM 100007
using namespace std;
int main(){
	int T, N, tmp, H[TAM], K[TAM], sum[TAM];
	scanf("%d", &T);
	while(T--){
		int cont =0, M=0;
		fori(0, TAM) sum[i]=LIM;
		sum[0]=0;
		scanf("%d", &N);
		//distance
		fori(0, N) {
			scanf("%d", &tmp);
            //Estava dando erro pq TAM tava em 501, jah que 0<=distance<=500
            //Mas eu decidi armazenar o dobro nos vetores, sendo assim, o vetor 
            //deveria ser de tamanho 1000, nao 500
			H[i]=2*tmp;
			M = max(M, H[i]);
		}
		//fuel capacity
		fori(0, N) {
			scanf("%d", &K[i]);
		}
		sort(K, K+N);
		fori(0, N){
			forj(1, M+1){
				if(j>=K[i]) sum[j]=min(sum[j-K[i]]+1, sum[j]);
			}
		}
		//resolver como XORSUB problem da errado, pois nao se conta
		//todas as combinacoes possiveis ja que pode haver repeticao
		//de elementos!!
		fori(0, N)
			cont+=sum[H[i]];
		printf("%d\n", cont);
	}
	return 0;
}

