#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    int rev_array[num];
    for (int i=num;i>=0;i--){
        rev_array[num-i]=arr[i];
    }
 
    for(i = 0; i < num-1; i++){
        printf("%d ", *(rev_array + i+1));
    }
        printf("%d", arr[0]);
    
    return 0;
}
