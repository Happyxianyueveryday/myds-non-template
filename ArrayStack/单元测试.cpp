#include "ArrayStack.h"
#include <iostream>

using namespace std;

int main(void)
{
	// 1. ���Թ��캯�� 
	ArrayStack sta1(100);           // Ĭ�Ϲ��캯�� 
	cout<<"ջsta1Ϊ�գ�sta1 = "<<endl;
	sta1.print();
	
	vector<int> data0={};
	ArrayStack sta0(100, data0);           // �����鹹��Ĺ��캯��
	sta0=sta0=sta0;
	cout<<"ջsta0Ϊ�գ�sta0 = "<<endl;
	sta0.print();
	
	vector<int> data={1,2,3,4,5,6};
	ArrayStack sta2(100, data);     // �����鹹��Ĺ��캯�� 
	cout<<"������{1,2,3,4,5,6}�����ջsta2Ϊ sta2 = "<<endl;
	sta2.print();
	cout<<"ջsta2�Ĵ�СΪ length = "<<sta2.length()<<endl;
	
	cout<<"--------------------------------------------"<<endl;
	
	// 2. ���Կ������ƺ��� 
	ArrayStack sta3(sta2);     //  �������캯�� 
	cout<<"��sta3 = sta2������ջ sta3 = "<<endl;
	sta3.print();
	cout<<"ջsta3�Ĵ�СΪ length = "<<sta3.length()<<endl;
	
	vector<int> data2={1,2,3,4,5,6,7,8};
	sta3=ArrayStack(100, data2);    // ������ֵ�����
	cout<<"������{1,2,3,4,5,6,7,8}���¹���ջsta3������sta3 = "<<endl;
	sta3.print();
	cout<<"ջsta3�Ĵ�СΪ length = "<<sta3.length()<<endl;
	
	cout<<"--------------------------------------------"<<endl;
	
	// 3. ������ջ���� 
	cout<<"�ڲ�����ջ����֮ǰ��ջ sta3 = "<<endl;
	sta3.print();
	
	sta3.push(9);
	cout<<"��ջԪ��9��ջ sta3 = "<<endl;
	sta3.print();
	cout<<"ջsta3�Ĵ�СΪ length = "<<sta3.length()<<endl;
	
	sta3.push(10);
	cout<<"��ջԪ��10��ջ sta3 = "<<endl;
	sta3.print();
	cout<<"ջsta3�Ĵ�СΪ length = "<<sta3.length()<<endl;
	
	// 4. ���Գ�ջ����
	cout<<"�ڲ��Գ�ջ����֮ǰ��ջ sta3 = "<<endl;
	sta3.print(); 
	cout<<"�������γ�ջԪ��ֱ��ջΪ��Ϊֹ"<<endl;
	
	int val;
	while(sta3.pop(val))
	{
		cout<<"��ջ��ջ��Ԫ��ֵΪ val = "<<val<<endl;
	}
	
	cout<<"--------------------------------------------"<<endl;
	
	// 5. ������պ���
	cout<<"�ڲ������ջ����֮ǰ��ջ sta2 = "<<endl;
	sta2.print();
	sta2.clear();
	cout<<"���ջsta2��ջsta2 = "<<endl;
	sta2.print();
}
