#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class list
{
	private:
		node *head, *tail;

	public:
		list()
		{
			head=NULL;
			tail=NULL;
		}

	void createmode(int value)
	{
		node *temp=new node;
		temp->data=value;
		temp->next = NULL;

		if (head==NULL)
		{
			head=temp;
			tail=temp;
			temp=NULL;

		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}

	void addToFront(int data)  {
        node* temp = new node();
        temp -> data = data;
        temp -> next = head;
        head = temp;
    }

   void insert_position(int pos, int value)
  {
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
      pre=cur;
      cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;
    temp->next=cur;
  }

  void delete_firstNode(){
    node* temp = new node;
    temp = head;
    head = temp->next;


  }

  void delete_lastNode(){
    node* cur = head;
    node* pre = new node;

    while(cur->next != NULL){
        pre = cur;
        cur = cur->next;

    }

    tail = pre;
    pre->next = NULL;

  }

    void delete_position(int pos){
        node *current=new node;
        node *previous=new node;
        current=head;
        for(int i=1;i<pos;i++){
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }


	void display()
	{
		node *temp=new node;
		temp=head;
			while(temp!=NULL)
			{
				cout << temp->data <<"\t" ;
				temp = temp->next;
			}

	}

};

int main(){
	list newList=list();
	newList.createmode(10);
	newList.createmode(20);
	newList.createmode(30);
	newList.addToFront(51);
	newList.createmode(20);
	newList.insert_position(3,85);
	newList.delete_firstNode();
	newList.delete_lastNode();
	newList.delete_position(3);
	newList.display() ;
	return 0;
}
