#include "BSTHeader.h"

/*
    Pre-Ordem:");
    PrintTreePreOrder(treeRoot);

    Em Ordem:");
    PrintTreeInOrder(treeRoot);

    Pos-Ordem:
    PrintTreePostOrder(treeRoot);

    Por Largura (Por seccao horizotal)
    PrintTreeAllTransversalLevel(treeRoot);

*/

int main(void) 
{
    NodePointer treeRoot;
    int input;

    CreateNewTree(&treeRoot);

    printf("______________________________________________________________________________\nOla! Bem vindo ao BST Maker Tool, digite de 8 numeros abaixo para obter sua BST\n\n");
    
    for (int i = 1; i <= 8; i++){
        printf("%d. ", i);
        scanf("%d", &input);
        AddData(&treeRoot, input);
    }
    printf("\nHere is your tree:\n\n");
    PrintGorgeousTree(treeRoot);
    printf("\nObrigado por usar nosso sistema extremamente util no dia a dia! Pressione qualquer numero e Enter para fechar. \n \ns");
    scanf("%d", &input);
}