#include<stdio.h>
void selectionsort(int a[],int n)
{
int i,j,temp,min_index;
for(i=0;i<n-1;i++)  // finding smallest element and placing in position
    { min_index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
            {
            min_index=j;
            }
        }
        if(min_index!=i) { temp=a[i];a[i]=a[min_index];a[min_index]=temp;}
 }
}

int main(){
int size,i;

printf("Enter size of the array: ");
scanf("%d",&size);

int a[size];

printf("Enter %d elements: ",size);
for(i=0;i<size;i++)
scanf("%d",&a[i]);

selectionsort(a,size);

printf("Sorted elements: ");
for(i=0;i<size;i++)
printf(" %d",a[i]);

return 0;
}
