//code by angeline-crl
#include <iostream>
using namespace std;

void createlist(int data);
void display();
void addbeg(int data);
void addend(int data);
void delbeg(int data);
void delend(int data);
void retmenu();

struct Node{
	int info;
	struct Node *link;
}*start;


int main(){
	int choice, element, n, i;
	while(1){
		system("cls");
		cout << " - - - - - - - - MENU - - - - - - - -\n\n"
			 << " [1] Create a List\n"
			 << " [2] Add Node in the Beginning\n"
			 << " [3] Add Node in the End\n"
			 << " [4] Delete Node in the Beginning\n"
			 << " [5] Delete Node in the End\n"
			 << " [6] Display\n\n"
			 << " [0] Exit\n\n"
			 << " Enter your Choice: \n"
			 << "     >> ";
		cin >> choice;
		
		switch(choice){
			case 1:
				cout << " How many Nodes do you want to Create?\n"
					 << "     >> ";
				cin >> n;
				
				cout << " Enter the Elements:\n";
			//loop to enter elements to the list
				for(i=0; i<n; i++){
					cout << "   > ";
					cin >> element;
					createlist(element);
				}
				
				cout << "\n [SUCCESS!] " << n << " Elements added to List";
				retmenu();
			break;
			
			case 2:
				cout << "\n [    Add Node in the Beginning    ]\n"
					 << " Enter Element to Add: \n";
					 cout << "   > ";
					 cin >> element;
					 addbeg(element);
					 
				retmenu();
			break;
			
			case 3:
				cout << "\n [    Add Node in the End    ]\n"
					 << " Enter Element to Add: \n";
					 cout << "   > ";
					 cin >> element;
					 addend(element);
		
				retmenu();
			break;
			
			case 4:
				delbeg(element);
				retmenu();
			break;
			
			case 5:
				delend(element);
				retmenu();
			break;
				
			case 6:
				display();
				retmenu();
			break;
			
			case 0:
				exit(0);
			break;
			
			default:
				cout << "\n Invalid Input. Please try Again\n";
				retmenu();
			break;
		}
	}
	
	return 0;
}

//Create List
void createlist(int data){
	struct Node *p, *q;
	q = new Node;
	
	q -> info = data; //to fetch data
	q -> link = NULL; //set the link to null
	
	if(start==NULL)
		start = q;
	else{
		p = start;
		
		while(p->link != NULL)
			p = p->link;
		
		p->link = q;
	}
}

//Add Node in the Beginning
void addbeg(int data){
	struct Node *p, *q;
	q = new Node;
	
	q -> info = data;
	q -> link = NULL;
	
	if(start==NULL){
		cout << "\n [SUCCESS!] " << data << " Added to the Beginning";
		start = q;
	}
	
	else{
		cout << "\n [SUCCESS!] " << data << " Added to the Beginning";
		q->link = start;
		start = q;
	}
}

//Add Node at the End
void addend(int data){
	struct Node *p, *q;
	q = new Node;
	
	q -> info = data;
	q -> link = NULL;
	
	if(start==NULL){
		cout << "\n [SUCCESS!] " << data << " Added to the Beginning";
		start = q;
	}
	else{
		cout << "\n [SUCCESS!] " << data << " Added to the End";
		p = start;
		
		while(p->link != NULL)
			p = p->link;
		
		p->link = q;
	}
}

//Delete Node at the Beginning
void delbeg(int data){
	struct Node *p, *q;
	q = new Node;
	
	if(start==NULL){
		cout << "\n [ERROR!] List is Empty\n";
	}
	else{
		cout << "\n [SUCCESS!] Node Deleted at the Beginning";
		q = start;
		
		if(q->link==NULL){
			start = NULL;
		}
		else{
		start = start->link;
		
		delete q;
		}
	}
}

//Delete Node at the End
void delend(int data){
	struct Node *p, *q;
	q = new Node;
	
	q -> info = data;
	q -> link = NULL;
	
	if(start==NULL){
		cout << "\n [ERROR!] List is Empty\n";
	}
	else{
		cout << "\n [SUCCESS!] Node Deleted at the End";
		p = start;
		
		if(p->link==NULL){
			start = NULL;
		}
		else{
		while(p->link->link != NULL)
			p = p->link;
			
		p->link = NULL;
		}
	}
}

//Display
void display(){
	struct Node *p;
	
	cout << endl;
	if(start==NULL){
		cout << " [ERROR!] List is Empty\n";
		return;
	}
	p = start;
	cout << " The List: \n";
	while(p != NULL){
		cout << " " << p->info << endl;
		p = p->link;
	}
}

//Return to Menu
void retmenu(){
	cout << "\n Press any Key to return to Menu\n"
		 << "     > ";
		 system("pause>0");
}

