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
    
    void inttoString()
    {
        for(int i = 0; i < intRow.size(); i++)
        {
            cout << intRow[i].name << ":" << intRow[i].val << endl;
        }
    }
    
    void doubletoString()
    {
        for(int i = 0; i < doubleRow.size(); i++)
        {
            cout << doubleRow[i].name << ":" << doubleRow[i].val << endl;
        }
    }
    
    void strtoString()
    {
        for(int i = 0; i < stringRow.size(); i++)
        {
            cout << stringRow[i].name << ":" << stringRow[i].val << endl;
        }
    }
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
    
    string name;
};

class LinkedList
{
private:
    Link *FirstTable;
    Link *FirstField;
public:
    
    LinkedList()
    {
        FirstTable = NULL;
        FirstField = NULL;
    }
    
    
    void AddIntField(Field<int> ifield)
    {
        Link *newLink = new Link;
        dbTable *ntable = new dbTable;
        newLink->table=ntable;
        ntable->intRow.push_back(ifield);
        newLink->Next = FirstField;
        FirstField= newLink;
        cout << "Int added";
    }
    
    void AddStrField(Field<string> strfield)
    {
        Link *newLink = new Link;
        dbTable *ntable = new dbTable;
        newLink->table=ntable;
        ntable->stringRow.push_back(strfield);
        newLink->Next = FirstField;
        FirstField= newLink;
        cout << "String added";
    }
    
    void AddDoubleField(Field<double> dfield)
    {
        
        Link *newLink = new Link;
        dbTable *ntable = new dbTable;
        newLink->table=ntable;
        ntable->doubleRow.push_back(dfield);
        newLink->Next = FirstField;
        FirstField= newLink;
        cout << "Double added";
    }
    
    LinkedList addDbTable(string name)
    {
        Link *newLink = new Link;
        dbTable *nTable;
        newLink->table=nTable;
        newLink->Next=FirstTable;
        FirstTable=newLink;
        LinkedList LL;
       // LL.name = name;
        return LL;
    }
    
    void AddTableEnd(int A,int B, string name)
    {
        
        
        Link *lastItem=new Link;
        Link *newNode=new Link;
        dbTable *nTable=new dbTable;
        lastItem=FirstTable;
        
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
        while(FirstTable != NULL)
        {
            if(name.compare(name) == 0)
            {
                RemoveLink(*FirstTable);
                cout << "Deleted " << endl;
                break;
            }
            FirstTable=FirstTable->Next;
        }
    }
    
