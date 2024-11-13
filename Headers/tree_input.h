#include <sys/stat.h>

#include "tree_output.h"
#include "tree_functions.h"

#ifndef TREE_INPUT_HEADER
#define TREE_INPUT_HEADER

struct File_input
{
    int size_of_file;
    char* buffer;
    int lines_amount;
};

enum TreeErrors MakeTreeData( struct File_input* file, struct Tree* tree );
void NodeFromData( struct Node_t* node, char** ptr_progres );
void InputFileNameChange( void );

#endif
