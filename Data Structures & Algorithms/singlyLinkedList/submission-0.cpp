class LinkedList {
    struct listNode {
        int info;
        listNode* next;
        listNode(int i) : info(i), next(nullptr) {}
        listNode(int i, listNode* n) : info(i), next(n) {}
    };
private:
    listNode* first;
    listNode* last;
public:
    LinkedList() {
        first = new listNode(-1);
        last = first;
    }

    int get(int index) {
        listNode* cur;
        cur = first->next;
        int idx = 0;

        while (cur != nullptr) {
            if (idx == index) {
                return cur->info;
            }
            idx++;
            cur = cur->next;
        }

        return -1;
    }

    void insertHead(int val) {
        listNode* newNode = new listNode(val);

        newNode->next = first->next;
        first->next = newNode;

        if (newNode->next == nullptr) {
            last = newNode;
        }
    }
    
    void insertTail(int val) {
        last->next = new listNode(val);
        last = last->next;
    }

    bool remove(int index) {
        if (index < 0) return false;
        
        listNode *cur = first->next;
        listNode *trail = first;
        int i = 0;

        while (cur != nullptr) {
            if (i == index) {
                trail->next = cur->next;
                if (cur == last) {
                    last = trail;
                }
                delete cur;
                return true;
            }

            trail = cur;
            cur = cur->next;
            i++;
        }

        return false;
    }

    vector<int> getValues() {
        vector<int> arr;
        listNode* cur = first->next;

        while (cur != nullptr) {
            arr.push_back(cur->info);
            cur = cur->next;
        }

        return arr;
    }
};
