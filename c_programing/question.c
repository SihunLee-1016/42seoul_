#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void f(double x, double y, double* z) {
   *z = sqrt(x * x + y * y + 4);
}

int main() {
   void f(double, double, double*);
   double z;
   int i;
   f(0, 0, &z);
   printf("f(0,0)=%g\n", z);
   f(-3,4,&z);
   printf("f(-3,4)=%g\n", z);
   f(0.3,0.7,&z);
   printf("f(0.3,0.7)=%g\n", z);
   f(3.3,-4.5,&z);
   printf("f(3.3,-4.5)=%g\n", z);
}
