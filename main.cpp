#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include <time.h>
#include <ctime>
#include <fstream>
#include "Tree.h"
using namespace std;


int main()
{
	//cout<<"please enter today date (day,month and year seperated by spaces) : "<<endl;
	//cin>>D>>M>>Y;
	
	
	
	
	string user;
	cout<<"Enter Your Name:";cin>>user;
	cout<<"hello "<<user<<" !"<<endl;
	Tree FileSystem;
	//initalize the tree with folder called first folder
	FileSystem.IntializeTheTree("root","folder",FileSystem.root);
	cout<<"Manual [instructions examples]"<<endl;
	cout<<"*********************"<<endl;
	cout<<"#Create: create folder folderName in root"<<endl;
	cout<<"_____"<<endl;
	cout<<"#Update: update folderName r true"<<endl;
	cout<<"#Update: update folderName w true"<<endl;
	cout<<"#Update: update folderName e true"<<endl;
	cout<<"#Update: update folderName owner ahmed"<<endl;
	cout<<"#Update: update folderName name myfolder"<<endl;
	cout<<"_____"<<endl;
	cout<<"#select: select folderName"<<endl;
	cout<<"_____"<<endl;
	cout<<"#Depth first search: DFS"<<endl;
	cout<<"#Bredth first search: BFS"<<endl;
	cout<<"_____"<<endl;
	cout<<"output: out"<<endl;
	cout<<"***********************"<<endl;
	string cmd,first,second,third,parent;
	while(1)
	{
		FILE *stream ;
	
		cin>>cmd;
		if(cmd=="end"){break;}
		else if(cmd=="out")
		{

			
		   if((stream = freopen("output.xml", "w", stdout)) == NULL)
			  exit(-1);

		  



			//freopen("A-small-attempt0.in","r",stdin);
		    //freopen("output.xml","w",stdout);
			FileSystem.xml(FileSystem.root);
			//freopen ("/dev/tty", "a", stdout);
		}
		else if(cmd=="DFS")
		{
			FileSystem.DFS(FileSystem.root);
		}
		else if(cmd=="BFS")
		{
			FileSystem.BFS(FileSystem.root);
		}
		else if(cmd=="select")
		{
			stream = freopen("CON", "w", stdout);
			cin>>first;
			FileSystem.Find(first,FileSystem.root);
		}
		else if(cmd=="update")
		{
			cin>>first>>second>>third;
			FileSystem.Update(first,second,third,FileSystem.root);
		}
		else if(cmd=="delete")
		{
				cin>>first;
				if(first==FileSystem.root->GetName() && FileSystem.root->FoldersAndFiles.size()==0 )
					cout<<"you can't delete the root folder"<<endl;
				else
					FileSystem.Delete(first,FileSystem.root,FileSystem.root->FoldersAndFiles,0);
	
		}
		else
		{
			stream = freopen("CON", "w", stdout);
			cin>>first>>second>>third>>parent;
			if(cmd=="create")
			{
				FileSystem.FindAndAdd(parent,second,first,user,FileSystem.root);
				cout<<"Done"<<endl;
				//printing the number of folders,files in the tree
				cout<<"Number of folders : "<<NumberOfFolders<<","<<"Number of files : "<<NumberOfFiles<<endl;
			
			
		
			}
			
			
			
		}
		
		
	}
	

	

	
	

	




	



    //system ("pause");
    return 0;
}