// Nguyen Van Duy - 20215334
/*
Bài 4.1. Hãy hoàn thiện các hàm thao tác trên một danh sách liên kết:
 • Thêm một phần tử vào đầu danh sách liên kết
 • In danh sách
 • Đảo ngược danh sách liên kết (yêu cầu độ phức tạp thời gian O(N) và chi phí bộ nhớ dùng thêm O(1))
*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node* newNode = new Node(data); // new node is new head
    newNode->next = head; // point to head
    return newNode; // return new node
}

// print the list content on a line
void print(Node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node* temp = head; // temp node
    while (temp != NULL) { // loop through
        cout << temp->data << " "; // print
        temp = temp->next; // next node
    }
    cout << endl; // end of
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node* prev = NULL; // previous
    Node* curr = head; // current
    Node* next = NULL; // next
    while (curr != NULL) { // loop through
        next = curr->next; // save next node
        curr->next = prev; // move the cursor to previous node
        prev = curr; // move to next
        curr = next; // move to next
    }
    return prev;
}

int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}
// Nguyen Van Duy - 20215334
