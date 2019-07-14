#include "MultiTree.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/**
 * Forest: �ɺ����ֵܱ�ʾ������ʾ�Ķ������ɵ�ɭ��
 * note: ������Ҫ������ʶ������ĵײ�ָ��ṹ����˱�������Ϊ���������Ԫ
 */
class Forest 
{
    public:
    // 1. constructor
    Forest();                       	  // Ĭ�Ϲ��캯���������յ�ɭ��
    Forest(const vector<MultiTree> &res); // ���캯�����Ӷ�������б���ɭ��
    Forest(const vector<TreeNode *> &res);// ���캯�����Ӷ�����ĸ����ָ���б���ɭ��  

    // 2. copy_controller
    Forest(const Forest &other) = delete;                 // ���ÿ������캯��
    Forest & operator = (const Forest &other) = delete;   // ���ÿ�����ֵ�����

    // 3. methods
    BinaryTreeNode *convertToBinaryTree();                			 // ����ǰ��ɭ��ת��Ϊ������
    static vector<TreeNode *> convertToForest(BinaryTreeNode *root); // �������Ķ�����ת��Ϊɭ��
    vector<int> preorder();  // ���ɵ�ǰɭ�ֵ�ǰ���������
    vector<int> postorder(); // ���ɵ�ǰɭ�ֵĺ����������

    // 4. destructor
    ~Forest();

    private:
    // 5. domains
    vector<MultiTree> treeroot;
    
    // 6. private functions
    static TreeNode *convertMultiToBinaryTree(BinaryTreeNode *root);     // ������������任Ϊ����� 
};

/**
 * Forest: Ĭ�Ϲ��캯��������һ���յ�ɭ��
 */
Forest::Forest()
{
}

/**
 * Forest: ���캯�����Ӷ�������б���ɭ��
 */   
Forest::Forest(const vector<MultiTree> &res)
{
    for(int i=0;i<res.size();i++)
    {
        treeroot.push_back(res[i]);
    }
}

/**
 * Forest: ���캯�����Ӷ�����ĸ����ָ���б���ɭ�� 
 */   
Forest::Forest(const vector<TreeNode *> &res)
{
	for(int i=0;i<res.size();i++)
	{
		treeroot.push_back(MultiTree(res[i]));
	}
}

/**
 * convertToBinaryTree: ����ǰ��ɭ��ת��Ϊ������
 * return: �ɵ�ǰɭ��ת���õ��Ķ�����
 * note:  ��ɭ��ת���ɶ������Ļ�������������ʾ��
 		(1) ��ɭ���е�ÿ�ö����ת��Ϊ������ 
 		(2) �Ӷ����ת��Ϊ���������㷨�У��õ���ÿ�ö������ĸ�����rightָ���Ϊ�գ��ع�һ�£���Ϊ�����ת���������㷨�ǣ���rightָ����ڵ�ǰ�����ֵ�ָ��brother����leftָ����ڵ�ǰ���Ķ���ָ��child�� 
 		(3) ���ֻ��Ҫ��ɭ���е�һ����������rightָ��ָ��ڶ��������ڶ�����������rightָ��ָ�����������...����n-1����������rightָ��ָ���n��������
 */
BinaryTreeNode *Forest::convertToBinaryTree()
{
	// 1. ����ǰɭ���е�ÿһ�����ɶ����ת��Ϊ������ 
	vector<BinaryTreeNode *> res;
	for(int i=0;i<treeroot.size();i++)
	{
		res.push_back(treeroot[i].convertToBinaryTree());	
	}  
	
	// 2. ���ν���i�����ĸ�����rightָ��ָ���i+1����
	for(int i=0;i<treeroot.size()-1;i++)
	{
		res[i]->right=res[i+1];
	} 
	
	return res[0];
}

/**
 * convertToForest: �������Ķ�����ת��Ϊɭ��
 * return: �ɸ����Ķ�����ת���õ���ɭ��
 * note 1: ����������ɭ��ת��Ϊ���������㷨�������׵õ���������ת��Ϊɭ�ֵ��㷨
 * note 2: ��ɭ��ת��Ϊ���������㷨�У������Ƚ�ɭ���е�ÿһ�ö����ת��Ϊ��������Ȼ�����i�ö�����������rightָ��ָ���i+1�ö����� 
 * note 3: ��˽�������ת��Ϊɭ��ʵ���Ͼ����������̵�����̣����Ĳ���������£�
 			(1) �Ӹ���㿪ʼ������rightָ��Ҳ�����ӽ��ķ�����;������ÿһ����㶼��¼������Ϊɭ����һ���������ĸ���㣬ͬʱ������������rightָ����Ϊ�� 
 			(2) �����������еõ��Ķ���������ת��Ϊ�������ת�������ǳ��򵥣�������н���childָ����ڶ������ж�Ӧ����leftָ�룬������н���brotherָ����ڶ������ж�Ӧ����rightָ�� 
 */
vector<TreeNode *> Forest::convertToForest(BinaryTreeNode *root)
{
	// 1. ���ȷ������������
	vector<BinaryTreeNode *> lis;
	BinaryTreeNode *now=root;
	
	while(now)
	{
		lis.push_back(now);
		BinaryTreeNode *temp=now->right;
		now->right=NULL;
		now=temp;
	}
	
	// 2. Ȼ�󽫸�������������ת��Ϊ�����
	vector<TreeNode *> res;
	for(int i=0;i<lis.size();i++)
	{
		res.push_back(Forest::convertMultiToBinaryTree(lis[i]));
	} 
	
	return res;
}

TreeNode *Forest::convertMultiToBinaryTree(BinaryTreeNode *root)
{
	if(!root)
	return NULL;
	else
	{
		TreeNode *res=new TreeNode(root->val);
		res->child=convertMultiToBinaryTree(root->left);
		res->brother=convertMultiToBinaryTree(root->right);
		
		return res;
	}
} 

/**
 * preorder: ���ɵ�ǰɭ�ֵ�ǰ���������
 * return: ��ǰɭ�ֵ�ǰ���������
 * note: ɭ�ֵ�ǰ������㷨����Ҫ������Ը���Ϊ: ����ȡ��ɭ���е�ÿһ��������ÿ�������ν���ǰ���������
 */
vector<int> Forest::preorder()
{
    vector<int> res;

    for(int i=0;i<treeroot.size();i++)
    {
        vector<int> temp=treeroot[i].preorder();
        for(int i=0;i<temp.size();i++)
        {
            res.push_back(temp[i]);
        }
    }

    return res;
}

/**
 * postorder: ���ɵ�ǰɭ�ֵĺ����������
 * return: ��ǰɭ�ֵĺ����������
 * note: ɭ�ֵĺ�������㷨����Ҫ������Ը���Ϊ: ����ȡ��ɭ���е�ÿһ��������ÿ�������ν��к����������
 */
vector<int> Forest::postorder()
{
    vector<int> res;

    for(int i=0;i<treeroot.size();i++)
    {
        vector<int> temp=treeroot[i].postorder();
        for(int i=0;i<temp.size();i++)
        {
            res.push_back(temp[i]);
        }
    }

    return res;
}

/**
 * Forest: ɭ�ֵ���������
 * note: ɭ�ֵ���������ʵ���ϲ���Ҫ���κεĶ����������Ϊvector�����������л��Զ�����MultiTree���������� 
 */
Forest::~Forest()
{
}
