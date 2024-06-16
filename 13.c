#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Node structure for chaining
struct Node {
    int key;
    int value;
    struct Node* next;
};

// Hash table structure
struct HashTable {
    struct Node* table[TABLE_SIZE];
};

// Hash function (simple modulo operation)
int hash(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*) malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Insert key-value pair using chaining
void insertChaining(struct HashTable* hashTable, int key, int value) {
    int index = hash(key);
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        struct Node* current = hashTable->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Search for a key in the hash table (chaining)
struct Node* searchChaining(struct HashTable* hashTable, int key) {
    int index = hash(key);
    struct Node* current = hashTable->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Main function to demonstrate usage
int main() {
    struct HashTable* ht = createHashTable();

    // Insert example keys
    insertChaining(ht, 10, 100);
    insertChaining(ht, 20, 200);
    insertChaining(ht, 11, 110);

    // Search example key
    struct Node* result = searchChaining(ht, 20);
    if (result != NULL) {
        printf("Key found, value = %d\n", result->value);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
