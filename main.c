#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void push(int** stack, int value, int* size, int* capacity) {
    if(*size >= *capacity) {
        *capacity *= 2;
        *stack = (int*)realloc(*stack, *capacity * sizeof(int));

        if(*stack == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    (*stack)[*size] = value;
    (*size)++;
}

void pop(int* size) {
    (*size)--;
}

int peek(int* stack, int size) {
    if(size <= 0) {
        return 0;
    }
    
    return stack[size - 1];
}

bool is_empty(int size) {
    return size <= 0;
}

int main() {
    int size = 0;
    int capacity = 5;
    int* stack = (int*)malloc(sizeof(capacity * sizeof(int)));

    if(stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    push(&stack, 1, &size, &capacity);
    push(&stack, 2, &size, &capacity);
    push(&stack, 3, &size, &capacity);
    push(&stack, 4, &size, &capacity);
    push(&stack, 5, &size, &capacity);
    int top = peek(stack, size);

    printf("Stack:\n");

    for(int i = size - 1; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
    
    printf("Top of Stack: %d\n", top);

    if(is_empty(size)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }
    
    free(stack);
    return 0;
}
