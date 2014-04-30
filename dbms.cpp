#include<iostream>
#include <stdio.h>

using namespace std;

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


class dbTable
{
public:
  	vector<Field> intRow()
	{
        vector <Field> v1;
        return v1;
	}
  	vector<Field> charRow()
	{
        vector <Field> v1;
        return v1;
	}
	vector<Field> stringRow()
	{
        vector <Field> v1;
        return v1;
	}
    String name;
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

   void AddTable(String name)
   {
     Link *newLink = new Link;
     dbTable *nTable;
     newLink->table=nTable;
     newLink->Next=First;
     First=newLink;
     name = name;
  }

   void AddTableEnd(int A,int B, String name)
   {
     name = name;
       
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

  void RemoveTable(String name)
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
    
  void DisplayTable()
    {
        Link *current = First;
    }
};

void insert()
{
    cout << "Please choose the number that corresponds with your desired field: ";
    cout << "1. Int field\n2. Double Field\n3. Add String Field";
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
            cout << "Choice not recognized, Please try again."
            break;
    }
}




int main()
{
    LinkedList database;
    String name;
    int numOfFields;
    int choice;
    do
    {
        cout << "Please choose the number that corresponds with your desired operation: ";
        cout << "1. Add Table\n2. Drop Table\n3.Display Table\n4.Exit";
        switch(choice)
        {
            case 1:
                cout << "Please enter the name of your table: ";
                cin >> name;
                AddTable(name);
                cout << "Please enter the number of fields: ";
                cin >> numOfFields;
                for(int i = 0; i < numOfFields; i++)
                {
                    insert();
                }
                break;
            case 2:
                cout << "What is the name of the table to drop?";
                cin >> name;
                database.RemoveTable(name);
                break;
            case 3:
                cout << "Which table would you like to display?";
                cin >> name;
                break;
            case 4: exit(0);
                    break;
            default:
                cout << "Choice not recognized, Please try again."
                break;
        }

    }while(choice != 4)
}
