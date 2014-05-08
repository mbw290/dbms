#include<iostream>
#include <stdio.h>
#include <vector>

using namespace std;
class LinkedList;
void chooseDisplay(LinkedList);
/*Database Management System
 * Rob Mancuso and Matt Wimpelberg
 * The database in this program is a linked list comprised of tables that are individual linkedlists of vectors
 * vectors are of various types depending on the datatype that the user wishes to enter
 */

//Field class that can be used to hold the field name and actual value which can be of any type which is why we use a template
template <class atype>
class Field
{
public:
    string name;
    atype val;
};

//Database object to hold rows which are vectors of data that can be of any data type

class dbTable
{
public:
    vector <int> intRow;
    
  	vector<double> doubleRow;
    
	vector<string> stringRow;
    int id;
    bool disp = false;
    string name;
    
	//Print an integer as a string
    void inttoString()
    {
        for(int i = 0; i < intRow.size(); i++)
        {
            cout << intRow[i] << endl;
        }
    }
    
	//Print a double as a string
	
    void doubletoString()
    {
        for(int i = 0; i < doubleRow.size(); i++)
        {
            cout << doubleRow[i] << endl;
        }
    }
    //Just print a string
	
    void strtoString()
    {
        for(int i = 0; i < stringRow.size(); i++)
        {
            cout << stringRow[i] << endl;
        }
    }
};


/*We need a link to point to the database table and the next item
 * something to hold the list and methods to add to the list and remove etc.
 */
class Link
{
public:
    
    //We will use links to each type of vector
    dbTable *table;
    Link *Next;
    Link *current;
   // Field<int> *ifield;
   // Field<string> *strfield;
   // Field<double> *dfield;
 
    string name;
};

class LinkedList
{
private:
    Link *FirstTable;
    Link *FirstField;
public:
    int const T = 0;
    int const F = 1;
    LinkedList()
    {
        FirstTable = NULL;
        FirstField = NULL;
    }
    
    //Add a field of an integer type and move the links to point to the next field in the actual table
    void AddIntField(string name)
    {
        Link *newLink = new Link;
        dbTable *ntable = new dbTable;
        newLink->table=ntable;
        newLink->table->name = name;
        newLink->table->id = 0;
        newLink->Next = FirstField;
        FirstField = newLink;
        
        cout << "Int added" << endl;
    }
    //Add a field of an string type and move the links to point to the next field in the actual table
    
    void AddStrField(string name)
    {
        Link *newLink = new Link;
        dbTable *ntable = new dbTable;
        newLink->table=ntable;
        newLink->table->id = 2;
        newLink->Next = FirstField;
        FirstField= newLink;
        cout << "String added";
    }
    //Add a field of an string type and move the links to point to the next field in the actual table
	
    
    
    
    void AddDoubleField(string name)
    {
        
        Link *newLink = new Link;
        dbTable *ntable = new dbTable;
        newLink->table=ntable;
        newLink->table->id = 1;
        newLink->Next = FirstField;
        FirstField= newLink;
        
        cout << "Double added";
    }
    
	//Add a table to the database
	
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
    
    void RemoveTable(string name)
    {
        while(FirstTable != NULL)
        {
            //Find the table that the user entered and Remove the link to it and point to the next table
            if(name.compare(name))
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
            //Go through the table and find the field that the user specified
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->table->name.compare(fname))
                    {
                        //Delete the link to the field that the user wishes to delete
                        RemoveLink(*FirstField);
                        cout << "Deleted" << endl;
                    }
					//Check the next node if the current isn't the node the user specified
                    else
                    {
                        FirstField = FirstField->Next;
                    }
                }
                
