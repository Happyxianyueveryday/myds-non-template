#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

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
	
	private:
	void real_merge(int lis[], int begin, int end);      // �鲢����ײ�ݹ�ʵ��
	void real_quick(int lis[], int begin, int end);      // ��������ײ�ݹ�ʵ�� 
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


/*
 * select_sort: ѡ������
 * note: ѡ�������˼���ð�������˼��ǡ���෴: ð�������i��ð��ѡ����i����������ڵ�����iλ�ϣ���ѡ�������i��ѡ����iС������ͨ���͵�iλ�����������Ӷ����ڵ�iλ�� 
*/
void Sort::select_sort(int lis[], int size)
{
	for(int i=0;i<size;i++)   // ѡ������ÿ��ѡ������lis[i]~lis[size-1]����С��һλ����lis[i]����λ��
	{
		int min=lis[i];       // ����Ԫ��lis[i]~lis[size-1]�е���Сֵ 
		int ind=i;            // ��Сֵ������λ�õ��±� 
		
		// ��������Ԫ��lis[i]~lis[size-1]�е���Сֵ 
		for(int k=i;k<size;k++)
		{
			if(lis[k]<min)
			{
				min=lis[k];
				ind=k;
			}
		}
		
		// ����Сֵ������Ԫ��lis[i]����λ��
		int temp=lis[i];
		lis[i]=lis[ind];
		lis[ind]=temp;
	}
	
	return;
}


/*
 * merge_sort: �鲢����
 * note: �鲢�����˼����һ�ֵݹ�˼��: ��һ����������������ȶԸ������ǰ�벿�ֺͺ�벿�ֱַ��������Ȼ���ٽ������ǰ�벿�ֺͺ�벿�ֺϲ��������������� ������������������ĺϲ���Ϊ�򵥣���μ�����������ϣ� 
*/
void Sort::merge_sort(int lis[], int size) 
{
	real_merge(lis, 0, size-1);
	return;
}

void Sort::real_merge(int lis[], int begin, int end)
{
	// 1. �ݹ���ֹ����: ��������û��Ԫ�ػ��߽���һ��Ԫ��ʱ�������鱾���������ģ������������ 
	if(begin>=end)
	return;
	
	int mid=(begin+end)/2;
	
	// 2. �ֱ�������ǰ�벿�ֺͺ�벿�ֽ��еݹ�����
	real_merge(lis, begin, mid);
	real_merge(lis, mid+1, end);
	
	// 3. ���Ѿ��ź����ǰ�벿������ͺ�벿��������кϲ� 
	vector<int> temp;
	
	int pos1=begin;
	int pos2=mid+1;
	
	while(pos1<=mid&&pos2<=end)
	{
		if(lis[pos1]<lis[pos2])	
		{
			temp.push_back(lis[pos1]);
			pos1+=1;
		}
		else
		{
			temp.push_back(lis[pos2]);
			pos2+=1;
		}
	}
	
	while(pos1<=mid)
	{
		temp.push_back(lis[pos1]);
		pos1+=1;
	}
	
	while(pos2<=end)
	{
		temp.push_back(lis[pos2]);
		pos2+=1;
	}
	
	for(int i=begin,k=0;i<=end;i++,k++)
	{
		lis[i]=temp[k]; 
	}
	
	return;
}


/*
 * quick_sort: ��������
 * note: ��������Ļ���˼����: ������������ѡȡһ����Ԫ��Ȼ����ݸ���Ԫ��������л��֣����ڸ���Ԫ�ķ�����Ԫ��С�ڸ���Ԫ�ķ�����Ԫǰ��Ȼ���Ը���ԪΪ�罫���黮��Ϊ�������֣��ֱ�����������ֽ��еݹ����򼴿� 
*/ 
void Sort::quick_sort(int lis[], int size)
{
	real_quick(lis, 0, size-1);
	return;
}

void Sort::real_quick(int lis[], int begin, int end)
{
	// 1. �ݹ���ֹ����: ������Ƭ���н�����һ��Ԫ�ػ���û��Ԫ��ʱ�������������ֱ�ӷ��ؼ���
	if(begin>=end)
	return;
	
	// 2. ���л��ֹ��̣�������������С����Ԫ��Ԫ�ط�����Ԫ֮ǰ�������������д��ڵ�����Ԫ��Ԫ�ط�����Ԫ֮�� 
	// 2.1 ѡ������Ƭ�ε���Ԫ����Ϊ��Ԫ
	int pivot=lis[begin];  
	
	int lastpos=begin;     // ���һ��С����Ԫ��Ԫ�ص�λ��
	
	// 2.2 ���±�begin+1��ʼ������ÿ��������������һ��С����Ԫ��ֵlis[i]�����Ƚ����һ��С����Ԫ��Ԫ�ص�λ��lastpos��1��Ȼ�󽻻�lis[i]��lis[lastpos] 
	for(int i=begin+1;i<=end;i++) 
	{
		if(lis[i]<pivot)   
		{
			lastpos+=1;
			swap(&lis[lastpos], &lis[i]);
		}
	}
	
	// 2.3 ��󽻻���Ԫlis[begin]�����һ��С����Ԫ��λ��lis[lastpos]���Ӷ���С����Ԫ�ķ�����Ԫǰ�����ڵ�����Ԫ�ķ�����Ԫ�� 
	swap(&lis[begin], &lis[lastpos]);
	
	// 3. ����ԪΪ�罫����Ƭ�λ���Ϊǰ�����Σ���ǰ�����ηֱ���еݹ�����
	real_quick(lis, begin, lastpos-1);
	real_quick(lis, lastpos+1, end);
	
	return;
}
