#include <vector>
#include <climits>

class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size() == 0)
        return INT_MIN;
        
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
       if (isEmpty())
            return 0;

        int max = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;

        while (parentIndex < pq.size())
        {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int maxIndex;

            if (leftChildIndex < pq.size() && rightChildIndex < pq.size())
                maxIndex = (pq[leftChildIndex] >= pq[rightChildIndex]) ? leftChildIndex : rightChildIndex;

            else if (leftChildIndex < pq.size() &&pq[leftChildIndex] > pq[parentIndex])
                maxIndex = leftChildIndex;
                
            else
                break;
                
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
        }
        return max;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }
};
