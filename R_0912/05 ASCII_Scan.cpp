#include <stdio.h>
#include <conio.h>
//입력한 키의 식별번호를 보여주는 프로그램 
// 테스트 입력값 : 1q2w3e!@#←↑→↓ 
int main(void) {
	int chr;
	do {
		chr=getch();
		if (chr==0 || chr == 0xe0) {			
			chr=getch();
			printf("확장키 code=%d\n", chr);
		}
		else
			printf("아스키 code=%d\n", chr);
	} while(1);
		return 0;
}

