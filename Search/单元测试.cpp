#include "Search.h"
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	Search search;
	
	int lis1[]={1,2,3,4,5,6,7,8,9};
	int lis2[]={2,4,6,8,10};
	int lis3[]={};
	int lis4[]={1};
	int lis5[]={9,6,3,2,5,8,7,4,1};      
	
	int index;
	
	index=search.binary_search(lis1,9,5);
	if(index!=-1)
	cout<<"����lis1 ��Ԫ��5���±�Ϊ index = "<<index<<endl;
	else
	cout<<"����lis1 ��Ԫ��5������"<<endl;
	
	index=search.binary_search(lis1,9,9);
	if(index!=-1)
	cout<<"����lis1 ��Ԫ��9���±�Ϊ index = "<<index<<endl;
	else
	cout<<"����lis1 ��Ԫ��9������"<<endl;
	
	index=search.binary_search(lis2,5,4);
	if(index!=-1)
	cout<<"����lis2 ��Ԫ��4���±�Ϊ index = "<<index<<endl;
	else
	cout<<"����lis2 ��Ԫ��4������"<<endl;
	
	index=search.binary_search(lis3,0,1);
	if(index!=-1)
	cout<<"����lis3 ��Ԫ��1���±�Ϊ index = "<<index<<endl;
	else
	cout<<"����lis3 ��Ԫ��1������"<<endl;
	
	index=search.binary_search(lis4,1,1);
	if(index!=-1)
	cout<<"����lis4 ��Ԫ��1���±�Ϊ index = "<<index<<endl;
	else
	cout<<"����lis4 ��Ԫ��1������"<<endl;
	
	index=search.seq_search(lis5,9,4);
	if(index!=-1)
	cout<<"����lis5 ��Ԫ��4���±�Ϊ index = "<<index<<endl;
	else
	cout<<"����lis5 ��Ԫ��4������"<<endl;
}
