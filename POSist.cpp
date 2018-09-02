#include <bits/stdc++.h>
#include "md5.h"
using namespace std;

int unique_id=0;
vector<string> key_store;

struct node
{
	string time_stamp;
	string data;
	int val;
	int node_Number;
	string nodeId;
	node* down; 
};

node* new_node(string time_stamp,string data,int val)
{
	node* newnode = new node();
	newnode->time_stamp=time_stamp;
	newnode->data = data; 
	newnode->val = val;
	newnode->node_Number = unique_id;
	unique_id+=1;
	newnode->down=NULL;
	return newnode;
}

node* insert(node* root,string time_stamp, string data,int val)
{

	if(root==NULL)
	{
		root=new_node(time_stamp,data,val);
		// cout<<"Went"<<endl;
	}
	else
	{
		root->down = insert(root->down,time_stamp,data,val);
	}

	return root;
}

void print(node* root)
{
	if(root==NULL)
		return;
	else
	{
		cout<<root->time_stamp<<" "<<root->data<<" "<<root->node_Number<<endl;
		print(root->down);
	}
}

void Longets_chain()
{
	cout<<"longest chain of the tree "<<unique_id;
	 
}
int main()
{

	node* GenesisNode=NULL; // Assumption that geneisis Node 
	// GenesisNode= insert(GenesisNode,"22feb","baba",123);
	// GenesisNode=insert(GenesisNode,"11feb","chotu",35);
	// GenesisNode=insert(GenesisNode,"3feb","chotu",135);
	// GenesisNode=insert(GenesisNode,"1feb","chotu",435);

	cout<<"When you are giving input: Press Done if finished in all the field"<<endl;
	string data="";

	while(data!="Done")
	{
		int val;
		string time_stamp;

		cout<<"Enter the time time_stamp: "<<endl;
		cin>>time_stamp;

		cout<<"Enter data: "<<endl;
		cin>> data ;

		cout<<"Enter the time Value: "<<endl;
		cin>>val;
		

		if(data!="Done")
		{
			string key=data;
			for(int i=0;i<key.length();i++)
			{
				if(i%2==0)
					key[i]='%';
			}
			key_store.push_back(key);
			string enc = encrypt(data,key);
			GenesisNode= insert(GenesisNode,time_stamp,enc,val);
		}
	}

	print(GenesisNode);
	Longets_chain();
}