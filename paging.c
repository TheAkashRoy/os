#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4

int main() {
    int n, i, j;
    printf("Enter the number of memory locations: ");
    scanf("%d", &n);
    
    // Calculate the number of pages
    int num_pages = n / PAGE_SIZE;
    if (n % PAGE_SIZE != 0) {
        num_pages++;
    }
    
    // Allocate memory for the page table
    int *page_table = (int *) malloc(num_pages * sizeof(int));
    
    // Initialize the page table with -1 (invalid page)
    for (i = 0; i < num_pages; i++) {
        page_table[i] = -1;
    }
    
    // Read the memory locations and update the page table
    printf("Enter the memory locations:\n");
    for (i = 0; i < n; i++) {
        int mem_loc;
        scanf("%d", &mem_loc);
        
        // Calculate the page number and offset for the memory location
        int page_num = mem_loc / PAGE_SIZE;
        int offset = mem_loc % PAGE_SIZE;
        
        // Check if the page is present in the page table
        if (page_table[page_num] == -1) {
            // If the page is not present, allocate a new page and update the page table
            page_table[page_num] = i;
            printf("Page %d allocated to frame %d\n", page_num, i);
        } else {
            // If the page is present, use the existing page and print the frame number
            printf("Memory location %d maps to frame %d\n", mem_loc, page_table[page_num]);
        }
    }
    
    free(page_table);
    return 0;
}