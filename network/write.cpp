
#include "write.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

void write(int node, int **a) {//m表示结点的个数
/*	int **a = new int *[m]; //动态分配二维数组a[m][n]
	for (int i = 0; i < m; ++i) {
		a[i] = new int[n];
	}*/
	ofstream out;
	out.open("network.txt");
	if (out) {
		for (int j = 0; j < node; ++j) {
			for (int k = 0; k < node; ++k) {
				out << a[j][k] << " ";
			}
			out << endl;
		}
	}
	out.close();
	/*for (int i = 0; i < row; i++) {//释放
		delete[] a[i];
	}
	delete[] a;*/
}