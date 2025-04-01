// codigo a completar
#include <stdio.h>
int main(){
    #define N 20
    int i;
    double vt[N];
    double *punt = vt;
    while(punt <= vt + N)
    {
        *punt=1+rand()%100;
        printf("%.2f ", *punt);
        punt++;
    }

    return 0;
}