// Minimum Spanning Tree - Kruskal's method
// Sample Input: nv=9
// Edges (u,v,wt): (1,2,4),(1,8,8),(2,8,11),(2,3,8), (3,9,2),(3,6,4), 
// (3,4,7), (4,6,14),(4,5,9),(5,6,10),(6,7,2),(7,8,1), (7,9,6), (8,9,7)
// Total no. of edges : 14
// Expected output
/*Edges in Minimum Spanning Tree
(7,8) : 1
(6,7) : 2
(3,9) : 2
(1,2) : 4
(3,6) : 4
(3,4) : 7
(1,8) : 8
(4,5) : 9
Total Weight of the Minimum Spanning Tree       37
--------------------------------
*/

# include <iostream>
# define max 50
using namespace std;
int p[max],rank[max],sum,nv,ne;
struct edge
{
	int u,v,wt;
}e[max],A[max];

void makeset(int x)
{
	p[x]=x;
	rank[x]=0;
}
int findset(int x)
{
	if (x!=p[x])
		p[x]=findset(p[x]);
	return p[x];
}
void link(int x,int y)
{
	if (rank[x] > rank[y])
		p[y]=x;
	else
	{
		p[x]=y;
		if (rank[x]==rank[y])
			rank[y]=rank[y]+1;
	}
}
void myunion(int x, int y)
{
	link(findset(x),findset(y));
}
int main()
{
	int i,j,u,v,w,f,t;
	cout<<"Kruskal's MST\n";
	cout<<"Number of vertices and edges \n";
	cin>>nv>>ne;
	cout<<"Edges \n";
	for (i=1;i<=ne;i++)
	{
		cout<<"Edge "<<i<<" ? "<<endl;
		cin>>f>>t;
		cout<<"Weight "<<endl;
		cin>>w;
		e[i].u=f;
		e[i].v=t;
		e[i].wt=w;
	}
	for (i=1;i<=nv;i++)
		makeset(i);
	for (i=0;i<ne-1;i++)
		for (j=i+1;j<ne;j++)
		{
			if (e[i].wt > e[j].wt)
			{
				struct edge t;
				t.u=e[i].u;
				t.v=e[i].v;
				t.wt=e[i].wt;
				
				e[i].u=e[j].u;
				e[i].v=e[j].v;
				e[i].wt=e[j].wt;
				
				e[j].u=t.u;
				e[j].v=t.v;
				e[j].wt=t.wt;
			}
		}
	j=1;
	for (i=1;i<=ne;i++)
	{
		u=e[i].u;
		v=e[i].v;
		w=e[i].wt;
		if (findset(u) != findset(v))
		{
			A[j].u=u;
			A[j].v=v;
			A[j].wt=w;
			sum+=w;
			j++;
		}
		myunion(u,v);
	}
cout<<"Edges in Minimum Spanning Tree \n";
for (i=1;i<=j-1;i++)
	cout<<"("<<A[i].u<<","<<A[i].v<<") : "<<A[i].wt<<endl;
cout<<"Total Weight of the Minimum Spanning Tree \t"<<sum;
}


