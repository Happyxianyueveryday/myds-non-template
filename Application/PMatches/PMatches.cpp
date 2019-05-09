#include <iostream> 
#include <string>
#include <stack>

using namespace std;

/*
 * PMatches: �жϸ����ı��ʽ�е������Ƿ�ƥ�� 
 * param exp: ��������ı��ʽ 
 * note: ����ջ�жϸ������ʽ�е������Ƿ�ƥ��ķ�����Ϊ�򵥣�ֱ�ӱ����������ʽ�е�ÿ���ַ���������������������ջ�����������������ջ����ջһ��Ԫ�أ��жϳ�ջ��Ԫ�غ͵�ǰ���������������Ƿ�ƥ�䣬��ƥ�����������ѭ����������ʽ���󣻱����������ж�ջ�Ƿ�Ϊ�գ���ջ��Ϊ�գ�����ʽ������ջΪ�գ�����ʽ��ȷ 
*/
bool PMatches(string exp)
{
	if(exp=="")
	return true;
	
	stack<char> sta;
	
	for(int i=0;i<exp.size();i++)
	{
		if(exp[i]=='['||exp[i]=='{'||exp[i]=='(')   // ���������ţ���ֱ����ջ 
		sta.push(exp[i]);
		else if(exp[i]==']'||exp[i]=='}'||exp[i]==')')   // ���������ţ���ջ����ջջ��Ԫ�أ��ж�ջ��Ԫ�غ͵�ǰ�������������Ƿ�ƥ�� 
		{
			if(sta.size())    
			{
				// ��ȡ����ջջ��Ԫ�� 
				char temp=sta.top();   
				sta.pop();   
				
				if(exp[i]==']'&&temp=='['||exp[i]=='}'&&temp=='{'||exp[i]==')'&&temp=='(')
				continue;
				else
				return false;
			}
			else     // ������������ʱջΪ�գ�����ʽ���� 
			return false;
		}
	}
	
	if(sta.size())
	return false;
	else
	return true;
}

int main(void)
{
	string lis[5]={"{(abc)}", "[{abc}{a(bc)]", "[{}", "", "[{abc(abcd(abcd))}]"};
	
	for(int i=0;i<5;i++)
	{
		if(PMatches(lis[i]))
		cout<<"���ʽ exp = "<<lis[i]<<" �Ϸ�"<<endl;
		else
		cout<<"���ʽ exp = "<<lis[i]<<" ���Ϸ�"<<endl;
	}
}
