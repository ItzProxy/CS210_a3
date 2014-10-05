#include "main.h"
list::list(){
	head = NULL;
	p = NULL;
	length = 0;
}
void list::resetToHead(){
	if (p == NULL){
		cerr << "P has not been set" << endl;
	}
	if (head != NULL){
		p = head;
	}
}
//this is the insert function, used to insert a value based on 3 conditions, 1.head, 2.somewhere in list 3. tail
void list::insert(char x){
	node* q;
	q = new node;
	if (head == NULL){ //this assigns the head a value
		q->value = x;
		q->next = NULL;
		head = q;
	}
	else{//inserting anywhere else in the list that is not the head or tail
		q = new node;
		q->value = x;
		q->next = p->next;
		q->previous = p;
		p->next = q;
	}
	p = q;
	length++;
	delete q;
}
void list::insertTail(char x){
	if (p == NULL){
		cerr << "P has not been set" << endl;
	}
	node* q;
	q = new node;
	if (head == NULL){ //this assigns the head a value
		q->value = x;
		q->next = NULL;
		head = q;
		//cout << "head has been set" << endl;
	}
	else{//inserting at tail in the list that is not the head 
		q = new node;
		q = head;
		while (q->next != NULL){
			q = q->next;
		}
		q->value = x;
		q->next = p->next;
		q->previous = p;
		p->next = q;
	}
	p = q;
	length++;
	delete q;
}
//finds the tail in the linked list
void list::findTail(){
	if (head != NULL && p != NULL){
		p = head;
		while (p->next != NULL){
			p = p->next;
		}
	}
}
//deletes the node previous to p
void list::backdelNode(){
	node* q;
	q = new node;
	q = p->previous;
	if (q != NULL){ //checks if we're deleting a valid node
		if (q == head){//deleting head
			head = p;
			if (head != NULL){//checks if there is head is a valid object
				head->previous = NULL;
			}
		}
		else if (p == NULL){//check if p is tail
			p = q->previous;
			p->next = NULL;
		}
		else{//deletes and links the previous and next p 
			p->previous = q->previous;
			p = q->previous;
			p->next = q->next;
			p = p->next;
		}
		length--;
	}
	delete q;
}
//deletes node where p is
void list::deleteNode(){
	node* q;
	q = new node;
	q = p;

	if (p->previous == NULL){//if we are deleting the head
		head = p->next;
		p->previous = NULL;//creates a new head
		delete q;
	}
	else if (p == NULL){//deleting tail
		p = q->previous;
		p->next = NULL;
		delete q;
	}
	else{//deleting anywhere else
		p->previous = q->previous;
		p = q->previous;
		p->next = q->next;
		p->previous = q->previous;
		delete q;
	}
	length--;
}
//resets p to the head

void list::iterateLeft(){
	if (p == NULL){
		cerr << "P has not been set" << endl;
	}
	if (p != NULL && p->previous != NULL){
		p = p->previous;
	}
}

void list::iterateRight(){
	if (p == NULL){
		cerr << "P has not been set" << endl;
	}
	if (p != NULL && p->next != NULL){
		p = p->next;
	}
}
char list::readP(){
	if (p != NULL){
		if (p->next != NULL){
			p = p->next;
		}
		return p->value;
	}
}
void list::iteratePrint(){
	node* q;
	q = new node;
	q = head;
	for (int i = 0; i < length; i++){
		while (q != NULL){//stop when the tail appears
			cout << q->value;
			if (q->value == '!' || q->value == '?' || q->value == '.'){
				break;
			}
			q = q->next;
		}
	}
	delete q;
}
