#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu_display(void);
void hamburger(void);
void spaghetti(void);
void press_any_key(void);

int main(void) {
	int c;
	while((c=menu_display()) != 3) {	// 3을 입력받으면 종료 
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
	printf("간식 만들기\n\n");
	printf("1. 햄버거 \n");
	printf("2. 스파게티\n");
	printf("3. 프로그램 종료\n\n");
	printf("메뉴번호 입력>");
	select=getch()-48;			// n = n + 48 in ASCII 
	return select;
}

void hamburger(void) {
	system("cls");
	printf("햄버거 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}

void spaghetti(void) {
	system("cls");
	printf("스파게티 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}
/* 
	press_any_key를 호출하는 함수는 hamburger(), spagetti()
	press_any_key가 return하면 위 함수들도 return하고 종료됨.
	그러면 main의 switch문에서 break로 switch를 벗어나고 다시 for의 조건문으로 돌아감
	이때 manu_display가 호출되면서 메인화면이 표시되는 것
*/
void press_any_key(void) {
	printf("\n\n");
	printf("아무키나 누르면 메인 메뉴로...");
	getch();		 
}
