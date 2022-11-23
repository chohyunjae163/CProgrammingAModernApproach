/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

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

void draw_tree(struct Node* n, int child_count, int level)
{
    printf("%c",n->data);
    if(n->sibling)
    {
        printf("-");
        int c = !!(n->child) + child_count;
        draw_tree(n->sibling,c, level + 1);
    }
    if(n->child)
    {
        printf("\n");
        if(child_count > 0)
        {
            for(int i = 0; i <= child_count; ++i)
            {
                printf("| ");   
            }
            printf("\n");
            for(int i = 0; i < child_count; ++i)
            {
                printf("| ");   
            }
        }
        else
        {
            for(int i = 0; i < level; ++i)
            {
                printf("  ");   
            }
            printf("|");
            printf("\n");
            for(int i = 0; i < level; ++i)
            {
                printf("  ");   
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
    struct Node* r = create_node('r');
    h->sibling = r;
    struct Node* g = create_node('g');
    h->child = g;
    
    
    //c family. c is b's sibling
    struct Node* c = create_node('c');
    b->sibling = c;
    struct Node* e = create_node('e');
    c->child = e;
    struct Node* y = create_node('y');
    e->child = y;

    
    //z - family. z is c's sibling
    struct Node* z = create_node('z');
    c->sibling = z;
    struct Node* s = create_node('s');
    z->child = s;
    struct Node* x = create_node('x');
    s->child = x;

    draw_tree(root,0,0);
    destroy_tree(root);
    return 0;
}



