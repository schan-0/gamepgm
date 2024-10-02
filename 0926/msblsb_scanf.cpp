#include <stdio.h>
#include <conio.h>
#include <math.h>
void serial_number(long long number);
void reverse_number(long long number);

int main(void) {
    
    long long number;
    scanf("%lld", &number);
    getchar();
    printf("�Է� ���� : %lld\n\n", number);
    printf("���� �������� ���\n");
    serial_number(number);
    printf("\n���� �������� ���\n");
    reverse_number(number);
	printf("\npress any key to continue.......");
	getch();
   return 0;
}

void serial_number(long long number) {
   long long num;
   int i, length=0;
   length=(int)(log10(number)+1);  //�ִ� �ڸ��� ���
   for(i=length;i>=1;i--)
   {
     num = number/(long long)pow(10, i-1);
     printf("%lld", num);
     number=number-num*(long long) pow(10,i-1);
    }
    printf("\n");
}

void reverse_number(long long number) {
   while(number>0) {
	   printf("%lld", number%10);
	   number/=10;
   }
}
