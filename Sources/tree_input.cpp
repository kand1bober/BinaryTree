#include "../Headers/tree_input.h"
#include "../Headers/tree_functions.h"
#include <pthread.h>

enum TreeErrors MakeTreeData( struct File_input* file, struct Tree* tree )
{
    printf(RED "====== START MakeTreeData ======\n" DELETE_COLOR);

    char filepath[256] = {};

    GetFilePath( filepath, tree_data_name_old);

    FILE* stream = fopen( filepath, "r" );
    struct stat file_info = {};
    stat( filepath, &file_info );
    
    unsigned long int size_of_stream = (unsigned long int)file_info.st_size;
    ON_DEBUG( printf(YELLOW "size of file: %lu\n" DELETE_COLOR, size_of_stream); )

    file->size_of_file = size_of_stream;

    file->buffer = (char*)calloc( size_of_stream + 1, sizeof(char) );

    fseek(stream, sizeof(char) * 0L,  SEEK_SET);
    fread( (void*)file->buffer, sizeof(char), size_of_stream, stream);
    fclose(stream);

    //----------------------------------------------
    char* tmp = nullptr;
    const char* delim_shit = " {";
    char* ptr_progres = file->buffer;
    tmp = strtok_r( ptr_progres, delim_shit, &ptr_progres);
        ON_DEBUG( printf(PURPLE "%s\n" DELETE_COLOR, tmp); )
        // ON_DEBUG( printf(PURPLE "%p\n" DELETE_COLOR, tree->root); )
    NodeFromData( tree->root, &ptr_progres );
    //----------------------------------------------

    free( file->buffer );

    printf(RED "====== END MakeTreeData ======\n" DELETE_COLOR);

    return GOOD_INPUT;
}


void NodeFromData( struct Node_t* node, char** ptr_progres )
{
    // char* tmp = nullptr;
    //---------------------------------
    const char* delim_open = " { \" } \n \t";

    struct Node_t* left = nullptr;
    struct Node_t* right = nullptr;
    struct Node_t* tmp_node = nullptr;

    char* command = nullptr; 
    char* data_ptr = nullptr;
    double data = 0;

    //---------------------------LEFT SON-----------------------------------
    if( (command = strtok_r( nullptr, delim_open, ptr_progres )) != nullptr )
    {
        if( strcmp( command, "null" ) != 0)
        {   
            ON_DEBUG( printf(YELLOW "left branch " DELETE_COLOR); )
            ON_DEBUG( printf(PURPLE "%s\n" DELETE_COLOR, command); )
            
            data = strtod( command, &data_ptr);
            CreateNode( data, &tmp_node );
            left = tmp_node;
            InsertLeave( node, LEFT, tmp_node);
            NodeFromData(left, ptr_progres); 
        }
        else 
        {
            node->left = nullptr;
        }
    }
    else 
    {
        printf(RED "left node data not found\n" DELETE_COLOR);
        return;
    }

    //---------------------------RIGHT SON----------------------------------

    if( (command = strtok_r( nullptr, delim_open, ptr_progres )) != nullptr )
    {
        if( strcmp( command, "null" ) != 0)
        {
            ON_DEBUG( printf(SINIY "right branch\n" DELETE_COLOR); )
            
            data = strtod( command, &data_ptr);
            CreateNode( data, &tmp_node );
            right = tmp_node;
            InsertLeave( node, RIGHT, tmp_node);
            NodeFromData(right, ptr_progres); 
        }
        else 
        {
            node->right = nullptr;
        }
    }
    else 
    {
        printf(RED "right node data not found\n" DELETE_COLOR);
        return;
    }
    

    return;
}




void InputFileNameChange( void )
{
    printf(RED "HUUUUUUUUUUUUUUUUUUUUUUUUUUUUY\n" DELETE_COLOR);
    char tmp_name[] = "tmp.txt";

    char command_1[300] = "mv";
    sprintf(command_1, " %s%s", tree_data_name_old, tmp_name);
    system( command_1 );
    ON_DEBUG( printf(YELLOW "%s\n" DELETE_COLOR, command_1); )

    char command_2[300] = "mv";
    system( command_2 );
    sprintf( command_2, "mv %s%s", tree_data_name_new, tree_data_name_old);
    ON_DEBUG( printf(YELLOW "%s\n" DELETE_COLOR, command_2); )

    char command_3[300] = "mv";
    system( command_3 );
    sprintf( command_3, "mv %s%s", tmp_name, tree_data_name_new);
    ON_DEBUG( printf(YELLOW "%s\n" DELETE_COLOR, command_3); )
}

