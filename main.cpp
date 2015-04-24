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
	
	
	cout<<"hello!"<<endl;
	
	string user;
	cout<<"user:";cin>>user;

	Tree FileSystem;
	//initalize the tree with folder called first folder
	FileSystem.IntializeTheTree("root","folder",FileSystem.root);
	cout<<"Manual"<<endl;
	cout<<"*********************"<<endl;
	cout<<"Create: create folder folder1 to root"<<endl;

	cout<<"output: out"<<endl;
	string cmd,type,child,to,parent;
	while(1)
	{
		FILE *stream ;
		
		cin>>cmd;
		if(cmd=="out")
		{

			
		   if((stream = freopen("file.txt", "w", stdout)) == NULL)
			  exit(-1);

		  



			//freopen("A-small-attempt0.in","r",stdin);
		    //freopen("output.xml","w",stdout);
			FileSystem.xml(FileSystem.root);
			//freopen ("/dev/tty", "a", stdout);
		}
		else
		{
			stream = freopen("CON", "w", stdout);
			cin>>type>>child>>to>>parent;
			if(cmd=="create")
			{
				FileSystem.FindAndAdd(parent,child,type,FileSystem.root);
				FileSystem.traverse(FileSystem.root);
				//printing the number of folders,files in the tree
				cout<<"Number of folders : "<<NumberOfFolders<<","<<"Number of files : "<<NumberOfFiles<<endl;
			
			
				FileSystem.traverse(FileSystem.root);
			}
			else if(cmd=="update"){}
			else if(cmd=="delete"){}
		}
		
		
	}
	

	

	
	

	




	



    system ("pause");
    return 0;
}