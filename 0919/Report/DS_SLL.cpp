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
    // �Է¿� ���Ͱ� ������ ĳ������������ �ν��ϴ� ��. ���η� ���ư��� printf�� ������ insert�� ���·� �Է��ϴ� ��ó�� �� �о����
    printf("\n\n");
    printf("���Էµ� ���� : ");         // ���� �� �����°�??
    print_linked_list(head->link);
    printf("\n");
    printf("�Է��� ���� : ");           // ����� �� �����ϰ� ��µǴ°�??
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
    // �������� �𸣰����� ���� ��¿��� esc�� �ٷ� �ޱ��ڸ� �Ծ������ ������ �߻��ؼ� ����ó��
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