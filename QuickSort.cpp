# include <iostream>
# include <stdlib.h>
using namespace std;
static int s;
int partition(int a[], int p, int r)
{
	int j,x,t,i;
	x=a[r];
	i=p-1;
	for (j=p;p<r;p++)
		if (a[i]<x)
		{
			t=a[i+1];
			a[i+1]=a[j];
			a[j]=t;
			s++;
		}
	return i+1;
}
void quick(int a[],int p,int r)
{
	int q;
	if (p<r)
	{
		q=partition(a,p,r);
		quick(a,p,q-1);
		quick(a,q+1,r);
	}
}



int main()
{
	int n,a[32000],i;



	cout<<"Total numbers to sort\n";
	cin>>n;
	cout<<"Enter the numbers \n";
	for (i=1;i<=n;i++)
		cin>>a[i];
	quick(a,1,n);
	for (i=1;i<=n;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
	cout<<"Total number of swaps :"<<s;
	
	return 0;
}




