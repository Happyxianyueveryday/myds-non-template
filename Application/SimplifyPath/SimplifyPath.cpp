#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std; 

/*
 * dividePath: ������·�����зָ�
 * note: ��������������·������б��'/'���зָ���罫ԭʼ·���ַ���"/home//foo/"�ָ�Ϊ{"home", "", "foo"}  
*/
vector<string> dividePath(string path)
{
	vector<string> res;
	
	string temp;     // ��ǰ����ƴ�ӵ�Ƭ��
	int flag=0;      // ��־����
	 
	for(int i=0;i<path.size();i++)
	{
		if(flag==0&&path[i]!='/')
		{
			temp.push_back(path[i]);
			flag=1;
		}
		else if(flag==1&&path[i]!='/')
		{
			temp.push_back(path[i]);
		}
		else if(flag==1&&path[i]=='/')
		{
			flag=0;
			res.push_back(temp);
			temp="";
		}
	}
	
	res.push_back(temp);     // ע�����������·�������ܲ���'/'��β�������Ҫ����ٽ�ʣ�µ��ַ��������������� 
	
	return res;
}

/*
 * simplifyPath: ������·�����м� 
 * note: ���ȶ������·���ַ������зָ�ָ�Ϊ�ַ������飬Ȼ��ʹ��ջ���н��⣬�����������£�
 *       (1) ���������ַ������飬������".."�����ջ�г�ջһ��Ԫ�أ����ջ�в�Ϊ�գ���������"."��""����ֱ�Ӻ��ԣ�������������������ջ 
 *       (2) ��ջ�е�Ԫ�����γ�ջ�������ΰ��ո�����ʽ����б�����  
*/
string simplifyPath(string path) 
{
	stack<string> sta;
	vector<string> lis=dividePath(path);
	
	for(int i=0;i<lis.size();i++)
	{
		if(lis[i]=="..")
		{
			if(sta.size())
			sta.pop();
		}
		else if(lis[i]==".")
		continue;
		else if(lis[i]=="")    // ע��������dividePath�����ķָ������ܴ��ڿո� 
		continue;
		else
		sta.push(lis[i]);
	}
	
	string res;
	
	while(sta.size())
	{
		string temp=sta.top();
		sta.pop();
		
		res="/"+temp+res;
	}
	
	if(res=="")
	res="/"+res; 
	
	return res;
}


int main(void)
{
	string path;
	
	path="/home/";
	cout<<simplifyPath(path)<<endl;
	
	path="/../";
	cout<<simplifyPath(path)<<endl;
	
	path="/home//foo/";
	cout<<simplifyPath(path)<<endl;
	
	path="/a/./b/../../c/";
	cout<<simplifyPath(path)<<endl;
	
	path="/a/../../b/../c//.//";
	cout<<simplifyPath(path)<<endl;
	
	path="/a//b////c/d//././/..";
	cout<<simplifyPath(path)<<endl;
}
