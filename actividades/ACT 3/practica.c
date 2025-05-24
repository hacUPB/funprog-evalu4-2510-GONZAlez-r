#include "exercises.h"

// 1. Calcula la suma de los elementos del arreglo
int calcSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 2. Encuentra el valor máximo en el arreglo
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 3. Calcula el promedio de los elementos del arreglo
float calcAverage(int arr[], int size) {
    int sum = calcSum(arr, size);
    return (float)sum / size;
}

// 4. Cuenta la cantidad de números pares en el arreglo
int countEvens(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// 5. Suma el primer y el último elemento del arreglo
int sumFirstLast(int arr[], int size) {
    if (size == 0) return 0; 
    return arr[0] + arr[size - 1];
}

// 6. Encuentra el valor mínimo en el arreglo
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// 7. Resta elemento a elemento de dos arreglos y suma todas las diferencias
int subtractArraysSum(int arr1[], int arr2[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += (arr1[i] - arr2[i]);
    }
    return total;
}

// 8. Fusiona dos arreglos y retorna la suma total
int mergeArraysSum(int arr1[], int size1, int arr2[], int size2) {
    int total = 0;
    for (int i = 0; i < size1; i++) {
        total += arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        total += arr2[i];
    }
    return total;
}

// 9. Calcula el producto de todos los elementos del arreglo
int productArray(int arr[], int size) {
    if (size == 0) return 0;  
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }
    return product;
}

// 10. Calcula la suma y el promedio usando punteros
void calcSumAverage(int arr[], int size, int *sum, float *average) {
    *sum = calcSum(arr, size);
    *average = (float)(*sum) / size;
}