struct Node
{
	int value; //информационное поле
	Node *prev; //указатель на предыдущий элемент
};


Node *First(int value); // создание первого элемента в очереди
void add(Node **pend, int value); // добавление элемента в очередь
int del(Node **pbeg); // удаление элемента из очереди
void print(Node **pbeg); // печать элементов очереди
void menu(); // интерфейс очереди
