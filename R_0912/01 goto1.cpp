#include <stdio.h>
#include <windows.h>
// 커서 위치 제어 프로그램 
void gotoxy(int x, int y);	// 구현은 나중에 하더라도 선언 먼저 해놔야 인식을 한다. 

int main(void) {
	gotoxy(2,4);
	printf("Hello");
	gotoxy(40, 20);
	printf("Hello");
	return 0;
}

void gotoxy(int x, int y){		// x가 열, y가 행이다. 
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
