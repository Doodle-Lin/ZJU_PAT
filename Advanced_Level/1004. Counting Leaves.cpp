#include<iostream>
#include<vector>
using namespace std;

const int MAX = 100;
vector< vector<int> > node;	//二维，第一维存储结点的子节点；
int leaves[MAX] = {0};	//存储每层含有的叶子结点；

void dfs(int id, int level);

/*
思路：题意就是输出树的每层叶子节点数。
无需构建树，通过DFS或者BFS遍历就好。
一般情况DFS代码量少，优先。
*/
int main()
{
	freopen("in.txt", "r", stdin);
	int N, M, i, j;
	cin >> N >> M;
	node.resize(N+1);	//重新定义大小；
	int id, k, child_id;
	for(i = 0; i < M; i++)
	{
		cin >> id >> k;
		for(j = 0; j < k; j++)
			{
				cin >> child_id;
				node[id].push_back(child_id);
			}
	}
	int level = 0;
	dfs(1, level);
	
	int all_leaf = N - M;
	int cnt = leaves[0];
	cout << leaves[0];
	for(i = 1; cnt < all_leaf; i++)
	{
		cout << " " << leaves[i];
		cnt += leaves[i];
	}	
	cout <<endl;

	return 0;
}

void dfs(int id, int level)	//id是从1开始的
{
	if(node[id].size() == 0)
	{
		leaves[level]++;
		return;
	}
	vector<int>::iterator it = node[id].begin();
	for(it; it < node[id].end(); it++)
		dfs(*it, level+1);//传递深度不能用level++
}
