class Solution {
public:
    struct node {
        int val;
        struct node* next;
        struct node* prev;
    };
    
    struct ll {
        struct node* head;
    };
    
    int findTheWinner(int n, int k) {
        // Implement a circular doubly linked list
        struct ll* list = new struct ll;
        struct node* head = new struct node;
        head->val = 1;
        head->next = NULL;
        list->head = head;
        
        for (int i = 2; i <= n; i++) {
            struct node* temp = new struct node;
            temp->val = i;
            temp->prev = head;
            head->next = temp;
            head = head->next;
        }
        
        list->head->prev = head;
        head->next = list->head;
        head = list->head;
        
        for (int i = 0; i < n - 1; i++) {
            if (!head->next) {
                return head->val;
            }
            for (int j = 0; j < k - 1; j++) {
                head = head->next;
            }
            head = head->prev;
            head->next = head->next->next;
            head->next->prev = head;
            head = head->next;
        }
        
        return head->val;
    }
};