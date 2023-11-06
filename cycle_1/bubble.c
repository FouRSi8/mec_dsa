#include <stdio.h>

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    } 
    printf("\n");
}

void sort(int arr[], int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]<arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insert(int arr[], int n, int m){
    int j;
    for(int i=0; i<n; i++){
        if(arr[i]<m){
            for(j=n; j>i; j--){
                arr[j]=arr[j-1];
            }
            arr[j] = m;
            break;
        }
    }
}

int main(){ 
    int n, m;
    printf("Enter total number: ");
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0; i<n; i++){
        printf("Enter number: ");
        scanf("%d",&arr[i]);
    }
    
    sort(arr,n);
    printf("Sorted array: ");
    display(arr,n);
    
    printf("Enter number to insert: ");
    scanf("%d",&m);
    insert(arr,n,m);
    printf("Array after inserting %d: ",m);
    display(arr,n+1);
}
