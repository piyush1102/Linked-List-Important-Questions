#include<iostream>
using namespace std;
class linkedList{
	private:
	int data;
	linkedList *next;
	/************ Constructor ************/
	linkedList(int val)
	{
		data=val;
		next=NULL;
	}
	
	public:
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
	/************ function to calculate length of linked list ************/
	static int getlength(linkedList *start)
	{
		int count=0;
		while(start)
		{
			count++;
			start=start->next;
		}
		return count;
	}
	/************ function to display linked list ************/
	static void display(linkedList* start)
	{	linkedList *temp;
		cout<<"Linked List is:";
		for(temp=start;temp!=NULL;temp=temp->next)
		cout<<temp->data<<" ";
	}
	/************ function to find kth node from end ************/
	static int KthElementFromLast(linkedList *start,int position)
	{
		linkedList *temp,*kthNode;
		int i;
		temp=kthNode=start;
		/*position must be less than length of linked list*/
		if(position>getlength(start))
		{
			cout<<"Error:K is greater than length of linked list";
		}
		/*move temp pointer to k-1th node.It will create difference of 
		k-1 nodes b/w temp & kthNode pointer*/
		for(i=0;i<position-1;i++)
		temp=temp->next;
		/*Now move both pointer untill temp points to last node.At this point
		kthNode points to the desiered node*/
		while(temp->next)
		{
			temp=temp->next;
			kthNode=kthNode->next;
		}
		return kthNode->data;
	}
};

/************ main function ************/

main()
{
	linkedList*start=NULL,*temp;
	int value,k;
	char ch;
	do{
		cout<<"Enter value: ";
		cin>>value;
		start=linkedList::insert(start,value);
		cout<<"Do you want to continue:\n";
		fflush(stdin);
		cin>>ch;
	}while(ch=='y');
	linkedList::display(start);
	cout<<"\nEnter position of Kth node from last: ";
	cin>>k;
	cout<<linkedList::KthElementFromLast(start,k);
	delete start;
	delete temp;
}
