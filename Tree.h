#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class Tree
{
private:
	string AllTheData;
	 
public :
	Node* root;
	int Depth;
	
	Tree(){root=NULL;AllTheData="";Depth=0;}

	//if the tree is empty we call this function (in the beginnsing)
	void IntializeTheTree(string FirstCreatedName,string FolderFile,Node* &Root)
	{
		Node * FirstCreated=new Node(FolderFile);
		FirstCreated->Rename(FirstCreatedName);
		Root=FirstCreated;
	}

	//if the tree is not empty we call this function
	void FindAndAdd(string ParentName,string ChildName,string FolderFile,Node* &CurrentNode)
	{
		
			//if it's the folder or the file we looking for
			if(CurrentNode->GetName()==ParentName)
			{
				//if it's not a folder (a file)
				if(!CurrentNode->IsFolder)
					cout<<"you can't add sub-folders or files to a file"<<endl;
				
				//if it's a folder
				else
				{
					/*
					1-create a folder or a file (according to the string FolderFile input parameter to this function)
					2-rename it by the string ChildName
					3-add to the childs vector of the parent node
					*/
					Node * Created=new Node(FolderFile);
					Created->Rename(ChildName);
					CurrentNode->add(Created);
					Depth++;
				}
			}

			//if it's not what we looking for then we will recurse through the childs vector of the current node
			else
			{
				for(int x=0;x<CurrentNode->FoldersAndFiles.size();x++)
					FindAndAdd(ParentName,ChildName,FolderFile,CurrentNode->FoldersAndFiles[x]);
			}
	}

	void Delete(string ChildName,Node* &CurrentNode)
	{
		
			//if it's the folder or the file we looking for
			if(CurrentNode->GetName()==ChildName)
			{
				
					
								
				
			}

			//if it's not what we looking for then we will recurse through the childs vector of the current node
			else
			{
				
			}
	}



	void PutTheWholeDataInString(Node* & Current)
	{
		for(int x=0;x<Current->FoldersAndFiles.size();x++)
		{
			if(Current->IsFolder)
			{
				AllTheData+="'"+Current->GetName()+"' Folder"+" Contains"+"\n"+Current->GetDate();
				PutTheWholeDataInString(Current->FoldersAndFiles[x]);
			}
			else
				AllTheData+="'"+Current->GetName()+"' File "+" , "; 
		}
		if(Current->FoldersAndFiles.size()==0)
		{
			if(Current->IsFolder)
				AllTheData+="'"+Current->GetName()+"' Folder"+",";
			else
				AllTheData+="'"+Current->GetName()+"' File "+",";
		}
	}
	void PrintTheWholeDataString()
	{
		cout<<AllTheData<<endl;
		AllTheData="";
	}

	void traverse(Node* curr,int depth=0)
	{
		
		if(depth==0){cout<<curr->GetName()<<endl;}
		if(curr->FoldersAndFiles.size()!=0)
		{
			depth++;
			string intend="";
			for(int i=0;i<depth;i++)
				intend+="    ";
			for(int x=0;x<curr->FoldersAndFiles.size();x++)
			{
				cout<<intend<<curr->FoldersAndFiles[x]->GetName()<<endl;
				traverse(curr->FoldersAndFiles[x],depth);
			}
		}
		
	}
	void xml(Node* curr,int depth=0)
	{
		
		if(depth==0)
		{
			cout<<"<?xml version='1.0' encoding='UTF-8'?>"<<endl;
			cout<<"<node>"<<endl;
			cout<<"<name>"<<curr->GetName()<<"</name>"<<endl;
			cout<<"<type>"<<curr->type<<"</type>"<<endl;
			cout<<"<owner>"<<curr->GetOwnerName()<<"</owner>"<<endl;
			cout<<"<date>"<<curr->GetDate()<<"</date>"<<endl;
		}
		if(curr->FoldersAndFiles.size()!=0)
		{
			depth++;
			string intend="";
			for(int i=0;i<depth;i++)
				intend+="    ";

			cout<<intend<<"<children>"<<endl;
			for(int x=0;x<curr->FoldersAndFiles.size();x++)
			{
				cout<<"<node>"<<endl;
				cout<<intend<<"<name>"<<curr->FoldersAndFiles[x]->GetName()<<"</name>"<<endl;
				cout<<intend<<"<type>"<<curr->FoldersAndFiles[x]->type<<"</type>"<<endl;
				cout<<intend<<"<owner>"<<curr->FoldersAndFiles[x]->GetOwnerName()<<"</owner>"<<endl;
				cout<<intend<<"<date>"<<curr->FoldersAndFiles[x]->GetDate()<<"</date>"<<endl;

				
				xml(curr->FoldersAndFiles[x],depth);
				cout<<"</node>"<<endl;
			}
			cout<<intend<<"</children>"<<endl;
			depth--;
			
		}
		if(depth==0)
		{
			cout<<"</node>"<<endl;
		}
		
	}
	/*
	in this function we need to search for the folder with the given name and Getting all its contnets and showing them(name,data,etc..)(Getters)
	else you will print not found
	*/
	//void FindCertainFolderAndGettingItsContents(string name){}

	//in this function we need to search for the folder with the given name and Setting all its contnets (name,data,etc..)(Setters)
	//void FindCertainFolderAndSettingItsContents(string name){}

	//here we will delete al the childs for this parent name (FolderFile),we will search for it then delete it with all its childs 
	//void DeleteFolderOrFile(string FolderFile){
};