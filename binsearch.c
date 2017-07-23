#include <stdio.h>
#include <time.h>

int binsearch(int x,int v[],int n);
int binsearch2(int x,int v[],int n);
void printa(int a[], int n);

int main(int argc, char const *argv[]) {
    int v[] = {0,2,3,5,7,10,11,12,14,15,17,18,19,21};
    int n = sizeof(v)/sizeof(v[0]);
    printa(v, n); // print array

    // timed searches
    clock_t begin = clock();

    printf("Searching...\n");
    for (size_t i = 0; i <= v[n-1]; i++) {
        int result = binsearch2(i, v, n);
        printf("%2zu is at position %2d\n", i, result);
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %fs\n", time_spent);


    // user input search
    printf("Enter number to search:\n");
    int x;
    scanf("%d",&x);
    int result = binsearch(x, v, n);
    printf("%2d is at position %2d\n", x, result);

    return 0;
}

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

int binsearch2(int x, int a[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low < high && x != a[mid]) {
        if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;

        mid = (low + high) / 2;
    }

    if(x == a[mid])
        return mid; /* found match */
    else
        return -1; /* no match */
}

void printa(int a[], int n) {
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\b\b]\n");
}
