#include <stdio.h>
int main(){
for (float x = 0.0; x != 1.0; x += 0.1) {
    printf("%.1f ", x);
}
}