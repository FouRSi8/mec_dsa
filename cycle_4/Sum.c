#include <stdio.h>

void main(){	
	int n, m;
	printf("Enter the number of rows in the matrix: ");
	scanf("%d", &n);
	printf("Enter the number of columns in the matrix: ");
	scanf("%d", &m);

	int A[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("Enter element: ");
			scanf("%d", &A[i][j]);	
			}	
		}
	for(int i = 0; i < n; i++){
		int row_sum = 0;
		for(int j = 0; j < m; j++){
			row_sum += A[i][j];
			}
		printf("Sum of elements of row %d is %d\n", i, row_sum);
		}
	for(int i = 0; i < m; i++){
		int col_sum = 0;
		for(int j = 0; j < n; j++){
			col_sum += A[j][i];
			}
		printf("Sum of elements of column %d is %d\n", i, col_sum);
		}
	}
