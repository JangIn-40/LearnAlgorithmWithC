#include <iostream>

struct node
{
	int key;
	node *next;
};

node *head;

void insert_node(int k)
{
	node *t;
	t = new node;
	t->key = 1;
	head = t;
	for (int i = 2; i <= k; ++i)
	{
		t->next = new node;
		t = t->next;
		t->key = i;
	}
	t->next = head;
}

void delete_after(node *t)
{
	node *s;
	s = t->next;
	t->next = t->next->next;
	delete s;
}

void joshephus(int n, int m)
{
	node *t;
	insert_node(n);
	t = head;
	while (t != t->next)
	{
		for (int i = 0; i < m - 1; ++i)
		{
			t = t->next;
		}
		std::cout << t->next->key << " ";
		delete_after(t);
	}
}

int main()
{
	int amount, distance;
	std::cout << "Input your node amount, distance ";
	std::cin >> amount >> distance;

	joshephus(amount, distance);
}