                break;
            }
            FirstTable=FirstTable->Next;
        }
    }
    //Remove a link to a database table
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
    //Go through the list of fields and use our inttoString method to print the values
    void DispChange(string tname, string fname, bool tf)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname))
                    {
                            FirstField->table->disp = tf;
                            break;
                    }
                    else
                    {
                        FirstField = FirstField -> Next;
                    }
                    if(FirstField == NULL)
                    {
                        //If we make it through each field and don't find a match tell the user we couldn't find it
                        cout<<"Field not Found" <<endl;
                        break;
                    }
                }
                break;
            }
            else
            {
                FirstTable = FirstTable->Next;
            }
        }

    }
    
    void DispChange(string tname, bool tf)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
      
                        FirstField->table->disp = tf;
                        FirstField = FirstField -> Next;
                }
                break;
            }
            else
            {
                FirstTable = FirstTable->Next;
            }
        }
        
    }
    
    void Display(string tname)
    {
        while(FirstTable != NULL)
        {
            
            if(FirstTable->name.compare(tname))
            {
                while(FirstField!=NULL)
                {
                    if(FirstField->table->disp)
                    {
                        switch(FirstField->table->id)
                        {
                            case 0:
                                DisplayIntField(tname, FirstField->table->name);
                                break;
                            case 1:
                                DisplayDoubleField(tname, FirstField->table->name);
                                break;
                            case 2:
                                DisplayStrField(tname,FirstField->table->name);
                                break;
                        }
                    }
                    FirstField = FirstField->Next;
                }
                
            }
            break;
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
                    if(FirstField->table->disp)
                    {
                        cout << FirstField->name << "---------------------\n" << endl;
                        FirstField->table->inttoString();
                        break;
                        FirstField = FirstField -> Next;
                    }
                    if(FirstField == NULL)
                    {
                        //If we make it through each field and don't find a match tell the user we couldn't find it
                        cout<<"Field not Found" <<endl;
                        break;
                    }
                }
                break;
            }
            else
            {
                FirstTable = FirstTable->Next;
            }
        }
    }
    
	//Go through the list of fields and use our doubletoString method to print the values
    
	
    void DisplayDoubleField(string tname, string fname)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->table->disp)
                    {
                        cout << FirstField->name << "---------------------\n" << endl;
                        FirstField->table->doubletoString();
                        FirstField = FirstField -> Next;
                         break;
                    }
                    if(FirstField == NULL)
                    {
                        //If we make it through each field and don't find a match tell the user we couldn't find it
                        cout<<"Field not Found" <<endl;
                        break;
                    }
                    else
                    {
                        break;
                    }
                    
                }
               
            }
            else if(FirstTable == NULL)
            {
                cout << "Table not found";
                break;
            }
            else
            {
                FirstTable = FirstTable->Next;
            }
        }
    }
	
	//Go through the list of fields and use our strtoString method to print the values
    
    void DisplayStrField(string tname, string fname)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->table->disp)
                    {
                        cout << FirstField->name << "---------------------\n" << endl;
                        FirstField->table->strtoString();
                        FirstField = FirstField -> Next;
                    }
                    else
                    {
                        FirstField = FirstField -> Next;
                    }
                    if(FirstField == NULL)
                    {
                        //If we make it through each field and don't find a match tell the user we couldn't find it
                        cout<<"Field not Found" <<endl;
                        break;
                    }
                    
                }
                break;
            }
            else
            {
                FirstTable = FirstTable->Next;
            }
        }
    }
    
	//Go to the table specified by the user, find the field they're inserting the data too, and push the values into the vector that represents that field
    
    void insertIntData(string tname, string fname, int data)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname))
                    {
                        FirstField->table->intRow.push_back(data);
                        break;
                    }
                    else
                    {
                        FirstField = FirstField->Next;
                    }
                    if(FirstField == NULL)
                    {
                        cout<<"Field not Found" <<endl;
                        break;
                    }
                    
                }
                break;
            }
            else if(FirstTable == NULL)
            {
                cout<< "Table not found" << endl;
                break;
            }
            else
            {
                FirstTable = FirstTable -> Next;
            }
        }
    }
    
	//Go to the table specified by the user, find the field they're inserting the data too, and push the values into the vector that represents that field
    
    
    void insertDoubleData(string tname, string fname, double data)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname))
                    {
                        FirstField->table->doubleRow.push_back(data);
                        break;
                    }
                    else
                    {
                        FirstField = FirstField->Next;
                    }
                }
                break;
            }
            else
            {
                FirstTable = FirstTable -> Next;
            }
        }
    }
    
	//Go to the table specified by the user, find the field they're inserting the data too, and push the values into the vector that represents that field
    
	
    void insertStrData(string tname, string fname, string data)
    {
        while(FirstTable != NULL)
        {
            if(FirstTable->name.compare(tname))
            {
                while(FirstField != NULL)
                {
                    if(FirstField->name.compare(fname))
                    {
                        FirstField->table->stringRow.push_back(data);
                        break;
                    }
                    else
                    {
                        FirstField = FirstField->Next;
                    }
                }
                break;
            }
            else
            {
                FirstTable = FirstTable -> Next;
            }
        }
    }
    
};

