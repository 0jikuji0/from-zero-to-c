/**
 * Exercise 23: Hash Table / Hash Map
 * Difficulty: **** (4/5)
 * 
 * Implement a simple hash table with collision resolution using linear probing.
 * Support insert, search, and delete operations.
 * 
 * Input:
 * - Commands: "insert key value", "search key", "delete key", or "exit"
 * 
 * Output:
 * - For search: print the value if found, or "not found"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    char* key;
    int value;
    int is_deleted;
} HashEntry;

typedef struct {
    HashEntry* entries;
    int size;
} HashTable;

unsigned int hashFunction(const char* key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash << 5) + hash + key[i];
    }
    return hash % TABLE_SIZE;
}

HashTable* createHashTable() {
    HashTable* table = malloc(sizeof(HashTable));
    table->entries = malloc(sizeof(HashEntry) * TABLE_SIZE);
    table->size = TABLE_SIZE;
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i].key = NULL;
        table->entries[i].is_deleted = 0;
    }
    
    return table;
}

void insert(HashTable* table, const char* key, int value) {
    unsigned int index = hashFunction(key);
    
    while (table->entries[index].key != NULL && !table->entries[index].is_deleted) {
        if (strcmp(table->entries[index].key, key) == 0) {
            table->entries[index].value = value;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    
    if (table->entries[index].key != NULL) {
        free(table->entries[index].key);
    }
    
    table->entries[index].key = malloc(strlen(key) + 1);
    strcpy(table->entries[index].key, key);
    table->entries[index].value = value;
    table->entries[index].is_deleted = 0;
}

int search(HashTable* table, const char* key) {
    unsigned int index = hashFunction(key);
    int iterations = 0;
    
    while (table->entries[index].key != NULL && iterations < TABLE_SIZE) {
        if (!table->entries[index].is_deleted && 
            strcmp(table->entries[index].key, key) == 0) {
            return table->entries[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
        iterations++;
    }
    
    return -1;
}

void deleteKey(HashTable* table, const char* key) {
    unsigned int index = hashFunction(key);
    int iterations = 0;
    
    while (table->entries[index].key != NULL && iterations < TABLE_SIZE) {
        if (!table->entries[index].is_deleted && 
            strcmp(table->entries[index].key, key) == 0) {
            table->entries[index].is_deleted = 1;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        iterations++;
    }
}

void freeHashTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->entries[i].key != NULL) {
            free(table->entries[i].key);
        }
    }
    free(table->entries);
    free(table);
}

int main() {
    HashTable* table = createHashTable();
    
    char cmd[50];
    while (scanf("%s", cmd) == 1) {
        if (strcmp(cmd, "exit") == 0) {
            break;
        }
        
        if (strcmp(cmd, "insert") == 0) {
            char key[50];
            int value;
            scanf("%s %d", key, &value);
            insert(table, key, value);
        } else if (strcmp(cmd, "search") == 0) {
            char key[50];
            scanf("%s", key);
            int result = search(table, key);
            if (result != -1) {
                printf("%d\n", result);
            } else {
                printf("not found\n");
            }
        } else if (strcmp(cmd, "delete") == 0) {
            char key[50];
            scanf("%s", key);
            deleteKey(table, key);
        }
    }
    
    freeHashTable(table);
    
    return 0;
}
