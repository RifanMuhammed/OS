#include <stdio.h>

int count = 0, size;
int buffer[100];

void display() {
    printf("Buffer: ");
    for(int i = 0; i < count; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void reader() {
    if(count == 0) {
        printf("Buffer is empty\n");
    } else {
        display();
    }
}

void writer() {
    if(count == size) {
        printf("Buffer full\n");
    } else {
        buffer[count] = count + 1;
        printf("Written: %d\n", buffer[count]);
        count++;
        display();
    }
}

int main() {
    int n;
    printf("Enter buffer size: ");
    scanf("%d", &size);
    while(1) {
        printf("\nChoices are \n1.Reader\n2.Writer\n3.Exit\nChoice: ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                reader();
                break;
            case 2:
                writer();
                break;
            case 3:
                return 0;
        }
    }
}
