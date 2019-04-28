#include "linked_list.h"
#include <iostream>

using namespace std;

int main(void)
{
	// 1. ���Թ��캯����ȷ�� 
	List lis;     // ����Ĭ�Ϲ��캯��
	lis.print();
	
	vector<int> data={1,2,3,4,5,6,7,8,9};
	List lis2(data);    // ���Դ����鹹��Ĺ��캯������ȷ��
	cout<<"����lis2 = "<<endl;
	lis2.print();
	cout<<"lis2�ĳ��� = "<<lis2.length()<<endl<<endl;
	
	cout<<"------------------------------------------"<<endl;
	
	
	// 2. ���Կ������ƺ�������ȷ�� 
	List lis3(lis2);   // ���Կ������캯��
	cout<<"����lis3 = "<<endl;
	lis3.print();     
	cout<<"lis3�ĳ��� = "<<lis3.length()<<endl<<endl;
	
	vector<int> data2={1,2,3,4,5,6};
	lis3=List(data2);  // ͬʱ���Կ������캯���Ϳ������������ 
	cout<<"��������lis3 = "<<endl;
	lis3.print();     
	cout<<"lis3�ĳ��� = "<<lis3.length()<<endl<<endl;
	
	cout<<"------------------------------------------"<<endl;
	
	// 3. ����ɾ������ 
	cout<<"����ɾ������֮ǰ����ʼ���������lis3 = "<<endl;
	lis3.print(); 
	
	int val;
	if(lis3.mydelete(0,val))
	{
		cout<<"ɾ���±�Ϊ0��Ԫ�غ���������lis3 = "<<endl;  
		lis3.print(); 
		cout<<"ɾ����Ԫ��ֵΪ: val = "<<val<<endl;	
	}
	else
	{
		cout<<"ɾ��ʧ�ܣ��������±겻�Ϸ���"<<endl; 
	}
	
	
	if(lis3.mydelete(4,val))
	{
		cout<<"ɾ���±�Ϊ4��Ԫ�غ���������lis3 = "<<endl;  // ����ɾ�� 
		lis3.print(); 
		cout<<"ɾ����Ԫ��ֵΪ: val = "<<val<<endl;	
	}
	else
	{
		cout<<"ɾ��ʧ�ܣ��������±겻�Ϸ���"<<endl; 
	}
	
	if(lis3.mydelete(6,val))
	{
		cout<<"ɾ���±�Ϊ6��Ԫ�غ���������lis3 = "<<endl;  // ����ɾ�� 
		lis3.print(); 
		cout<<"ɾ����Ԫ��ֵΪ: val = "<<val<<endl;	
	}
	else
	{
		cout<<"ɾ��ʧ�ܣ��������±�6���Ϸ���"<<endl; 
	}
	
	if(lis3.mydelete(-1,val))
	{
		cout<<"ɾ���±�Ϊ-1��Ԫ�غ���������lis3 = "<<endl;  // ����ɾ�� 
		lis3.print(); 
		cout<<"ɾ����Ԫ��ֵΪ: val = "<<val<<endl;	
	}
	else
	{
		cout<<"ɾ��ʧ�ܣ��������±�-1���Ϸ���"<<endl; 
	}
	
	cout<<"------------------------------------------"<<endl;
	
	// 4. ���Բ��뺯��
	vector<int> data3={};   // �ر�ע���������Ϊ�յ���� 
	List lis4(data3);
	cout<<"���Բ��뺯��֮ǰ����ʼ���������lis4Ϊ��"<<endl;
	lis4.print(); 
	if(lis4.insert(0,1))
	{
		cout<<"���±�Ϊ0��λ�ò���ֵ1����������lis4 = "<<endl;  
		lis4.print(); 
	}
	else
	{
		cout<<"����ʧ�ܣ��������±�0���Ϸ���"<<endl; 
	}
	
	if(lis4.insert(0,2))
	{
		cout<<"���±�Ϊ0��λ�ò���ֵ2����������lis4 = "<<endl;  
		lis4.print(); 
	}
	else
	{
		cout<<"����ʧ�ܣ��������±�0���Ϸ���"<<endl; 
	}
	
	if(lis4.insert(0,3))
	{
		cout<<"���±�Ϊ0��λ�ò���ֵ3����������lis4 = "<<endl;  
		lis4.print(); 
	}
	else
	{
		cout<<"����ʧ�ܣ��������±�0���Ϸ���"<<endl; 
	}
	
	if(lis4.insert(3,0))
	{
		cout<<"���±�Ϊ3��λ�ò���ֵ0����������lis4 = "<<endl;  
		lis4.print(); 
	}
	else
	{
		cout<<"����ʧ�ܣ��������±�3���Ϸ���"<<endl; 
	}
	
	cout<<"------------------------------------------"<<endl;
	
	// 5. ���Ի�ȡָ�����ֵ�ĺ��� 
	cout<<"���Ի�ȡָ�����ֵ�ĺ���֮ǰ����ʼ���������lis4 = "<<endl;
	lis4.print(); 
	if(lis4.getval(2,val))
	{
		cout<<"����lis4�±�Ϊ2��λ�õ�ֵΪval = "<<val<<endl;  
	}
	else
	{
		cout<<"��ȡֵʧ�ܣ��������±�2���Ϸ���"<<endl; 
	}
	
	if(lis4.getval(0,val))
	{
		cout<<"����lis4�±�Ϊ0��λ�õ�ֵΪval = "<<val<<endl;  
	}
	else
	{
		cout<<"��ȡֵʧ�ܣ��������±�0���Ϸ���"<<endl; 
	}
	
	if(lis4.getval(4,val))
	{
		cout<<"����lis4�±�Ϊ4��λ�õ�ֵΪval = "<<val<<endl;  
	}
	else
	{
		cout<<"��ȡֵʧ�ܣ��������±�4���Ϸ���"<<endl; 
	}
	
	if(lis4.getval(-1999,val))
	{
		cout<<"����lis4�±�Ϊ-1999��λ�õ�ֵΪval = "<<val<<endl;  
	}
	else
	{
		cout<<"��ȡֵʧ�ܣ��������±�-1999���Ϸ���"<<endl; 
	}
	
	cout<<"------------------------------------------"<<endl;
	
	// 6. ���Ի�ȡ���ȵĺ���
	cout<<"���Ի�ȡ���ȵĺ���֮ǰ����ʼ���������lis3 = "<<endl;
	lis3.print(); 
	cout<<"����lis3�ĳ���Ϊ: length = "<<lis3.length()<<endl;
	
	// 7. ����������������������Ѿ���ʽ���Թ��ˣ����ﲻ���ظ����� 
	 
}
