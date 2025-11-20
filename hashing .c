#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
int hashTable[TABLE_SIZE];

// Initialize hash table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;  // -1 indicates empty slot
}

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert function using linear probing
void insert(int key) {
    int index = hash(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("%d inserted at index %d\n", key, index);
}

// Search function
int search(int key) {
    int index = hash(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;

        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex)
            break;
    }

    return -1;  // Not found
}

// Display hash table
void display() {
    printf("Hash Table: \n");
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("Index %d: %d\n", i, hashTable[i]);
}

int main() {
    int choice, key;

    initialize();

    while (1) {
        printf("\n--- HASH TABLE MENU ---\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int pos = search(key);
                if (pos != -1)
                    printf("%d found at index %d\n", key, pos);
                else
                    printf("%d not found in hash table\n", key);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
