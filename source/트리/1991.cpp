#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	char data;
	Node* parent;
	Node* left;
	Node* right;
	Node(char d){
		this->data = d;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};

class BinaryTree{
	public:
	Node* root;
	vector<Node*> nodelist;
	BinaryTree(){
		Node* newroot = new Node('A');
		nodelist.push_back(newroot);
		root = newroot;
	}
	bool isEmpty(){
		return root==NULL;
	}
	Node* find(char c){
		for(int i=0;i<nodelist.size();i++){
			if(nodelist[i]->data == c){
				return nodelist[i];
			}
		}
		return NULL;
	}
	void insert(char par,char lc,char rc){
		Node* parent = find(par);
		Node* newlc = NULL;
		Node* newrc = NULL;
		if(lc != '.' && rc != '.'){
			newlc = new Node(lc);
			newlc->parent=parent;
			newrc = new Node(rc);
			newrc->parent=parent;
			nodelist.push_back(newlc);
			nodelist.push_back(newrc);
		}else if(lc != '.' && rc == '.'){
			newlc = new Node(lc);
			newlc->parent=parent;
			nodelist.push_back(newlc);
		}else if(lc == '.' && rc != '.'){
			newrc = new Node(rc);
			newrc->parent=parent;
			nodelist.push_back(newrc);
		}
		parent->left = newlc;
		parent->right = newrc;
	}
	void preorder(Node* v){
		cout << v->data;
		if(v->left)preorder(v->left);
		if(v->right)preorder(v->right);
	}
	void preorder(){
		preorder(root);
	}
	void inorder(Node* v){
		if(v->left)inorder(v->left);
		cout << v->data;
		if(v->right)inorder(v->right);
	}
	void inorder(){
		inorder(root);
	}
	void postorder(Node* v){
		if(v->left)postorder(v->left);
		if(v->right)postorder(v->right);
		cout << v->data;
	}
	void postorder(){
		postorder(root);
	}
};


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	BinaryTree bt;
	for(int i=0;i<n;i++){
		char c1,c2,c3;cin>>c1>>c2>>c3;
		bt.insert(c1,c2,c3);
	}
	bt.preorder();
	cout << "\n";
	bt.inorder();
	cout << "\n";
	bt.postorder();
	
	
}