#include <string>
#include<list>
using namespace std;

struct KeyandValue
{
	string name;
	int value;
};

class HashTable
{
	// int* table = new int[100];	
	// = int* table=(int*)malloc(100*sizeof(int)) 
	list<KeyandValue>* table;
	size_t size;
	size_t hashing(string key)		// hash na biblioteca c++
	{
		return key[0] + key[1] % size;
	}
public:
	HashTable(size_t sz)
	{
		table = new list<KeyandValue>[sz];
		size = sz;
	}
	void add(const string& key, int value)
	{
		size_t index = hashing(key);
		table[index].push_back({key, value}); // uma estrutura
	}
	int get(const string& key);
	bool remove(const string& key);
};