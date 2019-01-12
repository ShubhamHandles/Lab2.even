/*
Implement Singly Linked List using C++. Make sure the following functions: 
1. insert(int data) - Adds a new element to the end of the linked list. 
2. insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
	It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
3. delete() - Deletes the element at the end of the list. 
4. deleteAt(int pos) - Deletes the element(or node) at the position pos)
5. countItems() - Returns the number of items in the linked list. 
6. display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
*/

#include<iostream>
using namespace std;

//define circle
class Node{
	public:
	//Data
	int data;
	//Pointer to next node
	Node* next;
	//constructor for default pointer
	Node(){
		next=NULL;
	}
	
	Node(int data){
		this->data=data;
		next=NULL;
	}
};

//create a linklist
class LinkedList {
	//chain of circles linked according to some rule
	public:
	//head and tail pointer
	Node* head; 
	Node* tail;
	//constructor for default head and tail
	LinkedList(){
		head=NULL; tail=NULL;
	}
	//insert
	void insert(int data){
		//add node
		Node* temp = new Node(data);
		//insert data
		//update head and tail
		//for first node
		if(head==NULL){
			head=temp;
		}	
		//for any other node
		else{
			tail->next = temp;
		}
		tail = temp;
	}
	//insertAt
	void insertAt(int pos, int data){
		//if position exists
		int check = countItems();
		if(pos<=check+1){
			//Reach the place before the position
			Node* current = head;
			for(int i=1;i<pos-1;i++){
				current=current->next;
			}
			//add node
			Node* temp = new Node(data);
			//join the node to successor
			temp->next = current->next;
			//join predecessor
			current->next = temp;
			}
		//if position does not exist
		else{
			cout << "Linked List does not have that many elements" << endl;
		}
	}
	//delete
	void delet(){
		//store tail in temp
		Node* temp = tail;
		//reach the place before tail and make its next NULL
		Node* current = head;
		while(current->next != tail){
			current = current->next;
		}
		current->next = NULL;
		//update tail
		tail=current;
		//delete tail
		delete temp;
	}
	//deleteAt
	void deleteAt(int pos){
		//reach the place before the pos
		Node* current = head;
		for(int i=1;i<pos-1;i++){
			current=current->next;
		}
		//store next in temp
		Node* temp = current->next;
		//connect current next to temp next
		current->next = temp->next;
		//delete temp
		delete temp;
	}
	//countItems
	int countItems(){
		int count=1;
		Node* current=head;
		if(head==NULL){
			return 0;
		}
		else{
			while(current!=tail){
				count++;
				current=current->next;
			}
			return count;
		}
	}
	//display
	void display(){
		displayR(head);
		cout << endl;
	}
	
	void displayR(Node* temp){
		if(temp!=NULL){
			cout << temp->data << "->";
			displayR(temp->next);
		}
	}
};


int main(){
	LinkedList l1;
	
	l1.insert(1);
	l1.insert(7);
	l1.insert(2);
	l1.insert(3);
	l1.insert(5);
	l1.insertAt(5,4);
	l1.deleteAt(2);
	l1.delet();
	l1.display();
	
	return 0;
}
