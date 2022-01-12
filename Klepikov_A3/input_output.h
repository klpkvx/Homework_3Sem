#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H
#include "list_node.h"

void print_list(list_node *head, int r);
int read_list(char *filename, list_node **head);
void delete_list(list_node *head);

#endif