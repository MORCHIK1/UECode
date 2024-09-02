#include <iostream>

class Treap {
private:
	//template <typename T>
	struct TreapNode {
		TreapNode* parent = nullptr;
		TreapNode* right = nullptr;
		TreapNode* left = nullptr;
		double priority;
		int key;

		TreapNode(double _priority, int k) : priority(_priority), key(k)
		{}
		void SetLeft(TreapNode* child) {
			this->left = child;
			child->parent = this;
		}
		void SetRight(TreapNode* child) {
			this->right = child;
			child->parent = this;
		}
	};

	TreapNode* root;

	void RotateRight(TreapNode* rotate_child) {
		TreapNode* rotate_parent = rotate_child->parent;
		if (rotate_parent->parent != nullptr) {
			TreapNode* SaveNode = rotate_parent->parent;
			SaveNode->left = rotate_child;
			rotate_parent->SetLeft(rotate_child->right);
			rotate_child->right->SetRight(rotate_parent);
		}
		else {
			TreapNode* SaveNode = rotate_child->right;
			rotate_child->right->SetRight(rotate_parent);
			rotate_parent->SetLeft(SaveNode);
		}
	}
};