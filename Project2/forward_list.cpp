#include <iostream>
using namespace std;

template <class T>
struct Element
{
	// Данные
	T data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
template <class T>
class List
{
	// Адрес головного элемента списка
	Element<T>* Head;
	// Адрес головного элемента списка
	Element<T>* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(T data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();

	void Delete(int value);

	void AddToPosition(int value, T data);

	void Search(int value);
};

template <class T>
List<T>::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

template <class T>
List<T>::~List()
{
	// Вызов функции удаления
	DelAll();
}

template <class T>
int List<T>::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}



template <class T>
void List<T>::Add(T data)
{
	// создание нового элемента
	Element<T>* temp = new Element<T>;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
	}
}
template <class T>
void List<T>::Del()
{
	// запоминаем адрес головного элемента
	Element<T>* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

template<class T>
void List<T>::Delete(int value)
{
	if (value == 0)
	{
		Del();
	}
	Element<T>* temp = Head;
	for (int i = 0; i < value - 1; i++)
	{
		temp = temp->Next;
	}
	Element<T>* element = temp->Next;
	temp->Next = element->Next;
	delete element;
}

template<class T>
void List<T>::AddToPosition(int value, T data)
{
	Element<T>* newElement = new Element<T>;
	if (value == 0)
	{
		newElement->Next = Head;
		Head = newElement;
	}
	Element<T>* temp = Head;
	for (int i = 0; i < value - 1; i++)
	{
		temp = temp->Next;
	}
	newElement->Next = temp->Next;
	temp->Next = newElement;
}

template<class T>
void List<T>::Search(int value)
{
	Element<T>* temp = Head;
	for (int i = 0; i < value - 1; i++)
	{
		temp = temp->Next;
	}
	cout << "Position: " << value << " Data: " << temp->data;

	if (value < 0 || Head == nullptr)
	{
		cout << "Ploxo position!" << endl;
	}
}







template <class T>
void List<T>::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}
template <class T>

void List<T>::Print()
{
	// запоминаем адрес головного элемента
	Element<T>* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}
	cout << "\n\n";
}
// Тестовый пример
void main()
{
	// Создаем объект класса List
	List<char> lst;

	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << "\n\n";
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	lst.Print();
	// Удаляем три элемента списка
	lst.Del();
	lst.Del();
	lst.Del();
	//Распечатываем содержимое списка
	lst.Print();

	lst.Delete(5);
	lst.AddToPosition(2, 'g');
	lst.Search(4);
	lst.Print();
}






