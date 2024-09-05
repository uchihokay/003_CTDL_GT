#include<iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node *insert(node *t,int x){
	if (t == NULL){
		node * temp = new node;
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else{
		if (x < t->data){
			t->left = insert(t->left,x);
		}
		else {
			t->right = insert(t->right,x);
		}
	}
}


void PrintTree(node *t){
	if (t != NULL){
		PrintTree(t->left);
		cout<<t->data<<" ";
		PrintTree(t->right);
	}
}



//count leaves of tree
bool Isleafnode(node *t) {
    return (t->left == NULL && t->right == NULL);
}

int Count_leaf(node *t){
    if (t == NULL){
        return 0;
    }
    if (Isleafnode(t) == true){
        return 1;
    }
    return Count_leaf(t->left) + Count_leaf(t->right);
}



//count level of tree
int Count_level(node *t){
	if (t == NULL){
		return -1;
	}
	return 1 + max(Count_level(t->left),Count_level(t->right));
}


int main(){
	int n , x;
	cout<<"n = ";cin>>n;

	node *t = NULL;
	for (int i = 0 ; i < n ; i++){
		cin>>x;
		t = insert(t,x);
	}

	PrintTree(t);
	// cout<<" Origin = "<<t->data<<endl;
	// cout<<Count_level(t);
}