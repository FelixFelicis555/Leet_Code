/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    stack<Node*> st;
    Node* rec(Node*head)
    {
        
        Node* temp=head;
        while(head!=NULL)
        {
            if(head->child!=NULL)
            {
                if(head->next)
                    st.push(head->next);
                head->next=head->child;
                head->child->prev=head;
                head->child=NULL;
            } 
            temp=head;
            head=head->next;
        }  
        return temp;
    }    
    Node* flatten(Node* head) {
        Node* temp,*start=head;
        temp=rec(head);
        while(st.size()>=1)
        {
            Node*n=st.top();
            st.pop();
            temp->next=n;
            n->prev=temp;
            temp=rec(temp);
        }  
        return start;
        
    }
};