#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct stack_node {
    char data;
    struct stack_node *link;
}stack;

stack* push(char data, stack *top);
stack* pop(stack *top);

int main(void) {
    int count = 0;
    char key;
    stack *top = (stack*)malloc(sizeof(stack));
    top->link = NULL;

    do {
        count++;
        printf("%2d 번 문자 입력 > ", count);
        key = getch();
        top = push(key, top);
        printf("%c \n", key);
    } while(key != 27);

    printf("\n\n");
    printf("ㅁ데이터 pop과정 \n\n");
	
    while(top->link != NULL) {
        key = top->data;
        top = pop(top);
        printf("%c", key);
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

stack* push(char data, stack *top) {            // 이 안에서 top = new_node 하면 리턴됐을 때 *top이 원래대로 돌아감
    if (data==27)
        return top;
    stack *new_node;
    new_node = (stack*)malloc(sizeof(stack));
    new_node -> data = data;
    new_node -> link = top;
    return new_node;
}

stack* pop(stack *top) {
    
    stack *temp, *down;
    temp = top;
    down = top -> link;
    free(temp);
    return down;
}

