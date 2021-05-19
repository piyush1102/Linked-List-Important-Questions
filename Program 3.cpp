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
	
	/************ function to find starting of loop in linked list ************/
	static linkedList* findLoopBegins(linkedList *start)
	{
		linkedList *slowPtr,*fastPtr;
		slowPtr=fastPtr=start;
		bool hasLoop=false;
		while(slowPtr && fastPtr && fastPtr->next)
		{
			/* slowPtr will move one node per iteration whereas fastPtr will move
			two nodes per iteration*/
			slowPtr=slowPtr->next;
			fastPtr=fastPtr->next->next;
			/*if both pointers meet at some point it means linked list has loop*/
			if(slowPtr==fastPtr)
			{
				hasLoop=true;
				break;	
			}		
		}
		if(hasLoop)
		{
			slowPtr=start;
			/*iterate loop untill slowPtr is not equal to fastPtr*/
			while(slowPtr!=fastPtr)
			{
				slowPtr=slowPtr->next;
				fastPtr=fastPtr->next;
			}
			return slowPtr;
		}
			return (linkedList*) NULL;

	}
};

/************ main function ************/

main()
{
	linkedList* start=NULL,*loopHead;
	start=linkedList::insert(start,1);
	start=linkedList::insert(start,2);
	start=linkedList::insert(start,3);
	start=linkedList::insert(start,4);
	start->next->next=start->next; //creating loop 
	//linkedList::display(start);
	loopHead=linkedList::findLoopBegins(start);
	if(loopHead)
	{
		cout<<"\nLinked List has loop";
		cout<<"\nStarting Point of loop is:"<<loopHead->data;
	}
	else
	cout<<"\nLinked List has no loop";
	delete start;
}

