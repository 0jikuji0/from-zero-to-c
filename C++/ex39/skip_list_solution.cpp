/**
 * Exercise 39: Skip List
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing Skip List with random height assignment.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_LEVEL = 16;

struct SkipNode {
    int key;
    int value;
    vector<SkipNode*> forward;
    int level;
    
    SkipNode(int k, int v, int lvl) 
        : key(k), value(v), level(lvl), forward(lvl + 1, nullptr) {}
};

class SkipList {
private:
    SkipNode* header;
    int level;
    
    int randomLevel() {
        int lvl = 0;
        while (rand() % 2 == 0 && lvl < MAX_LEVEL - 1) {
            lvl++;
        }
        return lvl;
    }
    
public:
    SkipList() {
        header = new SkipNode(-1, -1, MAX_LEVEL - 1);
        level = 0;
    }
    
    int search(int key) {
        SkipNode* node = header;
        
        for (int i = level; i >= 0; i--) {
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
    
    void insert(int key, int value) {
        vector<SkipNode*> update(MAX_LEVEL);
        SkipNode* current = header;
        
        // Find position to insert
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }
        
        current = current->forward[0];
        
        if (current && current->key == key) {
            current->value = value; // Update existing key
            return;
        }
        
        int newLevel = randomLevel();
        
        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; i++) {
                update[i] = header;
            }
            level = newLevel;
        }
        
        SkipNode* newNode = new SkipNode(key, value, newLevel);
        
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
    
    bool deleteKey(int key) {
        vector<SkipNode*> update(MAX_LEVEL);
        SkipNode* current = header;
        
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }
        
        current = current->forward[0];
        
        if (!current || current->key != key) {
            return false; // Not found
        }
        
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }
        
        while (level > 0 && !header->forward[level]) {
            level--;
        }
        
        delete current;
        return true;
    }
    
    void display() {
        SkipNode* node = header->forward[0];
        
        if (!node) {
            cout << "Empty list" << endl;
            return;
        }
        
        bool first = true;
        while (node) {
            if (!first) cout << " ";
            cout << node->key << ":" << node->value;
            first = false;
            node = node->forward[0];
        }
        cout << endl;
    }
};

int main() {
    srand(time(nullptr));
    
    int n;
    cin >> n;
    cin.ignore();
    
    SkipList list;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "insert") {
            int key, value;
            cin >> key >> value;
            list.insert(key, value);
        } else if (operation == "search") {
            int key;
            cin >> key;
            int result = list.search(key);
            if (result != -1) {
                cout << result << endl;
            } else {
                cout << "Not found" << endl;
            }
        } else if (operation == "delete") {
            int key;
            cin >> key;
            list.deleteKey(key);
        } else if (operation == "display") {
            list.display();
        }
    }
    
    return 0;
}
