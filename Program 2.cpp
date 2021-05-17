#include<iostream>
using namespace std;
class linkedList{
	public:
	int data;
	linkedList *next;
	
	/************ Constructor ************/
	linkedList(int val)
	{
		data=val;
		next=NULL;
	}
	
	/************ function to insert node ************/
	static linkedList* insert(linkedList *start,int data)
	{
		linkedList *temp,*node=new linkedList(data);
		if (start==NULL)
		{
			start=node;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			temp=temp->next;
			temp->next=node;
		}
		return start;
	}

	/************ function to display linked list ************/
	static void display(linkedList* start)
	{	linkedList *temp;
		cout<<"Linked List is:";
		for(temp=start;temp!=NULL;temp=temp->next)//to print circular linked list replace temp!=NULL by temp!=head
		cout<<temp->data<<" ";
	}
	
	/************ function to find loop in linked list ************/
	static bool findLoop(linkedList *start)
	{
		linkedList *slowPtr,*fastPtr;
		slowPtr=fastPtr=start;
		while(slowPtr && fastPtr && fastPtr->next)
		{
			/* slowPtr will move one node per iteration whereas fastPtr will move
			two nodes per iteration*/
			slowPtr=slowPtr->next;
			fastPtr=fastPtr->next->next;
			/*if both pointers meet at some point it means linked list has loop*/
			if(slowPtr==fastPtr)
			return true;
		}
		return false;
		
		
	}
};

/************ main function ************/

main()
{
	linkedList* start=NULL;
	start=linkedList::insert(start,1);
	start=linkedList::insert(start,2);
	start=linkedList::insert(start,3);
	start=linkedList::insert(start,4);
	start->next->next->next=start; //creating loop by creating circular linked list
	//linkedList::display(start);
	if(linkedList::findLoop(start))
	cout<<"\nLinked List has loop";
	else
	cout<<"\nLinked List has no loop";
	delete start;
}
