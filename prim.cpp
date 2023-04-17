//Prims Algorithm : CLRS Text book
// Sample Input: nv=9
// Edges (u,v,wt): (1,2,4),(1,8,8),(2,8,11),(2,3,8), (3,9,2),(3,6,4), 
// (3,4,7), (4,6,14),(4,5,9),(5,6,10),(6,7,2),(7,8,1), (7,9,6), (8,9,7)
// Total no. of edges : 14
// Expected output
/* Edges in Minimum Spanning Tree
(1,2) - 4
(2,3) - 8
(3,4) - 7
(4,5) - 9
(3,6) - 4
(6,7) - 2
(7,8) - 1
(3,9) - 2
Total Weight of MST :37 */



# include <iostream>
# define inf 1000
# define max 50
using namespace std;
int pi[max],nv,ne,key[max],nq;
int w[max][max];
bool visit[max];
int extractmin()
{
	int m=inf;
	int ind;
	for (int u = 1;u<=nv;u++)
		if (visit[u]==false && key[u]<m)
		{
			m=key[u];
			ind=u;
		}
	return ind;
}
void mstprim(int r)
{
	int i,j,u,v;
	for (u=1;u<=nv;u++)
	{
		key[u]=inf;
		visit[u]=false;
		pi[u]=-1;
	}	
	key[r]=0;
	for (i=1;i<=nv;i++)
	{
		u=extractmin();
		visit[u]=true;
		for (v=1;v<=nv;v++)
		{
			if (w[u][v]!=inf && visit[v]==false && w[u][v]<key[v])
				{	
					pi[v]=u;
					key[v]=w[u][v];
				}	
		}
	}
}
int main()
{
	int i,f,t,wt,j;
	cout<<"Minimum Spanning Tree - Prim's Algorithm \n";
	cout<<"No. of vertices and edges \n";
	cin>>nv>>ne;
	for (i=1;i<=nv;i++)
		for (j=1;j<=nv;j++)
			w[i][j]=inf;
	for (i=1;i<=ne;i++)
	{
		cout<<"Edge "<<i<<endl;
		cout<<"From and To"<<endl;
		cin>>f>>t;
		cout<<"Weight \n";
		cin>>wt;
		w[f][t]=w[t][f]=wt;
	}	
	cout<<"Source vertex ";
	int r;
	cin>>r;
	mstprim(r);
	cout<<"Edges in Minimum Spanning Tree \n";	
	int sum=0;
    for (i = 1; i<=nv; i++)
    	if (i!=r)
    	{
        	cout<<"("<<pi[i]<<","<<i<<") - "<<w[i][pi[i]]<<endl;
        	sum=sum + w[i][pi[i]];
    	}
    cout<<"Total Weight of MST :"<<sum<<endl;
	return 0;
}





















