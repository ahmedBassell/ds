#include<iostream>
#include<string>
#include<vector>
#include <time.h>
#include <ctime>
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

	string cmd,type,child,to,parent;
	while(1)
	{
		cin>>cmd>>type>>child>>to>>parent;
		if(cmd=="add")
		{
			FileSystem.FindAndAdd(parent,child,type,FileSystem.root);
			FileSystem.traverse(FileSystem.root);
			//printing the number of folders,files in the tree
			cout<<"Number of folders : "<<NumberOfFolders<<","<<"Number of files : "<<NumberOfFiles<<endl;

		}
	}
	

	

	
	

	




	



    system ("pause");
    return 0;
}