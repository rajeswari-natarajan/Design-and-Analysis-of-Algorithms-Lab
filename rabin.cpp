// Rabin Karp Algorithm - Pattern Match
# include <iostream>
# include <math.h>
# include <string.h>
# define max 50

using namespace std;
char T[max],P[max];
void rabin(char T[], char P[],int d,int q)
{
	int h,j,p,t,s,i,n,m;
	h=1;
	n=strlen(T);
	m=strlen(P);
	for (i=0;i<m-1;i++)
		h=(h*d)%q;

	p=0;
	t=0;
	for (i=0;i<m;i++)
	{
		p=(d*p + P[i]) % q;
		t=(d*t + T[i]) % q;
	}
	cout<<"s \t t \t T"<<endl;
	for (s=0;s<=n-m;s++)
	{
		cout<<s<<"\t"<<t<<"\t";
		/*for (j=0;j<m;j++)
			cout<<P[j];
		cout<<"\t";*/
		for (j=0;j<m;j++)
			cout<<T[s+j];
		cout<<endl;
			
		if (p==t)
		{
			for (j=0;j<m;j++)
				if (T[s+j]!=P[j])
					break;
			if (j==m)
				cout<<"Pattern occurs with shift " <<s<<endl;
		}
		if (s<n-m)
		{
			t=(d*(t-T[s]*h) + T[s+m]) %q;
			//cout<<"New t = "<<t<<endl;
		}
		
		if (t<0)
			t=t+q;
	}
}
int main()
{
	int d,q;
	cout<<"Rabin Karp Algorithm \n";
	cout<<"Pattern T ?";
	cin>>T;
	cout<<"Pattern P?";
	cin>>P;
	d=10;
	q=11;
	rabin(T,P,d,q);
	return 0;
}
	

