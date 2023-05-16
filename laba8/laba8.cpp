#include <iostream>

//шаблон класу однонаправленого списку
template<typename T>
class list {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
public:
    list() : head(nullptr) {}
    list(const list& other) : head(nullptr) {
        Node* ptr = other.head;
        while (ptr != nullptr) {
            push_back(ptr->data);
            ptr = ptr->next;
        }
    }
    ~list() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    list& operator=(const list& other) {
        if (this == &other) {
            return *this;
        }
        Node* ptr = other.head;
        list temp;
        while (ptr != nullptr) {
            temp.push_back(ptr->data);
            ptr = ptr->next;
        }
        std::swap(head, temp.head);
        return *this;
    }
    void push_back(const T& val) {
        Node* temp = new Node{val, nullptr};
        if (head == nullptr) {
            head = temp;
        }
        else {
            Node* ptr = head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    void pop_back() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node* ptr = head;
            while (ptr->next->next != nullptr) {
                ptr = ptr->next;
            }
            delete ptr->next;
            ptr->next = nullptr;
        }
    }
    bool operator!=(const list& other) const {
        Node* ptr1 = head;
        Node* ptr2 = other.head;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->data != ptr2->data) {
                return true;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1 != ptr2;
    }
};

template<typename T>
list<T> operator+(const list<T>& l, const T& val) {
    list<T> temp(l);
    temp.push_back(val);
    return temp;
}

template<typename T>
list<T>& operator--(list<T>& l) {
    l.pop_back();
    return l;
};

// користувальницьки клас
class Person {
    public:
        std::string name;
        int age;
        Person(const std::string& n, int a) : name(n), age(a) {}
        bool operator!=(const Person& other) const {
            return name != other.name || age != other.age;
        }
};
