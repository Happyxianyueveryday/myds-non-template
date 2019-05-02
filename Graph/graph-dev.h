#include <iostream>
#include <string>
#include <vector> 
#include <stack>
#include <queue>
#include <cstring> 

using namespace std;

/*
* Graph: ����ͼ��
*/
class Graph
{
    public:

    // 1. ���캯��
    Graph();                                      // Ĭ�Ϲ��캯��
    Graph(const vector<vector<int> > &lis);       // ���ڽӾ�������(vector)����ͼ��ͼ�еĽ�����α�����Ϊ0,1,...,size-1

    // 2. ��������
    Graph(const Graph &gra);                      // �������캯��
    Graph & operator = (const Graph &other);      // ������ֵ�����

    // 3. ���������빦��
    vector<int> bfs(int start);                   // ͼ�Ĺ����������
    vector<int> dfs(int start);                   // ͼ�������������

    vector<int> dijkstra(int start);              // ����ĳ����㵽�������������������·������: dijkstra�㷨
    vector<int> prim(int start);                  // ����ĳ����㵽�������������������·������: floyd�㷨

    Graph prim();                                 // ������С������: prim�㷨
    Graph krustkal();                             // ������С������: krustkal�㷨

    void print();                                 // ���ͼ���ڽӱ� 

    // 4. ��������
    ~Graph();                                     // ��������

    private:
    int **data;                                   // ͼ���ڽӾ���: ����Ԫ��ֵΪ-1��ʾ�������֮�䲻���ڣ�֮��ľ���Ϊ����� 
    int size;                                     // ͼ�Ĵ�С
};

/*
 * Graph: Ĭ�Ϲ��캯��
*/
Graph::Graph()
{
    data=NULL;
    size=0;
}

/*
 * Graph: ���ڽӾ�������(vector)����ͼ
*/
Graph::Graph(const vector<vector<int> > &lis)
{
    // 0. �����ڽӱ��С
    size=lis.size();

    // 1. �����ڽӱ�ռ�
    data=new int *[size];
    
    for(int i=0;i<size;i++)
    {
        data[i]=new int[size];
    }

    // 2. �����ڽӱ�����
    for(int i=0;i<size;i++)
    {
        for(int k=0;k<size;k++)
        {
            data[i][k]=lis[i][k];
        }
    }
}

/*
 * Graph: �������캯��
*/
Graph::Graph(const Graph &other)
{
    // 1. ��������Ϳ���Դ��ͬ��С���ڽӱ��ڴ�
    size=other.size;
    data=new int*[size];

    for(int i=0;i<size;i++)
    {
        data[i]=new int[size];
    }

    // 2. �����ڽӱ�����
    for(int i=0;i<size;i++)
    {
        for(int k=0;k<size;k++)
        {
            data[i][k]=other.data[i][k];
        }
    }
}

/* 
 * operator = : ������ֵ�����
*/
Graph & Graph::operator = (const Graph &other)
{
    // 0. �������Ҹ�ֵ�����
    if(&other==this)
    return (*this);

    // 1. �ͷŵ�ǰ�ڽӱ��ڴ�
    for(int i=0;i<size;i++)
    {
        delete [] data[i];
    }
    delete [] data;

    // 2. ��������Ϳ���Դ��ͬ��С���ڽӱ��ڴ�
    size=other.size;
    data=new int*[size];

    for(int i=0;i<size;i++)
    {
        data[i]=new int[size];
    }

    // 3. �����ڽӱ�����
    for(int i=0;i<size;i++)
    {
        for(int k=0;k<size;k++)
        {
            data[i][k]=other.data[i][k];
        }
    }

    return (*this);
}

