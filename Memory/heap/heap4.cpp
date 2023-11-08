#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE heap1 = GetProcessHeap();
    HANDLE heap2 = HeapCreate(HEAP_NO_SERIALIZE, 4096, 0);

    int* p1 = (int*) HeapAlloc(heap1, HEAP_ZERO_MEMORY, 100);
    int* p2 = (int*) HeapAlloc(heap2, HEAP_ZERO_MEMORY, 100);

    printf("%p\n", p1);
    printf("%p\n", p2);

    HeapFree(heap1, 0, p1);
    HeapFree(heap2, 0, p2);

    HeapDestroy(heap2);
}