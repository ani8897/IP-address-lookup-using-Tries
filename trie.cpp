# include "trie.h"
typedef pair<string,string> pos;

trie::trie()
{
	head=NULL;
}

trie::~trie()
{
	delete head;
}

void trie::insert(vector<int> v, int count, pos d)
{
	int l;
	if(head==NULL)				//------------First insert-----------------
		head = new node;

	if(count == 0)				//-------------If Subnet Mask is 0.0.0.0-----------------
	{
		head->isend = true;
		head->data = d;
	}
	node* current=head;
	for(int i=0;i<count;i++)
	{
		l = v[i];
		if(current->child[l]==NULL) // ------------ If no child exists then create it!-----------------
			current->child[l]= new node;

		if(i==count-1) 				// ---------------Store the IP address Information in this node as it is the leaf node---------
		{
			current->child[l]->isend=true;
			current->child[l]->data = d;
		}
		current=current->child[l];			//---------------------Move to the next child-----------
	}
}

pos trie::find(vector<int> v)
{
	pos ans = make_pair("default","");
	int l,flag=0;

	if(head==NULL) return ans;
	if(head->isend) ans = head->data;

	node* current=head;
	for(int i=0;i<v.size();i++)
	{
		l=v[i];
		if(current->child[l]!=NULL) 
		{
			if(current->child[l]->isend)		//------- We can find multiple endings in one path, Find the longest one-----
				ans = current->child[l]->data;
			current=current->child[l];
		}
		else {flag=1;break;}		
	} 
	if(flag==1) return ans;

	return ans;
}
