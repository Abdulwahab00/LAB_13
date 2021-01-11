#include<iostream>
using namespace std;
int Max = 20;
class Hash {
	
public:
	int* Arr;
	int HashFuntion(int);
	Hash();
	void Display();
	void Insert(int);
	bool Search(int);
	void Delete(int);
	

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
void Hash::Delete(int key)
{
	int index;
	int count = 1;
	if (this->Search(key))
	{
		index = this->HashFuntion(key);
		this->Arr[index] = INT_MIN;
		while (true)
		{
			index = this->HashFuntion(key + count);
			count++;
			if (this->Arr[index] == INT_MIN)
			{
				break;
			}
			else
			{
				int val = this->Arr[index];
				this->Arr[index] = INT_MIN;
				this->Insert(val);


			}
		}
	}
	else
	{
		cout << "Data is not present" << endl;
	}
}
void Hash::Display()
{
	cout << "Index" << "	" << "Value" << endl;
	for (int i = 0; i < Max; i++)
	{
		if (this->Arr[i] != INT_MIN)
		{
			cout << i << "	" << this->Arr[i] << endl;;
		}
	}
	cout << endl;
}
void Hash::Insert(int key)
{
	int i = this->HashFuntion(key);
	int count = 0;
	if (this->Arr[i] == INT_MIN)
	{
		this->Arr[i] = key;
	}
	else 
	{
		do
		{
			i = this->HashFuntion(key + count); 
			count++;
			if (i >= Max)
			{
				cout << "Hash Table is Full" << endl;
				
				return;
			}

		} while (this->Arr[i] != INT_MIN);
		if (this->Arr[i] == key)
		{
			cerr << "Duplicate Data is not allowed" << endl;
		}
		else
		{
			this->Arr[i] = key;
		}
	}
}
bool Hash::Search(int key)
{
	int i = this->HashFuntion(key);
	if (this->Arr[i] == key)
	{
		return true;
	}
	else
	{
		int c = 0;
		do
		{
			i = this->HashFuntion(key + c);
			c++;
			if (i >= Max)
			{
				return false;
			}
			if (this->Arr[i] == key)
			{
				return true;
			}
		} while (this->Arr[i] != INT_MIN);
		if (this->Arr[i] == INT_MIN) 
		{
			return false;
		}
	}
}

int main(void)
{
	Hash obj;
	int opt;
	int key = 0;
	do
	{
		cout << "Press 1 --> Insert()" << endl
			<< "Press 2 --> Search()" << endl
			<< "Press 3 --> Delete()" << endl
			<< "Press 4 --> Display()" << endl;
		cout << endl;
		cin >> opt;
		cout << endl;
		switch (opt)
		{
		case 1:
		{
			
			
			while (key!=-111)
			{
				cout << "Enter the key or press -111 to exit: ";
				cin >> key;
				if (key!=-111)
				{
					obj.Insert(key);
				}
				
				
			}
			cout << endl;
			break;
			
		}
		
		case 2:
		{
			int n;
			cout << "Enter the key : ";
			cin >> n;
			if (obj.Search(n))
			{
				cout << n << " Key Found!!!" << endl;
			}
			else
			{
				cout << n << " Key does not Found!!!" << endl;
			}
			break;
		}
		
		case 3:
		{
			int n;
			cout << "Enter the key: ";
			cin >> n;
			obj.Delete(n);
			break;

		}
		
		case 4:
		{
			obj.Display();
			break;
		}
		default:
			cout << "Select the Correct Option" << endl;
			break;
		}
	} while (opt);

	system("pause");
	return 0;
}