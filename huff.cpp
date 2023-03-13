# include <iostream>
# include <queue>
# include <string.h>
using namespace std;
static int s,tot, tf;
class node
{
		public:
			int freq;
			char data;
			int s,total;
			const struct node *left, *right;		
			node(char d, int f = -1)
			{
				 //assign values in the node
				data = d;
      			freq = f;
      			left = NULL;
      			right= NULL;
      		}
      		node(const node *x, const node *y)
      		{
				    data = 0;
      			freq = x->freq + y->freq;
      			left=x;
      			right=y;
      		}
        bool operator< (const node  &a ) const
			  { 
            //< operator performs to find priority in queue
            //cout<<"comparing "<<freq<<" and "<<a.freq<< ":->Comparison : "<<(freq>a.freq)<<endl;
      	    return freq >a.freq;
   		  }
   			
   			void traverse(string code) const
  			{
      			if(left!=NULL)
				    {
					    left->traverse(code+'0'); //add 0 with the code as left child
         	    right->traverse(code+'1'); //add 1 with the code as right child
      			}
	  			  else
		  		  {
     	  		  int i;
				  	  for (i=0;code[i]!='\0';i++);
					    cout << "Data: " << data<< ", Frequency: "<<freq << ", Code: " << code<<". Total  "<<(i-1)*freq<<endl;
     			    tot=tot+(i-1)*freq;
     			    tf=tf+freq;
     		    }
    		  }
};
void huffmanCoding(string str)
{
  priority_queue<node> qu;
  int frequency[256];
  for(int i = 0; i<256; i++)
    frequency[i] = 0; //clear all frequency
  for(int i = 0; i<str.size(); i++)
  		frequency[int(str[i])]++; //increase frequency
  /*for(int i = 0; i<256; i++)
		{
	    		if(frequency[i])
		         cout<<frequency[i]<<endl;
  	}*/
  //cout<<"Construct PQ "<<endl;
  for(int i = 0; i<256; i++)
	{
	   		if(frequency[i])
	         qu.push(node(i, frequency[i]));
  }
  /*for(int i = 0; i<256; i++)
	{
	  		if(frequency[i])
			         cout<<frequency[i]<<endl;
  	}*/
	while(qu.size() >1)
	{
  		struct node *c0 = new node(qu.top()); //get left child and remove from queue
  		qu.pop();
      struct node *c1 = new node(qu.top()); //get right child and remove from queue
      qu.pop();
      qu.push(node(c0, c1)); //add freq of two child and add again in the queue
   }
   cout << "The Huffman Code: "<<endl;
   qu.top().traverse(" "); //traverse the tree to get code
  }
int main()
{
	string str = "engineering"; //arbitray string to get frequency
  huffmanCoding(str);
  cout<<"Compression Percentage : "<<(float)tot/tf;
  return 0;	
}
      
