#include <iostream> 
#include <string>
#include <stack>
#include "tree.h"

using namespace std; 


struct ThreadNode
{
    ThreadNode(int ival=0):val(ival),left(NULL),right(NULL),lflag(0),rflag(0)
    {
    }

    int val;
    ThreadNode *left;
    ThreadNode *right;
    int lflag;
    int rflag;
};


/*
 * ThreadTree: ��������Ķ�������������
 * note 1: ����ͨ�������У����ܴ������Ľ��ֻ�����ӽ��������ӽ�㣬������Ҷ�ӽ�㣬��ʱ�ý����left��right��Ա�ʹ��ڿ���״̬
 * note 2: Ϊ�������ӽ��/���ӽ��Ϊ�յ����������left��right��Ա���涨: �����ӽ��Ϊ��ʱ��ʹ��left�ֶμ�¼��ǰ������������ʱ��ǰ����㣻�����ӽ��Ϊ��ʱ��ʹ��right�ֶμ�¼��ǰ������������ʱ�ĺ�̽�㣬����������lflag��rflag����left�ֶκ�right�ֶ�ָ�����ǰ������㻹�������ӽ�㣬��͹����˶��������� 
*/
class ThreadTree
{
	public:  
	// 1. ���캯�� 
	ThreadTree();                                                      // Ĭ�Ϲ��캯�� 
	ThreadTree(const Tree &other);                                     // ����ͨ�������������ɶ�Ӧ��������
	
	// 2. �������� 
	ThreadTree(const ThreadTree &other);                               // �������캯��  
	ThreadTree & operator = (const ThreadTree &other) = delete;        // ��ֹ������ֵ�������ʹ�� 
	
	// 3. ���ܺ���: �ص�ע�������������ֻ�������getFirstNode��getNextNode 
	vector<int> inorder();                                              // ��ȡ��ǰ������������������У����㷨Ӧ����������������������ʵ�� 
	
	// 4. ��������
	~ThreadTree();
	
	private:
	ThreadNode *treeroot;     // �������ĸ���� 
	
	ThreadNode *__copyTree(TreeNode *root);                              // �Ӷ�������������һ���������ĵײ�ݹ�ʵ��
	
	// 5. ���������������ֻ�����������ȡ����������������׽�㣬��ȡ���������һ����� 
	ThreadNode *getFirstNode(ThreadNode *root);               // ��������������1: ��ȡ������������������������еĵ�һ����� 
	ThreadNode *getNextNode(ThreadNode *pos);                // ��������������2: ��ȡ����������е�ǰ������һ�����
};


/*
 * ThreadTree: Ĭ�Ϲ��캯�� 
*/
ThreadTree::ThreadTree()
{
	treeroot=NULL;
}


/*
 * ThreadTree: ������ͨ�������������ɶ�Ӧ��������
 * note: ����ͨ�����������������������㷨������Ի���Ϊ��������
 *       (1) ��һ������ԭʼ�������������������
 *       (2) �ڶ������ڿ��������ͨ���������������������������������ǰ����leftΪNULL������leftָ��ǰ�������������е�ǰ����㣻����ǰ����rightΪNULL������rightָ��ǰ�������������еĺ�̽�㣻���޸Ķ�Ӧ��״̬��Ǳ��� 
*/ 
ThreadTree::ThreadTree(const Tree &other)
{
	// 1. ���ȴ������Դ��������������������õ�һ������������ 
	treeroot=__copyTree(other.getroot());    
	
	// 2. Ȼ����иö�������������������ͨ��һ�������������ʵ�֣�����ʹ�÷ǵݹ鷽������ʵ�֣�������ͨ�����������������μ������������Ĳ��֣����������ظ����ܣ� 
	// note: ʹ���������ÿ�η���һ����㣬�����ڷ��ʵĽ����������� 
	stack<ThreadNode *> sta;
	
	ThreadNode *temp=treeroot;     // ���ڱ�������ʱָ�� 
	ThreadNode *nowprev=NULL;      // ��ǰ���now��ǰ�����ָ�� 
	
	while(temp)
	{
		sta.push(temp);
		temp=temp->left;
	}
	
	while(sta.size())
	{
		// 2.1 ���������������Ҫ�ĳ��沽�� 
		ThreadNode *now=sta.top();    // ��ǰ���ڷ��ʵĺ�׼�������������Ľ�� 
		sta.pop();
		
		temp=now->right;
		
		while(temp)
		{
			sta.push(temp); 
			temp=temp->left;
		}
		
		// 2.2 �Ե�ǰ���now�������������������������������Ķ���: ��now->left==NULL����now->leftָ��ǰ���now��ǰ�����nowprev����now->right==NULL����now->rightָ��ǰ���ĺ�̽�㣨��ǰ���now����һ�����ʵĽ����ǵ�ǰ��ջ����㣩�������ö�Ӧ�ı�־���� 
		if(!now->left)
		{
			now->left=nowprev;
			now->lflag=1;
		}
		if(!now->right)
		{
			// ע�������ж�ջ�Ƿ�Ϊ�գ������ʵ�ǰ����ջΪ�գ�˵����ǰ�������������е����һ����㣬û�к�̽�� 
			if(sta.size())
			now->right=sta.top();
			else
			now->right=NULL;
			
			now->rflag=1;
		}
		
		// 2.3 ���µ�ǰ���now��ǰ�����nowprev
		nowprev=now; 
	}
}

