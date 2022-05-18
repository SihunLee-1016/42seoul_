#include <stdio.h>

void    swap(int *a, int *b)
{
    int tmp = *a;
    *a= *b;
    *b = tmp;
}

int partition(int data[],int left, int right)
{
    int first = left;
    int pivot = data[first]; //첫번째 요소를 기준 요소로 설정.(pivot:중심)
    int i = 0;

    left++;

    while (left <= right) //ㅓ같아질때까지 반복.
    {
        while (data[left] <= pivot && left < right) // pivot의 값보다 큰 요소를 찾을 때 까지 탐색을 하며 left를 증가. 해당 요소의 위치를 left에 저장.
            ++left;

        while (data[right] > pivot && left <= right) // pivot의 값보다 작은 값을 가진 요소를 찾아 right에 저장.
            --right;
        
        if (left < right) //left가 right보다 작다면 left,right의 index에 해당하는 값을 swap. 
            swap(&data[left], &data[right]);
        else
            break ;
    }

    swap (&data[first], &data[right]); // 기준 요소와 정렬된 집합의 맨 오른쪽 끝에 있는 요소를 교환한다. 값의 비교는 x 
    printf("pivot = %d\n data : ",pivot);
    while (i < 8)
    {
        printf("%d ",data[i]);
        i++;
    }
    printf("\n");
    return right; // 분할이 끝났다면 분할에 의해 새로 생긴 왼쪽 데이터 집합의 오른쪽 끝에 있는 요소를 반환.
}

void quicksort(int data[], int left, int right)
{
    if (left < right) 
    {
        int index = partition(data, left, right);

        quicksort(data, left, index -1); //왼쪽 데이터 집합을 정렬.
        quicksort(data, index+1, right); //오른쪽 데이터 집합을 정렬
    }
}
int main()
{
    int data[] = {1,4,2,3,3,2,1,4};
    int lenght = sizeof(data) / sizeof (data[0]);
    int i = 0;

    quicksort(data, 0, lenght - 1); //left =0, right = lenght -1. 탐색범위 차이.

    while(i < lenght)
        printf("%d ",data[i++]);
    return (0);
}