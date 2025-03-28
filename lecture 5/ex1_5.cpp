#include <iostream>
using namespace std;

#define maxnode 1000
/***************
* brief: 	tao cau truc node gom data va 2 node: chinh va 1 node ae cua main
*/
struct Node {
    int data;
    Node* main;
    Node* sibling;
    Node(int val) {				//ham khoi tao 2 cau truc Node
        data = val;
        main = nullptr;
        sibling = nullptr;
    }
};
/***************
* brief: 	tao cay gom cac bien va cac ham chuc nang
*/
class Tree {				
private:
    int node_count;				//Bien dem so node duoc them vao cay				
    bool has_Parent[maxnode];	//Mang luu tru cac node con
    Node* nodes[maxnode];		//Mang con tro, tro den cac node trong cay

public:
    Tree() {					// Ham khoi tao cay
        node_count = 0;
        for (int i = 0; i < maxnode; i++) {
            has_Parent[i] = false;
            nodes[i] = nullptr;
        }
    }

    Node* getNode(int value) {			//ham tao ra node moi
        if (nodes[value] == nullptr) {		//Neu node chua co thi tao node moi 
            nodes[value] = new Node(value);
        }
        return nodes[value];    		//Neu da co thi tra ve gia tri ban dau
    }

    void addEdge(int parent, int child) {	// them node moi vao cay
        Node* parentNode = getNode(parent);		// tao mot node cha
        Node* childNode = getNode(child);		// tao mot node con
        if (!parentNode->main) {				//neu chua co node con
            parentNode->main = childNode;		//thi gan node con vua khoi tao la node con chinh (main)
        } else {
            Node* temp = parentNode->main;		// Neu co roi thì duyet sibling va them node con vao cuoi 
            while (temp->sibling) temp = temp->sibling;
            temp->sibling = childNode;
        }
        has_Parent[child] = true;				// danh dau vao mang la co node cha
    }

    Node* findRoot(int N) {					// ham tim node goc				
        for (int i = 1; i <= N; i++) { 		//duyet mang con tro, tro den cac node
            if (nodes[i] != nullptr && !has_Parent[i]) {  // neu con tro khong rong a khong co bo thi la node root
                return nodes[i];
            }
        }
        return nullptr;						// khong tim duoc thi tra ve con tro null
    }

    int treeHeight(Node* root) {			//ham tim chieu cao cay
        if (!root) return 0;				//neu khong tim duoc root tra ve 0
        int mainHeight = 0;				//tao bien luu chieu cao = 0
        Node* temp = root;
        while(temp->main){ 			// duyet cay theo nhanh main 
        	temp = temp->main;
        	mainHeight++;				// moi lan duyet thi chieu cao ++
		}
		return mainHeight;
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";		//in gia tri cua nut hien tai
        preorder(root->main);			//Duyet cay theo duong main
        preorder(root->sibling);		//Duyet cac sibling cua main
    }

void postorder(Node* root) {
    if (!root) return;
    Node* temp = root->main;
    while (temp) {						//duyyet qua cac nhanh con cua node hien tai
        postorder(temp);
        temp = temp->sibling;
    }

    cout << root->data << " ";			// In ra gia tri cac node sau khi da duyet xong cac node con
}

    bool isBinaryTree(Node* root) {
        if (!root) return true;			//neu cay rong thi van la cay nhi phan
        int count = 0;
        Node* temp = root->main;
        while (temp) {					//duyet qua tat cac con cua cac node
            count++;
            if (count > 2) return false; // neu co nhieu hon 2 con thikhong phai cay nhi phan
            temp = temp->sibling;
        }
	//kiem tra xem de quy tung nhanh de check cay nhi phan
    bool leftSubtree = isBinaryTree(root->main);
    bool rightSubtree = isBinaryTree(root->sibling);

    return leftSubtree && rightSubtree;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->main);			//duyet cay con bang duong main
    cout << root->data << " ";		//in gia tri cua node hien tai
    if (root->main) {				// neu co main thi duyet phan sibling cua no
        Node* rightChild = root->main->sibling;
        while (rightChild) {		//neu co sibling
            inorder(rightChild);	// de quy in ra gia tri cua sibling
            rightChild = rightChild->sibling;		// duyet den node tiep theo
        }
    }
}
/***************
* brief: 	process chinh cua chuong trinh
B1: tim node goc 
B2: tim chieu cao cua cay
B3: in ra preorder, postorder
B4: check cay nhin phan, neu dung thi in ra inorder
*/
void process(int N) {
    Node* root = findRoot(N);
    if (!root) {
        cout << "No root found" << endl;
        return;
    }

    cout << treeHeight(root) << endl;

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;
    
    if (isBinaryTree(root)) {
    inorder(root);
    cout << endl;
} else {
    cout << "This is NOT a binary tree.\n";
}
}
};
/***************
* brief: 	ham main
* Nhan dau vao lan luot la N, M 
* sau do lan luot nhan dau vao la u,v
=> them node bang addEdge va chay ham process
*/
int main() {
    int N, M;
    cin >> N >> M;

    Tree tree;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }

    tree.process(N);
    return 0;
}

