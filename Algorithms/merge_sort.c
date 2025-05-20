#include "stdio.h"
#include "stdlib.h"

#define MAX 112345
typedef long long ll;

int n, arr[MAX];
ll inv;

void merge(int start, int mid, int end) {
    int *aux = (int*) malloc((end - start + 1) * sizeof(int));
    int i = start, j = mid + 1, k = 0;
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        } else {
            aux[k++] = arr[j++];
            inv += mid - i + 1;
        }
    }
    while(i <= mid) aux[k++] = arr[i++];
    while(j <= end) aux[k++] = arr[j++];
    for(i = start; i <= end; i++) {
        arr[i] = aux[i - start];
    }
    free(aux);
}

void merge_sort(int start, int end) {
    if(start < end) {
        int mid = start + (end - start) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main() {
    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        inv = 0;
        merge_sort(0, n - 1);
        printf("%lld\n", inv);
    }
    return 0;
}
