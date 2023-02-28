# include <iostream>
# include <string.h>
# define max 100
using namespace std;
char x[max],y[max],b[max][max];

void printlcs(char b[][max], char x[], int i, int j)
{
	if (i==0 || j==0)
		return;
	else if (b[i][j] == 'd')
	{
		printlcs(b,x,i-1,j-1);
		cout<<x[i-1];	
	}
	else if (b[i][j] == 'u')
		printlcs(b,x,i-1,j);
	else
		printlcs(b,x,i,j-1);
}



void lcslength(char x[], char y[])
{
	int m,n,i,j;
	int c[max][max];
	m=strlen(x);
	n=strlen(y);
	cout<<"Lengths of X and Y are : "<<m<<" and "<<n<<" respectively\n";
	for (i=0;i<=m;i++)
		c[i][0]=0;
	for (j=0;i<=n;i++)
		c[0][j]=0;
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
			if (x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='d';
			}
			else if (c[i-1][j] >= c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='u';
			}
			else 
			{
				c[i][j]=c[i][j-1];
				b[i][j]='l';
			}
	cout<<"Length Matrix of the Longest Common Subsequence of "<<x<<" and "<<y<<endl;
	for (i=0;i<=m;i++)
	{
		for (j=0;j<=n;j++)
			cout<<c[i][j]<<"\t";
		cout<<"\n";
	}
	cout<<"Longest Common Subsequence : ";
	printlcs(b,x,m,n);
	cout<<endl;
	cout<<"Length : "<<c[m][n];
}


int main()
{
	cout<<"Sequence X : ";	
	cin>>x;
	cout<<"Sequence Y : ";
	cin>>y;
	lcslength(x,y);
	return 0;
	
}
