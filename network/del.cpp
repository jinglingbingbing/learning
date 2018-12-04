
#include "del.h"
#include "write.h"
#include <iostream>
#define MAX 999

using std::cin;
using std::cout;
using std::endl;

int delnode(int node, int **w) {//从网络拓扑中删除一个路由器结点并存入文件中去,返回值是删除的结点号
	int r;
	cout << "请输入要删除的结点号：" << endl;
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
void deledge(int node, int **w) { //从网络拓扑中删除某条边并将其存入到文件中去
	int r1, r2;
	cout << "请输入要删除的边（r1, r2）(输入0，0退出):" << endl;
	while (cin >> r1 >> r2) {
		if (r1 == 0 || r2 == 0)break;
		else {
			w[r1 - 1][r2 - 1] = MAX;
		}
	}
	write(node, w);
}