# include <iostream>
# define inf 100000
# define max 100
using namespace std;
int t, s[max][max];
void printpar(int s[][max], int i,int j)
{
	if (i==j)
	{
		cout<<"A"<<i;
		return;
	}
	else
	{
		cout<<"(";
		printpar(s,i,s[i][j]);
		printpar(s,s[i][j]+1,j);
		cout<<")";
	}
}

void matchainOrder(int p[],int plength)
{
	int n,i,j,l,k;
	n=plength-1;
	long int m[max][max],q;
	for (i=1;i<=n;i++)
		m[i][i]=0;
	for (l=2;l<=n;l++)
		for (i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=inf;
			for (k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if (q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	cout<<endl;
	cout<<" Table M:"<<endl;
	for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
				cout<<m[i][j]<<"\t";
			cout<<endl;
		}		
	cout<<"Minimum Number of Scalar Multiplications :"<<m[1][n]<<endl;
	cout<<" Table S: "<<endl;
	for (i=1;i<=n-1;i++)
		{
			for (j=2;j<=n;j++)
				cout<<s[i][j]<<" ";
			cout<<endl;
		}		
		printpar(s,1,plength-1);
}


	
int main()
{
	int p[max];
	int i;
	cout<<"Total Number of Matrices ?";
	cin>>t;
	cout<<"\n Enter "<<t<<" dimensions ";
	for (i=0;i<=t;i++)
		cin>>p[i];
	matchainOrder(p,t+1);
}
		


