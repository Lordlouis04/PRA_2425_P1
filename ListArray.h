#include <iostream>
#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

public:
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }

    ~ListArray() {
        delete[] arr;
    }

    T operator[](int pos) {
        if (pos >= 0 && pos < n) {
            return arr[pos];
        } else {
            throw std::out_of_range("posicion inexistente");
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "List => [";
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    void resize(int new_size) {
        T* aux = new T[new_size];
        for (int i = 0; i < n; i++) {
            aux[i] = arr[i];
        }
        delete[] arr;
        arr = aux;
        max = new_size;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("posicion invalida");
        }
        if (n >= max) {
            resize(max*2);
        }
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("posicion invalida");
        }
        T x = arr[pos];
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        return x;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("posicion invalida");
        }
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }
};

