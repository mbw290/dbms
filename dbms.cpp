#include<iostream>
#include <stdio.h>

using namespace std;

class dbTable
{
  public:
  	vector<int> intRow()
	{
	vector <int> v1;
	return v1;
	}
  	vector<char> charRow()
	{
	vector <char> v1;
	return v1;
	}
	vector<string> stringRow()
	{
	vector <string> v1;
	return v1;
	}
};

//we need a link to point to the puppy and the next item
//something to hold the list and methods to add to the list and remove etc.
class Link
{
  public:
   dbTable *table;
   Link *Next;
};

class LinkedList
{
  private:
    Link *First;
  public:
    LinkedList()
    {
      First = NULL;
    }

   void AddTable()
   {
     Link *newLink = new Link;
     dbTable *nTable;
     newLink->table=nTable;
     newLink->Next=First;
     First=newLink;
  }

   void AddTableEnd(int A,int B)
   {
     Link *lastItem=new Link;
     Link *newNode=new Link;
     dbTable *nTable=new dbTable;
     lastItem=First;
       while (lastItem->Next != NULL)
       {
         lastItem=lastItem->Next;
       }
       lastItem->Next=newNode;
       newNode->table=dbTable;
       newNode->Next=NULL; 
    }

  void RemoveTable()
  {
   First=First->Next;
  }

  void RemoveList(LinkedList LL)
  {
     Link *current=new Link;
     Link *temp = new Link;
     current=First;
       while (current != NULL)
       {
       temp=current->Next; 
       delete current->Table;
       delete current;
       current=temp;
       }
    delete current->Table;
    delete current;
  }
  
  void Display()
  {
   Link *current=First;
   while (current != NULL)
   {
     cout << "Age: " << current->Pup->Age<<"\n"<<"Breed: "<<current->Pup->Breed<<"\n";
     current = current->Next;
   }
  }
};

