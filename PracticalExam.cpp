#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *l;
	struct node *r;
}* rootnode;

int leaf=1;

void createtree() {
    int ch = 1;
    struct node* cpt, * ptr, * pptr;
    rootnode = (struct node*)malloc(sizeof(struct node));
    cout << "Enter Root Data: ";
    cin >> rootnode->data;
    rootnode->l = rootnode->r = NULL;
    while (ch == 1)
    {
        cpt = (struct node*)malloc(sizeof(struct node));
        cout << "Enter Data: ";
        cin >> cpt->data;
        cpt->l = cpt->r = NULL;
        ptr = rootnode;
        while (ptr != NULL)
        {
            pptr = ptr;
            if (cpt->data < ptr->data)
            {
                ptr = ptr->l;
                if (ptr == NULL)
                    pptr->l = cpt;
            }
            else
            {
                ptr = ptr->r;
                if (ptr == NULL)
                    pptr->r = cpt;
            }
        }
        cout << "Continue? (1-Yes, 0-No): ";
        cin >> ch;
    }
}

void countleaf(struct node* t) {
    if (t == NULL) {
        leaf = leaf + 1;
        return;
    }

    cout << t->data << "->";
    countleaf(t->l);
    countleaf(t->r);
}

int main() {
	int ch = 1;
	createtree();
    countleaf(rootnode);
    cout << "\n"<<"Leaf Node: " << leaf/2;
}