#include "common.h"

Class Tree{
    enum TREE_TYPE{
        BINARY_TREE           = 0,
        BINARY_SEARCH_TREE    = 1,
    };

public:
    Tree();
    virtual ~Tree();
};

Class BinaryTree : public Tree
{
public:
    BinaryTree();
    virtual ~BinaryTree();
    
};

Class BinarySearchTree : public BinarySearchTree
{
public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

    insert(int a){
        
    }
    delete(int a);

private:
    
};

Tree generateTree(int type, int size){
    if(type == Tree::BINARY_TREE)
        return generateBinaryTree(int size);
    else if(type == Tree::BINARY_SEARCH_TREE)
        return generateBinarySearchTree(int size);

    return Tree();
}

BinarySearchTree generateBinarySearchTree(int size){
    BinarySearchTree tree;

#if 1
	struct timeval tv;
    gettimeofday(&tv,NULL);
	uint32_t seed = tv.tv_sec + tv.tv_usec;
#else
	time_t stime;
    uint32_t seed = time(NULL);
	printf("seed = %d.\n", seed);
#endif
    srand(seed);

    for(int i = 0; i < size; ++i){
        tree.insert(size*rand()/RAND_MAX);
    }

    return tree;
}
