#include <cassert>
#include <iostream>
#include "RedBlackTree.h"

int main() {
	RedBlackTree<int> t;
	t.Add(0);
	t.Contains(0);
	t.Item(0);
	t.Remove(0);
	t.Clear();
	t.Size();
}