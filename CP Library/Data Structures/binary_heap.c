#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"

#define left(u) ((u) * 2 + 1)
#define right(u) ((u) * 2 + 2)
#define parent(u) (((u) - 1) / 2)

typedef struct {
    int *harr;
    int cap;
    int heap_size;
} heap;

void init_heap(heap *h, int n) {
    h->harr = malloc(n * sizeof(int));
    h->cap = n;
    h->heap_size = 0;
}

void delete_heap(heap *h) {
    free(h->harr);
    h->cap = 0;
    h->heap_size = 0;
}

void increase_cap(heap *h, int new_cap) {
    if(new_cap > h->cap) {
        int *temp = malloc(new_cap * sizeof(int));
        memcpy(temp, h->harr, h->cap * sizeof(int));
        free(h->harr);
        h->harr = temp;
        h->cap = new_cap;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void keep_property(heap *h, int i) {
    while(i != 0 && h->harr[parent(i)] > h->harr[i]) {
        swap(&h->harr[parent(i)], &h->harr[i]);
        i = parent(i);
    }
}

void insert_key(heap *h, int k) {
    if(h->cap == h->heap_size) {
        increase_cap(h, 2 * h->cap);
    }
    h->harr[h->heap_size] = k;
    h->heap_size++;
    keep_property(h, h->heap_size - 1);
}

void heapify(heap *h, int i) {
    int smallest = i;
    if(left(i) < h->heap_size && h->harr[left(i)] < h->harr[smallest]) {
        smallest = left(i);
    }
    if(right(i) < h->heap_size && h->harr[right(i)] < h->harr[smallest]) {
        smallest = right(i);
    }
    if(smallest != i) {
        swap(&h->harr[i], &h->harr[smallest]);
        heapify(h, smallest);
    }
}

int extract_min(heap *h) {
    if(h->heap_size == 0) return INT_MAX;
    if(h->heap_size == 1) {
        h->heap_size--;
        return h->harr[0];
    }
    int ans = h->harr[0];
    h->harr[0] = h->harr[h->heap_size - 1];
    h->heap_size--;
    heapify(h, 0);
    return ans;
}

int main() {
    int n, x, c, t;
    scanf("%d", &n);
    heap *h = malloc(sizeof(heap));
    init_heap(h, n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert_key(h, x);
    }
    c = 1;
    t = extract_min(h);
    for(int i = 1; i < n; i++) {
        x = extract_min(h);
        if(x != t) {
            printf("%d aparece %d vez(es)\n", t, c);
            c = 0;
        }
        t = x;
        c++;
    }
    printf("%d aparece %d vez(es)\n", t, c);
    return 0;
}