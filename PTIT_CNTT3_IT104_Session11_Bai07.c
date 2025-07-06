
#include <stdio.h>
#include <stdlib.h>
// Định nghĩa cấu trúc danh sách liên kết đôi
typedef struct Node{
    int data;
    struct Node *next; // Con trỏ đến phần tử tiếp theo
    struct Node *prev; // Con trỏ đến phần tử trước đó
}Node;
// Hàm tạo một Node
Node* createNode(int value){
    // Cấp phát bộ nhớ
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; // Gán giá trị cho node
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Hàm in danh sách
void printList(Node* head){
    Node* temp = head; // Biến trung gian
    while(temp != NULL){
        printf("%d <->",temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
    printf("\n");
}
// Hàm giải phóng bộ nhớ
void freeLíst(Node* head){
    Node* temp;

    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
// Hàm tìm kiếm
void searchList(Node* head, int x){
    int found = 0;
    int position = 1;

    while (head){
        if (head->data == x){
            printf("True");
            found = 1;
        }
        head = head->next;
        position++;
    }
    if (!found){
        printf("False");
    }
}
// Hàm đếm số phần tử trong danh sách
int countList(Node* head){
    int count = 0;
    Node* temp = head;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
// Hàm thêm phần tử vào vị trí bất kỳ
void addNode(Node** head, int data, int position){
    int total = countList(*head); // biến đếm phần tử trong danh sách
    // Kiểm tra chỉ số hợp lệ
    if (position < 1 || position > total + 1){
        printf("Vi tri them khong hop le");
        return;
    }
    // Node mới có giá trị data và các con trỏ
    Node* newNode = createNode(data);
    // Thêm vào vị trí đầu
    if (position == 1){
        // Thêm vào đầu
        newNode->next = *head; // Gán node mới vào node cũ
       if (*head != NULL){
           (*head)->prev = newNode; // Cập nhật node cũ
            *head = newNode;
            return;
       }
    }
    Node* temp = *head;
    // Thêm vào giữa hoặc cuối dánh sách
    for (int i = 1; i < position - 1 && temp; i++){
        temp = temp->next;
    }

    newNode->next = temp->next; // Gán node mới đến node tiếp
    newNode->prev = temp;  // Cập nhật node cũ
    // Nếu không thêm vào cuối thì cập nhật node cũ của node tiếp vào node mới
    if (temp->next){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
int main(){
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    // Liên kết các node với nhau
    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    Node* head = node1;

    printList(head);
    // Nhập số và vị trí muốn thêm
    int x, position;
    printf("value: ");
    scanf("%d", &x);
    printf("\nposition: ");
    scanf("%d", &position);
    // Thêm số
    addNode(&head, x, position);
    // In kết quả
    printList(head);
    freeLíst(head);
    return 0;
}