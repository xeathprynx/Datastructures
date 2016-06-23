#include<iostream>
using namespace std;
class Que{
	private:
		struct node{
			int value;
			node *ptr;
		}*head,*top;
	public:
		Que();
		void enque();
		void deque();
		void display();
};
Que::Que(){
	head = NULL;
}
void Que::enque(){
	node *newque = new node;
	if(head==NULL){
		newque->value = 8;
		newque->ptr=NULL;
		head = newque;
		top = newque;
	}
	else{
		newque->value = 9;
		newque->ptr = NULL;
		top->ptr = newque;
		top = newque;
	}
}
void Que::deque(){
	if(head==NULL){
		cout<<"Que is empty"<<endl;
	}
	else{
		node *temp;
		temp = head;
		head = head->ptr;
		cout<<"data dequed is : "<<temp->value<<endl;
		delete temp;
	}
}
void Que::display(){
	node *temp = head;
	if(head==NULL){
		cout<<"Que is empty"<<endl;
	}
	else{
		while(temp!=NULL){
			cout<<temp->value<<endl;
			temp = temp->ptr;
		}
	}
}
int main(){
	Que q;
	q.enque();
	q.enque();
	q.enque();
	q.deque();
	q.display();
	return 0;
}
