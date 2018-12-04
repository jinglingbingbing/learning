// network.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "del.h"
#include "add.h"
#include "read.h"
#include "dijkstra.h"
#include <iostream>
#include <fstream>
#define MAX 999

using std::cin;
using std::cout;
using std::endl;


int main()
{
	int node, function;
	node = 9;
	int **a = read(node);
        cout << "0.输出指定路由器的路由表" << endl;
	cout << "1.增加指定的边" << endl;
	cout << "2.增加一个新的路由器" << endl;
	cout << "3.删除指定的边" << endl;
	cout << "4.删除指定的路由器" << endl;
	cout << "5.退出" << endl;
	cout << "*************************" << endl;


	while (true) {
		cout << "请输入要执行的功能：";
		cin >> function;
		if (function == 1) {
			addedge(node, a);
			dijkstra(node, a);
		}
		else if (function == 2) {
			addnode(node, a);
			node = node + 1;
			a = read(node);
			dijkstra(node, a);
		}
		else if (function == 3) {
			deledge(node, a);
			dijkstra(node, a);
		}
		else if (function == 4) {
			int t;
			t = delnode(node, a);
			node = node - 1;
			a = read(node);
			cout << "输出的路由表中自第" << t
				<< "号路由器开始，第i号路由器都是原来第i+1号路由器" << endl;
			dijkstra(node, a);
		}
		else if (function == 0) {
			dijkstra(node, a);
		}
		else if (function == 5)
			break;
	}
	
	for (int i = 0; i < node; i++) {//释放分配给a的空间
	delete[] a[i];
	}
	delete[] a;
}

