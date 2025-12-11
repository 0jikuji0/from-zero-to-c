/**
 * Exercise 47: Skip List
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing Skip List with random height assignment.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEVEL 16

typedef struct SkipNode {
    int key;
    int value;
    struct SkipNode **forward;
    int level;
} SkipNode;

typedef struct {
    SkipNode *header;
    int level;
} SkipList;

int randomLevel() {
    int level = 0;
    while (rand() % 2 == 0 && level < MAX_LEVEL - 1) {
        level++;
    }
    return level;
}

SkipNode* createNode(int key, int value, int level) {
    SkipNode *node = (SkipNode*)malloc(sizeof(SkipNode));
    node->key = key;
    node->value = value;
    node->level = level;
    node->forward = (SkipNode**)malloc((level + 1) * sizeof(SkipNode*));
    
    for (int i = 0; i <= level; i++) {
        node->forward[i] = NULL;
    }
    
    return node;
}

SkipList* initSkipList() {
    SkipList *list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 0;
    list->header = createNode(-1, -1, MAX_LEVEL - 1);
    return list;
}

int search(SkipList *list, int key) {
    SkipNode *node = list->header;
    
    for (int i = list->level; i >= 0; i--) {
        while (node->forward[i] && node->forward[i]->key < key) {
            node = node->forward[i];
        }
    }
    
    node = node->forward[0];
    
    if (node && node->key == key) {
        return node->value;
    }
    return -1; // Not found
}

void insert(SkipList *list, int key, int value) {
    SkipNode *current = list->header;
    SkipNode **update = (SkipNode**)malloc((MAX_LEVEL) * sizeof(SkipNode*));
    
    // Find position to insert
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    current = current->forward[0];
    
    if (current && current->key == key) {
        current->value = value; // Update existing key
        free(update);
        return;
    }
    
    int newLevel = randomLevel();
    
    if (newLevel > list->level) {
        for (int i = list->level + 1; i <= newLevel; i++) {
            update[i] = list->header;
        }
        list->level = newLevel;
    }
    
    SkipNode *newNode = createNode(key, value, newLevel);
    
    for (int i = 0; i <= newLevel; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
    
    free(update);
}

int delete(SkipList *list, int key) {
    SkipNode *current = list->header;
    SkipNode **update = (SkipNode**)malloc((MAX_LEVEL) * sizeof(SkipNode*));
    
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    current = current->forward[0];
    
    if (!current || current->key != key) {
        free(update);
        return 0; // Not found
    }
    
    for (int i = 0; i <= list->level; i++) {
        if (update[i]->forward[i] != current) {
            break;
        }
        update[i]->forward[i] = current->forward[i];
    }
    
    while (list->level > 0 && !list->header->forward[list->level]) {
        list->level--;
    }
    
    free(current->forward);
    free(current);
    free(update);
    
    return 1;
}

void display(SkipList *list) {
    SkipNode *node = list->header->forward[0];
    int first = 1;
    
    if (!node) {
        printf("Empty list\n");
        return;
    }
    
    while (node) {
        if (!first) printf(" ");
        printf("%d:%d", node->key, node->value);
        first = 0;
        node = node->forward[0];
    }
    printf("\n");
}

void freeSkipList(SkipList *list) {
    SkipNode *node = list->header;
    SkipNode *temp;
    
    while (node) {
        temp = node->forward[0];
        free(node->forward);
        free(node);
        node = temp;
    }
    
    free(list);
}

int main() {
    srand(time(NULL));
    
    int n;
    scanf("%d", &n);
    getchar();
    
    SkipList *list = initSkipList();
    
    for (int i = 0; i < n; i++) {
        char operation[20];
        scanf("%s", operation);
        
        if (strcmp(operation, "insert") == 0) {
            int key, value;
            scanf("%d %d", &key, &value);
            insert(list, key, value);
        } else if (strcmp(operation, "search") == 0) {
            int key;
            scanf("%d", &key);
            int result = search(list, key);
            if (result != -1) {
                printf("%d\n", result);
            } else {
                printf("Not found\n");
            }
        } else if (strcmp(operation, "delete") == 0) {
            int key;
            scanf("%d", &key);
            delete(list, key);
        } else if (strcmp(operation, "display") == 0) {
            display(list);
        }
    }
    
    freeSkipList(list);
    return 0;
}
