#include <stdio.h>
#include <stdlib.h>

void get_data_from_adc(int *p, int N){
        for(int i=0; i<N; i++)
                p[i] = 1; //실제 ADC로부터 값을 샘플링해서 채울 예정.
                //혹은
                // *(p+i) = 1;
}


int main() {

        int arr[10] = {1,2,3,4,5,6,7,8,9,10};

        // arr[1]; // 첫번째 방 아님.
        for(int i=0; i<10; i++){
                printf("arr[%d]: %d at 0x%p\n",i ,arr[i], &arr[i]);
        }
        //%p : 주소

        // 배열의 이름은, 배열의 첫번째 방의 주소임
        // &arr[0] == arr
        // 즉 arr[i] === *(arr+i) equivalent
        for(int i=0; i<10; i++){
                printf("arr[%d]: %d at 0x%p\n", i, *(arr+i), &arr[i]);
        }

        // 2차원 배열
        int mat[5][5] = {
                {1,2,3,4,5},
                {6,7,8,9,10},
                {1,2,3,4,5},
                {6,7,8,9,10},
                {1,2,3,4,5}
        }; // 메모리 고정 5 by 5 * 4의 크기만큼

        //outer loop
        for(int i=0; i<5; i++){
                //inner loop
                for(int j=0; j<5; j++){
                        printf("%d\t", mat[i][j]);
                }
                printf("\n");
        }

        // 필요할 떄 on-demand하게 메모리로부터 공간할당 받기
        // heap memory 할당, by malloc();
        // 만약 ADC로부터 샘플링을 했다. 한 채널 한프레임 데이타

        int *p0 = (int *)malloc(sizeof(int)*5); // int 크기의 방 5개를 할당받고 그 공간의 첫번쨰 방의 주소를 리턴
        get_data_from_adc(p0, 5); // 이 버퍼를 이용해서 ADC로부터 샘플링 한 값을 채우기

        int *p1 = (int *)malloc(sizeof(int)*5);
        get_data_from_adc(p1, 5); 

        int *p2 = (int *)malloc(sizeof(int)*5);
        get_data_from_adc(p2, 5); 

        int *p3 = (int *)malloc(sizeof(int)*5);
        get_data_from_adc(p3, 5); 

        int *p4 = (int *)malloc(sizeof(int)*5);
        get_data_from_adc(p4, 5); 

        int *m[5] = {p0, p1, p2, p3, p4}; //포인터 기반 2차원 배열
        //주소 크기는 고정이기에 처리 속도 빠름

        



}