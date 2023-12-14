# include <iostream>
# include <stdlib.h>
using namespace std;
static int s;
int a[30];
void merge(int [],int,int,int);
//void mergesort(int a[], int l, int h);
void mergesort(int a[], int p, int r) 
{ 
	if (p < r) 
	{ 
		int q = (p+r)/2; 
		mergesort(a, p, q); 		
		mergesort(a, q+1, r); 	
		merge(a, p, q, r); 	
	} 
} 
void merge(int a[], int p, int q, int r) 		//MERGE FUNCTION
{ 
	int i, j, k; 
	int n1 = q - p + 1; 
	int n2 = r - q; 
	int L[n1+1], R[n2+1]; 
	for (i = 1; i <= n1; i++) 
		L[i] = a[p + i-1]; 
	L[n1+1]=5000;
	for (j = 1; j <= n2; j++) 
		R[j] = a[q + j]; 
	R[n2+1]=5000;
	i = 1; 
	j = 1;  
	for (k=	p;k<=r;k++) 
	{
		if (L[i] <= R[j]) 
		{ 
			a[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			a[k] = R[j]; 
			j++; 
		} 	 
		s++;
	}
} 

int main() 
{ 
	int n,i;
	cout<<"Total numbers to sort\n";
	cin>>n;
	cout<<"Enter the numbers \n";
	for (i=1;i<=n;i++)
		cin>>a[i];
	mergesort(a, 1, n); 
	for (i=1;i<=n;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
	cout<<"Total number of swaps :"<<s;

	return 0; 
} 

