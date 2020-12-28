#pragma warning (disable : 4996)
#include <iostream>
#include <windows.h>
using namespace std;

struct Item
{
	Item* leftItem = nullptr;
	int value = 0;
	Item* rightItem = nullptr;
};

struct List
{
	Item* beginPoint = nullptr;
	Item* endPoint = nullptr;
	//добавление в конец списка
	void Insert(int value)
	{
		Item* NewItem = new Item;
		NewItem->value = value;
		if (this->beginPoint == nullptr) //если нет элементов
			this->beginPoint = NewItem;

		if (this->endPoint != nullptr)	//делаем двунаправленые связи и элементов
		{
			NewItem->leftItem = this->endPoint;
			this->endPoint->rightItem = NewItem;
		}
		this->endPoint = NewItem;
	}
	//добавление в начало списка
	void InsertBegin(int value)
	{
		Item* NewItem = new Item;
		NewItem->value = value;
		if (this->beginPoint == nullptr)//если нет элементов
		{
			this->beginPoint = NewItem;
			this->endPoint = NewItem;
		}
		else
		{
			this->beginPoint->leftItem = NewItem;
			NewItem->rightItem = this->beginPoint;
			this->beginPoint = NewItem;
		}
	}

	//Печать
	void Print()
	{
		Item* tmppoint = beginPoint;
		if (tmppoint == nullptr)
		{
			cout << "Список пуст!\n";
			return;
		}

		while (tmppoint != endPoint)
		{
			cout << tmppoint->value << "\t";
			tmppoint = tmppoint->rightItem;
		}
		cout << endPoint->value << endl;
	}
	//Удаление элемента из списка
	void Delete(unsigned int index)
	{
		unsigned int counter = 0;
		Item* tmppoint = this->beginPoint;
		if (index == 0)//если удаляемый элемент является вначале списка
		{
			this->beginPoint = this->beginPoint->rightItem;
			delete tmppoint;
			return;
		}

		while (index != counter)//ищем элемент с индексом
		{
			tmppoint = tmppoint->rightItem;
			counter++;
			if (tmppoint == nullptr)
			{
				cout << "Выход за пределы списка";
				return;
			}
		}

		if (tmppoint == this->endPoint)//если удаляемый элемент является в конце списка
		{
			this->endPoint = this->endPoint->leftItem;
			if (this->endPoint == nullptr)
				this->beginPoint = nullptr;
			delete tmppoint;
			return;
		}

		// меняем указатели слева на право и справо налево
		Item* tmppointl = tmppoint->leftItem;
		Item* tmppointr = tmppoint->rightItem;
		tmppointl->rightItem = tmppointr;
		tmppointr->leftItem = tmppointl;
		delete tmppoint;
	}

	//уничтожение списка
	void Clear()
	{
		Item* tmpItemp = this->beginPoint;
		this->beginPoint = nullptr;
		this->endPoint = nullptr;
		while (tmpItemp != nullptr)
		{
			Item* deleteItem = tmpItemp;
			tmpItemp = tmpItemp->rightItem;
			delete deleteItem;
		}
	}

	//запись в файл
	void WriteToFile(const char* filepath)
	{
		FILE* file = fopen(filepath, "w+");
		Item* tmpItemp = this->beginPoint;
		while (tmpItemp != nullptr)
		{
			fwrite(&tmpItemp->value, sizeof(tmpItemp->value), 1, file);
			tmpItemp = tmpItemp->rightItem;
		}

		fclose(file);
	}

	void ReadFromFile(const char* filepath)
	{
		FILE* file = fopen(filepath, "r");
		int buffer;
		while (fread(&buffer, 4, 1, file))
			this->Insert(buffer);
		fclose(file);
	}

	~List()
	{
		this->Clear();
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List list;

	list.Insert(2);
	list.Insert(3);
	list.Insert(4);
	list.Insert(5);
	list.Insert(6);
	list.Insert(7);
	list.InsertBegin(1);
	list.InsertBegin(0);
	cout << "Элементы списка: " << endl;
	list.Print();
	cout << endl;
	list.Delete(4);
	cout << "Номер удаляемого элемента: 4 " << endl;
	cout << "Элементы списка: " << endl;
	list.Print();
	cout << endl;
	cout << "Добавление элемента в начало списка: " << endl;
	list.InsertBegin(10);
	list.Print();
	cout << endl;
	list.WriteToFile("F.txt");
	cout << "Элементы списка: " << endl;
	list.Clear();
	list.Print();
	cout << endl;
	cout << "Востановленный список " << endl;
	cout << "Элементы списка: " << endl;
	list.ReadFromFile("F.txt");
	list.Print();
	return 0;
}

