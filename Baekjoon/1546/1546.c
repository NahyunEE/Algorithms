#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    int num=0;
    int i =0;
    int max =0;
    int temp=0;
    float temp2 = 0.0;
    float sum =0.0;
    scanf("%d", &num);

    // malloc()함수는 파라미터로 주어진 바이트 수 만틈 Heap segment에 공간을 확보하고 그 시작주소를 반환한다.
    // malloc()함수를 통해 할당받은 공간은 사용하기 전에 초기화를 한다.

    int * arr = (int *)malloc(sizeof(int)*num);
    memset(arr,0,sizeof(int)*num);


    for(i=0; i< num; ++i){
        
        scanf("%d", &temp);
        
        if(max < temp){
            max = temp;
        }        
        arr[i] = temp;       
       

    }

    for(i=0; i< num; ++i){
        
        temp2 = (float)((float)arr[i]/(float)max) * 100;
        
        sum+=temp2;
        
    }

    float result = sum / num;
 
    printf("%f\n", result);


// free() 함수는 Heap segment에 동적으로 할당된 메모리 공간을 해제한다.
// 반드시 포인터 변수에 NULL값을 대입하여 더이상 참조할 수 없도록 해주어야한다.
   free(arr);
   arr = NULL;


    return 0;
}