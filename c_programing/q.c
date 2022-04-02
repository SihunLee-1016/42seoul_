#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
   char a;
   int b;
   scanf("%c %d", &a, &b);
   if (a >= 'a'&&a <= 'z') {
      a = a + b;
      if (a > 'z') {
         a = a % 'z';
         a = a + 'a' - 1;
         printf("%c", a);
      }
      else {
         printf("%c", a);
      }
   }
   else if (a >= 'A'&&a <= 'Z') {
      a = a + b;
      if (a > 'Z') {
         a = a % 'Z';
         a = a + 'A' - 1;
         printf("%c", a);
      }
      else {
         printf("%c", a);
      }
   }
   else {
      printf("%c", a);
   }
}