
#include "del.h"
#include "write.h"
#include <iostream>
#define MAX 999

using std::cin;
using std::cout;
using std::endl;

int delnode(int node, int **w) {//������������ɾ��һ��·������㲢�����ļ���ȥ,����ֵ��ɾ���Ľ���
	int r;
	cout << "������Ҫɾ���Ľ��ţ�" << endl;
	cin >> r;
	for (int i = 0; i < node; ++i) {
		for (int j = r - 1; j < node - 1; ++j) {
			w[i][j] = w[i][j + 1];
		}
	}
	for (int m = 0; m < node; ++m) {
		for (int n = r - 1; n < node - 1; ++n) {
			w[n][m] = w[n + 1][m];
		}
	}
	node = node - 1;
	write(node, w);
	return r;
}
void deledge(int node, int **w) { //������������ɾ��ĳ���߲�������뵽�ļ���ȥ
	int r1, r2;
	cout << "������Ҫɾ���ıߣ�r1, r2��(����0��0�˳�):" << endl;
	while (cin >> r1 >> r2) {
		if (r1 == 0 || r2 == 0)break;
		else {
			w[r1 - 1][r2 - 1] = MAX;
		}
	}
	write(node, w);
}