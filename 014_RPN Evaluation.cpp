#include<iostream>
#include<stack>
using namespace std;

//giải thuật định giá biểu thức hậu tố
int Change(stack<int> st , string s){
    for (int i = 0 ; i < s.length() ; i++){
        if (s[i] == ' ') continue;

        if (s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            int a = st.top() ;
            st.pop();
            int b = st.top() ;
            st.pop();
            switch(s[i]){
                case '+':
                    st.push(b+a);
                    break;
                case '-':
                    st.push(b-a);
                    break;
                case '*':
                    st.push(b*a);
                    break;
                case '/' :
                    st.push(b/a);
                    break;
            }
        }
    }
    return st.top();
}


int main(){
	string s ;
	getline(cin,s);
	stack<int> st ;                     
	cout<<Change(st,s);
	
}