#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
    ListNode(int ival=0):val(ival),next(NULL)
    {
    }

    int val;
    ListNode *next;
};


class Queue
{
	public:
	Queue();                                   // Ĭ�Ϲ��캯�� 
	Queue(const Queue &other);                 // �������캯��
	Queue & operator = (const Queue &other);   // ������������� 
	~Queue();                                  // �������� 
	
	bool front(int &val);                      // ��ȡ����Ԫ�� 
	bool pop(int &val);                        // Ԫ�س��Ӳ��� 
	void push(int val);                        // Ԫ����Ӳ��� 
	int length();                              // ��ȡ�����е�Ԫ�ظ��� 
	bool empty();                              // �ж϶����Ƿ�Ϊ�� 
		 
	private:
	ListNode *head;                            // ����Ԫ��ָ�루�������һ��ͷ���ƽ�㣩 
	ListNode *tail;                            // ��βԪ��ָ�� 
	int size;                                  // �����е�Ԫ������ 
};


/*
 * Queue: Ĭ�Ϲ��캯�� 
*/
Queue::Queue()
{
	head=new ListNode(0);   // ��ʼ��ͷ���ƽ�� 
	tail=head;             
	size=0;
}


/*
 * Queue: �������캯�� 
*/
Queue::Queue(const Queue &other)
{
	head=new ListNode(0);      // ��ʼ��ͷ��� 
	
	ListNode *now=head;
	ListNode *othernow=other.head->next;    // ע��ӵ�һ�������Ľ�㿪ʼ������Ҫ����ͷ���ƽ�� 
	
	while(othernow)
	{
		now->next=new ListNode(othernow->val);
		
		now=now->next;
		othernow=othernow->next;
	}
	
	tail=now;                // ��ʼ��β��� 
	size=other.size;         // ��ʼ��Ԫ�ظ��� 
}


/* 
 * operator = : ������ֵ����� 
*/
Queue &Queue::operator = (const Queue &other)
{
	// 0. �������Ҹ�ֵ���� 
	if(this==&other)
	return (*this);
	
	// 1. �����ͷŵ�ǰ���ڴ�
	ListNode *now=head;
	
	while(now) 
	{
		ListNode *temp=now;
		now=now->next;
		delete temp;
	}
	
	// 2. Ȼ��ӿ���Դ���н��п�������
	head=new ListNode(0);    // ���´���ͷ���ƽ��
	
	now=head;
	ListNode *othernow=other.head;
	
	while(othernow)
	{
		now->next=new ListNode(othernow->val);
		
		now=now->next;
		othernow=othernow->next;
	}
	 
	tail=now;           // ��ʼ��β��� 
	size=other.size;    // ��ʼ��Ԫ�ظ��� 
}


/*
 * ~Queue: �������� 
*/
Queue::~Queue() 
{
	ListNode *now=head;
	
	while(now) 
	{
		ListNode *temp=now;
		now=now->next;
		delete temp;
	}
}


/*
 * front: ��ȡ����Ԫ�� 
*/
bool Queue::front(int &val)
{
	if(!size)
	return false;
	else
	{
		val=head->next->val;
		return true;
	}
}


bool Queue::pop(int &val)
{
	if(!size)
	return false;
	else if(size==1)    // �״��: �������н�ʣ��һ��Ԫ��ʱ������ʹ����ͷ���ƽ�㣬��˱�������tailָ��    
	{
		ListNode *temp=head->next;
		val=temp->val;
		head->next=NULL;
		size=0;
		tail=head;
		delete temp;
		
		return true;
	}
	else                // ��������ʣ�¶���һ��Ԫ��ʱ����ʱ�������tailָ�� 
	{
		ListNode *temp=head->next;
		head->next=head->next->next;
		
		val=temp->val;
		delete temp;
		size-=1;
		
		return true;
	}
}


void Queue::push(int val)
{
	tail->next=new ListNode(val);
	tail=tail->next;
	size+=1;
}


int Queue::length()
{
	return size;
}


bool Queue::empty()
{
	return size;
}

