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
   Puppies *Pup;
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

   void AddPuppy(int A, int B)
   {
     Link *newLink = new Link;
     Puppies *newPup = new Puppies;
     //Pup pointer is now pointing to our new puppy
     newLink->Pup=newPup;
     newPup->Age=A;
     newPup->Breed=B;
     newLink->Next=First; //makes next null
     First=newLink;
  }

   void AddPuppyEnd(int A,int B)
   {
     Link *lastItem=new Link;
     Link *newNode=new Link;
     Puppies *newPup = new Puppies;
     lastItem=First;
       while (lastItem->Next != NULL)
       {
         lastItem=lastItem->Next;
       }
       lastItem->Next=newNode;
       newNode->Pup=newPup;
       newPup->Age=A;
       newPup->Breed=B;
       newNode->Next=NULL; 
    }

  void RemovePuppy()
  {
   delete First->Pup;
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
       delete current->Pup;
       delete current;
       current=temp;
       }
    delete current->Pup;
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

