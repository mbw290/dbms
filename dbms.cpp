#include<iostream>
#include <stdio.h>
#include <vector>
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


struct Field
{
    public:
    string name;
};

struct intField : Field
{
private: int val;
};

struct stringField : Field
{
private: string val;
};

struct doubleField : Field
{
private: double val;
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
   LinkedList addDbTable()
   {	
	LinkedList LL;
	return LL;
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
       newNode->table=nTable;
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
       delete current->table;
       delete current;
       current=temp;
       }
    delete current->table;
    delete current;
  }
  
};

void insert()
{
    int choice;
    cout << "Please choose the number that corresponds with your desired field: ";
    cout << "1. Int field\n2. Double Field\n3. Add String Field";
    cin >> choice;
    switch(choice)
    {
        case 1:
            //Add Int Field
            break;
        case 2:
            //Add Double Field
            break;
        case 3:
            //Add String Field
            break;
        default:
            cout << "Choice not recognized, Please try again.";
            break;
    }
}




int main()
{
    int choice;
    LinkedList LL;
    do
    {
        cout << "Please choose the number that corresponds with your desired operation: ";
        cout << "1. Add Table\n2. Drop Table\n3.Display Table\n4.Exit";
	cin >> choice;
        switch(choice)
        {
            case 1:
                LL.addDbTable();
                break;
            case 2:
                //Drop Table
                break;
            case 3:
                //Display Table
                break;
            case 4: 
		    return 0;
                    break;
            default:
                cout << "Choice not recognized, Please try again.";
                break;
        }

    }while(choice != 4);
}
