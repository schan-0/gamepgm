#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void) {
	int i, j;
	gotoxy(1, 20);
	for( j=1;j<=9;j++) {
		system("cls");				// '�ƹ� Ű'�� �Է¹ް� ���ƿ��� ȭ���� ���� 
		for(i=1;i<=9;i++)
			printf("%d*%d=%d\n", j, i, j*i);
		printf("�ƹ�Ű�� �����ÿ�.\n");
		getch();					// '�ƹ� Ű'�� �޾Ƴ� 
	}
	return 0;
}


void gotoxy(int x, int y){
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
