#include <stdio.h>
int binary(int a[],int n){
	int key;
	printf("Enter element to search: ");
	scanf("%d",&key);

	int m;
	int l = 0;
	int r = n;
	
	while(l<r){
		m = (l+r)/2;
		if(a[m]==key){
			return m;
		}
		else if(a[m]<key){
		l = m+1;
		continue;
		}
		
		else{
		r = m-1;
		continue;
		}
		
	return -1;
}
}

void main(){
	int n,i,key,m;
	
	printf("Enter limit: ");
	scanf("%d",&n);
	int a[n];
	
	printf("*Enter elements in ascending order*\n");
	
	for(i=0;i<n;i++){
		printf("Enter element %d\n",i+1);
		scanf("%d",&a[i]);
	}
	
	int x = binary(a,n);
	
	if(x==-1){
	printf("Element is not present\n");
	}
	
	else{
	
	printf("The element %d is present at %d\n",a[x],x);
	}
}
