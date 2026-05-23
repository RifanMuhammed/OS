#include <stdio.h>

int data = 0;
int readcount = 0;

void reader(int id) {
    readcount++;
    printf("Reader %d is reading data = %d\n", id, data);
    readcount--;
}

void writer(int id) {
    if(readcount > 0) {
        printf("Writer %d waiting\n", id);
    } else {
        data++;
        printf("Writer %d updated data to %d\n", id, data);
    }
}

int main() {
    int choice, id;
    while(1) {
        printf("\n1.Reader\n2.Writer\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Reader ID: ");
                scanf("%d", &id);
                reader(id);
                break;

            case 2:
                printf("Enter Writer ID: ");
                scanf("%d", &id);
                writer(id);
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
