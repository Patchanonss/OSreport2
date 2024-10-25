#include <stdio.h>
#include <stdlib.h>

int global1, global2, global3;

void func3(int level) {
    int local3 = level;
    int *ptr3 = (int*)malloc(sizeof(int));
    *ptr3 = level * 10;

    printf("In func3, level=%d\n", level);
    printf("  local3 address: %p\n", &local3);
    printf("  ptr3 address: %p, value: %d\n", ptr3, *ptr3);
    printf("  global1 address: %p, value: %d\n", &global1, global1);
}

void func2(int level) {
    int local2 = level;
    int *ptr2 = (int*)malloc(sizeof(int));
    *ptr2 = level * 100;

    printf("In func2, level=%d\n", level);
    printf("  local2 address: %p\n", &local2);
    printf("  ptr2 address: %p, value: %d\n", ptr2, *ptr2);
    func3(level + 1);
}

void func1(int level) {
    int local1 = level;
    int *ptr1 = (int*)malloc(sizeof(int));
    *ptr1 = level * 1000;

    printf("In func1, level=%d\n", level);
    printf("  local1 address: %p\n", &local1);
    printf("  ptr1 address: %p, value: %d\n", ptr1, *ptr1);
    func2(level + 1);
}

int main() {
    global1 = 1;
    global2 = 2;
    global3 = 3;

    printf("Global1 address: %p\n", &global1);
    printf("Global2 address: %p\n", &global2);
    printf("Global3 address: %p\n\n", &global3);

    func1(1);
    

    return 0;
}