#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        if(pq.size() == 0)
        return -1;

        int ans = pq[0];

        int temp = pq[pq.size()-1];
        pq[pq.size()-1] = pq[0];
        pq[0] = temp;

        pq.pop_back();

        int index = 0;
        bool c1 = false, c2 = false;

        while((2*index + 1 <= pq.size() - 1) || (2*index + 2 <= pq.size() -1))
        {

            int child1, child2, minIndex;

            if(2*index + 1 <= pq.size() - 1)
            child1 = 2*index + 1;

            else
            c1 = true;

            if(2*index + 2 <= pq.size() -1)
            child2 = 2*index + 2;

            else
            c2 = true;

            if(pq[index] > pq[child1] || pq[index] > pq[child2])
            {
                if(!c1 && !c2 && (pq[child1] < pq[child2]))
                minIndex = child1;

                else if(!c1 && !c2 && (pq[child1] > pq[child2]))
                minIndex = child2;

                else if(!c1 && c2)
                minIndex = c2;

                else if(c1 && !c2)
                minIndex = c1;

                int temp = pq[index];
                pq[index] = pq[minIndex];
                pq[minIndex] = temp;
            }

            else
            break;

            index = minIndex;
        }

        return ans; 
    }
};
