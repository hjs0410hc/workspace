#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* parent;
	vector<Node*> childlist;
	int numofchild;
	bool deleted;
	Node(int d){
		this->data =d;
		this->parent =NULL;
		this->numofchild = 0;
		deleted = false;
	}
	bool isLeaf(){
		return (numofchild == 0);
	}
};

class Tree{
	public:
	Node* root;
	vector<Node*> nodelist;
	Tree(int N){
		for(int i=0;i<N;i++){
			Node* newNode = new Node(i);
			nodelist.push_back(newNode);
		}
		root = nodelist[0];
	}
	
	void insert(int par,int chi){
		if(par!=-1){
			nodelist[chi]->parent = nodelist[par];
			nodelist[par]->childlist.push_back(nodelist[chi]);
			nodelist[par]->numofchild++;
		}
	}
	void erase(Node* e){
		e->deleted = true;
		if(e->parent)e->parent->numofchild--;
		for(auto w:e->childlist){
			erase(w); //DFS
		}
	}
	int solve(){
		int ret = 0;
		for(int i=0;i<nodelist.size();i++){
			if(!nodelist[i]->deleted && nodelist[i]->isLeaf()){
				ret++;
			}
		}
		return ret;
	}
};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	Tree t(n);
	for(int i=0;i<n;i++){
		int par;cin>>par;
		t.insert(par,i);
	}
	int k;cin>>k;
	t.erase(t.nodelist[k]);
	cout << t.solve();
	
}