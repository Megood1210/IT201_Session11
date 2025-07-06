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
void deleteNode(Node** head, int position){
    int total = countList(*head); // biến đếm phần tử trong danh sách
    // Kiểm tra vị trí
    if (position < 1 || position > total + 1){
        printf("Vi tri xoa khong hop le");
        return;
    }
    // Khởi tạo con trỏ hiện tại để duyệt
    Node* temp = *head;
    // Xóa vị trí đầu
    if (position == 1){
        *head = temp->next; // Di chuyển đầu sang node tiếp
       // Kiểm tra danh sách chứa phần tử
       if (*head){
           (*head)->prev = NULL; // Cập nhật node cũ của node đầu mới
            free(temp); // Giải phóng bộ nhớ
            return;
       }
    }
    // Duyệt đến node cần xóa
    for (int i = 1; i < position; i++){
        temp = temp->next;
    }
    // Cập nhật liên kết node trước để bỏ qua node hiện tại
    if (temp->prev){
        temp->prev->next = temp->next;
    }
    // Cập nhật liên kết node tiếp để bỏ qua node hiện tại
    if (temp->next){
        temp->next->prev = temp->prev;
    }
    free(temp); // Giải phóng bộ nhớ
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
    // Nhập vị trí muốn xóa
    int position;
    printf(" ");
    scanf("%d", &position);
    // Xóa số
    deleteNode(&head, position);
    // In kết quả
    printList(head);
    freeLíst(head);
    return 0;
}