ThreadNode *ThreadTree::__copyTree(TreeNode *root)
{
	if(!root)
	return NULL;
	else
	{
		ThreadNode *now=new ThreadNode(root->val);
		now->left=__copyTree(root->left);
		now->right=__copyTree(root->right);
		
		return now;
	}
}


/*
 * getFirstNode: ��������������1: ��ȡ������������������������еĵ�һ����㣬�ò������㷨˼�루��note���ǳ���Ҫ����طǳ��������������� 
 * param root: ����ĸ����������ĸ���� 
 * return: ������������������������׽�� 
 * note: ����һ����������������������׽���Ȼ�������Ľ�㣬���һֱ�������ӽ��ķ���ֱ�������������Ľ�㣬���ظý�㼴�� 
*/
ThreadNode *ThreadTree::getFirstNode(ThreadNode *root)
{
	// 1. ��ʼ���α�ָ��nowָ��������������ĸ���� 
	ThreadNode *now=root;
	
	// 2. �ƶ��α�ָ��now�������������Ľ��: ֱ�ӴӸ���㿪ʼһֱ�����ƶ������һ����㼴�ɣ��ж����һ�����ֻ����ݱ�־����lflag���� 
	while(now&&!now->lflag)   // lflag==1������ǰ���û�����ӽ�㣬��ʱ��ǰ�����������Ľ�㣬ֱ���˳�ѭ�������ؼ��� 
	{
		now=now->left;
	}
	
	return now;
}


/*
 * getNextNode: ��������������2: ��ȡ����������е�ǰ������һ����㣬�ò������㷨˼�루��note���ǳ���Ҫ����طǳ��������������� 
 * param pos: �������������� 
 * return: �����Ľ������������е���һ����� 
 * note: ����һ���������е�ĳ����㣬Ҫ��øý������������е���һ����㣬վ����������ĽǶ���˼������˼·�ǳ��򵥣�
 *       (1) ��������pos��rflag==1�����ݶ������������Ķ��壬��ʱ����right�ض��ܹ��ﵽ��̽�㣬��ֱ�ӷ���pos->right��
 *       (2) ��������pos��rflag==0����ʱ��ǰ����������������Ϊ��ǰ���pos�Ѿ�����������������еĺ�̽���ǵ�ǰ����������pos->right�е���������׽�㣬��ֱ�ӷ���getFirstNode(pos->right) ��Ϊʲô���ô�������������Ϊ��������getFirstNode���������ˣ�����ʹ��һ��ʾ������������⣩ 
*/          
ThreadNode *ThreadTree::getNextNode(ThreadNode *pos)
{
	if(pos->rflag)	
	return pos->right;
	else
	return getFirstNode(pos->right);
}


/* 
 * inorder: �Ե�ǰ�����������������������������������
 * note: ���㷨ֱ��ʹ�������������������ֻ�������������ɣ�����ʹ��getFirstNode������ȡ��������������������׽�㣬Ȼ�󲻶�ʹ��getNextNode������ȡ��������еĺ�̽�㣬ֱ�������ս��NULLΪֹ 
*/
vector<int> ThreadTree::inorder()
{
	vector<int> res;
	
	ThreadNode *now=getFirstNode(treeroot);
	
	while(now)
	{
		res.push_back(now->val);
		now=getNextNode(now);
	}
	
	return res;
}


/*
 * ~ThreadTree: �������� 
 * note: ͬ�����԰������������˳��������������ʹ��getFirstNode��getNextNode�����������б�����ͬʱ����ɾ������ 
*/
ThreadTree::~ThreadTree()
{
	ThreadNode *now=getFirstNode(treeroot);
	
	while(now)
	{
		ThreadNode *temp=now;
		now=getNextNode(now);
		delete now;
	} 
}
