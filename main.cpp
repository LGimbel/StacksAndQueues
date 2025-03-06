#include <iostream>
#include <string>

// node structure for both stack and queue
struct Node {
  // data value
  int data;

  // pointer to the next node in the list
  Node* next;

  // constructor (initialize the data value and the next pointer)
  Node(int val) : data(val), next(nullptr) {} 
};

// custom iterator class (for both stack and queue traversal)
class ListIterator {
private:
  // pointer to the current node
  Node* current;
public:
  // constructor (initialize the current pointer)
  ListIterator(Node* node) : current(node) {}
  
  // dereference operator (return the data value of the current node)
  int operator*() const { return current->data; } 

  // pre-increment operator (return the updated iterator)
  ListIterator& operator++() { current = current->next; return *this; } 

  // inequality operator (compare the current pointers)
  bool operator!=(const ListIterator& other) const { return current != other.current; }

  // arrow operator (return the current node)
  Node* operator->() { return current; }
};




void initialMenu();
void stackMenu();
void queueMenu();
int main(){
  std::cout << "hello World";
  std::cout << "test";
  initialMenu();
  return 0;
}

//Initial menu to allow the user to choose between stack and queue operation menus.
//Use a boolean value to see if the menu should display a welcome message.
//only called once for the entire program duration.
void initialMenu () {
  std::cout <<"\nWelcome" << std::endl;
  bool choiceMade = false;
  do {
    int choice = 0;
    std::string menu = "Please enter the data structure you wish to test.\n1.Stack\n2.Queue\n3.Exit Program\n";
    std::cout << menu;
    std::cin >> choice;
    switch (choice) {
      case 1: {
        stackMenu();
        break;
      }
      case 2: {
        queueMenu();
        break;
      }
      case 3: {
        std::cout << "Thank you for using the stack and queue system!" << std::endl;
        choiceMade = true;
        break;
      }
      default: {
        std::cout<< "Please try again and enter a valid choice." << std::endl;
        break;
      }
    }
  }while (!choiceMade);
}
//Menu for stack operations.
void stackMenu() {
  do {
    int choice = 0;
    std::string menu = "Please enter the desired stack action\n1.Push to the stack.\n2.Pop from the stack\n3.View entire stack\n4.Return to main menu.\n";
    std::cout << menu;
    std::cin >> choice;
    switch (choice) {
      case 1: {
        //TODO call push stack logic
        break;
      }
      case 2: {
        //TODO call pop stack logic
        break;
      }
      case 3: {
        //TODO call view stack logic
        break;
      }
      case 4: {
        //returns to the previous function which is the higher level menu.
        return;
      }
      default: {
        std::cout << "Please try again and enter a valid option" << std::endl;
        break;
      }
    }

  }while (true);

}
void queueMenu() {
  do {
    int choice = 0;
    std::string menu = "Please enter the desired queue action\n1.Enqueue\n2.Dequeue\n3.View entire Queue\n4.Return to main menu.\n";
    std::cout << menu;
    std::cin >> choice;
    switch (choice) {
      case 1: {
        //TODO call enqueue logic
        break;
      }
      case 2: {
        //TODO call dequeue logic
        break;
      }
      case 3: {
        //TODO call view queue logic
        break;
      }
      case 4: {
        return;
      }
      default: {
        std::cout << "Please try again and enter a valid option" << std::endl;
        break;
      }
    }

  }while (true);

}

