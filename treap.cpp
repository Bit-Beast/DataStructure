#include<bits/stdc++.h>
using namespace std;

template<class K,class D>
class node{

public:
	long long priority,siz;
	K key;
	D data;
	node<K,D> *L,*R;

	node(K k,D d):key(k),data(d),priority(rand()),siz(1),L(NULL),R(NULL)
	{

	}
};

template<class K,class D>
using treap_node = node<K,D>* ;

template<class K,class D>
class treap{

private:
	void split(treap_node<K,D> t,treap_node<K,D> &L,treap_node<K,D> &R,K key)
	{
		if(!t)L=R=NULL;
		else if(key >= t->key)
			split(t->R,t->R,R,key),L = t;
		else
			split(t->L,L,t->L,key),R = t;
		update_size(t);
	}

	void meld(treap_node<K,D> &t,treap_node<K,D> L,treap_node<K,D> R)
	{
		if(!L || !R)
			t = L?L:R;
		else if(L->priority > R->priority)
			meld(L->R,L->R,R), t = L;
		else 
			meld(R->L,L,R->L), t = R;

		update_size(t);

	}

	void inorder(treap_node<K,D> t)
	{
		if(!t)return;

		inorder(t->L);
		cout<<t->key<<" ";
		inorder(t->R);
	}

	void preorder(treap_node<K,D> t)
	{
		if(!t)return;

		cout<<t->key<<" ";

		
		preorder(t->L);		
		preorder(t->R);
	}

	void insert(treap_node<K,D> &t,treap_node<K,D> it)
	{
		if(!t)
			t=it;

		else if(it->priority > t->priority)
			split(t,it->L,it->R,it->key), t = it;

		else 
			insert(it->key < t->key ?t->L:t->R,it);
		update_size(t);
	}

	void erase(treap_node<K,D> &t,K key)
	{
		if(!t)
			return;

		else if(t->key == key)
			meld(t,t->L,t->R);
		else 
			erase(key < t->key ? t->L:t->R,key);
		update_size(t);
	}

public:
	treap_node<K,D> root;

	treap():root(NULL)
	{

	}

	long long sz(treap_node<K,D> t)
	{
		return t?t->siz:0;
	}

	void update_size(treap_node<K,D> t)
	{
		if(t)
			t->siz = sz(t->L)+sz(t->R)+1;
	}

	void insert(K key,D data)
	{
		treap_node<K,D> t = new node<K,D>(key,data);

		insert(root,t);
	}

	


	void erase(int k)
	{
		erase(root, k);
	}


	void inorder()
	{	cout<<"inorder traversal"<<endl;
		inorder(root);
		cout<<endl<<endl;
	}

	void preorder()
	{
		cout<<"preorder traversal"<<endl;
		preorder(root);
		cout<<endl<<endl;
	}



};


int main()
{
	treap<int,int>T;
	int i,n;
	n=5;

	
	for (int i = 0; i < n; ++i)
		//  T.insert(key,value)
		T.insert(i,10);
	
	T.preorder();
	// T.erase(key);
	T.erase(4);

	T.preorder();

}

