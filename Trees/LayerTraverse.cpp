#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	Node * left;
	Node * right;
	char data;
};

void visit(Node * node)
{
	if (node)
		cout << "visit : " << node->data << endl;
}
void LayerTraverse(Node * head, void (*visit) (Node*))
{
	if (!head)
		return;
	queue<Node*> q;
	q.push(head);
	while(!q.empty())
	{
		Node * temp = q.front();
		(*visit)(temp);
		q.pop();
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}

size_t PrintAtLayer(Node * head, size_t layer)
{
	if (!head)
		return 0;
	if (layer == 0)
	{
		cout << head->data << " ";
		return 1;
	}
	size_t nleft = PrintAtLayer(head->left, layer-1);
	size_t nright = PrintAtLayer(head->right, layer-1);
	return nleft + nright;
}

void PrintByLayer(Node * head)
{
	if (!head)
		return;
	queue<Node*> q;
	q.push(head);
	int size = q.size();
	while(!q.empty())
	{
		Node * temp = q.front();
		cout << temp->data << " ";
		q.pop();
		if (--size == 0)
			cout << endl;
		size = q.size();
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}

int main()
{
	Node * head = new Node();
	head->data = 'a';

	head->left = new Node();
	Node * left = head->left;
	left->data = 'b';
	left->left = new Node();
	left->left->data = 'd';
	left->left->left = NULL;
	left->left->right = NULL;
	left->right = new Node();
	left->right->data = 'e';
	left->right->left = NULL;
	left->right->right = NULL;

	head->right = new Node();
	Node * right = head->right;
	right->data = 'c';
	right->left = NULL;
	right->right = new Node();
	right->right->data = 'f';
	right->right->right = NULL;
	right->right->left = new Node();
	right->right->left->data = 'g';
	right->right->left->left = NULL;
	right->right->left->right = NULL;

	cout << "Layer Traverse :" << endl;
	LayerTraverse(head, visit);	
	cout << "\n\nprint 2nd layer : ";
	int n = PrintAtLayer(head, 2);
	cout << endl << n << " nodes";
	cout << "\n\nprint all layers :"<< endl;
	PrintByLayer(head);
}
		