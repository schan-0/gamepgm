#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char ch;
	printf("���ڸ� �Է��ϰ� Enter>");
	scanf("%c", &ch);
	system("cls");	// system()�� ���� �ֿܼ��� �ľ��� ��ɾ ��� ���ִ� ������ �Ѵ�. 
	printf("�Էµ� ���� %c\n", ch);
	return 0;
}


