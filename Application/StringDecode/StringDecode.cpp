#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std; 

/*
 * decodeString: �ַ�������
 * note: �����е��ַ�������ͬ����ʹ��ջ������ʵ��
 *       ������㷨����Ϊ: �����Ƚ�ԭʼ�ַ����ָ�Ϊ�ַ������飬Ȼ��˳����������ַ�������: 
 *       (1) ����ǰԪ��Ϊ���ֻ���ĸ����ֱ�ӽ���ǰԪ����ջ
 *       (2) ����ǰԪ��Ϊ�����ţ���ֱ�ӽ���ǰԪ����ջ
 *       (3) ����ǰԪ��Ϊ�����ţ��򲻶ϳ�ջԪ�ز�ƴ��Ϊһ���ַ���str��ֱ��ջ��Ԫ��Ϊ������Ϊֹ�������ų�ջ���ǲ������Ȼ���ٲ��ϳ�ջԪ�ز�ƴ��Ϊһ������num��ֱ��ջ��Ԫ�ز�Ϊ����ʱֹͣ����ǰ����ַ���str�ظ�num�μ���, ����ٽ��ظ��õ��Ľ����ջ 
 *       �������㷨������Լ�ʹ��һ�����ӽ���ģ�⣬����3[a12[bcd]] 
*/
string decodeString(string s) 
{
	// 0. ����������� 
	if(s=="")
	return s;
	
	stack<char> sta;
	
	// 1. ���α������������������ַ��� 
	for(int i=0;i<s.size();i++)
	{
		// 1.1 ����ǰԪ���������ţ���ֱ����ջ 
		if(s[i]=='[')     	
		sta.push(s[i]);
		
		// 1.2 ����ǰԪ��Ϊ�����ţ�ִ�����µ�����
		// (1) ��ջ�в��ϳ�ջԪ�أ�������ջ��Ԫ��ƴ��Ϊһ���ַ���str��ֱ��ջ��Ԫ��Ϊ������Ϊֹ 
		// (2) ��ջ���������ų�ջ�����ǲ�ƴ�ӵ��ַ���str�� 
		// (3) �ٴ�ջ�в��ϳ�ջԪ�أ�������ջ��Ԫ��ƴ��Ϊһ������num��ֱ��ջ��Ԫ�ز�Ϊ����Ϊֹ
		// (4) �����������еõ����ַ���str�ظ�num�Σ������ظ��Ľ�������ĸ��ջ 
		else if(s[i]==']')
		{
			string str;
			while(sta.top()!='[')
			{
				str.insert(0, 1, sta.top());
				sta.pop();
			}
			
			sta.pop();
			
			int num=0;
			int exp=0;
			while(sta.size()&&sta.top()>='0'&&sta.top()<='9')
			{
				num+=(sta.top()-'0')*pow(10, exp);   // ע�⣬char��'0'ֱ����ʽת��Ϊint��ASCIIֵ48�������Ҫ�ȼ�ȥ48����'0��������ʽת��Ϊint���ܵõ���ȷ�Ľ�� 
				exp+=1;
				sta.pop();
			}
			
			string tempres;
			for(int k=0;k<num;k++)
			{
				tempres+=str;
			}
			for(int k=0;k<tempres.size();k++)     
			{
				sta.push(tempres[k]);
			}
		}
		
		// 1.3 ����ǰԪ�������ֻ�����ĸ����ֱ����ջ 
		else
		sta.push(s[i]);
	}
	
	string res;
	
	while(sta.size())
	{
		res.insert(0, 1, sta.top());
		sta.pop();
	}
	
	return res;
}


int main(void)
{
	string s;
	
	s = "3[a]2[bc]";
	cout<<decodeString(s)<<endl;
	
	s = "3[a2[c]]";
	cout<<decodeString(s)<<endl;
	
	s = "2[abc]3[cd]ef";
	cout<<decodeString(s)<<endl;
}
