#include<iostream>
using namespace std;
int Max = 450; 
class Hash {
	
public:
	int* Arr;
	int HashFuntion(int);
	Hash();
	void Insert(int);
	void Display();

};
Hash::Hash()
{
	this->Arr = new int[Max];
	for (int i = 0; i < Max; i++)
	{
		this->Arr[i] = INT_MIN;
	}
}
int Hash::HashFuntion(int key)
{
	return (key % Max);
}
void Hash::Insert(int key)
{
	int Index = this->HashFuntion(key);
	int count = 0;
	if (this->Arr[Index] == INT_MIN)
	{
		this->Arr[Index] = key;
	}
	else
	{
		cout << "Duplicate Data is not allowed" << endl;
	}
}
void Hash::Display()
{
	cout << "Index"<<"	"<<"Value" << endl;
	for (int i = 0; i < Max; i++)
	{
		if (this->Arr[i] != INT_MIN)
		{
			cout << i << "	" << this->Arr[i] << endl;;
		}
	}
	cout << endl;
}

int main(void)
{
	int RollNo;
	Hash obj;
	cout << "Enter Roll No or Press -111 to Exit : ";
	cin >> RollNo;
	while (RollNo != -111)
	{
		obj.Insert(RollNo);
		cout << "Enter Roll No or Press -111 to Exit : ";
		cin >> RollNo;
	}
	cout << endl;
	obj.Display();
	cout << endl;
	system("pause");
	return 0;
}
