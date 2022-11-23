/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// visualize a tree!

struct Node {
    char data;
    struct Node* child;
    struct Node* sibling;
};

struct Node* create_node(char c)
{
    struct Node* n = (struct Node*)calloc(1,sizeof(struct Node));
    n->child = NULL;
    n->sibling = NULL;
    n->data = c;
}

void destroy_tree(struct Node* n)
{
    if(n)
    {
        if(n->sibling)
        {
            destroy_tree(n->sibling);
        }
        if(n->child)
        {
            destroy_tree(n->child);
        }
        
        free(n);
    }
}

void draw_tree(struct Node* n, int child_count[], int level)
{
    //print node's data first.
    printf("%c",n->data);
    //if it has siblings, draw siblings next.
    if(n->sibling)
    {
        printf("-"); //this is a must.
        child_count[level] = !!(n->child);  //it's necessary to store which sibling has a child.
        draw_tree(n->sibling,child_count, level + 1);
    }
    if(n->child)
    {
        printf("\n");
        if(level == 0)
        {
            printf("|");
            printf("\n");
        }
        else
        {
            //draw siblings' edges 
            for(int i = 0; i < level; ++i)
            {
                if(child_count[i] > 0)
                {
                    printf("| ");
                }
                else
                {
                    printf("  ");
                }
            }
            //draw self child's edge
            printf("|");
            printf("\n");//finish draw a must edge.
            //take care of siblings' edges
            for(int i = 0; i < level; ++i)
            {
                if(child_count[i] > 0)
                {
                    printf("| ");
                }
                else
                {
                    printf("  ");
                }
            } 
        }
        draw_tree(n->child,child_count,level);
    }
    
    return;
}

int main()
{
    //draw a tree
    
    //this is root
    struct Node* root = create_node('a');
    
    //b family. b has a child d.
    struct Node* b = create_node('b');
    root->child = b;
    struct Node* d = create_node('d');
    b->child = d;
    
    //h is d's sibling. h has a child, g. h has a r's sibling.
    struct Node* h = create_node('h');
    d->sibling = h;
    struct Node* g = create_node('g');
    h->child = g;
    struct Node* r = create_node('r');
    h->sibling = r;
    struct Node* w = create_node('w');
    r->sibling = w;
    struct Node* q = create_node('q');
    w->child = q;
    struct Node* k = create_node('k');
    w->sibling = k;
    struct Node* m = create_node('m');
    k->sibling = m;
    struct Node* n = create_node('n');
    m->sibling = n;
    struct Node* t = create_node('t');
    n->child = t;    
    
    
    //c family. c is b's sibling
    struct Node* c = create_node('c');
    b->sibling = c;
    struct Node* e = create_node('e');
    c->child = e;
    struct Node* j = create_node('j');
    e->sibling = j;
    struct Node* i = create_node('i');
    j->sibling = i;
    struct Node* o = create_node('o');
    i->child = o;
    struct Node* y = create_node('y');
    e->child = y;

    
    //z - family. z is c's sibling
    struct Node* z = create_node('z');
    c->sibling = z;
    struct Node* s = create_node('s');
    z->child = s;
    struct Node* x = create_node('x');
    s->child = x;

    int children[50];
    memset(children,0, 50 * sizeof(int));
    draw_tree(root,children,0);
    destroy_tree(root);
    return 0;
}

//OUTPUT
/*
a
|
b-c-z
| | |
| | s
| | |
| | x
| |
| e-j-i
| |   |
| |   o
| |
| y
|
d-h-r-w-k-m-n
  |   |     |
  |   |     t
  |   |
  |   q
  |
  g
*/

