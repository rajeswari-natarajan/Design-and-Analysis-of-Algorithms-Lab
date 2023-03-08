# include <iostream>
# include <stdlib.h>
# include <math.h>
using namespace std;
int a[100];
# include <iostream>
# include <stdlib.h>
using namespace std;
static int s;
int k=9;
void countsort(int a[],int g[],int n1) 
{ 
	int i,j,c[10],b[n1];
	for (i=0;i<=k;i++)
		c[i]=0;
	for (j=1;j<=n1;j++)		
		c[g[j]]=c[g[j]]+1;
	for (i=1;i<=k;i++)		
		c[i]=c[i]+c[i-1];
	for (j=n1;j>=1;j--)		
	{
		b[c[g[j]]]=a[j];
		c[g[j]]=c[g[j]]-1;
	}
	for (i=1;i<=n1;i++)
		a[i]=b[i];

	for (i=1;i<=n1;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
} 
int main() 
{ 
	int g[100],i,k,j,k1,k2,m,n,max=0,d=0,r,p,z;
	cout<<"Total Numbers ?\n";
	cin>>n;
	cout<<"Numbers to be sorted \n";
	for (i=1;i<=n;i++)
		cin>>a[i];
	for (i=1;i<=n;i++)
		if (max<a[i])
			max=a[i];
	while (max>0)
	{
		max=max/10;
		d++;		
	}
	p=0;
	for (i=1;i<=d;i++)
	{
		for (k=1;k<=n;k++)
			g[k]=(a[k]/(int)pow(10,p))%10;
		cout<<"Sorting in "<<i-1<<" place\n";
		countsort(a,g,n);
		p++;
	}
	cout<<"Numbers in ascending order \n";
	for (z=1;z<=n;z++)
		cout<<a[z]<<"\t";
	cout<<"\n";
		
	return 0;
}	
