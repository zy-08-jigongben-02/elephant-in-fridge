#ifndef MYARRAY_H
#define MYARRAY_H
#endif // MYARRAY_H
class MyArray {
private:
    int* p;
    int N;

public:
    MyArray();
    MyArray(int n);
    MyArray(const MyArray& arr);

    ~MyArray();

    MyArray merge(const MyArray& arr) const;

    MyArray add(const MyArray& arr) const;
    MyArray subtract(const MyArray& arr) const;
    MyArray multiply(const MyArray& arr) const;
    MyArray divide(const MyArray& arr) const;

    void print() const;
    int getSize() const;
    int getElement(int index) const;
};

