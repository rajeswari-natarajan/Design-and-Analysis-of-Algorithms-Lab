# include <iostream>
# define max 10
# define inf -1000
using namespace std;
float a[max],n;
float s[max];
struct node
{
	float val;
	struct node *next;
};
struct node *b[max];
void print()
{
	int i;
	for (i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}
void read()
{
	int i;
	//a[] = {-5, 8, 9, -6, 10, -15, 3};
	cout<<"No of inputs :";
	cin>>n;
	cout<<"Values ?\n";
	for (i=0;i<n;i++)
		cin>>a[i];
		
}
void printB()
{
	struct node *t;
	int p,i,v=0;
	for (i=0;i<n;i++)
	{
		if (b[i]!=NULL)
		{
			cout<<"\nList["<<i<<"]\n";
		
			for (t=b[i];t!=NULL;t=t->next)
			{
				a[v]=t->val;
				cout<<t->val<<"\t";
				v++;
			}
		}
	}
	cout<<"\nSorted order \n";
	print();
}
void insertionSort(float s[], int n1)
{
	int i, j;
	float key;
	for (i = 1; i < n1; i++)
	{
		key = s[i];
		j = i - 1;

		// Move elements of arr[0..i-1],
		// that are greater than key, to one
		// position ahead of their
		// current position
		while (j >= 0 && s[j] > key)
		{
			s[j + 1] = s[j];
			j = j - 1;
			//s++;
			//cout<<j<<"\t"<<s<<"\n";
		}
		s[j + 1] = key;
	}
}
void clearArray()
{
	for (int i=0;i<max;i++)
		s[i]=-1;
}


void bucSort()
{
	
	struct node *temp, *curr;
	int i,j;
	for (i=0;i<n;i++)
		b[i]=NULL;
	for (i=0;i<n;i++)	
	{
		temp=new node;
		temp->val= a[i];
		temp->next = NULL;
		int p;
		p=n * a[i];
		if (b[p] == NULL)
			b[p]=temp;
		else
			{
				for (curr = b[p];curr->next!=NULL;curr=curr->next);
				curr->next=temp;
			}
	}
	//copy elements of b[i]  in s[] for insertion sort
	struct node *t;
	int tot;
	for (i=0;i<n;i++)
	{
		if (b[i]!=NULL)
		{
			for (t=b[i],j=0;t!=NULL;t=t->next,j++)
				s[j]=t->val;
				//cout<<t->val<<"\t";
			tot=j;
			insertionSort(s,tot);
			for (t=b[i],j=0;t!=NULL;t=t->next,j++)
				t->val=s[j];
			
			clearArray();
		}	
	}
	printB();
}

int main()
{
	read();
	bucSort();
	return 0;
}
