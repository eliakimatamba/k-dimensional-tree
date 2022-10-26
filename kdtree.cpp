// For execute the above code that the functionalities, you'll need a driver software

#include "kdtree.h"

using namespace std;

int main()
{
    node *root = NULL;
    int points[][k] = {{30, 40}, {5, 25}, {70, 70},
                       {10, 12}, {50, 30}, {35, 45}};

    int n = sizeof(points)/sizeof(points[0]);

    for (int i=0; i<n; i++)
        root = reinterpret_cast<node *>(reinterpret_cast<struct Node *>(insert(root, points[i])));

    // Delete (30, 40);
    root = reinterpret_cast< struct node*>(deleteNodeRec(root, points[0]));

    cout << "Root after deletion of (30, 40)\n";
    cout << root->point[0] << ", " << root->point[1] << endl;

    return 0;
}
