// Perm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

void _swap(int* list, int k, int m);
void perm(int* list, int k, int m);

int main()
{
	int n;
	int *list;
	scanf_s("%d", &n);
	list = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &list[i]);
	}
	perm(list, 0, n - 1);
}

void perm(int* list, int k, int m) {
	if (k == m) {
		for (int i = 0; i <= m; i++)
			printf("%d", list[i]);
		printf("\n");
	}
	else {
		for (int i = k; i <= m; i++)
		{
			_swap(list, k, i);
			perm(list, k + 1, m);
			_swap(list, k, i);
		}
	}
}

void _swap(int* list, int k, int m) {
	int temp = list[k];
	list[k] = list[m];
	list[m] = temp;
	return;
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
