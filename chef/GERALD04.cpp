#include <stdio.h>
int main(){
	int T, H1, M1, H2, M2, dist;
	float t1, t2;
	scanf("%d", &T);
	while(T--){
		scanf("%d:%d", &H1, &M1);
		scanf("%d:%d", &H2, &M2);
		scanf("%d", &dist);
		t1 = 60*H1+M1;
		t2 = 60*H2+M2;
		printf("%.1f ", (float)(t1-t2+dist));
		if(t1<t2+2*dist) printf("%.1f\n", (float)(t1-t2)*0.5 + dist);
		else printf("%.1f\n", (float)(t1-t2));

	}
	return 0;
}