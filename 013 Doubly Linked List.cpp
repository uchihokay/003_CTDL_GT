#include<iostream> 				//xu ly th list rong trong menu
using namespace std; 			//cap nhat + delete
								
struct Node{
	int data;
	Node *next;
	Node *pre;
};

struct DouList{
	Node *head;
	Node *tail;
};

void CreateList(DouList &ds){
	ds.head = NULL;
	ds.tail = NULL;
}


void AddHead (DouList &ds , int data){
	Node *temp = new Node ;
	temp->data = data ;
	if (ds.head == NULL){
		temp->next = NULL;
		temp->pre = NULL;
		ds.head = temp;
		ds.tail = temp;
	}	
	else{
		temp->next = ds.head;
		temp->pre = NULL;
		ds.head->pre = temp;
		ds.head = temp;
	}	
}

void AddEnd(DouList &ds , int data){
	Node *temp = new Node ;
	temp->data = data ;
	if (ds.head == NULL){
		temp->next = NULL;
		temp->pre = NULL;
		ds.head = temp;
		ds.tail = temp;
	}	
	else{
		temp->next = NULL;
		temp->pre = ds.tail;
		ds.tail->next = temp;
		ds.tail = temp;
	}	
}


void Insert(DouList &ds,int &n){
	int k , val ;
	cout<<"Located = "; cin>>k;
	cout<<"Value = "; cin>>val;
	Node *x = new Node ;
	x->data = val;
	x->next = NULL;
	x->pre = NULL;
	
	if (k == 0){
		x->next = ds.head;
		x->pre = NULL;
		ds.head->pre = x;
		ds.head = x;
	}
	else if (k == n){
		x->next = NULL;
		x->pre = ds.tail;
		ds.tail->next = x;
		ds.tail = x;
	}
	else {
		Node *a = new Node;
		Node *b = ds.head;
		for (int i = 1 ; i <= k ; i++){
			a = b;
			b = b->next;
	}
		x->next = b;
		x->pre = a;
		a->next = x;
		b->pre = x;
	}
	n++;	
}

void Update(DouList &ds){
	int temp,k;
	if (ds.head == NULL){
		cout<<"\n\t\t---Empty---";
	}
	else {
		cout<<"Located :";cin>>k;
		cout<<"Value = " ;cin>>temp;
		Node *p = ds.head;
		for (int i = 0 ; i < k;i++){
			p = p->next;
		}
		p->data = temp;
	}
}

void Delete(DouList &ds,int &n){
	if (ds.head == NULL){
		cout<<"\n\n\t\t---Empty---";
		ds.tail=NULL; 
	}
	else {
		int k ;
		cout<<"Located = ";cin>>k;
		if ( k>0 && k<n-1){
			Node *a = new Node;
			Node *b = ds.head;
			Node *c = b->next;
			for (int i = 1 ; i <= k ; i++){
				a = b;
				b = b->next ;
				c = c->next ;
			}
			a->next = b->next ;
			c->pre = b->pre;
			delete b;
		}
		else if (k == 0){
			Node *a = ds.head;
			ds.head = ds.head->next;
			a->next = NULL;
			a->pre = NULL;
			delete a;
		}
		else if (k == n-1){
			Node *a = ds.tail->pre;
			Node *temp = ds.tail;
			a->next = NULL;
			ds.tail = a;
			delete(temp);
		}
	}
}



void Scan(DouList &ds,int &n){
	cout<<"	n = ";cin>>n;
	for (int i = 0 ; i < n ; i++){
		int var ;
		cin>>var;
		AddEnd(ds,var);
	}
}

void Print(DouList ds){
	if (ds.head == NULL){
		cout<<"\n\t---Empty---";
	}
	for (Node *p = ds.head ; p!=NULL ; p = p->next){
		cout<<p->data<<" ";
	}
}

int main(){
	DouList ds;
	CreateList(ds);
	int n,x;
	
	do{
		cout<<"\n	 ___________________________\n";
		cout<<"\n	|	1 .Create list 	     |";
		cout<<"\n	|	2 .Insert	     |";
		cout<<"\n	|	3 .Update data       |";
		cout<<"\n	|	4 .Delete value      |";
		cout<<"\n	|	5 .Print list        |";
		cout<<"\n	|	6 .Exit programme    |";
		cout<<"\n	 ___________________________";
		
		cout<<"\n\nEnter action : "; cin>>x;
		if (x == 1){
			Scan(ds,n);
			cout<<"\n\n	---Complele---";
		}
		
		else if (x==2){
			Insert(ds,n);
			cout<<"\n\n		---Complele---";
		}
		
		else if (x==3){
			Update(ds);
			cout<<"\n\n		---Complele---";
		}
		
		else if (x==4){
			Delete(ds,n);
			cout<<"\n\n		---Complele---";
		}
		
		else if (x==5){
			Print(ds);
			cout<<"\n\n		---Complele---";
		}
		
		else if (x==6){
			cout<<"\n\n		---Complele---";
			exit(0);		
		}
		
		else {
			cout<<"\n\n----Retype!!!----";
		}
	}while(x>0);
			
}

