#include<iostream>
using namespace std;
class sort{
	public:
	struct node{
		int data;
		node *next;
		node *previous;
	}*head,*cur_ptr;
	public:
		sort(){
			head = NULL;
		}
	void add(int x){
		node *temp = new node;
		temp->data = x;
		temp->next = NULL;
		temp->previous = NULL;
		if(head==NULL)
		{
			head = temp;
			cur_ptr = temp;
		}
		else{
			cur_ptr->next = temp;
			temp->previous = cur_ptr;
			cur_ptr = temp;
		}
	}
	
	// Selection sort using node swaping instead of data swaping
	void selection_sort(){	
	node *i,*j,*temp;
	node *a,*b,*c,*d;
		int low;
		for(i=head;i!=NULL;i=i->next){
			int count = 0;
			low = i->data;
			for(j=i;j!=NULL;j=j->next){
				
				if(j->data<low){
					low = j->data;
					temp = j;
					a = j->previous;
					b = j->next;
					if(b==NULL){
					count = 0;	
					}
					else{
						count = 1;
					}
					
				}
				
			}
		
		    if(count ==1){
		    c = i->previous;
		    d = i->next;
		   
		   if(c!=NULL){
		   	c->next = temp;
		   }
		    d->previous = temp;
		    if(c==NULL){
		    	temp->previous = NULL;
		    	head = temp;
			}
		    temp->previous = c;
		    temp->next = d;
		   if(c!=NULL){  
		    c->next = temp;
		}
		    
		    a->next = i;
		    if(b!=NULL){
		  	
			    b->previous = i;
		}
		    i->next = b;
		    i->previous = a;
		    
		    i = temp;
		    
		    }
		    
		}
	
}
	void display(){
		node *temp = head;
		if(head == NULL){
			cout<<"empty list";
		}
		else{
			while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		}
	}
};
int main(){
	sort t;
	t.add(5);
	t.add(7);t.add(10);t.add(9);t.add(2);t.add(44);
	
	cout<<"\nBefore sorting"<<endl;
	t.display();
	t.selection_sort();
	cout<<"\nAfter sorting"<<endl;
	t.display();
	return 0;
}

