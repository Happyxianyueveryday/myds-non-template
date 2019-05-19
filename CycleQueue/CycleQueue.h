#include <iostream> 
#include <vector>

using namespace std;

class CycleQueue
{
	public: 
	// 1. ���캯�� 
	CycleQueue(int max_size);
	CycleQueue(int max_size, const vector<int> &lis);
	
	// 2. ��������
	CycleQueue(const CycleQueue &other);
	CycleQueue & operator = (const CycleQueue &other);
	
	// 3. ���ܺ��� 
	bool push(int val);         // ��Ԫ����� 
	bool pop(int &val);         // ����Ԫ�س��� 
	bool frontval(int &val) const; // ��ȡ����Ԫ�� 
	void clear();               // ��ն��� 
	int length() const;         // ��ȡ�����е�Ԫ�ظ��� 
	
	// 4. ��������
	~CycleQueue();              // �����������  
	
	private: 
	int *data;                  // ��������ʵ�ʴ洢������
	int front;                  // ѭ���������α�frontָ�����Ԫ�ص��±� 
	int back;                   // ѭ���������α�backָ���βԪ�ص��±꣬��ʵ������ʹ�õĶӿպͶ������ж����������˶�������һ��Ԫ�ص�λ���ǲ����õ� 
	int MAX_SIZE;               // ���������С������������������Ԫ�ظ��� 
};

/*
 * CycleQueue: Ĭ�Ϲ��캯�� 
*/
CycleQueue::CycleQueue(int max_size)
{
	data=new int [max_size];
	front=back=0;
	MAX_SIZE=max_size+1;
}

/*
 * CycleQueue: �����鹹����� 
*/
CycleQueue::CycleQueue(int max_size, const vector<int> &lis)
{
	if(lis.size()>max_size)   // �����벻�Ϸ�����Ĭ�Ϲ���һ���յĶ��У����е�����СΪ100 
	{
		data=new int [100];
		front=back=0;
		MAX_SIZE=100;
		return; 
	}
	
	data=new int [max_size];
	front=0;
	back=lis.size();
	MAX_SIZE=max_size;
	
	for(int i=0;i<lis.size();i++)
	{
		data[i]=lis[i];
	}
	
	return;
}

/*
 * CycleQueue: �������캯�� 
*/
CycleQueue::CycleQueue(const CycleQueue &other)
{
	data=new int[other.MAX_SIZE];
	MAX_SIZE=other.MAX_SIZE;
	front=other.front;
	back=other.back;
	
	for(int i=front;i<back;i++)
	{
		data[i]=other.data[i];
	}
}

/*
 * CycleQueue: ������ֵ����� 
*/
CycleQueue & CycleQueue::operator = (const CycleQueue &other)
{
	if(&other==this) 
	return (*this);
	
	delete [] data;
	
	data=new int[other.MAX_SIZE];
	MAX_SIZE=other.MAX_SIZE;
	front=other.front;
	back=other.back;
	
	for(int i=front;i<back;i++)
	{
		data[i]=other.data[i];
	}
} 

/*
 * push: ��Ԫ������� 
 * note: ѭ�������У��ڽ�Ԫ�����֮ǰ��������Ҫ�ж϶����Ƿ��Ѿ������ж϶����Ƿ���������Ҫ����Ϊ(back+1)%MAX_SIZE==front����������е�β��Ԫ�ص�λ�ý����Ŷ���Ԫ�ص�λ�ã�������Ѿ�������ʱ����false�������δ������ʱ��Ҫ��ӵ�Ԫ��д��data[back]��Ȼ���α�back��1���MAX_SIZEȡģ����󷵻�true 
*/
bool CycleQueue::push(int val)
{
	if((back+1)%MAX_SIZE==front)
	return false;
	else
	{
		data[back]=val;
		back=(back+1)%MAX_SIZE;
		return true;
	}
}

/*
 * pop: ������Ԫ�س��� 
 * note: ѭ�������У��ڽ�Ԫ�س���֮ǰ��������Ҫ�ж϶����Ƿ�Ϊ�գ��ж϶����Ƿ�Ϊ�յ���Ҫ������front==end���������еĶ�β��β��Ԫ�ص��ڶ���Ԫ���±꣬��ʱ˵��������û��Ԫ�ط���false�������ȼ�¼����Ԫ�أ�Ȼ�󽫶����α�����1��ȡģ����front=(front+1)%MAX_SIZE����󷵻�true 
*/
bool CycleQueue::pop(int &val)
{
	if(front==back)
	return false;
	else
	{
		val=data[front];
		front=(front+1)%MAX_SIZE;
		return true;
	}
}

/*
 * frontval: ���ض���Ԫ�� 
 * note: ���ض���Ԫ�ص��㷨�ͳ��ӹ��̴�����ͬ�����������ظ����� 
*/
bool CycleQueue::frontval(int &val) const
{
	if(front==back)
	return false;
	else
	{
		val=data[front];
		return true;
	}
}

/*
 * clear: ���ջ��Ԫ�� 
*/
void CycleQueue::clear()
{
	front=back=0;
}
	
/*
 * length: ����ջ�е�Ԫ������ 
*/
int CycleQueue::length() const
{
	return (back-front+MAX_SIZE)%MAX_SIZE;    // �ù�ʽ��Ҫʹ�ü����򵥵������������Ƶ������򵥵ķ�����ֱ�Ӽ������ù�ʽ 
}

/*
 * ~CycleQueue: ��������  
*/ 
CycleQueue::~CycleQueue()
{
	delete [] data;
}


