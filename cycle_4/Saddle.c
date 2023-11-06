#include <stdio.h>

void findSaddle(int row, int col, int mat[row][col]){
	
	for(int i=0; i<row; i++){
		int min = mat[i][0], j_index=0, flag=1;
		for(int j=0; j<col; j++){
			if(mat[i][j]<min){
				min = mat[i][j];
				j_index = j;
			}
		}
		for(int k=0; k<row; k++){
			if(min<mat[k][j_index]){
				flag=0;
				break;
			}
		}
		if(flag){
			printf("Saddle point: %d\n", mat[i][j_index]);
		}
	}
}


int main(){

	int m, n;
	printf("Enter row, column: ");
	scanf("%d %d", &m, &n);
	int mat[m][n];
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("Enter element matrix[%d][%d]: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	

	
	findSaddle(m, n, mat);
	
}
