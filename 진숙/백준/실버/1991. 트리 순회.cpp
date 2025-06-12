#include <iostream>
#include <vector>
using namespace std;

#define TYPE char   // 필요에 따라서 타입 바꿔쓰려고

struct Node {
    TYPE data;
    Node* left;
    Node* right;
    Node(TYPE d): data(d), left(nullptr), right(nullptr){}
};

class Tree {
public:
    // 찾기 쉽게 값과 Node* 를 pair로 보관
    // 아마 다른 좋은 방법이 있겠지.... 시간초과 안난게 신기해
    vector<pair<TYPE, Node*>> nodeVec;  
    Node* root = nullptr;

    // 노드 탐색 & 생성 함수
    Node* getNode(TYPE data) {
        // data를 가진 노드 찾기
        for (auto& node : nodeVec) {
            // 노드 하나씩 써내서 확인
            if (node.first == data)
                // 같은 값을 가진 node가 있으면 pair.second 반환
                return node.second;
        }

        // return안되고 내려온거면 한번도 생성된적 없는 값의 노드
        Node* newNode = new Node(data); // 만들고 
        nodeVec.push_back({data, newNode}); // vecotr에도 넣고 
        return newNode; // 반환하기
    }

    void insert(Node* node) {
        // getNode() 통해서 node 가져오기
        Node* pNode = getNode(node->data);

        // 루트가 null이면 루트에 넣어주기
        if (root == nullptr) root = pNode;

        // left랑 right 있으면 같은 값 가지는 노드 있는지 확인(없으면 생성해줄거임)하고 연결하기
        if (node->left) pNode->left = getNode(node->left->data);
        if (node->right) pNode->right = getNode(node->right->data);
    }

    void preOrder(Node* node) {
        if (!node) return;
        cout << node->data;     //Root
        preOrder(node->left);   //L
        preOrder(node->right);  //R
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);    //L
        cout << node->data;     //Root
        inOrder(node->right);   //R
    }

    void postOrder(Node* node) {
        if (!node) return;
        postOrder(node->left);  //L
        postOrder(node->right); //R
        cout << node->data;     //Root
    }
};

int main() {
    int n;
    cin >> n;

    Tree tree;

    for (int i = 0; i < n; i++) {
        TYPE data, left, right;
        cin >> data >> left >> right;

        Node* node = new Node(data);
        if (left != '.') node->left = new Node(left);
        if (right != '.') node->right = new Node(right);

        tree.insert(node);
    }

    tree.preOrder(tree.root);
    cout << endl;
    tree.inOrder(tree.root);
    cout << endl;
    tree.postOrder(tree.root);
    cout << endl;

    return 0;
}
