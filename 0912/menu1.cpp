#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu_display(void);
void hamburger(void);
void spaghetti(void);
void press_any_key(void);

int main(void) {
	int c;
	while((c=menu_display()) != 3) {	// 3�� �Է¹����� ���� 
		switch(c) {
			case 1 : hamburger();
				break;
			case 2 : spaghetti();
				break;
			default : break;
		}
	}
	return 0;
}

int menu_display(void) {
	int select;
	system("cls");
	printf("���� �����\n\n");
	printf("1. �ܹ��� \n");
	printf("2. ���İ�Ƽ\n");
	printf("3. ���α׷� ����\n\n");
	printf("�޴���ȣ �Է�>");
	select=getch()-48;			// n = n + 48 in ASCII 
	return select;
}

void hamburger(void) {
	system("cls");
	printf("�ܹ��� ����� ���\n");
	printf("�߷�\n");
	press_any_key();
}

void spaghetti(void) {
	system("cls");
	printf("���İ�Ƽ ����� ���\n");
	printf("�߷�\n");
	press_any_key();
}
/* 
	press_any_key�� ȣ���ϴ� �Լ��� hamburger(), spagetti()
	press_any_key�� return�ϸ� �� �Լ��鵵 return�ϰ� �����.
	�׷��� main�� switch������ break�� switch�� ����� �ٽ� for�� ���ǹ����� ���ư�
	�̶� manu_display�� ȣ��Ǹ鼭 ����ȭ���� ǥ�õǴ� ��
*/
void press_any_key(void) {
	printf("\n\n");
	printf("�ƹ�Ű�� ������ ���� �޴���...");
	getch();		 
}
