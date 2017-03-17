# include "trie.h"
typedef pair<string,string> pos;

//Convert integer to 8 bit representation
//--------------------------------
vector<int> ConvertTo8Bits(int x){
	vector<int> ret(8);
	int i=7;
	while(x) {
	    if (x&1)
	    	ret[i]=1;
	    else
	    	ret[i]=0;
	    i--;
	    x>>=1;  
	}
  	return ret;
}
//-------------------------------------

//Convert IP address to binary representation
//--------------------------------------
vector<int> ConvertToBinary(string s){
	int n=0;
	for(int i=s.length()-1;i>=0;i--)
	{
		n += pow(10,s.length()-1-i) * ((int) s[i] - 48);
	}
	return ConvertTo8Bits(n);
}
//---------------------------------------

int main(){
	trie t;
	while(1)
	{
		//Parsing
		//----------------------------------------------
		string line;
		getline(cin,line);
		if(line[0]=='d') break;
		if(line[0]=='N') continue;
		int i=0;
		vector<int> NetAdd, NetMask;
		string temp,NetAdds,NetMasks;
		while(line[i]!=' ')
		{
			if(line[i]=='.') 
			{
				vector<int> v=ConvertToBinary(temp);
				NetAdd.insert(NetAdd.end(),v.begin(),v.end());
				temp = "";
			}
			else temp += line[i];
			NetAdds += line[i];
			i++;
		}
		vector<int> v=ConvertToBinary(temp);
		NetAdd.insert(NetAdd.end(),v.begin(),v.end());
		temp="";
		while(line[i]==' ') i++;

		while(line[i]!='\0')
		{
			if(line[i]=='.') 
			{
				vector<int> v=ConvertToBinary(temp);
				NetMask.insert(NetMask.end(),v.begin(),v.end());
				temp = "";
			}
			else if(line[i]!=' ') temp += line[i];
			if(line[i]!=' ')NetMasks += line[i];
			i++;
		}
		v=ConvertToBinary(temp);
		NetMask.insert(NetMask.end(),v.begin(),v.end());

		//--------------------------------------------

		//Inserting into Trie

		int c = count(NetMask.begin(),NetMask.end(),1);
		t.insert(NetAdd, c, make_pair(NetAdds,NetMasks));

		//----------------------------------------------
	}

	int n;
	cin>>n;int j=n;
	while(j>=0)
	{
		// Parsing
		//----------------------------------------------
		string line,temp,IPaddrs;
		vector<int> IPaddr;
		getline(cin,line);
		if(j!=n)
		{
			int i=0;
			while(line[i]!='\0')
			{
				if(line[i]=='.') 
				{
					vector<int> v=ConvertToBinary(temp);
					IPaddr.insert(IPaddr.end(),v.begin(),v.end());
					temp = "";
				}
				else if(line[i]!=' ')temp += line[i];
				if(line[i]!=' ') IPaddrs += line[i];
				i++;
			}
			vector<int> v=ConvertToBinary(temp);
			IPaddr.insert(IPaddr.end(),v.begin(),v.end());

		//-----------------------------------------------

		//Finding in a trie;
		//------------------------------------------------
			pos c = t.find(IPaddr);
			if(c.second!="") cout<<IPaddrs<<" "<<c.first<<" "<<c.second<<endl;
			else cout<<IPaddrs<<" "<<c.first<<endl;

		//--------------------------------------------------
		}
		j--;
	}
	

}