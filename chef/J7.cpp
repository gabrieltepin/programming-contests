#include <iostream>
#include <cmath>
//na expressao do volume, tava faltando um x. Cuidado com as expressoes!!!
int main (){
    int T;
    float P, S;
    scanf("%d", &T);
    while (T--){
        scanf("%f%f", &P, &S);
        double x;
        double delta = sqrt(0.25*P*P - 6.0*S);
        if (delta<0) delta =0;
        x = (0.5*P-delta)/6.0;
        double V = x*x*x - P*x*x*0.25 + S*x*0.5;
        printf("%.2f\n", V);
    }
    return 0;
}
