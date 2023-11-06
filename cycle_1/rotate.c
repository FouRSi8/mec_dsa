#include <stdio.h>
void main()
{
	int a[20],n,i,j,temp,r;
	char dir;
	
	//Getting limit of the array	
	printf("Enter number of elements:\n");
	scanf("%d",&n);	
	
	//Getting array input
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	{	
		scanf("%d",&a[i]);
		
	}
	
	printf("Enter number of rotation:\n");
		scanf("%d",&r);
		
	//Choosing left or right rotation
	printf("Enter rotation l/r:\n");
	scanf("%c ",&dir);
	
	if(dir == 'l')
	{
		
		for(i=1;i<=r;i++)
		{	
			for(j=0;j<n-1;j++)
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}

		}
	}
		
	else if(dir == 'r')
	{	
		for(i=1;i<=r;i++)
		{	
			for(j<n-1;j=0;j--)
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}

		}
	}
	
	else
	{
		printf("Invalid input");
	}	
	
	
	
	
		
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}	
