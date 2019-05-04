#include <iostream>
#include <string> 
#include <vector> 
#include <stack>
#include <queue>
#include <cstring>  
#include <algorithm>

using namespace std;

/*
* Graph: ����ͼ��
*/
class Graph
{
    public:

    // 1. ���캯��
    Graph();                                      // Ĭ�Ϲ��캯��
    Graph(int isize);                              // ��ʼ��һ������size������ͼ��ͼ��Ĭ��û���κεı� 
    Graph(const vector<vector<int> > &lis);       // ���ڽӾ�������(vector)����ͼ��ͼ�еĽ�����α�����Ϊ0,1,...,size-1
    Graph(const int *lis, int isize);             // ���ڽӾ������鹹��ͼ

    // 2. ��������
    Graph(const Graph &gra);                      // �������캯��
    Graph & operator = (const Graph &other);      // ������ֵ�����

    // 3. ���������빦��
    vector<int> bfs(int start);                   // ͼ�Ĺ����������
    vector<int> dfs(int start);                   // ͼ�������������

    vector<int> dijkstra(int start);              // ����ĳ����㵽�������������������·������: dijkstra�㷨
    vector<int> floyd(int start);                 // ����ĳ����㵽�������������������·������: floyd�㷨

    Graph prim();                                 // ������С������: prim�㷨
    Graph kruskkal();                             // ������С������: krustkal�㷨

    void print();                                 // ���ͼ���ڽӱ� 

    // 4. ��������
    ~Graph();                                     // ��������

    private:
    int **data;                                   // ͼ���ڽӾ���: ����Ԫ��ֵΪ-1��ʾ�������֮�䲻���ڣ�֮��ľ���Ϊ����� 
    int size;                                     // ͼ�Ĵ�С
    
