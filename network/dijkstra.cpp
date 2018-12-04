
#include "del.h"
#include "read.h"
#include <iostream>
#include <fstream>
#define MAX 999

using std::cin;
using std::cout;
using std::endl;

void dijkstra(int node, int **w) {
	int *dis = new int[node];
	int *parent = new int[node];
	int *temp = new int[node];
	bool *book = new bool[node];
	int n, min, u;
	cout << "������Ҫ���·�ɱ�Ľ��ţ�";
	cin >> n;

	for (int i = 0; i < node; ++i) {//��ʼ��dis����,book����;
		dis[i] = w[n - 1][i];
		if (dis[i] == MAX) {
			parent[i] = -1;
		}
		else {
			parent[i] = n - 1;
		}
		book[i] = false;
	}
	parent[n - 1] = -1;
	book[n - 1] = true;
	for (int i = 0; i < node; ++i) {
		min = MAX;
		for (int j = 0; j < node; ++j) {//�ҵ���Դ�������Ľ��
			if (book[j] == false && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		book[u] = true;
		for (int v = 0; v < node; ++v) {
			if (w[u][v] < MAX) {
				if (dis[v] > w[u][v] + dis[u]) {
					dis[v] = dis[u] + w[u][v];
					parent[v] = u;
				}
			}
		}
	}
	cout << endl;
	cout << n << "��·������·�ɱ��ǣ�" << endl;
	cout << "Ŀ������" << '\t'
		<< "��һ��" << '\t'
		<< "����"<< endl;
	for (int m = 0; m < node; ++m) {
		int nextstep = 0, d = 0;
		for (int a = 0; a < node; ++a) {
			temp[a] = parent[a];
		}
		if (temp[m] == n - 1) {
			nextstep = m;
		}
		else {
			while (true) {
				if (m != n - 1) {
					nextstep = temp[m];
					temp[m] = temp[temp[m]];
					d = d + 1;
					if (temp[m] == n - 1)
						break;
				}
				else
					break;
			}
		}
		if (m == n - 1) {
			nextstep = n - 1;
			d = -1 ;
		}
		cout << m + 1 << ".x.x.x       " << '\t'
			<< nextstep + 1 << '\t'
			<< dis[m] << "/"
			<< d + 1 << "��" << endl;
	}
	delete[] dis;
	delete[] book;
	delete[] parent;
	delete[] temp;
}