    void RemoveField(string tname, string fname)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname) == 0)
            {
                while(FirstField != NULL)
                {
                    if(FirstField->table->name.compare(fname) == 0)
                    {
                        RemoveLink(*FirstField);
                        cout << "Deleted" << endl;
                    }
                    else
                    {
                        FirstField = FirstField->Next;
                    }
                }
               // cout << "Deleted " << endl;
                break;
            }
            FirstTable=FirstTable->Next;
        }
    }
    
    void RemoveLink(Link L)
    {
        Link *current=new Link;
        Link *temp = new Link;
        current=FirstTable;
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
        Link *current = FirstTable;
        Link *temp = new Link;
        dbTable *nTable = new dbTable;
        cout << FirstTable->table->name;
        while (current != NULL)
        {
            string tname=current->table->name;
            cout << tname << "\n";
            if (name.compare(tname) == 0)
            {
                cout << "DISPLAY " << tname << "\n";
                break;
            }
            current=current->Next;
        }
    }
    
     void DisplayIntField(string tname, string fname)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname) == 0)
                    {
                        FirstField->table->inttoString();
                    }
                    else
                    {
                        FirstField = FirstField -> Next;
                    }
                }
            }
            else
            {
                FirstTable = FirstTable->Next;
            }
        }
    }

    void DisplayDoubleField(string tname, string fname)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname) == 0)
                    {
                        FirstField->table->doubletoString();
                    }
                    else
                    {
                        FirstField = FirstField -> Next;
                    }
                }
            }
            else
            {
                FirstTable = FirstTable->Next;
            }
        }
    }
    
    void DisplayStrField(string tname, string fname)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname) == 0)
                    {
                        FirstField->table->strtoString();
                    }
                    else
                    {
                        FirstField = FirstField -> Next;
                    }
                }
            }
            else
            {
                FirstTable = FirstTable->Next;
            }
        }
    }
    
    
    void insertIntData(string tname, string fname, Field<int> data)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname) == 0)
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname))
                    {
                        FirstField->table->intRow.push_back(data);
                    }
                    else
                    {
                        FirstField = FirstField->Next;
                    }
                }
            }
            else
            {
                FirstTable = FirstTable -> Next;
            }
        }
    }
    
    
    void insertDoubleData(string tname, string fname, Field<double> data)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname) == 0)
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname))
                    {
                        FirstField->table->doubleRow.push_back(data);
                    }
                    else
                    {
                        FirstField = FirstField->Next;
                    }
                }
            }
            else
            {
                FirstTable = FirstTable -> Next;
            }
        }
    }
    
    void insertStrData(string tname, string fname, Field<string> data)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname) == 0)
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname))
                    {
                        FirstField->table->stringRow.push_back(data);
                    }
                    else
                    {
                        FirstField = FirstField->Next;
                    }
                }
            }
            else
            {
                FirstTable = FirstTable -> Next;
            }
        }
    }
    
};

void insert(LinkedList &database)
{
    int choice;
    Field<int> userint;
    Field<double> userdouble;
    Field<string> userstr;
    cout << "Please choose the number that corresponds with your desired field: " <<endl;
    cout << "1. Int field\n2. Double Field\n3. String Field" << endl;
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

void chooseDisplay(LinkedList &database)
{
    string tname;
    string fname;
    int choice;
    cout << "Please choose the number that corresponds with your desired field type: " <<endl;
    cout << "1. Int field\n2. Double Field\n3. String Field" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "Please tell me which table" << endl;
            cin >> tname;
            cout << "Please enter your desired field" << endl;
            cin >> fname;
            database.DisplayIntField(tname, fname);
            break;
        case 2:
            cout << "Please tell me which table" << endl;
            cin >> tname;
            cout << "Please enter your desired field" << endl;
            cin >> fname;
            database.DisplayDoubleField(tname, fname);
            break;
        case 3:
            cout << "Please tell me which table" << endl;
            cin >> tname;
            cout << "Please enter your desired field" << endl;
            cin >> fname;
            database.DisplayStrField(tname,fname);
            break;
        default:
            cout << "Choice not recognized, Please try again.";
            break;
    }
}



int main()
{
    
    string name;
    string tableName;
    string fieldName;
    string dataName;
    string data;
    Field<int> intFieldData;
    Field<double> doubleFieldData;
    Field<string> stringFieldData;
    int Idata;
    double Ddata;
    int numOfFields;
    int choice;
    LinkedList database;
    do
    {
        cout << "Please choose the number that corresponds with your desired operation: " << endl;
        cout << "1. Add Table\n2. Drop Table\n3. Display Field\n4. Add to existing int field" << endl;
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
                chooseDisplay(database);
                break;
            case 4:
                cout << "What is the name of the table to insert into?" << endl;
                cin >> tableName;
                cout << "What field would you like to insert into?" << endl;
                cin >> fieldName;
                cout << "What is the name of the field data?" << endl;
                cin >> dataName;
                cout << "Enter data" <<endl;
                cin >> Idata;
                intFieldData.name = dataName;
                intFieldData.val = Idata;
                database.insertIntData(tableName, fieldName, intFieldData);
                break;
            case 5: exit(0);
                break;
            default:
                cout << "Choice not recognized, Please try again." <<endl;
                break;
        }
        
    }while(choice != 6);
}
