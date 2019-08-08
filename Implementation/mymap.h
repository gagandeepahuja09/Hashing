#include<string>
using namespace std;

template <typename V>

class MapNode {
	public:
		string key;
		V value;
		MapNode *next;
		
		MapNode(string key, V value) {
			this -> key = key;
			this -> value = value;
			next = NULL;
		}

		~MapNode() {
			delete next;
		}
};

template <typename V>

class mymap {
	MapNode<V>** buckets;
	int count;
	int numBuckets;
	
	public:
	mymap() {
		count = 0;
		numBuckets = 5;
		buckets = new MapNode V*[numBuckets];
		for(int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}
	}

	~mymap() {
		for(int i = 0; i < numBuckets; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {
		return count;
	}
	
	V getValue(string key) {
		
	}

	private:
	int getBucketIndex(string key) {
		int hashCode = 0, currCoeff = 1;
		for(int i = key.size() - 1; i >= 0; i--) {
			hashCode += key[i] * currCoeff;
			hashCode %= numBuckets;
			currCoeff *= 37;
			currCoeff %= numBuckets;
		}
		return hashCode % numBuckets;	
	}

	public:
	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while(head) {
			if(head -> key == key) {
				head -> value = value;
				return;
			}
			head = head -> next;
		}
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key, value);
		node -> next = head;
		buckets[bucketIndex] = node;
		count++;	
	}
};
