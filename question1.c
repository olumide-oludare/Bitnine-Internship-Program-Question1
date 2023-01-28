#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD, SUB, MUL, DIV, FIB, NIL
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
    TypeTag fibOperator;
} Node;


Node* makeFunc(TypeTag type) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->type = type;
    newNode->value = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int fibonacci(int n, TypeTag operator) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int prev = 0, curr = 1;
    if (operator == ADD) {
        for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr += prev;
        prev = temp;
    }
    } else if (operator == SUB) {
        for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr -= prev;
        prev = temp;
    }
    } else if (operator == MUL) {
        for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr *= prev;
        prev = temp;
    }
    } else if (operator == DIV) {
        for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr /= prev;
        prev = temp;
    }
    } else {
        printf("Invalid operator");
        return -1;
    }
    return curr;
}

void calc(Node* node) {
    if (node == NULL) {
        printf("NULL\n");
        return;
    }
    if (node->type == FIB) {
        node->value = fibonacci(node->left->value, node->fibOperator );
        printf("fibo: %d\n", node->value);
    }
    else if (node->type == ADD) {
        node->value = node->left->value + node->right->value;
        printf("add: %d\n", node->value);
    }
    else if (node->type == SUB) {
        node->value = node->left->value - node->right->value;
        printf("sub: %d\n", node->value);
    }
    else if (node->type == MUL) {
        node->value = node->left->value * node->right->value;
        printf("mul: %d\n", node->value);
    }
    else if (node->type == DIV) {
        node->value = node->left->value / node->right->value;
        printf("div: %d\n", node->value);
    }
    else {
        printf("Invalid type\n");
    }
}

int main() {
    Node *add = makeFunc(ADD);
    add->left = makeFunc(NIL);
    add->left->value = 10;
    add->right = makeFunc(NIL);
    add->right->value = 6;
    calc(add);

    Node *mul = makeFunc(MUL);
    mul->left = makeFunc(NIL);
    mul->left->value = 5;
    mul->right = makeFunc(NIL);
    mul->right->value = 4;
    calc(mul);

    Node *sub = makeFunc(SUB);
    sub->right = mul;
    sub->left = add;
    calc(sub);

    Node *fibo = makeFunc(FIB);
    fibo->fibOperator = SUB;
    fibo->left = sub;
    // fibo->left->value = sub->value;
    calc(fibo);

return 0;
}