    bool hasloop(Graph gra, int u, int v, int len);  // �жϸ�����ͼ����һ����u,v���Ƿ��л� 
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
 * Graph: ����̶���С���ޱ�ͼ 
*/
Graph::Graph(int isize)
{
	// 0. �����ڽӱ��С
    size=isize;

    // 1. �����ڽӱ�ռ�
    data=new int *[size];
    
    for(int i=0;i<size;i++)
    {
        data[i]=new int[size];
    }
    
    // 2. ��ʼ���ڽӱ�Ϊ��������û�бߵ�ͼ
	for(int i=0;i<size;i++) 
	{
		for(int k=0;k<size;k++)
		{
			if(i==k)
			data[i][k]=0;
			else
			data[i][k]=-1;
		}
	}
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
 * Graph: ���ڽӾ������鹹��ͼ 
*/
Graph::Graph(const int *lis, int isize)
{
	size=isize;
	
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
            // �����ʹ��һά����ָ��lis�����ж�ά����Ĵ��Σ�ʵ����lisָ��ָ���ά�������Ԫ�أ���Ϊʹ�õ���һάָ�룬��˱���ʹ��lis[i*size+k]������lis[i][k] 
			data[i][k]=lis[i*size+k];
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
 * dijkstra: dijkstra�㷨��������С����·�� 
 * note: ��ΪC++������û�����õ����û�����ʵ���������˱���ʹ�úܶ༼������֤ʵ���������� 
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
	// ��ע: ���´����У���ʹ��INT_MAX�滻-1��ʾ�������� 
	int dist[size];
	for(int i=0;i<size;i++)
	{
		if(data[start][i]==-1)
		dist[i]=INT_MAX;
		else
		dist[i]=data[start][i];
	}
	
	// 3. ѭ���������²���ֱ������NΪ��: 
	// (1). �Ӽ���N��ѡ�����start����dist[i]��С�Ľ��m
	// (2). ���ý��m�Ӽ���N��ɾ�������뼯��S��
	// (3). Ȼ����¼���N�еĽ��k����ʼ���start�ľ���: dist[k]=min(dist[k], data[k][m]+dist[m])
	for(int i=0;i<size-1;i++)   // ����ѭ��ֻ�����size-1�ν�������Ϊ����N�еĽ����ĿΪsize-1 
	{
		// 3.1 	����dist����С������visit[m]==false�Ľ��m 
		int m=-1;
		int min=INT_MAX;
		
		for(int k=0;k<size;k++)
		{
			if(visit[k]==false&&dist[k]<=min) 
			{
				min=dist[k];
				m=k;
			}
		}
		
		// 3.2 �����m�Ӽ���N��ɾ�������뼯��S��
		visit[m]=true;
		
		// 3.3 ���¼���N��ʣ�µĽ��u����ʼ��start�ľ���: dist[u]=min(dist[u], data[u][m]+dist[m])
		for(int u=0;u<size;u++)
		{ 
			if(visit[u]==false)
			{
				// ��Ҫ�ر�ע��data[u][m]==INT_MAX��ʾ���ɴ����ʱ(data[u][m]+dist[m])�Ľ����Ȼ�ǲ��ɴ���ͬ��ΪINT_MAX
				// �ر�أ�INT_MAX���ܲ�����ֵ���㣬����ᵼ����� 
				int temp=(data[u][m]==-1)?INT_MAX:(data[u][m]+dist[m]);   // ע��data[u][m]�е������������-1��ʾ�ģ��� 
				
				if(temp<dist[u]) 
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
 * floyd: floyd�㷨��������С����·�� 
 * note: dijkstra��floyd�㷨����ͼ��������·���ĺ����㷨����������������ԭ�� 
*/
vector<int> Graph::floyd(int start)
{
	// floyd�㷨������˼��ǳ��򵥣�����Ĺ�ʽ������: data[i][j]=min(data[i][m]+data[m][j], data[i][j])��ֻ���ÿһ�����mӦ��������ʽ��һֱȡ��Сֵ�����ռ�����ý��i�ͽ��j֮�����̾��� 
	vector<int> res;
	int copy[size][size];
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(data[i][j]==-1)
			copy[i][j]=INT_MAX;
			else
			copy[i][j]=data[i][j];
		}
	}
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			for(int m=0;m<size;m++)
			{
				int temp=(copy[i][m]==INT_MAX||copy[m][j]==INT_MAX)?INT_MAX:(copy[i][m]+copy[m][j]);
				
				if(temp<copy[i][j])
				copy[i][j]=temp;
			}
		}
	}
	
	for(int i=0;i<size;i++)
	{
		res.push_back(copy[start][i]);
	}
	
	return res;
}

/*
 * prim: ������С��������prim�㷨 
 * note: prim�㷨�ĺ���˼·��dijkstra�㷨�ǳ����ƣ�������ʾ:
 *	     1. ������������S��N����ʼ��S����ͼ�е�����һ�����u����ʼ��N����ͼ�е��������
 *	     2. ѭ���������²���ֱ������Ϊ��Ϊֹ�����ȴӼ���N��ѡ��һ��������S������̵Ľ��u��Ȼ�󽫸ý��u�Ͷ�Ӧ�ı߼��뼯���У������¼���N�и������i������S�ľ���dist[i]�����¹�ʽΪ: dist[i]=min(dist[i], data[i][u])
 * 		 ��ע: ���u������S����̾��붨��Ϊ���u������S�и������ľ������Сֵ
*/
Graph Graph::prim()
{	
	// 0. �����������
	if(!size) 
	return (*this);
	
	// 1. ��ʼ�����ͼ���ڽӱ�
	int res[size][size];
	
	for(int i=0;i<size;i++)
	{
		for(int k=0;k<size;k++)
		{
			if(i==k)
			res[i][k]=0;
			else
			res[i][k]=-1;
		}
	}
	
	// 2. ��ʼ����������S��N��ѡ����0���뼯��S�����������뼯��N
	bool visit[size]; 
	memset(visit, 0, size*sizeof(bool));
	visit[0]=true;
	
	// 3. ��ʼ������N�и�����㵽����S����̾��� 
	int dist[size];     // ��¼����N�и�����㵽����S����̾��� 
	int node[size];     // ��¼����N�и������ȡ��̾����S�еĵ� 
	
	for(int i=0;i<size;i++)
	{
		if(data[i][0]==-1)
		{
			dist[i]=INT_MAX;
			node[i]=-1;
		}
		else
		{
			dist[i]=data[i][0];
			node[i]=0;
		}
	}
	
	// 4. ѭ���������²���ֱ������NΪ��: �Ӽ���N��ѡ��һ��������S�ľ�������Ľ��u�������u�Ӽ���N��ɾ�������뼯��S��������Ӧ�ı߼�����С��������������¸��¼���N�еĸ�����㵽����S�ľ��룬�����¶�Ӧ��ȡ����С�����S�еĽ�� 
	for(int i=0;i<size-1;i++)
	{
		int u, v;
		int min=INT_MAX;
		
		for(int k=0;k<size;k++)    // �Ӽ���N���ҳ�������S��������Ľ�� 
		{
			if(!visit[k]&&dist[k]<=min)
			{
				min=dist[k];
				u=k;
				v=node[k];
			}
		}
		
		visit[u]=true;            // �����u�Ӽ���N��ɾ�������뼯��S 
		
		res[u][v]=dist[u];        // ����u-v�������ڽӾ�����
		res[v][u]=dist[u];        // ע�⣬��Ҫ����v-u�������ڽӾ����� (ʵ���Ͼ���ͬһ����) 
		
		for(int k=0;k<size;k++)   // ���¼���N�еĸ������k������S�ľ���dist[k]���Լ���Ӧ��S�еĽ��node[k]�����¹�ʽΪ: dist[k]=min(dist[k], data[k][u]), node[k]=(data[k][u]<dist[k])?u:node[k]
		{
			int temp=(data[k][u]==-1)?INT_MAX:data[k][u];   // ע�����ڽӾ�������ʹ��-1����ʾ�����ģ��뱾�㷨�еĹ涨�������� 
			
			if(temp<dist[k])
			{
				dist[k]=temp;
				node[k]=u;
			}
		}
	}
	
	Graph result((const int *)res, size);
	return result;
}

/*
 * kruskkal: ������С��������kruskkal�㷨 
 * note: ��prim�㷨�к��Ĳ�����: ����Sװ���Ѿ��������Ľ�㣬Ȼ�󽫾��뼯��S����Ľ����뼯��S����kruskkal�㷨ʹ��������һ��˼��: �ڼ���S��װ�������ıߣ�ÿ�ν���̾����һ���߼��뼯��S�����ұ�֤����󼯺�S�в�������· 
 *		 ������ԣ�kruskkal�㷨�Ĳ���������ʾ: 
 *       1. ������������S��N����ʼ������Sװ��ԭͼ����̵�һ���ߣ���ʼ������N����ԭͼ�е�������
 *       2. ѭ���������²���ֱ������NΪ��ʱֹͣ���Ӽ���N��ѡ����̵����ܱ�֤���뼯��S�󲻻�������ıߣ����ñߴӼ���N��ɾ�������뼯��S
*/
Graph Graph::kruskkal()
{
	// 0. �����ʾͼ�ıߵ��Զ������ݽṹ
	struct Edge
	{
		Edge(int ix, int iy, int ilen):x(ix), y(iy), len(ilen)
		{
		}
		
		int x;     // �˵�1 
		int y;	   // �˵�2 
		int len;   // �߳� 
	};
	
	Graph res(size);   // ����һ���͵�ǰͼ��С��ͬ��ͼ����ͼ��Ϊ���յ���С������ 
	
	// 1. ��ʼ�����бߵ��б�
	vector<Edge> edge;
	for(int i=0;i<size;i++)
	{
		for(int k=0;k<i+1;k++)    // ע��: k<i+1��Ŀ���Ǳ�֤�ų��ظ��ߣ�����u-v��v-u��ͬһ���ߣ�ֻ��Ҫ��¼����һ������ 
		{
			if(data[i][k]!=-1&&data[i][k]!=0)   // �ų��������ı߳����ų������ڵıߣ������ڵı����ڽӱ���ֵΪ-1�� 
			edge.push_back(Edge(i,k,data[i][k]));
		}
	}
	
	// 2. ���ձ߳���С������б�������� 
	sort(edge.begin(),edge.end(),[](const Edge &a, const Edge &b) -> bool { return a.len<b.len; });
	
	// 3. ��ʼ������S�ͼ���N������S��ʼ����½�������̵ıߣ�����N����������
	bool visit[edge.size()];
	memset(visit, 0, edge.size()*sizeof(bool));
	
	visit[0]=true;     // ����̵ı߼��뼯��S�������ı߼��뼯��N, visit[i]=true������edge[i]�ڼ���S�У������ڼ���N�� 
	res.data[edge[0].x][edge[0].y]=edge[0].len;       // ������S�еı�д����ͼ�� 
	res.data[edge[0].y][edge[0].x]=edge[0].len; 
	
	// 4. ѭ���������²���ֱ������S������(n-1)����ʱֹͣ���Ӽ���N��ѡ����̵����ܱ�֤���뼯��S�󲻻�������ıߣ����ñߴӼ���N��ɾ�������뼯��S
	int count=1;      // ����S�������ı���
	
	for(int i=1;i<edge.size();i++)
	{
		if(count==size-1)
		break;
		
		if(!hasloop(res, edge[i].x, edge[i].y, edge[i].len))   // ������edge[i]���뼯��S�в��ᵼ�³��ֻ����򽫸ñ߼��뼯��S 
		{
			count+=1;
			visit[i]=true;   // �����ϲ����ֻ��ıߴӼ���N��ɾ���������뼯��S 
			
			res.data[edge[i].x][edge[i].y]=edge[i].len;       // ���¼��뼯��S�ı�д����ͼ�� 
			res.data[edge[i].y][edge[i].x]=edge[i].len; 
		}
	}
	
	return res;
}

/*
 * hasloop: �ж�ͼ�м���һ���ߺ��Ƿ������ 
 * note: �ж�ͼ���Ƿ���ڻ��ķ����ǳ��򵥣�ֻ��Ҫ����������ȱ�����������������з������Ѿ����ʹ��Ľ�㣬���ͼ�бض����ڻ� 
*/
bool Graph::hasloop(Graph gra, int u, int v, int len)
{
	gra.data[u][v]=len;
	gra.data[v][u]=len;
	
	stack<int> sta;
    bool visit[gra.size];    // ���ڼ�¼��Ӧ����Ƿ��Ѿ������ʹ�������
    memset(visit, 0, (gra.size)*sizeof(bool));
    sta.push(0);
    
    while(sta.size())
    {
        int temp=sta.top();
        sta.pop();
        
        // ��ջ�е����Ľ���Ѿ����ʹ�����˵��ͼ�д��ڻ� 
        if(visit[temp])   
        {
        	return true;
		}
        else
        {
        	visit[temp]=true;

        	for(int i=0;i<size;i++)
        	{
            	if(gra.data[temp][i]!=-1&&!visit[i])
            	sta.push(i);
        	}
		}
    }
    
    return false;	
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

 
