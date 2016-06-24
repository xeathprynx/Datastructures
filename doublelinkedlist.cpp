#include<iostream>
using namespace std;
class doubly_linked_list{
	private:
		struct node{
			int data;
			node *next;
			node *previous;
		}*head,*current_node;
	public:
		doubly_linked_list();
		void add(int l);
		void insert(int r);
		void  remove(int f);
		void find(int v);
		void replace(int d);
		void sort();
		void display();
};
doubly_linked_list::doubly_linked_list(){
	head = NULL;
}
void doubly_linked_list::add(int l){
	int j = l;
	node *newnode = new node;
	if(head==NULL){
		newnode->data = j;
		newnode->previous=NULL;
		newnode->next=NULL;
		head = newnode;
		current_node = newnode;
	}
	else{
		newnode->data =j;
		newnode->previous = current_node;
		current_node->next = newnode;
		current_node = newnode;
		current_node->next = NULL;
	}
}
void doubly_linked_list::remove(int f){
	int h = f;
	if(head==NULL){
		cout<<"List is empty"<<endl;
	}
	else{
		node *temp;
		temp = head;
		while(temp!=NULL){
			if(temp->data==h){
				cout<<"Node to be removed is : "<<temp->data<<endl;
				node *for_delete;
				node *for_delete1;
				for_delete = temp;
				for_delete1 = temp;
				for_delete=for_delete->previous;
				for_delete1 = for_delete1->next;
				for_delete->next=for_delete1;
				for_delete1->previous= for_delete;
				
			}
			temp=temp->next;
		}
	}
}
void doubly_linked_list::find(int v){
	int r = v;
	node *temp = head;
	while(temp!=NULL){
		if(temp->data == r){
			cout<<"Data found : "<<temp->data<<endl;
		}
		temp=temp->next;
	}
}
void doubly_linked_list::display(){
	if(head==NULL){
		cout<<"Empty List : "<<endl;
	}
else{
	node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp= temp->next;
	}
}	
}
void doubly_linked_list::replace(int d){
	int h = d;
	node *temp = head;
	while(temp!=NULL){
		if(temp->data==d){
			int f;
			cout<<"Enter number to replace : "<<temp->data<<endl;
			cin>>f;
			temp->data = f;
			cout<<"new data is "<<temp->data<<endl;
		}
		temp=temp->next;
	}
}
void doubly_linked_list::sort(){
	node *temp = head;
	node *temp1 = head->next;
	while(temp->next!=NULL){
		if(temp->data<temp1->data){
			temp = temp->next;
			temp1=temp1->next;
		}
		else{
			int m = temp->data;
			temp->data = temp1->data;
			temp1->data = m;
			sort();
		}
	}
}
void doubly_linked_list::insert(int g){
	if(head==NULL){
		cout<<"List is empty"<<endl;
	}
	else{
		int j = g;
		node *temp = head;
		while(temp!=NULL){
			if(temp->data==j){
				node *inserting_node = new node;
				node *helping_node = temp;
				int l;
				cout<<"insert data for newly created node : ";
				cin>>l;
				inserting_node->data =l;
				helping_node = helping_node->next; 
				inserting_node->previous= temp;
				temp->next=inserting_node;
				inserting_node->next = helping_node;
				helping_node->previous = inserting_node;
			}
			temp=temp->next;
		}
	}
}
int main(){
	
	doubly_linked_list dl;
	
	int choice;
	int m;
	while(true){
		cout<<"press 1 to input data in linkedlist : "<<endl;
		cout<<"press 2 to remove data from linkedlist : "<<endl;
		cout<<"press 3 to find data in linkedlist : "<<endl;
		cout<<"press 4 to replace data in linkedlist : "<<endl;
		cout<<"press 5 to sort data in linkedlist : "<<endl;
		cout<<"press 6 to insert after the selected node : "<<endl;
		cout<<"press 7 to display data in linkedlist : "<<endl;
		cout<<"press 8 to Quit : "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Input any number : ";
				cin>>m;
				dl.add(m);
				break;
			case 2:
				cout<<"Input number to remove the node containing that number : ";
				cin>>m;
				dl.remove(m);
				break;
			case 3:
				cout<<"Input number to find in list : ";
				cin>>m;
				dl.find(m);
				break;
			case 4:
				int g;
				cout<<"enter no in origonal list to be replaced : ";
				cin>>g;
				dl.replace(g);
				break;
			case 5:
				dl.sort();
				break;
			case 6:
				cout<<"insert number to find and insert new node after it : ";
					cin>>m;
					dl.insert(m);
					break;
				case 7:
					dl.display();
				break;
			case 8:
				return false;
				break;
			default:
			cout<<"wrong input : Please input again : "<<endl;
			break;	
		}
	}
	return 0;
}

