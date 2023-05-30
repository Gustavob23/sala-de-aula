#include<stdio.h>

void swap(int*a, int*b) {

    int t = *a;

    *a = *b;
    *b = t;

}

int main() {

    int x, y;
    x = 10;
    y = 20;

    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

return 0;
}