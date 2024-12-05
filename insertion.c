#include <stdio.h>

void print_array(int arr[], int used){
    printf("Array: ");
    for(int i=0; i<used; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
};

void insert_element(int arr[], int used, int total, int element, int index){
    if(total == used){
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    for(int i=used-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    used++;
    print_array(arr, used);
};

void delete_element(int  arr[],int used, int del_idx){
    if(used <= del_idx){
        printf("Invalid index. Cannot delete element.\n");
        return;
    }
    for(int i=del_idx; i<used-1; i++){
        arr[i]=arr[i+1];
        used--;
        print_array(arr, used);
    }
}



int main(){
    int total_size, used_size, element, index;
    printf("Enter the total size of the array: ");
    scanf("%d", &total_size);

    printf("Enter the used size of the array: ");
    scanf("%d", &used_size);
    
    int arr[total_size];
    
    for(int i = 0; i < used_size; i++){
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Array before insertion: ");
    print_array(arr, used_size);

    printf("Enter the element:");
    scanf("%d", &element);

    printf("Enter the index to insert the element: ");
    scanf("%d", &index);
    
    insert_element(arr, used_size, total_size, element, index);
    
    int del_idx =3;
    delete_element(arr,used_size,del_idx);

    return 0;
}