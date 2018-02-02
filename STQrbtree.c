#include <stdio.h>
#define true  1
#define flase 0

#define RB_RED 	 0
#define RB_BLACK 1

struct rbtree_node
{
	unsigned long __rb_parent_color;
	struct rbtree_node *left;
	struct rbtree_node *right;
};

struct rbtree_root
{
	struct rbtree_node * root;	
};

#define get_parant_node(rb) ((struct rbtree_node *)((rb)->__rb_parent_color & ~3))

int is_color_red(struct rbtree_node *node) {
	return !(node->__rb_parent_color & 1);
}

int is_color_black(struct rbtree_node *node) {
	return (node->__rb_parent_color & 1);
}

void rb_set_color(struct rbtree_node *parent, struct rbtree_node * node, int color) {
	node->__rb_parent_color = (unsigned long)parent | color;
}

void rb_set_black(struct rbtree_node * node) {
	node->__rb_parent_color |= RB_BLACK;
}

void rb_set_red(struct rbtree_node * node) {
	node->__rb_parent_color |= RB_RED;
}

void __rb_insert(struct rbtree_root * root, struct rbtree_node * node) {

	struct rbtree_node *parent = get_parant_node(node), *gparent, *tmp;
	
	while(true) {

		if(!parent){
			rb_set_color(NULL, node, RB_BLACK);
			break;
		}

		if(is_color_black(parent))
			break;

		gparent = get_parant_node(parent);
		tmp = gparent->left;

		if(tmp != parent) {  //parent = gparent->right

			if(tmp && is_color_red(tmp)) {
				rb_set_color(gparent, parent, RB_BLACK);
				rb_set_color(gparent, tmp, RB_BLACK);
				node = gparent;
				parent = get_parant_node(node);
				rb_set_color(parent, node, RB_RED);
				continue;
			}

			tmp = parent->right;
			if(tmp == node) {
				/*
					       G             G
					      / \           / \
					     p   U  -->    n   U
					      \           /
					       n         p
				*/
				tmp = node->left;
				parent->right = tmp;
				node->left = parent;
				if(tmp){
					rb_set_color(node, tmp, RB_BLACK);
				}
				rb_set_color(node, parent, RB_RED);
				parent = node;
				tmp = node->right;
			}
			/*
			 * Case 3 - node's uncle is black and node is
			 * the parent's left child (right rotate at gparent).
			 *
			 *        G           P
			 *       / \         / \
			 *      p   U  -->  n   g
			 *     /                 \
			 *    n                   U
			 */
			gparent->left = tmp;
			parent->right = gparent;
			if(tmp){
				rb_set_color(gparent, tmp, RB_BLACK);
			}

			tmp = get_parant_node(gparent);
			parent->__rb_parent_color = gparent->__rb_parent_color;
			rb_set_color(parent, gparent, RB_RED);
			if(tmp){
				if(tmp->left == gparent)
					tmp->left = parent;
				tmp->right = parent;
			}else {
				root->root = parent;
			}

			break;
		}else {//parent = gparent->left

		}

	}
}

void del_color(){

	// 1. D 
	// 2.

}