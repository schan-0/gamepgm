#include <stdio.h>
#include <conio.h>
#include <math.h>
void serial_number(long long number);
void reverse_number(long long number);

int main(void) {
    
    long long number;
    scanf("%lld", &number);
    getchar();
    printf("입력 숫자 : %lld\n\n", number);
    printf("높은 단위부터 출력\n");
    serial_number(number);
    printf("\n낮은 단위부터 출력\n");
    reverse_number(number);
	printf("\npress any key to continue.......");
	getch();
   return 0;
}

void serial_number(long long number) {
   long long num;
   int i, length=0;
   length=(int)(log10(number)+1);  //최대 자리수 계산
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
