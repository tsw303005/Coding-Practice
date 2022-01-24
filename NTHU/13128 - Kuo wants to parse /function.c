#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"


BTNode* EXPR()
{
	BTNode *right;
	if(pos >= 0)
		right = FACTOR();
	if(pos > 0)
	{
		if(expr[pos] == '|' || expr[pos] == '&')
		{
			BTNode *root = makeNode(expr[pos--]);
			root->right = right;
			root->left = EXPR();
			return root;
		}
		else
			return right;
	}
	else
		return right;
}
BTNode* FACTOR()
{
	if(expr[pos] == ')')
	{
		pos--;
		BTNode *re = EXPR();
		pos--;
		return re;
	}
	else
	{
		BTNode *re = makeNode(expr[pos]);
		pos--;
		return re;
	}
}
BTNode* makeNode(char c)
{
	BTNode *re = (BTNode*)malloc(sizeof(BTNode));
	for(int i = 0 ; i < NUMSYM ; i++)
	{
		if(c == sym[i])
		{
			//printf("%c\n",c);
			re->data = i;
			break;
		}
	}	
	re->left = NULL;
	re->right = NULL;
	return re;
} 