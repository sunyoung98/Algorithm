#include <iostream>
#include <string>

using namespace std;


typedef struct node *nodePointer;
class node {
private:
	char data;
	nodePointer left, right;
public:
	node() {
		data = NULL;
		left = NULL;
		right = NULL;
	}
	void setData(char data) {
		this->data = data;
	}
	void setLeft(node *left) {
		this->left = left;
	}
	void setRight(node *right) {
		this->right = right;
	}
	void preorder(nodePointer pointer) {
		if (pointer) {
			cout << pointer->data;
			preorder(pointer->left);
			preorder(pointer->right);
		}
	}
	void inorder(nodePointer pointer) {
		if (pointer) {
			inorder(pointer->left);
			cout << pointer->data;
			inorder(pointer->right);
		}
	}
	void postorder(nodePointer pointer) {
		if (pointer) {
			postorder(pointer->left);
			postorder(pointer->right);
			cout << pointer->data;
		}
	}

};

int main() {
	int UserNum;
	cin >> UserNum;
	char data, left, right;
	node *nodes = new node[UserNum];
	for (int i = 0; i < UserNum; i++) {
		cin >> data >> left >> right;
		nodes[(int)(data-'A')].setData(data);
		if (left != '.')
			nodes[(int)(data-'A')].setLeft(&nodes[(int)(left-'A')]);
		else
			nodes[(int)(data - 'A')].setLeft(NULL);
		if (right != '.')
			nodes[(int)(data - 'A')].setRight(&nodes[(int)(right - 'A')]);
		else
			nodes[(int)(data - 'A')].setRight(NULL);

	}
	nodes->preorder(&nodes[0]);
	cout << endl;
	nodes->inorder(&nodes[0]);
	cout << endl;
	nodes->postorder(&nodes[0]);
	return 0;
}