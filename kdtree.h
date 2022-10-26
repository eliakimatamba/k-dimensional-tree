#ifndef UNTITLED_KDTREE_H
#define UNTITLED_KDTREE_H

#endif //UNTITLED_KDTREE_H
/*A linear search trees in which the information in each nodes is a K-Dimensional region of space is known as just a K-D Trees. In a nutshell, it's a sequence of bytes for arranging objects inside a K-Dimensional universe that uses space partition.

Inside a K-D trees, a quasi nodes splits each space into two halves, known called 1/2.

A left subgraph of the that symbolizes locations towards the correct side of the this space, whereas the right root of the tree represents locations to the privilege of both the space. We'll describe where room is partitioned and trees are generated in the near future.


For the sake of simplicity, let us understand a 2-D Tree with an example.

The root would have an x-aligned plane, the root’s children would both have y-aligned planes, the root’s grandchildren would all have x-aligned planes, and the root’s great-grandchildren would all have y-aligned planes and so on.

Generalization:
Let us number the planes as 0, 1, 2, …(K – 1). From the above example, it is quite clear that a point (node) at depth D will have A aligned plane where A is calculated as:

A = D mod K

For such sake of simplicity, let's consider the example of a 2-D Trees.

The root's offspring both would have y-aligned structures, its root's grandkids all would have x-aligned planes, as well as the root's wonderful all had y-aligned planes, and etc.

Let's all name the surfaces 0, 1, 2,...(K – 1) as just a generalisation. It's indeed evident from of the previous example that a location (nodes) of distance D would have an A matched planes, wherein A is determined as:

D module K = A*/

// A C++ programme that demonstrates KD trees functions.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int j = 2;
const int k = j;
// An entity that represents a kd trees vertex.
struct node
{
    int point[j]; // To keep track of j-dimensional points
    node *left, *right;
};

// A technique for making a j D tree nodes.
struct node* newnode(int arr[])
{
    struct node* temp = new node;

    for (int i=0; i<k; i++)
        temp->point[i] = arr[i];

    temp->left = temp->right = NULL;
    return temp;
}

// Introduces a unique component to the tree and provides the updated tree's root.
// The thickness argument is being used to determine overall comparative plane.
node *insertRec(node *root, int point[], unsigned depth)
{
    // Is the tree null/EMPTY?
    if (root == NULL)
        return newnode(point);

    // Determine the actual comparability measurement (CD).
    unsigned cd = depth % j;

    // Just on existing dimensions 'CD,' compare the new point towards the roots.
    // and choose between the left and right subtrees
    if (point[cd] < (root->point[cd]))
        root->left = insertRec(root->left, point, depth + 1);
    else
        root->right = insertRec(root->right, point, depth + 1);

    return root;
}

// Replace the entire position with the specific location in this procedure.
// Append an additional root to the KD Trees. It primarily makes use of recursive functions.
// f"insertRec()" is a function used in this place.
node* insert(node *root, int point[])
{
    return insertRec(root, point, 0);
}

// A useful approach for determining whether two factors are one and the same.
// Searches a Point represented by "point[]" in the K D tree.
bool arePointsSame(int point1[], int point2[])
{
    // constrast each values of the point_inate as shown below.
    for (int i = 0; i < j; ++i)
        if (point1[i] != point2[i])
            return false;

    return true;
}

// Inside the K D trees, looks for a node symbolized as "point[]".
// The present direction is determined by the profundity variable.
bool searchRec(node* root, int point[], unsigned depth)
{
    // Instances of foundation/base
    if (root == NULL)
        return false;
    if (arePointsSame(root->point, point))
        return true;

    // The present dimensionality is calculated by adding the present depths to the overall depth.
    // proportions (j)
    unsigned cd = depth % j;

    // In terms of cd, compared source and root (Present dimension)
    if (point[cd] < root->point[cd])
        return searchRec(root->left, point, depth + 1);

    return searchRec(root->right, point, depth + 1);
}

// Inside the K D trees, looks for a node. It primarily makes use of
// The "searchRec()"
bool search(node* root, int point[])
{
    // Set the new depths to 0
    return searchRec(root, point, 0);
}

// A utility function to find minimum of three integers
node *minNode(node *x, node *y, node *z, int d)
{
    node *res = x;
    if (y != NULL && y->point[d] < res->point[d])
        res = y;
    if (z != NULL && z->point[d] < res->point[d])
        res = z;
    return res;
}

// Recursively finds minimum of d'th dimension in KD tree
// The parameter depth is used to determine current axis.
node* findMinRec(node *root, int d, unsigned depth)
{
    if (root == NULL)
        return NULL;
    unsigned cd = depth % j;
    if (cd == d)
    {
        if (root->left == NULL)
            return root;
        return findMinRec(root->left, d, depth+1);
    }
    return minNode(root,
                   findMinRec(root->left, d, depth+1),
                   findMinRec(root->right, d, depth+1), d);
}
node* findMin(node* root, int d)
{
    return findMinRec(root, d, 0);
}
/*bool arePointsSame(int point1[], int point2[])
{
    for (int i = 0; i < j; ++i)
        if (point1[i] != point2[i])
            return false;

    return true;
}
*/
// Transfers are pointing from p2 towards p1.
void copyPoint(int p1[], int p2[])
{
    for (int i=0; i<k; i++)
        p1[i] = p2[i];
}

// Deletes a given location from the a trees containing roots using the expression 'point[]'.
// as if it were a 'root' depth represents the current depth, which was initially set at 0.
// Provides the changed massive tree root.
node *deleteNodeRec(node *root, int point[], int depth)
{
    // The specified point is not existent.
    if (root == NULL)
        return NULL;

    // Know the current datatype dimensions.
    int cd = depth % j;

    // If the element to be removed is located just at foundation
    if (arePointsSame(root->point, point))
    {
        // 2.b) If the correct child isn't Empty
        if (root->right != NULL)
        {
            // In the sub - tree, determine the root's minimal dimensions.
            node *min = findMin(root->right, cd);

            // To mount, replicate the minimum necessary.
            copyPoint(root->point, min->point);

            // Remove the bare minimum in a recursive manner.
            root->right = deleteNodeRec(root->right, min->point, depth+1);
        }
        else if (root->left != NULL) // the same as before
        {
            node *min = findMin(root->left, cd);
            copyPoint(root->point, min->point);
            root->right = deleteNodeRec(root->left, min->point, depth+1);
        }
        else // If the node that has to be eliminated is a node,
        {
            delete root;
            return NULL;
        }
        return root;
    }

    // 2) If the current node lacks a point, search lower.
    if (point[cd] < root->point[cd])
        root->left = deleteNodeRec(root->left, point, depth+1);
    else
        root->right = deleteNodeRec(root->right, point, depth+1);
    return root;
}

// 'underlying cause' is a function that deletes a given location from the a K D Trees.
node* deleteNodeRec(node *root, int point[])
{
// Set the depth to 0
    return deleteNodeRec(root, point, 0);
}
