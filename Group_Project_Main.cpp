#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Node structure for linked list
struct Node {
	
	// Value stored in node
    int data; 
	
	// Points to next node      
    Node* next;     
    Node(int val) : data(val), next(nullptr) {}  // Constructor
};

// Abstract base class for linked list
class LinkedList {
protected:
	// Points to first node
    Node* head; 
	
	// Points to last node    
    Node* tail;     
public:
    LinkedList() : head(nullptr), tail(nullptr) {}  // Constructor
    virtual ~LinkedList() {  // Destructor
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    virtual void display() = 0;  // Pure virtual function
};

// Stack implementation (LIFO)
class Stack : public LinkedList {
public:
    // Add element to top
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = newNode;
        std::cout << "Pushed: " << val << std::endl;
    }
    
    // Remove top element
    void pop() {
        if (!head) {
            std::cout << "Stack is empty!\n";
            return;
        }
        Node* temp = head;
        std::cout << "Popped: " << temp->data << std::endl;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
    }
    
    // Display stack contents
    void display() override {
        Node* temp = head;
        std::cout << "Stack (Top to Bottom): ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// Queue implementation (FIFO)
class Queue : public LinkedList {
public:
    // Add element to end
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        std::cout << "Enqueued: " << val << std::endl;
    }
    
    // Remove element from front
    void dequeue() {
        if (!head) {
            std::cout << "Queue is empty!\n";
            return;
        }
        Node* temp = head;
        std::cout << "Dequeued: " << temp->data << std::endl;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }
    
    // Display queue contents
    void display() override {
        Node* temp = head;
        std::cout << "Queue (Front to Back): ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// Iterator for traversing linked list
class Iterator {
private:
	// Current node
    Node* current;  
public:
    Iterator(Node* start) : current(start) {}
    
    // Check if more elements exist
    bool hasNext() {
        return current != nullptr;
    }
    
    // Get next element
    int next() {
        if (!current) throw std::out_of_range("No more elements.");
        int value = current->data;
        current = current->next;
        return value;
    }
};

// Fill both structures with random values
void fillRandom(Stack& stack, Queue& queue) {
    int count;
    std::cout << "Enter the number of random values to generate (0-99): ";
    std::cin >> count;
    if (count < 0 || count > 99) {
        std::cout << "Invalid input. Please enter a number between 0 and 99.\n";
        return;
    }
    srand(time(0));
    for (int i = 0; i < count; i++) {
        int randomValue = rand() % 100;
        stack.push(randomValue);
        queue.enqueue(randomValue);
    }
    std::cout << "Random values added to Stack and Queue.\n";
}

// Main menu function
void menu() {
    Stack stack;
    Queue queue;
    bool exitProgram = false;
    while (!exitProgram) {
        int choice, val;
        std::cout << "\n1. Push to Stack\n2. Pop from Stack\n3. Enqueue to Queue\n4. Dequeue from Queue\n5. Display Stack\n6. Display Queue\n7. Fill with Random Values\n8. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> val;
                stack.push(val);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                std::cout << "Enter value to enqueue: ";
                std::cin >> val;
                queue.enqueue(val);
                break;
            case 4:
                queue.dequeue();
                break;
            case 5:
                stack.display();
                break;
            case 6:
                queue.display();
                break;
            case 7:
                fillRandom(stack, queue);
                break;
            case 8:
                std::cout << "Exiting...\n";
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    }
}

// Program entry point
int main() {
    menu();
    return 0;
}