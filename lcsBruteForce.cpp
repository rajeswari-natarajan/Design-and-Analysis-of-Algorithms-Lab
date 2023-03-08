# include <iostream>
# include <string.h>
# define maxi 100
using namespace std;
char x[maxi],y[maxi], chk[maxi], seq[maxi];
static int pp;
int lcs( char x[], char y[], int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m-1] == y[n-1])
       return 1 + lcs(x, y, m-1, n-1);
	else
        return max(lcs(x, y, m, n-1),lcs(x, y, m-1, n));
}
void printSeq( char x[], char y[], int m, int n )
{
    while (m > 0 && n > 0)
    {
		if (x[m-1] == y[n-1])
    	{	
   			seq[pp]=x[m-1];
   			m--;
   			n--;
    		pp++;
    	}
   		else if (lcs(x, y, m, n-1) > lcs(x, y, m-1, n))
   			n--;
   		else
   			m--;
	}
}

int main()
{
	cout<<"Sequence X : ";	
	cin>>x;
	cout<<"Sequence Y : ";
	cin>>y;
	int i;
	for (i=0;i<maxi;i++)
		seq[i]=' ';
	int len=lcs(x,y,strlen(x), strlen(y));
	printSeq(x,y,strlen(x), strlen(y));
	cout<<"Length : "<<len<<endl;
	cout<<"Longest common subsequence :";
	for (i=len-1;i>=0;i--)
		cout<<seq[i];
	return 0;
	
}
