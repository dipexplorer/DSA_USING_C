#include<stdio.h>

int search(int arr[],int size, int el){
    for(int i=0;i<size;i++){
        if(arr[i]==el){
            return i;
        }
    }
            return -1; // Element not found in the array

};

void binary_search(int arr[],int el,int n){
        int low,mid,high;
        low=0;
        high=n-1;
    while(low <= high){
        int mid=(low + high) / 2;
        if(arr[mid] ==el){
            printf("elements is found in %d",mid);
        }
        if(arr[mid] < el){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
};

int main(){
    int arr[]={1,2,3,5,7,9,77};
    int n=sizeof(arr)/sizeof(arr[0]);
    int el=2;
    int status=search(arr,n,el);
    if(status==-1){
        printf("Element not found in the array.\n");
    }else{
        printf("Element found at index %d.\n",status);
    }

    binary_search(arr, el, n);
    return 0;
}