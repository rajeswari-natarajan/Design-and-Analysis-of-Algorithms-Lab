// The Knuth-Morris-Pratt algorithm - CLRS Textbook
# include <iostream>
# include <math.h>
# include <string.h>
# define max 50
/*Sample Input 
T - aabbabbabbaabba
P - bba
Expected Output: 
Prefix Array of  bba
0       1       0
Pattern occurs with shift 2
Pattern occurs with shift 5
Pattern occurs with shift 8
Pattern occurs with shift 12
*/
using namespace std;
char T[max],P[max];
static int pi[max];
int n,m;

void prefun()
{
	int k,q;
	m=strlen(P);
	pi[1]=0;
	k=0;
	for (q=2;q<m;q++)
	{
		while ((k>0) && P[k+1]!=P[q])
			k=pi[k];
		if (P[k+1]==P[q])
			k=k+1;
		pi[q]=k;
	//	cout<<q<<"   "<<pi[q]<<endl;
	}
	cout<<"Prefix Array of "<<P<<endl;
	for (q=1;q<m;q++)
		cout<<pi[q]<<"\t";
	cout<<endl;
}
void kmp(char T[], char P[])
{
	int i,q;
	prefun();
	q=0;
	for (i=1;i<=n;i++)
	{
		while ((q>0) && (P[q+1] !=T[i]))
			q=pi[q];
		if (P[q+1] ==T[i])
			q=q+1;
		//cout<<q<<m<<endl;
		if (q+1==m)
		{
			cout<<"Pattern occurs with shift "<<i-m+1<<endl;
			q=pi[q];
		}
	}
		
}

int main()
{
	int i;
	cout<<"The Knuth-Morris-Pratt algorithm \n";
	cout<<"Pattern T ?";
	cin>>T;
	cout<<"Pattern P?";
	cin>>P;
	n=strlen(T);
	m=strlen(P);
	cout<<"Lengths of the Strings T and P are "<<n<<" and "<<m<<" respectively \n";
	for (i=n;i>=1;i--) // T to index from 1 to n
		T[i]=T[i-1];
	T[0]=' ';
	
	for (i=m;i>=1;i--) // P to index from 1 to m
		P[i]=P[i-1];
	P[0]=' ';

	for (i=1;i<=max;i++)
		pi[i]=-1;
	kmp(T,P);
	return 0;
}
	

