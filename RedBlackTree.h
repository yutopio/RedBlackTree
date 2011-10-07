
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.h"
#include "Traversal.h"

enum Color {
	Black,
	Red
};

template <class N>
struct Entity {
	Color color;
	N value;

	bool operator <(Entity val) { return value < val.value; }
	bool operator >(Entity val) { return value > val.value; }
	bool operator <=(Entity val) { return value <= val.value; }
	bool operator >=(Entity val) { return value >= val.value; }
	bool operator ==(Entity val) { return value == val.value; }
	bool operator !=(Entity val) { return value != val.value; }
};

template <class T>
class RedBlackTree {

private:
	static bool Delete(Node<Entity<T> > *node) {
		delete node;
		return false;
	}

public:
	RedBlackTree();
	explicit RedBlackTree(const RedBlackTree<T> &heap);
	virtual ~RedBlackTree() { Clear(); }

	void Add(T value);
	T Item(int index);

	void Clear() {
		if (root) DFS(root, Delete, PostOrder);
		root = NULL;
		size = 0;
	}

	bool Contains(T value);
	void Remove(T value);

	int Size() { return size; }

private:
	int size;
	Node<Entity<T> > *root;
};

template <class T>
RedBlackTree<T>::RedBlackTree() {
	root = NULL;
	size = 0;
}

template <class T>
void RedBlackTree<T>::Add(T value) {
	if (!root) {
		root = new Node<Entity<T> >();
		root->Value.value = value;
		size = 1;
		return;
	}

}

static int itemSeek = 0;

template <class T>
static bool ItemSeekCount(Node<Entity<T> > *n) {
	return !(itemSeek--);
}

template <class T>
T RedBlackTree<T>::Item(int index) {
	if (!size) {
		std::cerr << "[RedBlackTree] No more element in heap." << std::endl;
		return -1;
	}

	itemSeek = index;
	Node<Entity<T> > *seek = BFS<Node<Entity<T> > >(root, ItemSeekCount);
	return seek ? seek->Value.value : NULL;
}


template <class T>
bool RedBlackTree<T>::Contains(T value) {
	Node<Entity<T> > *seek = root;

	while (seek) {
		if (value < seek->Value) {
			seek = seek->Left;
		} else if (seek->Value < value) {
			seek = seek->Right;
		} else if (seek->Value == value) {
			return true;
		}
	}

	return false;
}

template <class T>
void RedBlackTree<T>::Remove(T value) {
	if (!root) return;
}


#endif
