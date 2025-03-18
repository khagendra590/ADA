#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void simple_sort(int [], int, int, int);
void merge_sort(int [], int, int);

int main() {
    int n;
    int i;

    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the array elements: \n");
    for (i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }

    merge_sort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        simple_sort(a, low, mid, high);
    }
    else return;
}

void simple_sort(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int c[high+1];

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    while (i <= mid) {
        c[k++] = a[i++];
    }

    while (j <= high) {
        c[k++] = a[j++];
    }

    for (int r = low; r <= high; r++) {
        a[r] = c[r];
    }
}
