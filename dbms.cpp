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
    vector <Field<int>> intRow;
 
  	vector<Field<double>> doubleRow;

	vector<Field<string>> stringRow;
    
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
    Field<int> *ifield;
    Field<string> *strfield;
    Field<double> *dfield;
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
    

     void AddIntField(Field<int> ifield)
    {
        Link *newLink = new Link;
        dbTable *ntable = new dbTable;
        newLink->table=ntable;
        ntable->intRow.push_back(ifield);
        newLink = newLink->Next;
        First= newLink;
        cout << "Int added";
    }
    
    void AddStrField(Field<string> strfield)
    {
        Link *newLink = new Link;
        dbTable *ntable = new dbTable;
        newLink->table=ntable;
        ntable->stringRow.push_back(strfield);
        newLink = newLink->Next;
        First= newLink;
        cout << "String added";
    }
    
    void AddDoubleField(Field<double> dfield)
    {
        Link *newLink = new Link;
        dbTable *ntable = new dbTable;
        newLink->table=ntable;
        ntable->doubleRow.push_back(dfield);
        newLink = newLink->Next;
        First= newLink;
        cout << "Double added";
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
        
        while(First != NULL)
        {
            if(name.compare(name) == 0)
            {
                RemoveList(*First);
                cout << "Deleted " << endl;
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

    void DisplayTable()
    {
        Link *current = First;
    }
    

};

void insert(LinkedList &database)
{
    int choice;
    Field<int> userint;
    Field<double> userdouble;
    Field<string> userstr;
    cout << "Please choose the number that corresponds with your desired field: " <<endl;
    cout << "1. Int field\n2. Double Field\n3. Add String Field" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "Please name your field";
            cin >> userint.name;
            cout << "Please enter your int";
            cin >> userint.val;
            database.AddIntField(userint);
            break;
        case 2:
            cout << "Please name your field";
            cin >> userdouble.name;
            cout << "Please enter your double";
            cin >> userdouble.val;
            database.AddDoubleField(userdouble);
            break;
        case 3:
            cout << "Please name your field";
            cin >> userstr.name;
            cout << "Please enter your int";
            cin >> userstr.val;
            database.AddStrField(userstr);
            break;
        default:
            cout << "Choice not recognized, Please try again.";
            break;
    }
}


int main()
{
  
    string name;
    int numOfFields;
    int choice;
    LinkedList database;
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
                    insert(database);
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
                break;
            case 4: exit(0);
                break;
            default:
                cout << "Choice not recognized, Please try again." <<endl;
                break;
        }
        
    }while(choice != 4);
}
