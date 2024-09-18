#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char ch;
	printf("문자를 입력하고 Enter>");
	scanf("%c", &ch);
	system("cls");	// system()은 내가 콘솔에서 쳐야할 명령어를 대신 쳐주는 역할을 한다. 
	printf("입력된 문자 %c\n", ch);
	return 0;
}


