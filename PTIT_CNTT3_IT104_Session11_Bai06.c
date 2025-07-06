
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
// Hàm xóa phần tử đầu danh sách
Node* deleteNode(Node* head){
    // Kiểm tra danh sách rỗng
    if (head == NULL){
        printf("Danh sach rong");
        return NULL;
    }
    // Kiểm tra danh sách chỉ có 1 node
    if (head->next == NULL){
        return NULL;
    }
    Node* temp = head; // Lưu node hiện tại vào biến tạm
    head = (head)->next; // Cập nhật node
    // Kiểm tra danh sách chứa phần tử
    if (head != NULL){
        head->prev = NULL;
    }
    // Giải phóng
    free(temp);
    return head; // Trả về node mới
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
    //Xóa phần tử
    head = deleteNode(head);
    // In kết quả
    printList(head);
    freeLíst(head);
    return 0;
}