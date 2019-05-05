#include "Sort.h"
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	Sort sort; 
	
	int lis[]={9,6,3,2,5,8,7,4,1};
	int lis2[]={1};
	
	// 1. ����ð������ 
	cout<<"ð������ bubble_sort = "<<endl;
	sort.bubble_sort(lis, 9);
	for(int i=0;i<9;i++)
	{
		cout<<lis[i]<<" ";
	}
	cout<<endl;
	
	sort.bubble_sort(lis2, 1);
	for(int i=0;i<1;i++)
	{
		cout<<lis2[i]<<" ";
	}
	cout<<endl;
	
	// 2. ���Բ������� 
	cout<<"�������� insert_sort = "<<endl;
	int lis3[]={9,6,3,2,5,8,7,4,1};
	int lis4[]={1};
	
	sort.insert_sort(lis3, 9);
	for(int i=0;i<9;i++)
	{
		cout<<lis3[i]<<" ";
	}
	cout<<endl;
	
	sort.insert_sort(lis4, 1);
	for(int i=0;i<1;i++)
	{
		cout<<lis4[i]<<" ";
	}
	cout<<endl;
	
	// 3. ����ѡ������
	cout<<"ѡ������ select_sort = "<<endl;
	int lis5[]={9,5,1,7,3,8,4,6,2};
	int lis6[]={1,2};
	
	sort.select_sort(lis5,9);
	for(int i=0;i<9;i++)
	{
		cout<<lis5[i]<<" ";
	}
	cout<<endl;
	
	sort.select_sort(lis6,2);
	for(int i=0;i<2;i++)
	{
		cout<<lis6[i]<<" ";
	}
	cout<<endl;
	
	// 4. ���Թ鲢���� 
	cout<<"�鲢���� merge_sort = "<<endl;
	int lis7[]={9,8,7,4,5,6,1,2,3};
	int lis8[]={1};
	
	sort.merge_sort(lis7, 9);
	for(int i=0;i<9;i++)
	{
		cout<<lis7[i]<<" ";
	}
	cout<<endl;
	
	sort.insert_sort(lis4, 1);
	for(int i=0;i<1;i++)
	{
		cout<<lis8[i]<<" ";
	}
	cout<<endl;
	
	// 5. ���Կ������� 
	cout<<"�������� quick_sort = "<<endl;
	int lis9[]={9,8,7,4,5,6,1,2,3};
	int lis10[]={1}; 
	
	sort.quick_sort(lis9, 9);
	for(int i=0;i<9;i++)
	{
		cout<<lis9[i]<<" ";
	}
	cout<<endl;
	
	sort.quick_sort(lis10, 1);
	for(int i=0;i<1;i++)
	{
		cout<<lis10[i]<<" ";
	}
	cout<<endl;
	
	// 6. ����ϣ������ 
	cout<<"ϣ������ shell_sort = "<<endl;
	int lis11[]={9,8,7,4,5,6,1,2,3}; 
	int lis12[]={1}; 
	
	sort.shell_sort(lis11, 9);
	for(int i=0;i<9;i++)
	{
		cout<<lis11[i]<<" ";
	}
	cout<<endl;
	
	sort.shell_sort(lis12, 1);
	for(int i=0;i<1;i++)
	{
		cout<<lis12[i]<<" ";
	}
	cout<<endl;
}
