//Topological Sort : CLRS Text book
# include <iostream>
# define max 50
using namespace std;
int pi[max],nv,ne,dis[max],fin[max];
int adj[max][max];
static int time;
char c[max];
// sample input : Vertices: {1,2,3,4,5,6,7,8,9} , Edges : { (1,2),(1,4),(2,3),(4,3),(6,7),(6,9),(7,4),(7,9),(8,9)}
// Expected output: 8,6,7,9,5,1,4,2,3
struct node
{
	int v;
	struct node *next;
}*head=NULL;
void insert(int v)
{
	struct node *temp;
	temp=new node;
	temp->v=v;
	temp->next=NULL;
	if (head!=NULL)
		temp->next=head;
	head=temp;
}
void topoSort()
{
	struct node *temp;
	cout<<"Linear ordering \n";
	for (temp=head;temp!=NULL;temp=temp->next)
		cout<<temp->v<<"-->";
	cout<<"NULL";
}
void dfsvisit(int u)
{
	int v;
	cout<<u<<"\t";
	time=time+1;
	dis[u]=time;
	c[u]='g';
	for (v=1;v<=nv;v++)
	{
		if (adj[u][v])
		{	
			if (c[v]=='w')
			{
				pi[u]=u;
				dfsvisit(v);
			}
		}
	}
	c[u]='b';
	time=time+1;
	fin[u]=time;
	insert(u);
}
void dfs()
{
	int u,i;
	for (u=1;u<=nv;u++)
	{
		c[u]='w';
		pi[u]=-1;
	}
	time = 0;
	for (i=1;i<=nv;i++)
	{
		if (c[i]=='w')
			dfsvisit(i);
	}
}

void init()
{
	int i,j;
	for (i=1;i<=nv;i++)
		for (j=1;j<=ne;j++)
			adj[i][j]=0;
	
	for (i=1;i<=max;i++)
	{
		c[i]=' ';
		dis[i]=-1;
		fin[i]=-1;
	}
}
int main()
{
	int i,f,t;
	cout<<"Topological Sort \n";
	cout<<"No. of vertices and edges \n";
	cin>>nv>>ne;
	for (i=1;i<=ne;i++)
	{
		cout<<"Edge "<<i<<endl;
		cout<<"From and To"<<endl;
		cin>>f>>t;
		adj[f][t]=1;
	}	
	cout<<"\nDepth First Search \n";
	dfs();
	cout<<"\nDiscovery time and Finish Times \n";
	for (i=1;i<=nv;i++)
		cout<<"Vertex "<<i<<" : "<<dis[i]<<"/"<<fin[i]<<endl;
	topoSort();
	return 0;
}





















