#include <bits/stdc++.h>
#include "md5.h"
using namespace std;

int unique_id=0; //To give unique Id to every Node
vector<string> key_store; //Storing Key values:

struct node //Struct of the node
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

void edit(node* root,int unique_id, int choice) //data can't be changed
{
	while(root->node_Number!=unique_id)
	{
		root=root->down;
	}

	if(root->node_Number==unique_id)
	{
		// int choice=0;
		cout<<"What would you like to change "<<endl;
		cout<<"Press 1) time_stamp"<<endl;
		cout<<"Press 2) value"<<endl;
		cout<<"Press 3) both"<<endl;

		cin>>choice;
		
		if(choice==1)
		{
			string temp;
			cout<<"Enter time stamp: "<<endl;
			cin>>temp;
			root->time_stamp=temp;
		}
		else if(choice==2)
		{
			int temp;
			cout<<"Enter value: "<<endl;
			cin>>temp;
			root->val=temp;
		}
		else if(choice==3)
		{
			string temp;
			int val_temp;
			cout<<"Enter time stamp & value: "<<endl;
			cin>>temp>>val_temp;
			root->time_stamp=temp;
			root->val=val_temp;
		}
		// else
		// {
		// 	cout<<"invalid choice"<<endl;
		// }

	}
	else
	{
		edit(root->down,unique_id,choice);
	}
	// return root;
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
	GenesisNode= insert(GenesisNode,"22feb","baba",123);//Demo Adds
	GenesisNode=insert(GenesisNode,"11feb","abc",35);//Demo adds
	GenesisNode=insert(GenesisNode,"3feb","def",135);//Deme adds--
	GenesisNode=insert(GenesisNode,"1feb","hello",435);//Demo adds

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
	// int choice=1;
	// edit(GenesisNode,1,choice);
	// Longets_chain();
}