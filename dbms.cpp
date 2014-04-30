#include<iostream>
#include <stdio.h>
#include <vector>
using namespace std;


template <class atype>
class Field
{
public:
    string name;
    atype val;
};


class dbTable
{
public:
  	vector<Field<int> > intRow()
	{
        vector <Field<int> > v1;
        return v1;
	}
  	vector<Field<double> > doubleRow()
	{
        vector <Field<double> > v1;
        return v1;
	}
	vector<Field<string> > stringRow()
	{
        vector <Field<string> > v1;
        return v1;
	}
    string name;
};


//we need a link to point to the puppy and the next item
//something to hold the list and methods to add to the list and remove etc.
class Link
{
public:
    dbTable *table;
    Link *Next;
    Link *current;
};

class LinkedList
{
private:
    Link *First;
public:
    string name;
    LinkedList()
    {
        First = NULL;
    }
    
    void AddTable(string name)
    {
        Link *newLink = new Link;
        dbTable *nTable;
        newLink->table=nTable;
        newLink->Next=First;
        First=newLink;
        name = name;
    }
    
    void AddTableEnd(int A,int B, string name)
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
        newNode->table = nTable;
        newNode->table->name = name;
        newNode->Next=NULL;
    }
    
    void RemoveTable(string name)
    {
        string dName;
        while(First != NULL)
        {
            if(name.compare(name) == 0)
            {
                RemoveList(*First);
                cout << "Deleted " << name << endl;
                break;
            }
            First=First->Next;
        }
        
    }
    
    void RemoveList(Link L)
    {
        Link *current=new Link;
        Link *temp = new Link;
        current=First;
        while (current != NULL)
        {
            temp=current->Next;
            delete current;
            current=temp;
        }
        delete current;
    }

    void DisplayTable(string name)
    {
	while (First != NULL)
	{
		if (name.compare(name) == 0)
		{
		cout << "DISPLAY " << name << "\n";
		break;
		}
	First=First->Next;
	}
    }
    
    LinkedList addDbTable(string name)
    {
        Link *newLink = new Link;
        dbTable *nTable;
        newLink->table=nTable;
        newLink->Next=First;
        First=newLink;
        LinkedList LL;
        LL.name = name;
        return LL;
    }
};

void insert()
{
    int choice;
    cout << "Please choose the number that corresponds with your desired field: " <<endl;
    cout << "1. Int field\n2. Double Field\n3. Add String Field" << endl;
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
    LinkedList database;
    string name;
    int numOfFields;
    int choice;
    do
    {
        cout << "Please choose the number that corresponds with your desired operation: " << endl;
        cout << "1. Add Table\n2. Drop Table\n3. Display Table\n4. Exit" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Please enter the name of your table: " << endl;
                cin >> name;
                database.addDbTable(name);
                cout << "Please enter the number of fields: " << endl;
                cin >> numOfFields;
                for(int i = 0; i < numOfFields; i++)
                {
                    insert();
                }
                break;
            case 2:
                cout << "What is the name of the table to drop?" << endl;
                cin >> name;
                database.RemoveTable(name);
                break;
            case 3:
                cout << "Which table would you like to display?" << endl;
                cin >> name;
                database.DisplayTable(name);
		break;
            case 4: return 0;
                break;
            default:
                cout << "Choice not recognized, Please try again." <<endl;
                break;
        }
        
    }while(choice != 4);
}
