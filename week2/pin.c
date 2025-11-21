#include <stdio.h>


int capacity;
int avarage_power;
double time;
double batery;
int main(){
    scanf("%d%d%lf", &capacity, &avarage_power, &time);
    batery = (double)capacity/avarage_power;
    double weak = (batery-time)/batery *100;
    printf("%.2lf", weak);
}