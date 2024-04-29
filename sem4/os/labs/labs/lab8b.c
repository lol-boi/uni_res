#include <stdio.h>

void findPageAndOffset(int virtual_address, int page_s) { 
    int page_number, offset;
    page_number = virtual_address / page_s;
    offset = virtual_address % page_s;
    printf("Page Number: %d\n", page_number);
    printf("Offset: %d\n", offset);
}

int main() {
    int page_s;
    printf("Enter the page size: ");
    scanf("%d", &page_s);
    int virtual_address;
    printf("Enter the virtual address: ");
    scanf("%d", &virtual_address);
    findPageAndOffset(virtual_address, page_s);
    return 0;
}


