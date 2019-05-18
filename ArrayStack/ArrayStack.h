#include <iostream> 
#include <vector>

using namespace std;

class ArrayStack
{
	public: 
	// 1. ���캯�� 
	ArrayStack(int max_size);
	ArrayStack(int max_size, const vector<int> &lis);
	
	// 2. ��������
	ArrayStack(const ArrayStack &other);
	ArrayStack & operator = (const ArrayStack &other);
	
	// 3. ���ܺ��� 
	bool push(int val);         // ��Ԫ����ջ 
	bool pop(int &val);         // ջ��Ԫ�س�ջ 
	bool top(int &val) const;   // ��ȡջ����Ԫ��
	void clear();               // ���ջ 
	int length() const;         // ��ȡջ�е�Ԫ�ظ��� 
	void print() const;         // ���ջ�е����� 
	
	// 4. ��������
	~ArrayStack();              // ����������� 
	
	private:
	int *data;                  // ջ����ʵ�ʴ洢������
	int pos;                    // ջ��Ԫ���������е��±� 
	int MAX_SIZE;               // ���������С����ջ����������Ԫ�ظ��� 
};

/*
 * ArrayStack: Ĭ�Ϲ��캯�� 
*/
ArrayStack::ArrayStack(int max_size)
{
	data=new int [max_size];
	pos=-1;
	MAX_SIZE=max_size;
}

/*
 * ArrayStack: �����鹹��ջ 
*/
ArrayStack::ArrayStack(int max_size, const vector<int> &lis)
{
	if(lis.size()>max_size)   // �����벻�Ϸ�����Ĭ�Ϲ���һ���յ�ջ��ջ������СΪ100 
	{
		data=new int [100];
		pos=-1;
		MAX_SIZE=100;
		return; 
	}
	
	data=new int [max_size];
	pos=lis.size()-1;
	MAX_SIZE=max_size;
	
	for(int i=0;i<lis.size();i++)
	{
		data[i]=lis[i];
	}
	
	return;
}

/*
 * ArrayStack: �������캯�� 
*/
ArrayStack::ArrayStack(const ArrayStack &other)
{
	data=new int[other.MAX_SIZE];
	MAX_SIZE=other.MAX_SIZE;
	pos=other.pos;
	
	for(int i=0;i<=pos;i++)
	{
		data[i]=other.data[i];
	}
}

/*
 * ArrayStack: ������ֵ����� 
*/
ArrayStack & ArrayStack::operator = (const ArrayStack &other)
{
	if(&other==this) 
	return (*this);
	
	delete [] data;
	
	data=new int[other.MAX_SIZE];
	MAX_SIZE=other.MAX_SIZE;
	pos=other.pos;
	
	for(int i=0;i<=pos;i++)
	{
		data[i]=other.data[i];
	}
} 

/*
 * push: ��Ԫ����ջ 
 * note: �������ʾ��ջ�У�����Ҫ�ж�ջ�Ƿ���������ջ����������ջʧ�ܣ�����false����ջδ����ֻ��Ҫ���Ƚ�ջ��Ԫ�ص��±��1��Ȼ����д���Ԫ�ؼ��ɣ���󷵻�true 
*/
bool ArrayStack::push(int val)
{
	if(pos==MAX_SIZE-1)
	return false;
	else
	{
		pos+=1;
		data[pos]=val;
		return true;
	}
}

/*
 * pop: ��ջ��Ԫ�س�ջ
 * note: ��ջ���㷨Ҳ��Ϊ�򵥣������ж�ջ���Ƿ����Ԫ�أ���ջΪ�գ����ջʧ�ܣ�����false����ջδ�գ������ȼ�¼��ǰջ��Ԫ�ص�ֵ��Ȼ��ֱ�ӽ�ջ��Ԫ�ص��±��1������ջ��ɣ�����true 
*/
bool ArrayStack::pop(int &val)
{
	if(pos==-1)
	return false;
	else
	{
		val=data[pos];
		pos-=1;
		return true;
	}
}

/*
 * top: ����ջ��Ԫ�� 
 * note: ����ջ��Ԫ�ص��㷨�ͳ�ջ���̴�����ͬ�����������ظ����� 
*/
bool ArrayStack::top(int &val) const
{
	if(pos==-1)
	return false;
	else
	{
		val=data[pos];
		return true;
	}
}

/*
 * clear: ���ջ��Ԫ�� 
*/
void ArrayStack::clear()
{
	pos=-1;
}
	
/*
 * length: ����ջ�е�Ԫ������ 
*/
int ArrayStack::length() const
{
	return (pos+1);
}

/*
 * print: ���ջ
*/ 
void ArrayStack::print() const
{
	string res;
	
	for(int i=0;i<=pos;i++)
	{
		if(i==0)
		res=to_string(data[i])+res;
		else
		res=to_string(data[i])+"<-"+res;
	}
	
	cout<<res<<endl;
}

/*
 * ~ArrayStack: ��������  
*/ 
ArrayStack::~ArrayStack()
{
	delete [] data;
}


