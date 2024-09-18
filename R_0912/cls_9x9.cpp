#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void) {
	int i, j;
	gotoxy(1, 20);
	for( j=1;j<=9;j++) {
		system("cls");				// '아무 키'를 입력받고 돌아오면 화면을 지움 
		for(i=1;i<=9;i++)
			printf("%d*%d=%d\n", j, i, j*i);
		printf("아무키나 누르시오.\n");
		getch();					// '아무 키'를 받아냄 
	}
	return 0;
}


void gotoxy(int x, int y){
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
