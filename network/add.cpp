#include "pch.h"
#include "add.h"
#include "write.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//���һ���µıߵ����������в���������ļ���
void addedge(int node, int **w) {
	int r1, r2, weight; //�洢�¼���ı߼���Ȩֵ

	cout << "������Ҫ����ıߣ�r1,r2,weight��:(����0��0��0�˳�)" << endl;
	while (cin >> r1 >> r2 >> weight) {
		if (r1 == 0 && r2 == 0)break;
		else 
			w[r1 - 1][r2 - 1] = weight;
	}
	write(node, w);
}
//��һ���µĽ����뵽���������в������ļ���ȥ
void addnode(int node, int **w) {
	int **b = new int *[node + 1];
	for (int n = 0; n < node + 1; ++n) {
		b[n] = new int[node + 1];
	}

	cout << "�¼���Ľ����ţ�" << node + 1 << endl;
	for (int i = 0; i < node; ++i) {
		for (int j = 0; j < node; ++j) {
			b[i][j] = w[i][j];
		}
	}
	cout << "�������¼���Ľ������±ߵ�Ȩֵ��" << endl;
	for (int k = 0; k < node + 1; ++k) {
		cout << node + 1 << " " << k + 1 << ": ";
		cin >> b[node][k];
	}
	for (int m = 0; m < node + 1; ++m) {
		b[m][node] = b[node][m];
	}
	write(node + 1, b);

	for (int l = 0; l < node + 1; ++l) {//�ͷŷ����b�Ŀռ�
		delete[] b[l];
	}
	delete[] b;
}