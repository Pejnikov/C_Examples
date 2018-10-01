#include <stdio.h>

void swap(int *x, int *y);

main()
{
    int x = 5, y = 10;
    printf("\nBefore swap\t x is: %d\t y is: %d", x, y);
    printf("\nRef for tr\t &x is: %d\t &y is: %d", &x, &y);
    swap(&x, &y);
    printf("\nAfter swap\t x is: %d\t y is: %d", x, y);
    return 0;
}

void swap(int *px, int *py){
    int temp;
    printf("\nInside swap\t px is: %d\t py is: %d", px, py);
    printf("\nInside swap\t *px is: %d\t *py is: %d", *px, *py);
    temp = *px;
    *px = *py;
    *py = temp;
}