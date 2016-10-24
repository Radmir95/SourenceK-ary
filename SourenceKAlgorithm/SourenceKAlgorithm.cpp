// SourenceKAlgorithm.cpp: главный файл проекта.

#include "stdafx.h"

using namespace System;
using namespace std;

#include <iostream>

int k;
int u;
int v;

int *tableI;
int *tableA;
int *tableG;

void extended_euclid(long a, long b, long *x, long *y, long *d)
/* вычисление a * *x + b * *y = gcd(a, b) = *d */
{
 long q, r, x1, x2, y1, y2;
 if (b == 0) {
 *d = a, *x = 1, *y = 0;
 return;
 }

 x2 = 1, x1 = 0, y2 = 0, y1 = 1;
 while (b > 0) {
 q = a / b, r = a - q * b;
 *x = x2 - q * x1, *y = y2 - q * y1;
 a = b, b = r;
 x2 = x1, x1 = *x, y2 = y1, y1 = *y;
 }

 *d = a, *x = x2, *y = y2;
}

long inverse(long a, long n)
/* вычисление инверсии модуля n */
{
 long d, x, y;
 extended_euclid(a, n, &x, &y, &d);
 tableG[a] = d;
 if (d == 1) return x;
 return 0;
}

void initializeTables()
{
	tableI = new int[k];	
	tableG = new int[k];
}

void fillTableI()
{
	for (int i = 0; i < k; i++)
	{
		tableI[i] = inverse(i,k);
	}
}

void printTable(int *table)
{

	for(int i = 0; i < k; i++)
	{
		cout << table[i] << " ";
	}
	cout << endl;
}

int TakingModInUpSide(int number, int mod)
{
	
	int t = number % mod;
	if (t < 0)
		t+=mod;
	cout << t;
	return t;

}

// главная фукнция
int main(void)
{
	printf("Enter k:");
	cin >> k;

	initializeTables();

	fillTableI();

	printTable(tableG);
	
	system("pause");

 return 0;
}