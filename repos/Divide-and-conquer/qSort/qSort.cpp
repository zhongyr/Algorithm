// qSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "qsort.h"
int partition(int* a, int p, int r);
void swap(int* a, int i, int j);

int main()
{
 
}

void qSort(int* a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qSort(a,p, q - 1);
		qSort(a,q + 1, r);
	}
}

int partition(int*a, int p, int r) {
	int i = p;
	int j = r+1;
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
