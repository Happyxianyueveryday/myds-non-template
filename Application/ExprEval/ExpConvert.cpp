#include <iostream> 
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <cstdlib>

using namespace std;

// ��������������ʽ������ 
// note: �����沨�����ʽ��������ݣ���������׸������������ϵ�������ݣ�������ͨ���ʽ(2+5*10)*2���沨�����ʽΪ: 2 5 10 * + 2 * 

/*
 * ExpConvert: ����ͨ���ʽת��Ϊ�沨�����ʽ 
 * param exp: �������ͨ���ʽ 
 * note: ����ͨ���ʽת��Ϊ�沨�����ʽ�ķ���ͬ����ͨ��һ����ʱջ����ջ��ֻ����������������ʵ��: 
 *       ����һ����ʱջ��˳���������ԭʼ���ʽ: 
 *       (1) ���������֣���ֱ�ӽ�����뵽�沨�����ʽ�����
 *       (2) �����������ţ���ֱ�ӽ�����뵽ջ��
 *       (3) �����������ţ����ջ�в��ϳ�ջջ���������ֱ������������Ϊֹ�������ų�ջ���ǲ������������ʽ�� 
 *       (4) ���������������������+, -, *, /�������ջ�в��ϳ�ջջ������������������У�ֱ��ջ������������ȼ�С�ڣ�û�е��ڣ�����ǰԪ�ص����ȼ�����ջ�������Ϊ������Ϊֹ��Ȼ���ٽ���ǰԪ����ջ ����εõ�����㷨���Ա��ʽ2*5+5ģ��һ�鼴�ɣ� 
 *       ���������󣬽�ջ��ʣ�µķ������γ�ջ�������������ʽ�� 
*/
vector<string> ExpConvert(const vector<string> &exp)
{
	vector<string> res;	     // ����沨�����ʽ
	
	map<string, int> rank;   // ���ȼ� 
	rank["+"]=rank["-"]=0;
	rank["*"]=rank["/"]=1;
	
	// 0. ����������� 
	if(!exp.size()) 
	return res;
	
	// 1. ˳����������������ͨ���ʽ
	stack<string> sta;
	
	for(int i=0;i<exp.size();i++)
	{
		// 1.1 �����������ţ���ֱ�ӽ���������ջ
		if(exp[i]=="(")	      
		sta.push(exp[i]);
		
		// 1.2 �����������ţ����ջ����ջԪ�ز������������ʽ�У�ֱ������һ��������Ϊֹ�������ų�ջ���ǲ���� 
		else if(exp[i]==")")  
		{
			while(sta.size()&&sta.top()!="(")
			{
				res.push_back(sta.top());
				sta.pop();
			}
			sta.pop();   // ��ջ�����ŵ��ǲ������������ʽ�� 
		}
		
		// 1.3 ��������������򲻶ϳ�ջջ��Ԫ�ز������������ʽ�У�ֱ������һ�������Ż���ջ��Ԫ�ص����ȼ�С�ڵ�ǰԪ��ʱֹͣ���ٽ���ǰԪ����ջ 
		else if(exp[i]=="+"||exp[i]=="-"||exp[i]=="*"||exp[i]=="/")  
		{
			while(sta.size()&&sta.top()!="("&&rank[sta.top()]>=rank[exp[i]])
			{
				res.push_back(sta.top());
				sta.pop();
			}
			sta.push(exp[i]);    // ����ǰԪ����ջ 
		} 
		else
		res.push_back(exp[i]);           // 1.4 ������������ֱ�������������ʽ�� 
	}
	
	// 2. ���������󣬽�ջ��ʣ�µķ������γ�ջ�������������ʽ�� 
	while(sta.size())
	{
		res.push_back(sta.top());
		sta.pop();
	}
	
	return res;
}


/*
 * ExpCal: ���沨�����ʽ��ֵ
 * exp: ������沨�����ʽ
 * note: ���ݸ������沨�����ʽ������ֵ���㷨����: 
 *       ˳������������沨�����ʽ: 
 *       (1) ����ǰԪ��Ϊ���֣���ֱ�ӽ���ǰԪ����ջ
 *       (2) ����ǰԪ��Ϊ���������ջ�г�ջ����Ԫ�أ�������Ԫ������ǰ��������涨������õ�������ٽ������ջ 
*/
double ExpCal(const vector<string> &exp) 
{
	// 0. ����������� 
	if(!exp.size())
	return 0;
	
	// 1. ����������沨�����ʽ
	stack<double> sta;
	
	for(int i=0;i<exp.size();i++) 
	{
		if(exp[i]=="+")
		{
			double right=sta.top();
			sta.pop();
			double left=sta.top();
			sta.pop();
			
			sta.push(left+right);
		}
		else if(exp[i]=="-")
		{
			double right=sta.top();
			sta.pop();
			double left=sta.top();
			sta.pop();
			
			sta.push(left-right);
		}
		else if(exp[i]=="*")
		{
			double right=sta.top();
			sta.pop();
			double left=sta.top();
			sta.pop();
			
			sta.push(left*right);
		}
		else if(exp[i]=="/")
		{
			double right=sta.top();
			sta.pop();
			double left=sta.top();
			sta.pop();
			
			sta.push(left/right);
		}
		else
		{
			double num=atof(exp[i].c_str());
			sta.push(num);
		}
	}
	
	// 2. ���ջ��ʣ�µ�Ψһһ��Ԫ�ؾ������ձ��ʽ��ֵ�Ľ��
	double res=sta.top();
	sta.pop();
	
	return res;
}

/*
 * print: ������ʽ 
*/
void print(string infor, const vector<string> &res)
{
	cout<<infor;
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
}

int main(void)
{
	// 1. ԭʼ���ʽ = (5+6*5)*8 = 280
	vector<string> input={"(", "5", "+", "6", "*", "5", ")", "*", "8"};
	vector<string> res=ExpConvert(input);
	print("��ͨ���ʽ = ", input);
	print("�沨�����ʽ = ", res);
	cout<<"���ʽ��ֵ��� = "<<ExpCal(res)<<endl;
	cout<<"---------------------------------------------"<<endl;
	
	// 2. ԭʼ���ʽ = ((2.5+3.75)*7+(3.75+2.25*8)/2)-(8-7) = 53.625
	vector<string> input1={"(", "(", "2.5", "+", "3.75", ")", "*", "7", "+", "(", "3.75", "+", "2.25", "*", "8", ")", "/", "2", ")", "-", "(", "8", "-", "7", ")"};
	vector<string> res1=ExpConvert(input1);
	print("��ͨ���ʽ = ", input1);
	print("�沨�����ʽ = ", res1);
	cout<<"���ʽ��ֵ��� = "<<ExpCal(res1)<<endl;
	cout<<"---------------------------------------------"<<endl;
}
