#include <iostream>
#include <vector>
#include <string>
using namespace std;



const static string NEWFILE="file",NEWFOLDER="folder";
int D,M,Y;
static int NumberOfFolders=0;
static int NumberOfFiles=0; 

class Node
{
private :
	float at;	//time of creation
	string name;
	string owner;
	string date;
	string data;  

public:
	bool IsReadable;
	bool IsWritable;
	bool IsExceutable;
	bool IsFolder;

	

	vector<Node*> FoldersAndFiles;

	Node(string fileorfolder)
	{
		if(fileorfolder==NEWFILE)
		{
			this->name="new file "+to_string((long long)NumberOfFiles);NumberOfFiles++;this->owner=" ",date=to_string((long long)D)+"/"+
			to_string((long long)M)+"/"+to_string((long long)Y),at=0;IsReadable=true;IsWritable=true;IsExceutable=false,IsFolder=false;
		}
		else if(fileorfolder==NEWFOLDER)
		{
			this->name="new folder "+to_string((long long)NumberOfFolders);NumberOfFolders++;this->owner=" ",date=to_string((long long)D)+"/"+
			to_string((long long)M)+"/"+to_string((long long)Y),at=0;IsReadable=true;IsWritable=false;IsExceutable=false,IsFolder=true;
		}
		else
		{
			cout<<"only files and folders are allowed to create "<<endl;
			cout<<"to create a folder : FolderOrFile objectName (NEWFOLDER);"<<endl;
			cout<<"to create a file : FolderOrFile objectName (NEWFILE);"<<endl;
		}
	}
	void SetOwnerName(string owner)
	{
		this->owner=owner;
	}
	string GetOwnerName()
	{
		return this->owner; 
	}
	void Rename(string Name)
	{
		this->name=Name;
	}
	string GetName()
	{
		return this->name;
	}
	void SetDate(int day,int month,int year)
	{
		this->date=to_string((long long)day)+"/"+to_string((long long)month)+"/"+to_string((long long)year);
	}
	string GetDate()
	{
		return this->date;
	}
	void SetTimeOfCreation(float t)
	{
		this->at=t;
	}
	float GetTimeOfCreation()
	{
		return at;
	}
	void SetData(string data)
	{
		this->data=data;
	}
	string GetData()
	{
		return this->data;
	}
	void add(Node*& NewNode)
	{
		if(this->IsFolder)
			this->FoldersAndFiles.push_back(NewNode);
		else
			cout<<"you can't make sub-folder or file to a file"<<endl;
	}

};
