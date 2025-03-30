#include <stdio.h>
#include <stdlib.h>

// X[N]
// ввод из терминала
// 1) нам нужно найти минимальный элемент 
// 2) все элементы до минимального упорядочить по возрастанию

// 1, 2, 3, 0, 2, 4, 1
// 1) 0
// 2) 1, 2, 3

int findMin(int *arr, const int N)
{
    int minElement = arr[0];
    for (int i = 0; i < N; ++i) {
        if (minElement > arr[i]) {
            minElement = arr[i];
        }
    }
    return minElement;
}

void fillArray(int *arr, const int N)
{
    int num;
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        arr[i] = num;
    }
}

int main()
{
    int n = 0; // int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int)); // просим память на куче для нашего массива

    fillArray(arr, n); // заполняем массив
    int minElement = findMin(arr, n); // поиск минимального элемента
    printf("Min element in array: %d", minElement);

    return 0;
}
