#include <stdio.h>

int main() {
    int n, frames, i, j, found, index = 0, page_faults = 0, hit = 0;

    printf("Enter the size of the page: ");
    scanf("%d", &n);

    char pages[100]; 
    printf("Enter the page string: ");
    scanf("%s", pages);

    printf("Enter the number of page frames: ");
    scanf("%d", &frames);

    int mem[frames];

    
    for (i = 0; i < frames; i++) {
        mem[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int current_page = pages[i] - '0';  
        found = 0;

        
        for (j = 0; j < frames; j++) {
            if (mem[j] == current_page) {
                hit++;
                found = 1;
                break;
            }
        }

        
        if (!found) {
            mem[index] = current_page;
            index = (index + 1) % frames;
            page_faults++;
        }
    }printf("Page faults: %d\n", page_faults);
    printf("Page hits: %d\n", hit);
    printf("Hit Ratio: %d\n", hit);
    printf("page_fault Ratio: %d\n",page_faults);

    return 0;
}