//Grab the information that we are inserting into the database from the user

void insert(LinkedList &database)
{
    int choice;
    string name;
    cout << "Please choose the number that corresponds with your desired field: " <<endl;
    cout << "1. Int field\n2. Double Field\n3. String Field" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "Please name your field" << endl;
            cin >> name;
            database.AddIntField(name);
            break;
        case 2:
            cout << "Please name your field" << endl;
            cin >> name;
            database.AddDoubleField(name);
            break;
        case 3:
            cout << "Please name your field" << endl;
            cin >> name;
            database.AddStrField(name);
            break;
        default:
            cout << "Choice not recognized, Please try again.";
            break;
    }
}

//Ask the user which table and which field they are trying to display the values of
int main()
{
    const int MAXSTR = 100;
    string name;
    string tableName;
    string fieldName;
    string dataName;
    string data;
    string input;
    int intFieldData;
    double doubleFieldData;
    string stringFieldData;
    int Idata;
    double Ddata;
    string Strdata;
    int numOfFields;
    int choice;
    LinkedList database;
	//Find out which operation the user would like to perform and call the appropriate methods
    do
    {
        cout << "Please choose the number that corresponds with your desired operation: " << endl;
        cout << "1. Add Table\n2. Drop Table\n3. Display Field\n4. Add to existing int field\n5. Add to existing double field\n6. Add to existing string field\n7. exit" << endl;
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
                
                cout << "Please tell me which table" << endl;
                cin >> tableName;
                do
                {
                    cout << "Please enter your desired field" << endl;
                    cin >> fieldName;
                    database.DispChange(tableName, fieldName, true);
                    cout << "Enter 'yes' if you wish to display another field" << endl;
                    cin >> input;
                }while(input == "yes");
                database.Display(tableName);
                database.DispChange(tableName, false);
                break;
            case 4:
                cout << "What is the name of the table to insert into?" << endl;
                cin >> tableName;
                cout << "What field would you like to insert into?" << endl;
                cin >> fieldName;
                //cout << "What is the name of the field data?" << endl;
                //cin >> dataName;
                do
                {
                    cout << "Enter data" << endl;
                    cin >> Idata;
                    database.insertIntData(tableName, fieldName, Idata);
                    cout << "Enter 'yes' to enter another record: " << endl;
                    cin >> input;
                }while(input == "yes");
                break;
            case 5:
                cout << "What is the name of the table to insert into?" << endl;
                cin >> tableName;
                cout << "What field would you like to insert into?" << endl;
                cin >> fieldName;
                do
                {
                    cout << "Enter data" <<endl;
                    cin >> Ddata;
                    database.insertDoubleData(tableName, fieldName, Ddata);
                    cout << "Enter 'yes' to enter another record: " << endl;
                    cin >> input;
                }while(input == "yes");
                break;
            case 6:
                cout << "What is the name of the table to insert into?" << endl;
                cin >> tableName;
                cout << "What field would you like to insert into?" << endl;
                cin >> fieldName;
                do
                {
                    cout << "Enter data" << endl;
                    cin >> Strdata;
                    if(Strdata.size() > MAXSTR)
                    {
                        cout << "String too long. Must be under 100 characters. Start Over";
                    }

                    else
                    {
                        database.insertStrData(tableName, fieldName, Strdata);
                    }
                    cout << "Enter 'yes' to enter another record: " << endl;
                    cin >> input;
                }while(input == "yes");
                break;
            case 7: exit(0);
                break;
            default:
                cout << "Choice not recognized, Please try again." <<endl;
                break;
        }
    }while(choice != 6);
}
