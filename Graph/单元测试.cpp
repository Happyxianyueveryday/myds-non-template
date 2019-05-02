#include <iostream>
#include "graph-dev.h"

using namespace std;

int main(void)
{
	// 1. ���Թ��캯�� 
	Graph graph1;   // Ĭ�Ϲ��캯��
	graph1.print();
	
	vector<vector<int> > lis={{0,1,-1,-1,1},{1,0,1,1,1},{-1,1,0,1,-1},{-1,1,1,0,1},{1,1,-1,1,0}};   // ����Ϊ-1��ʾ�����֮�����Ϊ����� 
	Graph graph2(lis);  // �����鹹��Ĺ��캯�� 
	graph2.print();
	
	// 2. ���Կ������ƺ���
	Graph graph3(graph2);    // �������캯�� 
	graph3.print();
	
	Graph graph4=Graph();
	graph4=graph4=graph1=graph3; // ������������� 
	graph1.print();
	graph3.print();
	graph4.print();
	
	// 3. ���Թ�����ȱ�����������ȱ���
	cout<<"graph2������������� dfs = "<<endl; 
	vector<int> res=graph2.dfs(1);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
	cout<<"graph2�Ĺ���������� bfs = "<<endl; 
	res=graph2.bfs(1);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
	// 4. ������̾���·����dijkstra�㷨��floyd�㷨 
	cout<<"graph2�н��1������������̾��� dijkstra = "<<endl; 
	res=graph2.dijkstra(0);
	for(int i=0;i<res.size();i++)
	{
		cout<<"���0�����"<<i<<"����̾��� dist = "<<res[i]<<" "<<endl;
	}
	cout<<endl;
	
	
}
