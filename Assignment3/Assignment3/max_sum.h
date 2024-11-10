#pragma once
#include "task3.h"
#include "task3_queue.h"

int max_finder(Node* node, int& maxx)
{
    if (node == NULL) return 0; 

    int left_sum = max_finder(node->left, maxx);
    if (left_sum < 0)
    {
        left_sum = 0;
    }

    int right_sum = max_finder(node->right, maxx);
    if (right_sum < 0) {
        right_sum = 0;
    }

    int currentPathSum = node->val + left_sum + right_sum;

    if (currentPathSum > maxx)
    {
        maxx = currentPathSum;
    }

    int maxChildSum;
    if (left_sum > right_sum) 
    {
        maxChildSum = left_sum;
    }
    else 
    {
        maxChildSum = right_sum;
    }
    
    return node->val + maxChildSum;
}

int max_sum_path(Node* root)
{
    int maxx;
    if (root == NULL)
    {
        maxx = 0;
    }
    else 
    {
        maxx = root->val;
    }
    max_finder(root, maxx);
    return maxx;
}

Node* create_tree(Queue& queue) 
{
    if (queue.isEmpty()) 
        return NULL;

    Node* root = queue.dequeue();
    Queue q1;
    q1.enqueue(root);

    while (!q1.isEmpty()) 
    {
        Node* node = q1.dequeue();

        if (!queue.isEmpty()) 
        {
            Node* leftNode = queue.dequeue();
            if (leftNode->val != -1) // -1 shows null
            {
                node->left = leftNode;
                q1.enqueue(leftNode);
            }
        }

        if (!queue.isEmpty()) 
        {
            Node* rightNode = queue.dequeue();
            if (rightNode->val != -1) 
            {
                node->right = rightNode;
                q1.enqueue(rightNode);
            }
        }
    }
    return root;
}

