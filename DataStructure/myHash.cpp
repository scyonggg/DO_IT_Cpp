#include <iostream>
#define NOITEM 0  // The entry have not been inserted
#define ISITEM 1  // The entry has been inserted
#define AVAILABLE 2  // The entry had been inserted and deleted now

using namespace std;

struct Entry {
    int key;
    string value;
    int valid;

    Entry() {
        key = 0;
        value = "";
        valid = NOITEM;
    }

    Entry(int key, string value) {
        this->key = key;
        this->value = value;
        this->valid = ISITEM;
    }

    void erase() {
        valid = AVAILABLE;
    }
};

// Linear hashing
class HashTable {
    Entry* hash_table;  // Hash table
    int capacity;  // Size of hash table

    int hash_func(int key) {  // Hash function
        return key % capacity;
    }
public:
    HashTable(int N) {
        capacity = N;
        hash_table = new Entry[capacity];
        return;
    }

    void put(int key, string value) {
        int index = hash_func(key);
        int probing = 1;

        while (hash_table[index].valid == ISITEM && probing <= capacity) {
            index = hash_func(index + 1);  // Linear probing
            probing++;
        }

        if (probing > capacity) return;
        hash_table[index] = Entry(key, value);
        return;
    }

    void erase(int key) {
        int index = hash_func(key);
        int probing = 1;

        while (hash_table[index].valid != NOITEM && probing <= capacity) {
            if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
                hash_table[index].erase();
                return;
            }
            index = hash_func(index + 1);
            probing++;
        }
        return;
    }
};

// Double hashing
class HashTable_double {
    Entry* hash_table;
    int capacity;
    int divisor;

    int hash_func(int key) {
        return key % capacity;
    }

    int hash_func2(int key) {  // d(k) = q - (k mod q)
        return divisor - (key % divisor);
    }

    void put(int key, string value) {
        int index = hash_func(key);
        int probing = 1;

        while (hash_table[index].valid == ISITEM && probing <= capacity) {
            index = hash_func(index + hash_func2(key));
            probing++;
        }

        if (probing > capacity) return;
        hash_table[index] = Entry(key, value);
        return;
    }

    void erase(int key) {
        int index = hash_func(key);
        int probing = 1;

        while (hash_table[index].valid != NOITEM && probing <= capacity) {
            if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
                hash_table[index].erase();
                return;
            }
            index = hash_func(index + hash_func2(key));
            probing++;
        }
        return;
    }
};