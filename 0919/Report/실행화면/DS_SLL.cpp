#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct linked_list {
    char data;
    struct linked_list *link;
};
void print_linked_list(struct linked_list *now);
void print_reverse_linked_list(struct linked_list *now);
void add_node(char data, linked_list *head);

int main(void) {
    int count = 0;
    char key;
    struct linked_list *head = (linked_list*)malloc(sizeof(struct linked_list));
    head->link = NULL;
    
    do {
        count++;
        printf("%2d", count);
        key = getch();
        add_node(key, head);
        printf("%c \n", key);
    } while (key != 27);
    // 입력에 엔터가 있으면 캐리지리턴으로 인식하는 듯. 문두로 돌아가서 printf의 문장을 insert켠 상태로 입력하는 것처럼 다 밀어버림
    printf("\n\n");
    printf("ㅁ입력된 순서 : ");         // ㅁ은 왜 씹히는가??
    print_linked_list(head->link);
    printf("\n");
    printf("입력의 역순 : ");           // 여기는 왜 멀쩡하게 출력되는가??
    print_reverse_linked_list(head->link);
    printf("\n");
    system("PAUSE");
    return 0;
}

void print_linked_list(struct linked_list *now) {

    while (now != NULL) {
        printf("%c", now->data);
        now = now->link;
    }
    printf("\n");
}


void print_reverse_linked_list(struct linked_list *now) {
    if (now -> link != NULL) {
        print_reverse_linked_list(now->link);
        printf("%c", now->data);
    }
    else
        printf("%c", now->data);
}


void add_node(char data, linked_list *head) {
    struct linked_list *new_node, *last;
    last = head;
    // 왜인지는 모르겠으나 역순 출력에서 esc가 바로 뒷글자를 먹어버리는 문제가 발생해서 예외처리
    if(data == 27)
        return;

    while (last->link != NULL)
        last = last->link;
    new_node = (struct linked_list *)malloc(sizeof(struct linked_list));
    new_node->data = data;
    new_node->link = last->link;
    last->link = new_node;
    last = new_node;
}