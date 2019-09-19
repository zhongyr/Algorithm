// binarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int binarySearch(int arr[], int traget, int len);
void qSort(int* a, int i, int j);
int partition(int*a, int p, int r);
void swap(int* a, int i, int j);

int main()
{
	int n=0;
	int *arr;
	scanf_s("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	int target;
	scanf_s("%d", &target);
	qSort(arr, 0, n-1);
	int ret =binarySearch(arr, target, n);
	ret == -1 ? printf("not found") : printf("%d", ret);
	free(arr);
}

int binarySearch(int arr[], int target, int len) {
	int left = 0;
	int right = len - 1;
	while (left < right) {
		int middle = (left + right) / 2;
		if (target == arr[middle])return middle;
		if (target > arr[middle]) left = middle + 1;
		else right = middle - 1;
	}
	return -1;
}

void qSort(int* a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qSort(a, p, q - 1);
		qSort(a, q + 1, r);
	}
}

int partition(int*a, int p, int r) {
	int i = p;
	int j = r + 1;
	int x = a[p];
	while (true) {
		while (a[++i] < x&&i < r);
		while (a[--j] > x);
		if (i >= j) break;
		swap(a, i, j);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

void swap(int* a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
