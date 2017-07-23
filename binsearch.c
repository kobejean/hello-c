#include <stdio.h>

int binsearch(int x, int a[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < a[mid])
            high = mid - 1;
        else if (x > a[mid])
            low = mid + 1;
        else
            return mid; /* found match */
    }
    return -1; /* no match */
}

void printa(int a[], int n) {
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\b\b]\n");
}

int main(int argc, char const *argv[]) {
    int v[] = {0,2,3,5,7,10,11,12,14,15,17,18,19,21};
    int n = sizeof(v)/sizeof(v[0]);
    printa(v, n);

    for (size_t i = 0; i <= v[n-1]; i++) {
        int result = binsearch(i, v, n);
        printf("%2zu is at position %2d\n", i, result);
    }
    return 0;
}
