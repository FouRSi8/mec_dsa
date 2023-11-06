#include<stdio.h>
void main(){
	int a[100][100],i,j,p,q,c=0;
	printf("Enter the order p:");
	scanf("%d",&p);
	printf("Enter the order q:");
	scanf("%d",&q);
	for (i=0;i<p;i++){
		for(j=0;j<q;j++){
			printf("Enter the element:");
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			if(a[i][j]!=0){
				c++;
				printf("\nIndex:(%d,%d)",i,j);
			}
		}
	}
	printf("\ncount=%d\n",c);
}
