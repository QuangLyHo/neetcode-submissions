class DynamicArray {
private:
    int *arr;
    int length;
    int capacity;
public:
    DynamicArray(int capacity) :
        capacity(capacity), length(0) {
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (getSize() >= getCapacity()) {
            resize();
        }
        
        arr[length] = n;
        length++;
    }

    int popback() {
        int temp = arr[length - 1];
        length--;
        return temp;
    }

    void resize() {
        capacity = 2 * capacity;

        int *newArr = new int[capacity];
        for (int i = 0; i < length; i++) {
            newArr[i] = arr[i];
        }
        
        delete [] arr;
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
