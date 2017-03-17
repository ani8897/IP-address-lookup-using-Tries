# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <cmath>
using namespace std;
typedef pair<string,string> pos;

class trie
{
	struct node
	{
		pos data;
		bool isend;
		node* child[1];

		node()
		{
			data = make_pair("","");
			isend = false;
			child[0]=NULL;
			child[1]=NULL; 
		}
	};
	node* head;
	
	public:
		trie();
		~trie();
		void insert(vector<int> v,int count ,pos d);
		pos find(vector<int> v);
};