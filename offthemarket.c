#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *ptrs[10];

void debugshell(){
    system("/bin/sh");
}

void create(){
    unsigned int i, size;
    unsigned int index = 10;
    char buf[1024];

    for (i = 0; i < 10; i++) {
        // Check if there's an empty pointer(NULL)
        if(ptrs[i] == NULL){
            index = i;
            break;
        }
    }

    if (index == 10){
        puts("no free slots\n");
        return;
    }

    printf("\nUsing slot %u\n", index);
    
    printf("Size: ");
    scanf("%u", &size);

    if (size > 1023){
        puts("Max size exceededd\n");
        return;
    }

    printf("Item name: ");
    size = read(0, buf, size); // Vuln
    buf[size] = 0x00; // Vuln

    ptrs[index] = (char*) malloc(size);
    strcpy(ptrs[index], buf);

    puts("Successfully created an item for interstellar trade.\n");

}

void process(int choice){
    int index;
    printf("Index: ");
    scanf("%u", &index);

    if (index > 10) {
        puts("invalid index\n");
        return;
    }

    if(ptrs[index] == NULL){
        puts("Item spot doesn't exist");
        return;
    }

    if(choice == 1) {
        free(ptrs[index]);
        ptrs[index] = NULL;
        puts("Item deleted successfully");
    } else if (choice == 2) {
        printf("Item content: \n");
        printf("%s", ptrs[index]);
        printf("\n\n");
    }
}

int main(){
    setvbuf(stdout, NULL, _IONBF, 0);

    while (1) {
        /* code */
        int choice;
        puts("Welcome to the Cosmic Emporium Trading Post.");
        puts("1. Create an item to sell in the Galactic Market");
        puts("2. Delete an item from the Celestial Stock");
        puts("3. Print items for interstellar viewing");
        puts("4. Exit the Multiverse Market\n");

        printf("> ");
        scanf("%u", &choice);


        switch(choice) {
            case 1:
                create();
                break;
            case 2:
                process(1);
                break;
            case 3:
                process(2);
                break;
            case 4:
                exit(0);
                break;
        }
    }
    
}