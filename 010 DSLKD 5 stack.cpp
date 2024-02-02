#include<iostream>									
using namespace std ;

struct node{
	int data ;
	node *next ;
};

struct list{
	node *phead;
	node *ptail;
};

void CreateList(list &ds){
	ds.phead = NULL;
	ds.ptail = NULL;
}

void InsertEnd(list &ds,int x ){       			   
	node *p = new node ;
	p->data = x ;
	p->next = NULL;
	if (ds.phead == NULL){
		ds.phead = p ; 
		ds.ptail = p ;
	}
	else {
		ds.ptail->next = p;
		ds.ptail = p;
	}
}


void Enter(list &ds){							
	int n,x ;
	cout<<"\n\tNumber of elements :";cin>>n;
	for (int i = 0 ; i < n ; i++){
		cout<<i+1<<" : ";cin>>x;
		InsertEnd(ds,x);
	}
}
void Print(list &ds){								
	if (ds.phead == NULL){
		cout<<"\n\n\t In4 is not enterd !!"<<"\n"; 
	}
	else {
		for (node *p = ds.phead ; p!= NULL; p=p->next){
			cout<<p->data<<" ";
		}
	}
}
void InsertMid(list &ds){
	int b ; 
	cout<<"\n Enter Number :"; cin>> b;
	node *new_node = new node;
	new_node->data = b;
	new_node->next = NULL;
	
	if (ds.phead == NULL){
		ds.phead = new_node;
		ds.ptail = new_node;
	}
	else {
		int k;
		cout<<"\n Enter location : ";
		cin>>k;
		
		if (k==0){
			new_node->next = ds.phead;
			ds.phead = new_node;
		} 
		else {
			node *p = new node;
			p = ds.phead ;
			for (int i = 0 ; i<k-2 ; i++){
				p = p->next ;
			}
			new_node->next = p->next;
			p->next = new_node;	
		}
	}
}
	
void Delete(list &ds){
	if (ds.phead == NULL){
		cout<<"\n\tNothing to delete !!! \n";
	}
	else {
		cout<<"\n\t\t 1.Delete head .";
		cout<<"\n\t\t 2.Delete tail .";
		cout<<"\n\t\t 3.Other location .";

		int x ; 
		cout<<"\n\t\t\t Your answer : ";cin>>x;
		
		if (x == 1){                        	 	 
			node *p = ds.phead;
			ds.phead = ds.phead->next;
			p->next = NULL;
			delete p;
		}
		else if (x == 2){							
			for (node *k = ds.phead ; k!= NULL ; k= k->next){
				if (k->next == ds.ptail){
					delete ds.ptail;
					k->next = NULL;
					ds.ptail = k;
				}
			}
		}
		else if (x==3){
			int var;    /*vi tri cu the*/
			cout<<"Enter location (started with 1): ";cin>>var;
			if (var == 0){							
				node *p = ds.phead;				
				ds.phead = ds.phead->next;
				p->next = NULL;
				delete p;
			}
			
			else {
				node *m = ds.phead ;
				node *n = new node;
				for (int i = 0; i < var-1 ;i++){
					n = m;
					m = m->next;
				}
				n->next = m->next ;
				delete m;				
			}
		}
	}
}

int main() {
	list ds;
	CreateList(ds);
	int var ;
	
	do{
		cout<<"\n\t\t----------------------------------------\n";
		cout<<"\t\t 1. Enter list ."<<"\n";
		cout<<"\t\t 2. Scan list"<<"\n";
		cout<<"\t\t 3. Insert in4"<<"\n";
		cout<<"\t\t 4. Delete ."<<"\n";
		cout<<"\t\t 5. Exit"<<"\n";
		
		cout<<"\n"<<"Enter your answer : " ; cin>>var;
		
		if (var == 1){
			Enter(ds);
			cout<<"\n\t\t\tComplete!!!";
		}
		else if (var == 2){
			Print(ds);
			cout<<"\n\t\t\tComplete!!!";
		}
		else if ( var == 3){
			InsertMid(ds);
			cout<<"\n\t\t\tComplete!!!";
		}
		else if (var == 4){
			Delete(ds);
			cout<<"\n\t\t\tComplete!!!";
		}
		else if (var == 5){
			cout<<"\n\t\t\tComplete!!!";
			exit(0);
		}		
	}while(var >= 0 && var <= 4);
}



					
	
	
	
	
	

