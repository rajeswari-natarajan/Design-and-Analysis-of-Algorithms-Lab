# include <iostream>
# define max 10
# define inf 1000
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
	for (i=1;i<=n;i++)
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
	for (i=1;i<=n;i++)
		cin>>a[i];
		
}
void printB()
{
	struct node *t;
	int p,i,j=1;
	for (i=0;i<n;i++)
	{
		if (b[i]!=NULL)
		{
			cout<<"\nList["<<i<<"]\n";
			for (t=b[i];t!=NULL;t=t->next)
			{	
				a[j]=t->val;
				j++;
				cout<<t->val<<"\t";
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
	for (i = 1; i <= n1; i++)
	{
		key = s[i];
		j = i - 1;
		while (j >= 0 && s[j] > key)
		{
			s[j + 1] = s[j];
			j = j - 1;
		}
		s[j + 1] = key;
	}
}
void clearArray()
{
	for (int i=1;i<=max;i++)
		s[i]=inf;
}


void bucSort()
{
	
	struct node *temp, *curr;
	int i,j,p;
	for (i=0;i<n;i++)
		b[i]=NULL;
	for (i=1;i<=n;i++)	
	{
		temp=new node;
		temp->val= a[i];
		temp->next = NULL;
		p= n * a[i];
		cout<<p<<endl;
		
		if (b[p] == NULL)
			b[p]=temp;
		else
			{
				for (curr = b[p];curr->next!=NULL;curr=curr->next);
				curr->next=temp;
			}
	}
	cout<<"Before sorting \n";
	//copy elements of b[i]  in s[] for insertion sort
	struct node *t;
	int tot,k;
	for (i=0;i<n;i++)
	{
		if (b[i]!=NULL)
		{
			for (t=b[i],j=1;t!=NULL;t=t->next,++j)
				s[j]=t->val;
			tot=j-1;
			insertionSort(s,tot);
			for (t=b[i],j=1;t!=NULL;t=t->next,j++)
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
