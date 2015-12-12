class tree
{
	unsigned int deg;
public:
	//virtual void addNode(int key) =0;
	//virtual int delNode(int key) =0;
	//virtual int find(int key) =0;
};



class bst :public tree
{
	bst *leftSubtree;
	bst *rightSubtree;
	int value;
public:
	bst();
	bst(int val);
	~bst();

	void addNodeWrapper(int key);
	void addNode(bst *root, int key);
	bst delNode(bst *root, int key);
	bst find(bst *root, int key);
	bst minimumLeft(bst *root);
};
