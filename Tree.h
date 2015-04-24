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
	
	Tree(){root=NULL;AllTheData="";}

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