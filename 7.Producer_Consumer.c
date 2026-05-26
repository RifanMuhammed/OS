#include <stdio.h>
// SIMPLEST PRODUCER CONSUMER PROBLEM SOLUTION -- MAY 26 
int count = 0, size;
int buffer[100];

void display() {
    printf("\nBuffer: ");
    for(int i = 0; i < count; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void consumer() {
    if(count <= 0) {
        printf("\nBuffer is empty\n");
    } else {
        printf("Consumed: %d\n", buffer[count - 1]);
        count--;
        display();
    }
}

void producer() {
    if(count == size) {
        printf("\nBuffer full\n");
    } else {
        buffer[count] = count + 1;
        printf("Produced: %d\n", buffer[count]);
        count++;
        display();
    }
}

int main() {
    int n;
    printf("Enter buffer size: ");
    scanf("%d", &size);

    while(1) {
        printf("\nChoices are\n1.Consumer\n2.Producer\n3.Exit\nChoice: ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                consumer();
                break;
            case 2:
                producer();
                break;
            case 3:
                return 0;
        }
    }
}
