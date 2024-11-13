#include "../Headers/tree_functions.h"
#include "../Headers/tree_output.h"
#include "../Headers/tree_input.h"

int main()
{
    // struct Node_t n_50 = { 50, &n_30, &n_70, &my_tree->root };


    //------------Initialize------------
    struct File_input tree_input = {}; //for input
    struct File_text tree_output = {};   // for output
    struct File_text graph_file = {};  //for inpit
    struct Tree my_tree = {};
    TreeCtor( &my_tree );
    //----------------------------------

    MakeTreeData( &tree_input, &my_tree );

/*        
    //----------- PREKOLES ----------
    printf(RED "--------- Init -----------\n" DELETE_COLOR);
    struct Node_t* find_node = nullptr; //
    struct Node_t* tmp_node = nullptr;  //shold be used everytime you need to create a new node, otherwise it will be seg-fault
    CreateNode( 14.88, &tmp_node );
    InsertLeave( my_tree.root, LEFT, tmp_node );
    //---------------------------------
    printf(RED "--------- 1 -----------\n" DELETE_COLOR);
    CreateNode( 7.77, &tmp_node );
    Find( &my_tree, 14.88, &find_node );
    printf("find_node: %p\n", find_node);
    InsertLeave( find_node, RIGHT, tmp_node );
    //--------------------------------
    printf(RED "--------- 2 -----------\n" DELETE_COLOR);
    CreateNode( 6.66, &tmp_node );
    Find( &my_tree, 14.88, &find_node );
    printf("find_node: %p\n", find_node);
    InsertLeave( find_node, RIGHT, tmp_node );
    //-------------------------------
    printf(RED "--------- 3 -----------\n" DELETE_COLOR); //Предупреждение о вызове не той функции
    Find( &my_tree, 14.88, &find_node );
    CreateNode( 17.25, &tmp_node);
    NodeInsert( find_node->right, nullptr, tmp_node );
    printf("find_node: %p\n", find_node);
    //-------------------------------
    printf(RED "--------- 4 -----------\n" DELETE_COLOR);
    CreateNode( 20.24, &tmp_node);
    Find( &my_tree, 17.25, &find_node );
    InsertLeave( find_node, RIGHT, tmp_node);
    printf("find_node: %p\n", find_node);
    //-------------------------------
    printf(RED "--------- 5 -----------\n" DELETE_COLOR);
    CreateNode( 17.17, &tmp_node);
    Find( &my_tree, 20.24, &find_node );
    InsertLeave( find_node, RIGHT, tmp_node);
    printf("find_node: %p\n", find_node);
    //-------------------------------



    // //-------------------------------
    // printf(RED "--------- 6 -----------\n" DELETE_COLOR);
    // Find( &my_tree, 17.25, &find_node );
    // printf("find_node: %p\n", find_node);
    // ExtractNode( find_node );
    // //-------------------------------
*/

    //-------------SAVING TREE DATA--------------
    TreeData( &my_tree, &tree_output );
    InputFileNameChange();
    //-------------------------------------------

    //-----------------PRINTING------------------
    if(my_tree.status == GOOD_TREE)
    {
        Output( &graph_file, &my_tree);
    }
    else 
    {
        printf(RED "Bad Tree :(\n" DELETE_COLOR);
    }
    //-------------------------------------------
    TreeDtor( &my_tree );

    return 0;
}
