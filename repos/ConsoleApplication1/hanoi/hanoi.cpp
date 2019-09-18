// hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>



typedef struct {
	int itme[3];
	int top;
} Tower;

Tower* towers[3];

void printTower(Tower* towers[]);
void move(Tower* a, Tower* b);
void hanoi(int n, Tower* a, Tower *b, Tower *c);

int main()
{
	for (int i = 0; i < 3; i++) {
		towers[i] = (Tower*)malloc(sizeof(Tower));
		for (int k = 0; k < 3; k++) {
			(towers[i]->itme[k]) = 0;
		}
		towers[i]->top = 3;
	}
	//printf("Initiate[1] Succeded\n");
	for (int i = 2; i>=0; i--) {
		(towers[0]->itme[i]) = i + 1;
	}
	towers[0]->top = 0;
	//printf("Initiate[2] Succeded\n");
	hanoi(3, towers[0], towers[1], towers[2]);
	for (int i = 0; i < 3; i++) {
		free(towers[i]);
	}
	return 0;
}

void move(Tower* a, Tower* b) {
	int _a = a->top;
	int _b = b->top;
	(b->itme[_b - 1]) = (a->itme[_a]);
	(a->itme[_a]) = 0;
	(b->top) -= 1;
	(a->top) += 1;
}


void printTower(Tower* towers[]) {
	printf("\ta\tb\tc\n");
	for (int i = 0; i < 3; i++) {
		printf("\t%d\t%d\t%d\n", towers[0]->itme[i], towers[1]->itme[i], towers[2]->itme[i]);
	}
}

void hanoi(int n, Tower* a, Tower *b, Tower *c) {
	static int count=0;
	
	if (n > 0) {
		hanoi(n - 1, a, c, b);
		move(a, b);
		count++;
		printf("step %d:\n", count);
		printTower(towers);
		hanoi(n - 1, c, b, a);
	}
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
