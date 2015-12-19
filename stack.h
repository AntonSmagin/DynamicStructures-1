struct node 
{ 
 	int value;     // информационное поле
 	node *prev;    // указатель на предыдущий элемент
};

void print(node **top); 
void print1(node *top); 
void push(node **top, int d);   // занесение в стек  
int pop(node**top);             // удаление из стека

