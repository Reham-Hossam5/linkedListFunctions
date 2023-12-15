#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* l;

public:
    LinkedList() : l(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = l;
        l = newNode;
    }

    void removeFromBeginning() {
        if (l) {
            Node* temp = l;
            l = l->next;
            delete temp;
        } else {
            cout << "List is empty. Cannot remove from an empty list." << endl;
        }
    }

    void findSumAvgCount() {
        int sum = 0;
        int count = 0;

        Node* p = l;
        while (p) {
            sum += p->data;
            count++;
            p = p->next;
        }

        double average = (count == 0) ? 0 : static_cast<double>(sum) / count;

        cout << "Sum: " << sum << endl;
        cout << "Count: " << count << endl;
        cout << "Average: " << average << endl;

    }

    bool searchElement(int value) {
        Node* p = l;
        while (p) {
            if (p->data == value) {
                return true;
            }
            p = p->next;
        }
        return false;
    }
};

int main() {
    LinkedList myList;

    char choice;
    do {
       cout << "Choose an operation:\n";
       cout << "1. Insert at the beginning\n";
       cout << "2. Remove from the beginning\n";
       cout << "3. Find sum, average, and count\n";
       cout << "4. Search for an element\n";
       cout << "5. Exit\n";
       cin >> choice;

        switch (choice) {
            case '1': {
                int value;
               cout << "Enter a number to insert: ";
                cin >> value;
                myList.insertAtBeginning(value);
                break;
            }
            case '2':
                myList.removeFromBeginning();
                break;
            case '3':
                myList.findSumAvgCount();
                break;
            case '4': {
                int value;
               cout << "Enter a number to search: ";
                cin >> value;
                if (myList.searchElement(value)) {
                    cout << value << " found in the list." << endl;
                } else {
                    cout << value << " not found in the list." << endl;
                }
                break;
            }
            case '5':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != '5');

    return 0;
}
