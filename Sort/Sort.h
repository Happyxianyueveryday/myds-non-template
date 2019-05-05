#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sort
{
	public:
	void bubble_sort(int lis[], int size);      // ð������ 
	void insert_sort(int lis[], int size);      // �������� 
	void select_sort(int lis[], int size);      // ѡ������ 
	void merge_sort(int lis[], int size);		// �鲢���� 
	void quick_sort(int lis[], int size);       // �������� 
	void shell_sort(int lis[], int size);       // ϣ������ 
	void heap_sort(int lis[], int size);        // ������ 
};


/*
 * bubble_sort: ð�������㷨ʵ��
 * note: ð�������˼·��Ϊ��: ð������ÿ�ֽ���ֻ���������е�һλ����ͨ������Ԫ�ص���������������i���ֵ�ƶ���������i��λ���ϣ�����size�ֺ�������� 
*/
void Sort::bubble_sort(int lis[], int size)
{
	for(int i=size-1;i>=0;i--)	  // ð������ÿ�����������е�һλ�����ν���m���ֵ�ƶ���������m��λ����	
	{
		for(int k=0;k<i;k++)      // ͨ����ǰ(size-i)��Ԫ�ص�����������������ǰ(size-i)��Ԫ�ص����ֵ�ƶ�����iλ 
		{
			if(lis[k]>lis[k+1])   // ��lis[k]>lis[k+1]���򽻻�lis[k]��lis[k+1] 
			{
				int temp=lis[k];
				lis[k]=lis[k+1];
				lis[k+1]=temp;
			}
		}
	}
	
	return;
}

/*
 * insert_sort: �������� 
 * note: ���������˼·Ҳ��Ϊ��: ���������i��ѭ������i��Ԫ�أ��������κ͵�1������2����...����i-1��Ԫ�رȽϣ����������ǰ(i-1)��Ԫ���к��ʵ�λ���ϼ��� 
*/
void Sort::insert_sort(int lis[], int size)
{
	for(int i=0;i<size;i++)
	{
		// ��lis[i]���뵽ǰi-1��Ԫ���е���ȷλ���� 
		int tar=lis[i];
		
		int ins=-1;     // ����� 
		
		for(int k=0;k<i;k++)  // ��ǰ�������lis[0]~lis[i-1]�����ҵ����е�һ������lis[i]��Ԫ�ص�λ�� 
		{
			if(lis[k]>tar)
			{
				ins=k;
				break;
			}
		}
		
		if(ins==-1)          // ������������ins==-1����lis[0]~lis[i-1]�в����ڴ���lis[i]��Ԫ�أ���ʱlis[i]��λ����ȷ��������в��� 
		continue;
		else                 // ��Ҫ���в���������lis[i]�Ͳ��뵽λ���±�ins�� 
		{
			for(int k=i;k>ins;k--)
			{
				lis[k]=lis[k-1];
			}
			lis[ins]=tar;
		}
	}
	
	return;
} 

