#include <stdio.h>
int main(void) {
	int T, d;
	scanf("%d", &T);
	while(T--){
	    scanf("%d", &d);
	    printf("%d\n", d%9 + 1);
	}
	return 0;
}
