/*-------------
Funciones para el BST
Sacadas de las actividades formativas
--------------*/

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;


template <class T> class BST;

template <class T>
class Node {
    private:
	    T value;
	    Node *left, *right;
	    Node<T>* succesor();

    public:
	    Node(T);
	    Node(T, Node<T>*, Node<T>*);
	    int height() const;
	    void add(T);
	    int whatlevelamI(T);
	    bool find(T); 
	    void remove(T);
	    void removeChilds();
	    void inorder(stringstream&) const;
	    void preorder(stringstream&) const;
	    void postorder(stringstream&) const;
	    void levelorder(stringstream&) const;
	    void printlevel(stringstream&, int) const;
        bool ancestors(T, stringstream&) const;
	
	    friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}
	
template <class T>
int Node<T>::height() const {

	int level_left = 0;
	int level_right = 0;

	if (left != 0) {
		level_left = left->height() + 1;
	}
	if (right != 0) {
		level_right= right->height() +1;
	}
	if (level_left == 0 && level_right == 0)
		return 1;

	return (level_right > level_left) ? level_right : level_left;
}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
int Node<T>::whatlevelamI(T val) {
	if (val == value) {
		return 1;
	} else if (val < value) {
		if(left != 0)
			return left->whatlevelamI(val) + 1;
	} else if (val > value) {
		if (right != 0)
		return right->whatlevelamI(val) + 1;
	}
	return -9999;
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
}

template <class T>
bool Node<T>::ancestors(T val, stringstream &aux) const{

	if (val == value) {
	  return true;
	} else if (val < value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (left != 0 && left->ancestors(val,aux));
	} else if (val > value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (right != 0 && right->ancestors(val,aux));
	}
}

template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *l, *r;

	l = left;
	r = right;

	if (left == 0) {
		if (right != 0) {
			right = 0;
		}
		return r;
	}

	if (left->right == 0) {
		left = left->left;
		l->left = 0;
		return l;
	}

	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}

template <class T>
void Node<T>::remove(T val) {
	Node<T> * succ, *old;

	if (val < value) {
		if (left != 0) {
			if (left->value == val) {
				old = left;
				succ = left->succesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != 0) {
			if (right->value == val) {
				old = right;
				succ = right->succesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			} else {
				right->remove(val);
			}
		}
	}
}

template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

template <class T>
void Node<T>::inorder(stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(stringstream &aux) const {
	if (left != 0) {
		left->postorder(aux);
	}

	if (right != 0) {
		right->postorder(aux);
	}
	if (aux.tellp() != 1) {
			aux << " ";
	}
	aux << value;
}

template <class T>
void Node<T>::printlevel(stringstream &aux, int level) const {

	if(level == 0){
		if (aux.tellp() != 1) {
				aux << " ";
		}
		aux << value;
	}
	if (left != 0) {
		left->printlevel(aux, level -1);
	}
	if (right != 0) {
		right->printlevel(aux, level -1);
	}

}

template <class T>
void Node<T>::levelorder(stringstream &aux) const {
	int level = height();
	for(int i = 0; i < level; i++){
			printlevel(aux, i);
	}
}

//-------------------------------------------------------------

template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	~BST();
	string visit();
	int height() const;
	void add(T);
	string ancestors(T) const;
	int  whatlevelamI(T) const;
	bool empty() const;
	bool find(T) const;	
	void remove(T);
	void removeAll();
	string inorder() const;
	string preorder() const;
	string postorder() const;
	string levelorder() const;
	void ordenar(vector<T> &h);		
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template <class T>
string BST<T>::visit() {
	stringstream aux;
	aux << preorder() << "\n";
	aux << inorder() << "\n";
	aux << postorder() << "\n";
	aux << levelorder();
	return aux.str();
}

template <class T>
int BST<T>::height() const {
	return root->height();
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
string BST<T>::ancestors(T val) const {
	stringstream aux;
	aux << "[";
	if (!empty()) {
		if(!root->ancestors(val, aux))
			return "[]";
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val) const {
	if (root != 0) {
	 	int num = root->whatlevelamI(val);
		if(num < 0) return -1;
		return num;
	}
	else {
		return -1;
	}
}

template <class T>
void BST<T>::remove(T val) {
	if (root != 0) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != 0) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		} else {
			root->remove(val);
		}
	}
}

template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	}
	else {
		return false;
	}
}

template <class T>
string BST<T>::inorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::preorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::postorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::levelorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->levelorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
void BST<T>::ordenar(vector<T> &h){
	int min;
	string aux, aux2;
	for(int i=0; i<h.size()-1; i++){
		min=i;
		for(int j=i+1; j<h.size()-1; j++){
			if(h[j]<h[min]){
				min=j;
			}
		}
		aux=h[i];
		h[i]=h[min];
		h[min]=aux;
	}
}

#endif
