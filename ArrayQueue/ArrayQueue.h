#include <iostream> 
#include <vector>

using namespace std;

class ArrayQueue
{
	public: 
	// 1. ���캯�� 
	ArrayQueue(int max_size);
	ArrayQueue(int max_size, const vector<int> &lis);
	
	// 2. ��������
	ArrayQueue(const ArrayQueue &other);
	ArrayQueue & operator = (const ArrayQueue &other);
	
	// 3. ���ܺ��� 
	bool push(int val);         // ��Ԫ����� 
	bool pop(int &val);         // ����Ԫ�س��� 
	bool frontval(int &val) const; // ��ȡ����Ԫ�� 
	void clear();               // ��ն��� 
	int length() const;         // ��ȡ�����е�Ԫ�ظ��� 
	void print() const;         // ��������е����� 
	
	// 4. ��������
	~ArrayQueue();              // ����������� 
	
	private:
	int *data;                  // ��������ʵ�ʴ洢������
	int front;                  // ����Ԫ���±� 
	int back;                   // ��βԪ���±��1��ֵ������βԪ�ص�β��Ԫ�ص��±�  
	int MAX_SIZE;               // ���������С������������������Ԫ�ظ��� 
};

/*
 * ArrayQueue: Ĭ�Ϲ��캯�� 
*/
ArrayQueue::ArrayQueue(int max_size)
{
	data=new int [max_size];
	front=back=0;
	MAX_SIZE=max_size;
}

/*
 * ArrayQueue: �����鹹����� 
*/
ArrayQueue::ArrayQueue(int max_size, const vector<int> &lis)
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
 * ArrayQueue: �������캯�� 
*/
ArrayQueue::ArrayQueue(const ArrayQueue &other)
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
 * ArrayQueue: ������ֵ����� 
*/
ArrayQueue & ArrayQueue::operator = (const ArrayQueue &other)
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
 * note: �������ʾ�Ķ����У�����Ҫ�ж϶����Ƿ������������������������ʧ�ܣ�����false����ջδ����ֻ��Ҫ��Ҫ��ӵ�ֵд��data[back]��Ȼ��back��1���ɣ���󷵻�true 
*/
bool ArrayQueue::push(int val)
{
	if(back==MAX_SIZE)
	return false;
	else
	{
		data[back]=val;
		back+=1;
		return true;
	}
}

/*
 * pop: ������Ԫ�س��� 
 * note: ��ջ���㷨Ҳ��Ϊ�򵥣������ж϶����Ƿ�Ϊ�գ�������Ϊ�գ������ʧ�ܣ�����false��������δ�գ������ȼ�¼����Ԫ�ص�ֵdata[front]��Ȼ��front��1����������ɣ�����true 
*/
bool ArrayQueue::pop(int &val)
{
	if(front==back)	
	return false;
	else
	{
		val=data[front];
		front+=1;
		return true;
	}
}

/*
 * frontval: ���ض���Ԫ�� 
 * note: ���ض���Ԫ�ص��㷨�ͳ��ӹ��̴�����ͬ�����������ظ����� 
*/
bool ArrayQueue::frontval(int &val) const
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
void ArrayQueue::clear()
{
	front=back=0;
}
	
/*
 * length: ����ջ�е�Ԫ������ 
*/
int ArrayQueue::length() const
{
	return (back-front);
}

/*
 * print: ���ջ
*/ 
void ArrayQueue::print() const
{
	string res;
	
	for(int i=front;i<back;i++)
	{
		if(i==0)
		res=to_string(data[i])+res;
		else
		res=to_string(data[i])+"<-"+res;
	}
	
	cout<<res<<endl;
}

/*
 * ~ArrayQueue: ��������  
*/ 
ArrayQueue::~ArrayQueue()
{
	delete [] data;
}


