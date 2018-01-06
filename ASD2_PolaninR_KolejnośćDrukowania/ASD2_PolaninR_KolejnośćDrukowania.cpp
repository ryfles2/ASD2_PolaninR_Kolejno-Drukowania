#include <iostream>

using namespace std;

struct queue
{
	long value;
	bool flag;
};
class Print
{
public:
	//deklaracja rozmiaru tablicy
	long size_;
	//deklaracja wskaŸnika na tablicê typu long
	queue *tab_;


	Print::Print()
	{
		size_ = 0;
		tab_ = 0;
	}
	Print::~Print()
	{
		//usuwanie tablicy dynamicznej
		delete[] tab_;
	}
	//ustawienie rozmiaru tablicy
	void TabSize(long _value)
	{
		size_ = _value;
	}
	//utworzenie tablicy dynamicznej o rozmiarze sieze_
	void CreateTable()
	{
		if (tab_)
		{
			delete[] tab_;
		}
		tab_ = new queue[size_];
	}
	//wyœwietlanie ca³ej tablicy
	void PrintTab()
	{
		for (long i = 0; i < size_; i++)
		{
			cout << tab_[i].value << " "<<tab_[i].flag<<"    ";
		}
		std::cout << std::endl;
	}
	//Ustawienie kolejki
	long DoPrint()
	{
		long help = 0;
		bool helpFlag = false;
		long index = 0;
		long time = 0;
		if (index == size_ - 1)
		{
			time = 1;
		}
		while (index < size_)
		{
			for (long i = index; i < size_; i++)
			{
				if (tab_[index].value < tab_[i].value)
				{
					helpFlag = true;
				}
			}
			if (helpFlag == true)
			{
				for (long j = index; j < size_ - 1; j++)
				{
					helpFlag= tab_[j].flag;
					tab_[j].flag = tab_[j + 1].flag;
					tab_[j + 1].flag = helpFlag;

					help = tab_[j].value;
					tab_[j].value = tab_[j + 1].value;
					tab_[j + 1].value = help;
				}
				helpFlag = false;
			}
			else
			{
				//cout << "index= " << index << " " << endl;
				if (tab_[index].flag == true)
				{
					time = index + 1;
					break;
				}
				else
				{
					index++;
				}	
			}
		}
		return time;
	}
	void AddToTable(long _index, long _value)
	{
		tab_[_index].value = _value;
		tab_[_index].flag = false;
	}
	void AddFlag(long _index)
	{
		tab_[_index].flag = true;
	}
};




int main()
{
	Print D;
	long nTest = 0;
	cin >> nTest;

	long size = 0;
	long position = 0;
	long value = 0;

	for (long i = 0; i < nTest; i++)
	{
		cin >> size;
		D.TabSize(size);
		D.CreateTable();
		cin >> position;
		for (long j = 0; j < size; j++)
		{
			cin >> value;
			D.AddToTable(j, value);
		}
		D.AddFlag(position);
		//D.PrintTab();
		cout<<D.DoPrint()<<endl;
		//D.PrintTab();
	}


	return 0;
}