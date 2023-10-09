//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    unordered_map<Node*,Node*> parent_track;
    Node* t;
    
    void makeParents(Node* root, unordered_map<Node*,Node*>& parent_track ){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            
            if(current -> left){
                parent_track[current->left] = current;
                q.push(current->left);
            }

            if(current -> right){
                parent_track[current->right] = current;
                q.push(current -> right);
            }
        }
    }
    Node* getRef(Node* root, int target)
    {
        if(root==NULL || root->data == target)
            return root;
        Node *left= getRef(root->left,target);
        Node *right= getRef(root->right, target);
        if(left!=NULL)
        return left;
        if(right!=NULL)
        return right;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        t=getRef(root,target);
        makeParents(root,parent_track);

        unordered_map<Node* ,bool> visited;
        queue<Node*> que;
        que.push(t);
        visited[t] = true;
        int curr_level = 0;
        while(!que.empty()){
            int size = que.size();
            if(curr_level++ == k)
                break;

            for(int i = 0; i< size ;i++){
                Node* current = que.front();
                que.pop();
                if(current -> left && !visited[current -> left]){
                    que.push(current -> left);
                    visited[current -> left] = true;
                }
                if(current -> right && !visited[current -> right]){
                    que.push(current -> right);
                    visited[current -> right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    que.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }   
        }
        vector<int> res;
        while(!que.empty()){
            Node* node = que.front();
            que.pop();
            res.push_back(node->data);
        }
        sort(res.begin() ,res.end());
        return res;
    }
    
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends