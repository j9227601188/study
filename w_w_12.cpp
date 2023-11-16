#include "Header.h"

//��������� ������ (Linked List) 12.2

class Node
{
public:
    Node(int data) : m_data(data), m_next(nullptr) {}
    int m_data;
    Node* m_next;
    //Node* m_prev; // ���������� ������, ��������� �� ���������� �������
};

class List
{
public:
    List() : m_head(nullptr) {}
    ~List() { clear(); }
    void push_back(int data) {
        // ������� ����� ����
        Node* node = new Node(data);
        // ���� ������ ����, ���������� ����
        if (m_head == nullptr)
        {
            m_head = node;
            return;
        }
        // � ����� ���� ��������� ������� ������
        Node* last = m_head;
        while (last->m_next != nullptr)
        {
            last = last->m_next;
        }
        // ��������� ��������� next ���������� ���� �� ��������� �� ����� ����
        last->m_next = node;
        return;
    }
    void push_front(int data) {
        Node* node = new Node(data);
        node->m_next = m_head;
        m_head = node;
    }
    void insert(int pos, int data) {
        // ������� ����� ���� 
        Node* newNode = new Node(data);
        if (m_head == nullptr)
        {
            // ���� ������ ����, ����� ���� � ����� ������� ������
            m_head = newNode;
            return;
        }

        if (pos == 0)
        {
            // ������� ������ - �������  � ������ ������
            newNode->m_next = m_head;
            m_head = newNode;
            return;
        }

        int currPos = 0;

        Node* current = m_head;
        // � ����� ���� �� ������, ���� ������ �� ��������, ��� ���� �� ������ �� �������
        while (currPos < pos - 1 && current->m_next != nullptr)
        {
            current = current->m_next;
            currPos++;
        }
        // ������ ��������� �� ��������� ���� �� ��������� �� ����� ����
        Node* next = current->m_next;
        current->m_next = newNode;
        // ��������� ������ �������, ������ ��������� �� ����, ��������� ����� ������ ����, �� ��������� �� ����, ��������� �� current
        newNode->m_next = next;
    }
    void show() {
        Node* current = m_head;
        while (current) {
            std::cout << current->m_data;
            current = current->m_next;
        }
    }
    void deleteNode(int data) {
        Node* temp = m_head;
        Node* prev = nullptr;

        // ������� ������ �������� ������ ������
        if (temp && temp->m_data == data)
        {
            m_head = temp->m_next;
            delete temp;
            return;
        }
        // ���� �� ������, ���� �� ������ ���� �� ��������� ������, ������ �����
        while (temp && temp->m_data != data)
        {
            prev = temp;
            temp = temp->m_next;
        }
        // ���� ���� �� ������, ����������
        if (!temp)
            return;
        // ������ ��������� ���������� ���� ��� ����������� ���� �� ����, ��������� �� ��������� �����, � ������� ���� � �������
        prev->m_next = temp->m_next;
        delete temp;
    }
    void deleteNodePosition(int position) {
        Node* current = m_head;
        Node* last = nullptr;

        if (position == 0) {
            m_head = m_head->m_next;
            delete current;
            return;
        }

        while (current && position != 0) {
            last = current;
            current = current->m_next;
            --position;
        }
        if (!current) {
            return;
        }
        last->m_next = current->m_next;
        delete current;
    }
    void clear(){
        Node* current = nullptr;
        while (m_head) {
            current = m_head;
            m_head = m_head->m_next;
            delete current;
        }
    }
private:
    Node* m_head;
};

//���� � ������� () 12.3
#define MAX 1000

class Stack {
private:
    int m_top;

public:
    int m_items[MAX];
    Stack() : m_top(-1) {}
    bool push(int x) {
        if (isFull()) {
            std::cout << "Stack Overflow\n";
            return false;
        }
        else {
            ++m_top;
            m_items[m_top] = x;
            return true;
        }
    }
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        else {
            return m_items[m_top--]; //int x = m_items[m_top]; --m_top; return x;
        }
    }
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        else {
            return m_items[m_top];
        }
    }
    bool isFull() {
        return m_top >= (MAX - 1);
    }
    bool isEmpty() {
        return m_top < 0;
    }
};



void w_w_12() {
	std::cout << " Unit 12 run: \n";


};