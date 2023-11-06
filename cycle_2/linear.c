#include <stdio.h>
void main(){
	int a[20],i,n,m;
	printf("Enter limit:\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("Enter element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	
	printf("Enter a number to search: ");
	scanf("%d",&m);
	
	for(i=0;i<n;i++){
		if(a[i]==m){
		printf("%d is present",m);
		break;}
	}
	
	if(i==n){
	printf("%d is not present",m);}
}
