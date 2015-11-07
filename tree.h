struct node
{
	int key_value;
	node *left;
	node *right;
};

class btree
{
protected:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
	node *root;
public:
	btree();
	~btree();

	void insert(int key);
	node *search(int key);
	void destroy_tree();


};

void menu();
