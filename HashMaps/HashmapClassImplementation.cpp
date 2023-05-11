template <typename V>

class MapNode{
public:

	string key;
	V value;
	MapNode *next;

MapNode(string key, V value){
	this->key = key;
	this->value = value;
	next = NULL;
}

~MapNode()
{
	delete next;
}

};

template <typename V>

class ouramp{
	MapNode<V>** buckets;
	int count;
	int numBuckets;

public:

	ourmap(){
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<v>*[numBuckets];
		for(int i=0; i<numBuckets; i++)
			buckets[i] = NULL;
	} 

	~ourmap(){
		for(int i=0; i<numBuckets; i++)
			delete buckets[i];

		delete [] buckets;
	}

	int size(){
		return count;
	}

	V getValue(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V> *head = buckets[bucketIndex];

		while(head != NULL)
		{
			if(head->key == key)
			{
				return head->value;
			}

			head = head->next;
		}

			return 0;
	}

private:

	int getBucketIndex(string key)
	{
		int hashCode;
		int currentCoeff = 1;

		for(int i=key.length() - 1; i>=0; i--)
		{
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets;
		}

		return hashCode % numBuckets;
	}

public:

	void insert(string ket, V value)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V> *head = buckets[bucketIndex];

		while(head != NULL)
		{
			if(head->key == key)
			{
				head->value = value;
				return;
			}

			head = head->next;
		}

		head = buckets[bucketIndex];
		MapNode<V> *node = new MapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;
	}

	V remove(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V> *head = buckets[bucketIndex];
		MapNode<V> *prev = NULL;

		while(head != NULL)
		{
			if(head->key == key)
			{
				if(prev == NULL)
					buckets[bucketIndex] = head->next;

				else
					prev->next = head->next;

				V val = head->value;
				count--;
				return val;

				head->next = NULL;
				delete head;
			}

			prev = head;
			head = head->next;
		}

		return 0;
	}

};
