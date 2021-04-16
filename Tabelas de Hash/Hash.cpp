#include <string>
#include <list>
#include <iostream>
#include <stdexcept>

using namespace std;

struct KeyAndValue 
{
    string key;
    long value;
};

class HashTable 
{
    list<KeyAndValue>* table;
    size_t _size;
    size_t hashing(string key) 
    {            // existe hash na bilioteca do C++
        size_t index = key[0] - 'A' + key[1] - 'a';
        return index % _size;
    }
public:
    HashTable(size_t sz) 
    {
        table = new list<KeyAndValue>[sz];
        _size = sz;
    }
    void add(const string& key, long value) 
    {
        size_t index = hashing(key);
        table[index].push_back({ key, value });
    }
    int get(const string& key) {
        size_t index = hashing(key);
        for (KeyAndValue kv : table[index]) 
        {
            if (kv.key == key)
                return kv.value;
        }
        throw out_of_range("The name does not exist!");
    }
    bool remove(const string& key) 
    {
        size_t index = hashing(key);
        for (list<KeyAndValue>::iterator it = table[index].begin();
            it != table[index].end();
            it++)
            if (it->key == key) 
            {
                table[index].erase(it);
                return true;
            }
        return false;
    }
    size_t size() 
    {
        size_t count = 0;
        for (int i = 0; i < _size; i++)
            count += table[i].size();
        return count;
    }
    float loadFactor() 
    {
        size_t occupied = 0;
        for (int i = 0; i < _size; i++)
            if (table[i].size() > 0)
                occupied++;
        return static_cast<float>(occupied) / _size;
    }
};

int main()
{
    HashTable telefones(200);
    telefones.add("jose", 919293949);
    telefones.add("joao", 911922933);
    telefones.add("maria", 922933944);

    string name;
    long number;
    cin >> name;
    try 
    {
        number = telefones.get(name);
        cout << number << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    cin >> name;
    if (telefones.remove(name))
        cout << "Removido!\n";
    else
        cout << "Nao existe!\n";

    cout << telefones.size() << endl;
    cout << telefones.loadFactor() << endl;
}


