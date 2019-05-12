#include <iostream> 

using namespace std;

class Search
{
	public:
	int seq_search(int lis[], int size, int target);        // ˳������㷨  
	int binary_search(int lis[], int size, int target);     // ���ֲ����㷨 
};

/*
 * seq_search: ˳������㷨
 * param lis: ������������� 
 * param size: ���������Ĵ�С 
 * param target: Ҫ���ҵ�Ŀ��ֵ 
 * note: ������Ĳ��ҷ���������ÿ�춼��ʹ�ã��㷨�Ļ���˼����: ���α������������е�ÿһ��Ԫ�أ�����ǰԪ�ص�ֵ��Ŀ��ֵ��ȣ��������������±� 
*/
int Search::seq_search(int lis[], int size, int target)
{
	// 1. ������������������Ŀ��ֵ���±꣬���ҵ����������� 
	for(int i=0;i<size;i++)
	{
		if(lis[i]==target)
		return i;
	}
	
	// 2. �����Ҳ�������Ŀ��ֵ��Ԫ�أ��򷵻�-1��ʾ���Ҳ�����Ӧ��Ԫ�� 
	return -1;
}


/*
 * binary_search: ���ֲ����㷨 
 * param lis: ������������� 
 * param size: ���������Ĵ�С 
 * param target: Ҫ���ҵ�Ŀ��ֵ 
 * note 1: ���ֲ����ǲ����㷨������Ҫ�Ĳ����㷨����Ȼ˼��ܼ򵥣�����һ�ξ�д����ȫ��ȷ�Ĵ���ȴ�������ף������������ӣ����е��±�任��΢�Ķ������ܵ��º����εĴ�����������ǳ������ĳ̶� 
 * note 2: ���ֲ����㷨�Ļ���˼����: ���ȱȽ�������м�Ԫ�غ�Ŀ��ֵ�Ĵ�С������ȣ���ֱ�ӷ����м�Ԫ�ص��±ꣻ��Ŀ��ֵ�����м�Ԫ�أ�������벿��������ң��±귶ΧΪ0~mid-1������Ŀ��ֵС���м�Ԫ�أ������Ұ벿��������ң��±귶ΧΪmid+1~size-1�� 
 * note 3: ����ʹ��(begin+end)/2���ܵ���������������μ�: https://zhuanlan.zhihu.com/p/32719708
*/
int Search::binary_search(int lis[], int size, int target)
{
	int begin=0;       // �����ҵ�����Ƭ�ε���ʼԪ���±�  
	int end=size-1;    // �����ҵ�����Ƭ�ε���ֹԪ���±�  
	
	while(begin<=end)
	{
		int mid=begin+(end-begin)/2;    // �����ҵ�����Ƭ�ε��м�Ԫ���±꣬Ϊʲô����ʹ�ü���������(begin+end)/2�أ���Ϊ(begin+end)/2������ϴ�ʱ����������� 
		
		if(target>lis[mid])         // ��Ŀ��ֵ���������м�λ�ã���������ĺ�벿�ֲ��� 
		begin=mid+1;                // ע�⣬�ı䷶Χʱbegin=mid+1�������ܰ���mid����Ϊmid�Ѿ��ȽϹ��ˣ���begin=mid�Ǵ���� 
		else if(target<lis[mid])    // ��Ŀ��ֵС�������м�λ�ã����������ǰ�벿�ֲ��� 
		end=mid-1;  
		else
		return mid;
	}
	
	return -1;
}

