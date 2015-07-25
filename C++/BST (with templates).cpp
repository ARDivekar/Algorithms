#include<iostream>
#include "Queue (with templates).h"
using namespace std;

template<typename T>
class Node{
	public:
	T data;
	Node<T> *left;
	Node<T> *right;
	Node<T> *parent; 
	int times_visited;
	Node(T input_data=NULL){
		data=input_data;
		left=NULL;
		right=NULL;
		parent =NULL;	 
	}
	
};



template<typename T>
class BinarySearchTree{
	private:
	long n;
	Node<T> *root;
	

	public:
 	BinarySearchTree(Node<T> *input_root=NULL, long input_size=0){
		n=input_size;
		root=input_root;
	}
	

	Node<T>* search(T data, Node<T> *p=NULL){
		if(!p) p=root;
		while(p!=NULL && p->data!=data){
			if(data <= p->data)
				p=p->left;
			else 
				p=p->right;
		}
		return p;
	}


	void insert(T  data, Node<T> *p=NULL){
		if(!p) p=root;
		Node<T> *par=NULL;
		while(p!=NULL){
			par=p;
			if(data <= p->data)
				p=p->left;
			else 
				p=p->right;
		}
		Node<T> *z=new Node<T>(data);
		if(root==NULL){
			root=z;
			n=1;
			return;
		}
		z->parent=par;
		if(data<=par->data)
			par->left=z;
		else
			par->right=z;

		n+=1;	 	 	 	 
	}


	Node<T>* Tree_min(Node<T> *p=NULL){
		if(!p) p=root;
		while(p->left!=NULL)
			p=p->left;
		return p;
	}

	void transplant(Node<T> *u, Node<T> *v){	// u belongs to this tree, v may not
		if(u->parent!=NULL){
			if(u==u->parent->left)
				u->parent->left=v;
			else 
				u->parent->right=v;
		}
		else 
			root=v;
		if(v!=NULL)
			v->parent=u->parent;
		u->parent=NULL;
		delete u;
	}
	
	void remove(T data, Node<T> *p=NULL){
		cout<<"\nRemoving "<<data<<endl;
		if(!p) p=root;
		Node<T> *z=search(data);
		if(z==NULL)
			return;
		
		if(z->left==NULL)
			transplant(z,z->right);
		else if(z->right==NULL)  //z->left!=NULL, but z->right==NULL
			transplant(z,z->left);
		else{ //both children exist
			Node<T> *succ=Tree_min(z->right);
			T succ_data=succ->data;
			transplant(succ,succ->right);
			z->data=succ->data;
		}
		n-=1;
				
	}

	void inorder(){
		cout<<"\n<---BST--->"<<endl;
		inorder(root);
		cout<<"\n<---End of BST--->"<<endl;
	}

	void inorder(Node<T> *p){
		if(p){
			inorder(p->left);
			cout<<p->data<<" ";
			inorder(p->right);
		}
	}

	void postorder(){
		cout<<"\n<---BST Postorder--->"<<endl;
		postorder(root);
		cout<<"\n<---End of BST--->"<<endl;
	}

	void postorder(Node<T> *p){
		if(p){
			postorder(p->left);
			postorder(p->right);
			cout<<p->data<<" ";
		}
	}

	
	void level_order(Node<T> *p=NULL){
		cout<<"\n<---BST--->"<<endl;
		if(!p) p=root;
		Queue<Node<T> *> * Q=new Queue<Node<T> *>();
		Q->enqueue(p);
		while(!Q->is_empty()){
			Node<T> *temp=Q->dequeue();
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
				Q->enqueue(temp->left);
			if(temp->right!=NULL)
				Q->enqueue(temp->right);

		}
		cout<<"\n<---End of BST--->"<<endl;
	}

	bool is_tree(Node<T> *p=NULL){
		if(!p) p=root;
		return is_tree(p, NULL, NULL);
	}

	private:

	bool is_tree(Node<T> *n, long min, long max){
		if(n==NULL) return true;		
		cout<<"\nmin: "<<min<<" data: "<<n->data<<" max: "<<max;
		if((min!=NULL && n->data <=min) || (max!=NULL && n->data > max))
			return false;
		if(!is_tree(n->left, min, n->data) || !is_tree(n->right, n->data, max))
			return false;
		return true;
	}
	
	public:
	
	Node<T> *Tree_max(Node<T> *p=NULL){
		if(!p) p=root;
		while(p->right!=NULL)
			p=p->right;
		return p;
	}
		
	Node<T>* successor(T data, Node<T> *p=NULL){ //top-down successor, does not need parent pointer
		if(!p) p=root;
		Node<T> *lowest_common_ancestor=NULL;
		if(data>=Tree_max(p)->data) //case where data is the largest element, or larger, thus has no successor
			return NULL;

		while(p!=NULL && p->data!=data){
			if(data<=p->data){
				lowest_common_ancestor=p;
				p=p->left;
			}
			else
				p=p->right;
		}
		if(p==NULL) //the item 'data' does not exist in the tree
			return NULL;
		//below, we assume p->data == data.
		if(p->right!=NULL)
			return Tree_min(p->right);
		else
			return lowest_common_ancestor;
		
	}



	void Morris_inorder(Node<T> *p=NULL){
		if(!p) p=root;
		Node<T> *current=p;
		Node<T> *pred=NULL;
		while(current!=NULL){
			if(current->left==NULL){
				cout<<current->data<<" ";
				current=current->right;
			}
			else{
				pred=current->left;
				while(pred->right!=NULL && pred->right!=current)
					pred=pred->right;
				
				if (pred->right == NULL){
					pred->right=current;
					current=current->left;
				}
				else if (pred->right==current){
					pred->right=NULL;
					cout<<current->data<<" ";
					current=current->right;
				}
			}
		}
	}

};


int main(){
	BinarySearchTree<int> *t=new BinarySearchTree<int>();


	t->insert(5);
	t->insert(3);
	t->insert(9);
	t->insert(2);
	t->insert(4);
	t->insert(4);
	t->insert(1);
	t->insert(12);
	t->insert(6);
	t->insert(7);
	t->insert(10);
	t->insert(9);

	t->postorder();
	//t->Morris_inorder();
	//cout<<"\n\n"<<t->is_tree();
	t->inorder();

	/*t->insert( -5);
	t->insert( -15);
	t->insert( -3);
	t->insert( -14);
	t->insert( -25);
	t->insert( -10);
	cout<<t->successor(-5)->data<<endl;
	t->inorder();

	if(t->is_tree())
		t->inorder();
	t->remove(-25);
	if(t->is_tree())
		t->inorder();	   
	t->remove(-14);
	if(t->is_tree())
		t->inorder();
	*/	  
		

}

