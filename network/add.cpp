#include "pch.h"
#include "add.h"
#include "write.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//添加一个新的边到网络拓扑中并将其读入文件中
void addedge(int node, int **w) {
	int r1, r2, weight; //存储新加入的边及其权值

	cout << "请输入要加入的边（r1,r2,weight）:(输入0，0，0退出)" << endl;
	while (cin >> r1 >> r2 >> weight) {
		if (r1 == 0 && r2 == 0)break;
		else 
			w[r1 - 1][r2 - 1] = weight;
	}
	write(node, w);
}
//将一个新的结点加入到网络拓扑中并存入文件中去
void addnode(int node, int **w) {
	int **b = new int *[node + 1];
	for (int n = 0; n < node + 1; ++n) {
		b[n] = new int[node + 1];
	}

	cout << "新加入的结点序号：" << node + 1 << endl;
	for (int i = 0; i < node; ++i) {
		for (int j = 0; j < node; ++j) {
			b[i][j] = w[i][j];
		}
	}
	cout << "请输入新加入的结点产生新边的权值：" << endl;
	for (int k = 0; k < node + 1; ++k) {
		cout << node + 1 << " " << k + 1 << ": ";
		cin >> b[node][k];
	}
	for (int m = 0; m < node + 1; ++m) {
		b[m][node] = b[node][m];
	}
	write(node + 1, b);

	for (int l = 0; l < node + 1; ++l) {//释放分配给b的空间
		delete[] b[l];
	}
	delete[] b;
}