#include <stdio.h>

int main() {
   int n, x, i;
   int poly[100];
   int result = 0;

   printf("Enter the degree of polynomial: ");
   scanf("%d", &n);

   printf("Enter the coefficients of the polynomial: ");
   for (i = 0; i <= n; i++) {
      scanf("%d", &poly[i]);
   }

   printf("Enter the value of x: ");
   scanf("%d", &x);

   for (i = n; i >= 0; i--) {
      result = result * x + poly[i];
   }

   printf("The result of the polynomial for x = %d is %d\n", x, result);

   return 0;
}

