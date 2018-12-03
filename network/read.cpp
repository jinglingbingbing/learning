#include "pch.h"
#include "read.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

int** read(int node) {
	int **a = new int *[node]; //动态分配二维数组a[m][n]
	for (int i = 0; i < node; ++i) {
		a[i] = new int[node];
	}
	ifstream in;
	in.open("network.txt");
	if (in) {
		for (int i = 0; i < node; ++i) {
			for (int j = 0; j < node; ++j) {
				in >> a[i][j];
			}
		}
	}
	in.close();
	return a;
}