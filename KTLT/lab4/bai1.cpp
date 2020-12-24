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
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */
    Node* new_node = new Node(data);
    new_node->next = head;

    head = new_node;

    return head;
    /*****************/
}

// print the list content on a line
void print(Node* head) {
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */
    Node *tmp = head;
    while(tmp != NULL){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    cout << endl;
    /*****************/
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    /*****************/
    Node* current = head->next;
    Node* prev = head; prev->next = NULL;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;

    return head;
    /*****************/
}

int main() {
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
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
