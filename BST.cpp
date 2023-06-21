struct BST {

    int data;
    BST *left, *right;

    BST(int data = 0){
        this -> data = data;
        left = right = nullptr;
    }

    // Insert New node

    BST* Insert(BST* root, int val){
        if(!root) return new BST(val);
        if(val > root -> data)
            root -> right = Insert(root -> right, val);
        else
            root -> left = Insert(root -> left, val);
        return root;
    }

    // Inorder Traverse (LRR)

    void Inorder(BST* root){
        if(!root) return;
        Inorder(root -> left);
        cout << root -> data << " ";
        Inorder(root -> right);
    }

    // Preorde Traverse (RLR)

    void Preorder(BST* root){
        if(!root) return;
        cout << root -> data << " ";
        Preorder(root -> left);
        Preorder(root -> right);
    }

    // Postorder Traverse (LRR)

    void Postorder(BST* root){
        if(!root) return;
        Postorder(root -> left);
        Postorder(root -> right);
        cout << root -> data << " ";

    }

    // Traverse each level

    void Level_Order(BST* root){
        if(!root) return;
        queue < BST* > bfs;
        bfs.push(root);
        while(!bfs.empty()){
            BST* curr = bfs.front();
            bfs.pop();
            cout << curr -> data << " ";
            if(curr -> left)
                bfs.push(curr -> left);
            if(curr -> right)
                bfs.push(curr -> right);
        }
    }

    // Search on a node

    bool Search(BST* root, int val){
        if(!root) return false;
        if(root -> data == val) return true;
        if(val > root -> data) return Search(root -> right, val);
        else return Search(root -> left, val);
    }

    // Get minimum node in BST

    BST* minValueNode(BST* node){
        BST* current = node;
        while (current && current -> left != nullptr) current = current -> left;
        return current;
    }

    // Get maximum node in BST

    BST* maxValueNode(BST* node){
        BST* current = node;
        while (current && current -> right != nullptr) current = current -> right;
        return current;
    }

    // Delete Node

    BST* Delete_Node(BST* root, int key){
        if(!root) return root;
        if(key < root -> data)
            root -> left = Delete_Node(root -> left, key);
        else if(key > root -> data)
            root -> right = Delete_Node(root -> right, key);
        else {
            if(!root -> left && !root -> right) return nullptr;
            else if(!root -> left){
                BST* temp = root -> right;
                free(root);
                return temp;
            }else if(!root -> right){
                BST* temp = root -> left;
                free(root);
                return temp;
            }
            BST* temp = minValueNode(root -> right);
            root -> data = temp -> data;
            root -> right = Delete_Node(root -> right, temp -> data);
        }
        return root;
    }
};
