class Node {
public:
    int key;
    int value;
    int freq;

    Node(int k, int v) : key(k), value(v), freq(1) {}
};

class LFUCache {
private:
    int cap;  // Capacity of the cache
    int minFreq;  // Minimum frequency of any key in the cache
    unordered_map<int, Node*> mapping;  // Map to hold key to Node mapping
    unordered_map<int, list<Node*>> freq;  // Map to hold frequency to list of nodes

public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}

    void update(Node* node) {
        // Update the frequency of the node
        int oldFreq = node->freq;
        node->freq++;

        freq[oldFreq].remove(node);
        if (freq[oldFreq].empty()) {
            freq.erase(oldFreq);
            if (minFreq == oldFreq) {
                minFreq++;
            }
        }
        freq[node->freq].push_back(node);
    }

    int get(int key) {
        if (mapping.find(key) == mapping.end()) {
            return -1; 
        }

        Node* node = mapping[key];
        update(node); 
        return node->value;
    }

    void put(int key, int value) {
        if (cap <= 0) return;
        
        if (mapping.find(key) != mapping.end()) {
            Node* node = mapping[key];
            node->value = value;
            update(node);
        } else {
    
            if (mapping.size() >= cap) {
                Node* lfuNode = freq[minFreq].front();
                freq[minFreq].pop_front();
                mapping.erase(lfuNode->key);
                delete lfuNode; 
            }
            // Create a new node
            Node* newNode = new Node(key, value);
            mapping[key] = newNode; 
            freq[1].push_back(newNode); 
            minFreq = 1; 
        }
    }
};