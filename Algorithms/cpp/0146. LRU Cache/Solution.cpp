// https://leetcode-cn.com/problems/lru-cache/

struct DLL{
    int key;
    int value;
    DLL* prev;
    DLL* next;
    DLL(): key(-1), value(-1), prev(nullptr), next(nullptr) {};
    DLL(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
	int size;
	int capacity;
	DLL *head;
	DLL *back;
	unordered_map<int, DLL*> umap;
public:
	LRUCache(int _capacity) {
		capacity = _capacity;
		size = 0;
		head = new DLL();
		back = new DLL();
		head->next = back;
		back->prev = head;
	}

	void addToHead(DLL* node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}

	void removeDLL(DLL* node) {
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}

	DLL* popTail() {
		DLL* node = back->prev;
		removeDLL(node);
		return node;
	}

	int get(int key) {
		auto iter = umap.find(key);
		if (iter == umap.end()) {
			return - 1;
		}
		else {
			removeDLL(iter->second);
			addToHead(iter->second);
			return iter->second->value;
		}
	}

	void put(int key, int value) {
		auto iter = umap.find(key);
		if (iter == umap.end()) {
			DLL* new_added = new DLL(key, value);
			umap.emplace(key, new_added);
			addToHead(new_added);
			size++;
			if (size > capacity) {
				DLL* deleted = popTail();
				umap.erase(umap.find(deleted->key));
				size--;
			}
		}
		else {
			iter->second->value = value;
			removeDLL(iter->second);
			addToHead(iter->second);
		}
	}
};