#include <stdio.h>
#include <windows.h>
// Ŀ�� ��ġ ���� ���α׷� 
void gotoxy(int x, int y);	// ������ ���߿� �ϴ��� ���� ���� �س��� �ν��� �Ѵ�. 

int main(void) {
	gotoxy(2,4);
	printf("Hello");
	gotoxy(40, 20);
	printf("Hello");
	return 0;
}

void gotoxy(int x, int y){		// x�� ��, y�� ���̴�. 
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
