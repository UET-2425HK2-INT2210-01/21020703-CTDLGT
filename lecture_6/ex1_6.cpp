#include <iostream>
using namespace std;

// Dinh nghia node cua cay nhi phan
struct node {
    int data; // Du lieu cua node
    node* left; // Con trai
    node* right; // Con phai

    // Ham khoi tao node voi gia tri dau vao
    node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Dinh nghia lop cay nhi phan
class binarytree {
public:
    node* root = nullptr; // Con tro goc cua cay, khoi tao la null

    // Ham them phan tu vao cay
    void insert(node*& root, int value) {
        if (!root) { // Neu cay rong, tao node moi
            root = new node(value); // Gan gia tri moi cho node
            return;
        }
        if (value < root->data) insert(root->left, value);  // Them vao cay con ben trai
        else if (value > root->data) insert(root->right, value); // Them vao cay con ben phai
    }

    // Ham tim node nho nhat ben phai
    node* minright(node* temp) {
        while (temp && temp->left) temp = temp->left; // Duyet cay con trai de tim node nho nhat
        return temp; // Tra ve node nho nhat tim duoc
    }

    // Ham xoa mot phan tu trong cay
    void deleted(node*& root, int value) {
        if (!root) return; // Neu cay rong, dung lai

        if (value < root->data) deleted(root->left, value); // Duyet cay con trai
        else if (value > root->data) deleted(root->right, value); // Duyet cay con phai
        else { // Da tim thay node can xoa
            if (!root->left) { // Truong hop khong co con trai
                node* temp = root->right;
                delete root;
                root = temp;
            }
            else if (!root->right) { // Truong hop khong co con phai
                node* temp = root->left;
                delete root;
                root = temp;
            }
            else { // Truong hop co ca hai con
                node* temp = minright(root->right); // Tim node nho nhat cua cay con ben phai
                root->data = temp->data; // Thay the gia tri node can xoa
                deleted(root->right, temp->data); // Xoa node nho nhat ben phai
            }
        }
    }

    // Duyet cay theo thu tu giua (Inorder traversal)
    void inorder(node* root) {
        if (root) {
            inorder(root->left); // Duyet cay con trai
            cout << root->data << " "; // In du lieu cua node hien tai
            inorder(root->right); // Duyet cay con phai
        }
    }
};

int main() {
    binarytree tree; // Khoi tao mot cay nhi phan

    // Them cac phan tu vao cay
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20, 14, 0, 35};
    for (int value : values) tree.insert(tree.root, value);

    // Xoa cac phan tu trong cay
    int toDelete[] = {6, 13, 35};
    for (int value : toDelete) tree.deleted(tree.root, value);

    // Duyet cay theo thu tu giua
    cout << "Cay nhi phan: ";
    tree.inorder(tree.root);

    return 0;
}