/*
 * print: ����ڽӱ�
*/ 
void Graph::print()
{
	for(int i=0;i<size;i++)	
	{
		for(int k=0;k<size;k++)
		{
			cout<<data[i][k]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

/*
 * bfs: ͼ�Ĺ����������
 * param start: ���������������ʼ����±�
 * note: ͼ�Ĺ���������������Ĳ�α���ʹ�õĵ����㷨���ƣ�����ʹ�ö������������
*/
vector<int> Graph::bfs(int start)
{
    vector<int> res;    
    // 0. �����������
    if(!size||start<0||start>=size)
    return res;

    // 1. �������ڹ�����������Ķ��У����ҽ���ʼ�Ľ�������У����Ҵ���һ���������ڱ�Ƕ�Ӧ�±�Ľ���Ƿ��Ѿ����ʹ�
    queue<int> que;      // ���ڹ�����������Ķ���
    bool visit[size];    // ���ڼ�¼��Ӧ����Ƿ��Ѿ������ʹ�������
    memset(visit, 0, size*sizeof(bool));
    que.push(start);

    // 2. ѭ���������µĲ���ֱ������Ϊ��ֹͣ: �Ӷ����г���һ����㣬���ý��δ���ʹ���������ó��ӵĽ�㲢��Ǹý���Ѿ����ʹ���Ȼ����ý��ֱ�������ӵ�δ���ʹ����ھӽ��ȫ�����
    // ��ע: ͼ�Ĺ�������������������ƣ�������Ҫ�ر�ע�⣬��Ҫ���ͼ�е�ÿ������Ƿ��Ѿ����ʹ�
    // ��ע: һ��Ҫע��ʹ�����η��ʼ�飬�����ǰ���Ҫ����Ľ���Ƿ��Ѿ����ʹ����ڽ����ջǰ���Ҫ��ӵĽ���Ƿ��Ѿ����ʹ� 
    while(que.size())
    {
        int temp=que.front();
        que.pop();
        
        // 2.1 �����ӵĽ���Ѿ����ʹ���ֱ�Ӻ��Լ��� 
        if(visit[temp])
        continue; 
        
        // 2.2 �����ӵĽ��û�б����ʹ���������ý�㣬�����ý��δ���ʹ����ھ���� 
        else
        {
        	res.push_back(temp);
        	visit[temp]=true;

        	for(int i=0;i<size;i++)
        	{
            	if(data[temp][i]!=-1&&!visit[i])
            	que.push(i);
        	}
		}
    }

    // 3. ���ر������
    return res;
}

/*
 * dfs: ͼ�������������
 * param start: ���������������ʼ����±�
 * note: ͼ�������������������ǰ�����ʹ�õĵ����㷨���ƣ�����ʹ��ջ���������
*/
vector<int> Graph::dfs(int start)
{
    vector<int> res;
    
    // 0. �����������
    if(!size||start<0||start>=size)
    return res;

    // 1. ����������ʹ�õ�ջ��������ʼ������ջ�У����Ҵ���һ���������ڱ�Ƕ�Ӧ�±�Ľ���Ƿ��Ѿ����ʹ�
    stack<int> sta;
    bool visit[size];    // ���ڼ�¼��Ӧ����Ƿ��Ѿ������ʹ�������
    memset(visit, 0, size*sizeof(bool));
    sta.push(start);

    // 2. ѭ���������²���ֱ��ջΪ��ֹͣ: ��ջ����ջһ����㣬���ý��δ���ʹ���������ý�㲢��Ǹý��Ϊ�Ѿ����ʣ�Ȼ����ý��ֱ������������δ���ʹ����ھӽ�����μ���ջ�� 
    // ��ע: һ��Ҫע��ʹ�����η��ʼ�飬�����ǰ���Ҫ����Ľ���Ƿ��Ѿ����ʹ����ڽ����ջǰ���Ҫ��ջ�Ľ���Ƿ��Ѿ����ʹ�����Ҫע�⣬��ջ�е����Ľ��Ҳ�п����Ѿ����ʹ���������Ϊ��������ܾ�����ͬ���ھӣ��Ӷ���һ���������ջ 
    while(sta.size())
    {
        int temp=sta.top();
        sta.pop();
        
        // 2.1 ��ջ�е����Ľ���Ѿ����ʹ�����ֱ�Ӻ��Լ���
        if(visit[temp])   
        continue;
        
        // 2.2 ��ջ�е����Ľ��δ�����ʹ�������������ý�㣬Ȼ�󽫸ý��δ���ʹ����ھӽ����ջ 
        else
        {
        	res.push_back(temp);
        	visit[temp]=true;

        	for(int i=0;i<size;i++)
        	{
            	if(data[temp][i]!=-1&&!visit[i])
            	sta.push(i);
        	}
		}
    }

    // 3. �������ձ������
    return res;
}

/*
 * dijkstra: dijkstra�㷨��� 
*/
vector<int> Graph::dijkstra(int start)
{
	vector<int> res;
	
	// 0. ������������ͷǷ�����
	if(start<0||size==0||start>=size)
	return res;
	
	// 1. ��ʼ���������ϣ���һ��bool����ʵ�֣�ֵΪtrue�Ľ�����ڼ���S��ֵΪfalse�Ľ�����뼯��N����ʼ������S�������start������N���������������
	bool visit[size];
	memset(visit, 0, size*sizeof(bool));
	visit[start]=true;      // ������ʼ���ı��Ϊ1�������ڼ���S������������ڼ���N 
	
	// 2. ��ʼ��������㵽��ʼ���start�ľ��룬��ʼ�����ھӽ�㵽start�ľ������ֱ�Ӿ��룬���ھӽ�㵽start�ľ�������Ϊ�����
	// ��ע: ���´����У���ʹ��-1��ʾ�������� 
	int dist[size];
	for(int i=0;i<size;i++)
	{
		dist[i]=data[start][i];
	}
	
	for(int i=0;i<size;i++)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	
	// 3. ѭ���������²���ֱ������NΪ��: 
	// (1). �Ӽ���N��ѡ�����start����dist[i]��С�Ľ��m
	// (2). ���ý��m�Ӽ���N��ɾ�������뼯��S��
	// (3). Ȼ����¼���N�еĽ��k����ʼ���start�ľ���: dist[k]=min(dist[k], data[k][m]+dist[m])
	for(int i=0;i<size-1;i++)   // ����ѭ��ֻ�����size-1�ν�������Ϊ����N�еĽ����ĿΪsize-1 
	{
		// 3.1 	����dist����С������visit[m]==false�Ľ��m 
		int m=0;
		int min=INT_MAX;
		
		for(int k=0;k<size;k++)
		{
			if(visit[k]==false&&dist[k]!=-1&&dist[k]<min)   // ע��-1��ʾ���ɴ�/����� 
			{
				min=dist[k];
				m=i;
			}
		}
		
		// 3.2 �����m�Ӽ���N��ɾ�������뼯��S��
		visit[m]=true;
		
		// 3.3 ���¼���N��ʣ�µĽ��u����ʼ��start�ľ���: dist[u]=min(dist[u], data[u][m]+dist[m])
		for(int u=0;u<size;u++)
		{
			if(visit[u]==false)
			{
				// ��Ҫ�ر�ע��data[u][m]==-1��ʾ���ɴ����ʱ(data[u][m]+dist[m])�Ľ����Ȼ�ǲ��ɴ���ͬ��Ϊ-1 
				// ֮����ʹ��-1��ʾ���ɴ�����߼�ʵ�ֵĸ����ԣ���Ҫ������Ϊcppû�����������ܹ��ܺõر�ʾ����� 
				int temp=(data[u][m]==-1)?-1:(data[u][m]+dist[m]);
				
				if(temp!=-1&&temp<dist[u])
				dist[u]=temp;
			}
		}
	}
	
	// 4. ��dist�����е�ֵ����װ��vector���͵�res��������Ϊ���ս��
	for(int i=0;i<size;i++) 
	{
		res.push_back(dist[i]);
	}
	
	return res;
}

/*
 * ~Graph: ��������
*/
Graph::~Graph()
{
    if(data!=NULL)
    {
        for(int i=0;i<size;i++)
        {
            delete [] data[i];
        }
        delete [] data;
    }
}



