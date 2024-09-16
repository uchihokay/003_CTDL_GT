#include<iostream>
#include<stack>
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

//use recursive - mid
void Print_tree_mid(node *t){
	if (t != NULL){
		Print_tree_mid(t->left);
		cout<<t->data<<" ";
		Print_tree_mid(t->right);
	}
}

//not use recursive - mid
void Print_tree_mid2(node* root) {
    stack<node*> st;
    node* current = root;

    while (current != NULL || !st.empty()) {
        // Đưa tất cả các node bên trái vào stack
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }

        // Lấy node ở trên cùng stack (node trái nhất)
        current = st.top();
        st.pop();

        // In giá trị node hiện tại (gốc)
        cout << current->data << " ";

        // Chuyển sang cây con bên phải
        current = current->right;
    }
}



//Not use recursive - before
void Print_tree_before(node *t) {				
    stack<node*> st; 
    if (t == NULL) {
        return;
    } else {
        st.push(t); 
		while(st.top() != NULL){
			cout<<st.top()->data<<" ";
			node *a  = st.top();
			st.pop();

			if (a->right != NULL){
				st.push(a->right);
			}
			if (a->left != NULL){
				st.push(a->left);
			}
		}
    }
}


//Not use recursive - after
void Print_tree_after(node *t){
	stack<node*> st1,st2;
	if (t == NULL){
		return;
	}
	else{
		st1.push(t);
		while(st1.empty() != true){
			st2.push(st1.top());
			node *a = st1.top();
			st1.pop();

			if (a->left != NULL){
				st1.push(a->left);
			}
			if (a->right != NULL){
				st1.push(a->right);
			}
		}

		while (st2.top() != NULL){
			cout<<st2.top()->data<<" ";
			st2.pop();
		}
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


}
