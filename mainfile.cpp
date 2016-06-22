#include<iostream>
using namespace std;
class stack{
	private:
		struct node{
			int data;
			node *ptr;
		}*top;
	public:
		stack();
		void push();
		void pop();
		void display();
};

stack::stack(){
	top = NULL;
}

void stack::push(){
	// making pointer object to make sure it contains values in memory for ever
	node *mynode = new node; 
	
	if(top==NULL){
		// -> is used when we try to access pointer object/variables
		mynode->data = 5;
		mynode->ptr=NULL;
		top = mynode;
	}
	else{
		
		mynode->data =7;
		mynode->ptr = top;
		top = mynode;
	}
	
	
}

void stack::pop(){
	
	if(top==NULL){
		
		cout<<"stack is empty"<<endl;
	}
	else{
		
		node *temp;
		temp = top;
		
		cout<<temp->data<<" Poped"<<endl;
		top = top->ptr;
		delete temp;
		
	}
}

void stack::display(){
	
	if(top == NULL){
		
		cout<<"Stack is empty"<<endl;
	}

else{
	
	node *temp;
	temp = top;
	
	do{
		
		cout<<temp->data;
		temp = temp->ptr;
	}while(temp->ptr!=NULL);
}	
}



int main(){
	
	stack s;
	
	s.push();
	s.push();
	s.push();
	s.push();
	//s.pop();
	s.display();
	
	return 0;
}
