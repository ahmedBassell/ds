#include<iostream>
#include<string>
#include<vector>
#include <time.h>
#include "Tree.h"
using namespace std;


int main()
{
	//cout<<"please enter today date (day,month and year seperated by spaces) : "<<endl;
	//cin>>D>>M>>Y;
	cout<<"hello!"<<endl;
	

	Tree FileSystem;
	//initalize the tree with folder called first folder
	FileSystem.IntializeTheTree("root","folder",FileSystem.root);
	//newfolder2 in new folder1
	FileSystem.FindAndAdd("root","newfolder2","folder",FileSystem.root);
	//newfile0 in newfolder2
	FileSystem.FindAndAdd("newfolder2","newfile0","file",FileSystem.root);
	//newfolder3 in newfolder2
	FileSystem.FindAndAdd("newfolder2","newfolder3","folder",FileSystem.root);
	//newfile1 in newfolder2
	FileSystem.FindAndAdd("newfolder2","newfile1","file",FileSystem.root);
	//newfile2 in newfolder3
	FileSystem.FindAndAdd("newfolder3","newfile2","file",FileSystem.root);

	//put the whole data in string
	//FileSystem.PutTheWholeDataInString(FileSystem.root);
	//print this string
	//FileSystem.PrintTheWholeDataString();

	FileSystem.traverse(FileSystem.root);


	//printing the number of folders,files in the tree
	cout<<"Number of folders : "<<NumberOfFolders<<","<<"Number of files : "<<NumberOfFiles<<endl;
    system ("pause");
    return 0;
}