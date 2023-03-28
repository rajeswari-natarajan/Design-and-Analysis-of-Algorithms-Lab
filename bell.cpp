# include <iostream>
#include <bits/stdc++.h>
# define inf 1000
# define max 100
using namespace std;
// Run time input
struct edge
{
	int u,v,wt;
}e[max];
// Global input
/*struct edge
{
	int u,v,wt;
}e[10]={{2,3,5},{2,4,8},{2,5,-4},{3,2,-2},{4,3,-3},{4,5,9},{5,3,7},{5,1,2},{1,2,6},{1,4,7}};*/
int d[max],w[max][max],s,nv,ne,pi[max];

int main()
{
	int f,t,weight,i,j,u,v;
	cout<<"Bellman Ford Algorithm"<<endl;
	// Initialize 
	cout<<"Number of Vertices and Edges "<<endl;
	cin>>nv>>ne;
	cout<<"Source Vertex "<<endl;
	cin>>s;
	for (i=1;i<=nv;i++)
	{
		d[i]=inf;
		pi[i]=-1;
	}
	d[s]=0;
	
	for (i=1;i<=ne;i++)
	{
		// input during run time
		cout<<"Edge "<<i<<" ? "<<endl;
		cin>>f>>t;
		cout<<"Weight "<<endl;
		cin>>weight;
		w[f][t]=weight;
		e[i].u=f;
		e[i].v=t;
		e[i].wt=weight;
		// global input
		/*f=e[i].u;
		t=e[i].v;
		w[f][t]=e[i].wt;*/
	}
	for (i=1;i<=nv;i++)
	{
		for (j=1;j<=ne;j++)
		{
			u=e[j].u;
			v=e[j].v;
			if (d[v]>d[u]+w[u][v])
			{
				d[v]=d[u]+w[u][v];
				pi[v]=u;
			}
		}
	}
	int cycle=0;
	for (j=1;j<=ne;j++)
	{
		u=e[j].u;
		v=e[j].v;
		if (d[v]>d[u]+w[u][v])
		{
			cycle=1;
			break;
		}	
	}
	if (!cycle)
	{
		cout<<"Shortest distance from the vertex "<<s<<" to every other vertices "<<endl;
		for (i=2;i<=nv;i++)
			cout<<i<<"\t"<<d[i]<<endl;
	}
	else
		cout<<"Graph contains negative cycle "<<endl;
	
	return 0;
}

