/*************************************************************************
        Copyright © 2021 Konstantinidis Konstantinos

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef char BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);

int BSTLevel(BinTreePointer *Root, BinTreeElementType Item);
BinTreeElementType MinBSTValue(BinTreePointer *Root);
BinTreeElementType MaxBSTValue(BinTreePointer *Root);

main(){
    BinTreePointer Root;
    char word[50];
    int level, i;
    char Min, Max;

    CreateBST(&Root); //Create the binary search tree

    printf("Insert a word: ");
    scanf("%s", word);

    for(i=0; word[i]!='\0'; i++)
        BSTInsert(&Root, word[i]); //Insert each of the characters of the word in the bst

    if(!EmptyBST(Root)){
        for(i=0; word[i]!='\0'; i++){
            level = BSTLevel(&Root, word[i]); //Get the level of each character
            printf("Level of %c: %d", word[i], level); //And print it
            printf("\n");
        }

        Min = MinBSTValue(&Root); //Find the minimum letter (e.g. Word->Atom min is the letter A(1st in alphabetical order))
        printf("Min Value Is: %c \n", Min);

        Max = MaxBSTValue(&Root); //Find the minimum letter (e.g. Word->Atom max is the letter T)
        printf("Max Value Is: %c \n", Max);
    }

    system("PAUSE");
}

void CreateBST(BinTreePointer *Root){
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root){
    return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item){
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while(!Found && LocPtr != NULL){
        Parent = LocPtr;
        if(Item<LocPtr->Data)
            LocPtr = LocPtr->LChild;
        else if(Item>LocPtr->Data)
            LocPtr = LocPtr->RChild;
        else
            Found = TRUE;
    }
    if(Found)
        printf("Letter %c is already in the binary search tree\n", Item);
    else{
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr->Data = Item;
        LocPtr->LChild = NULL;
        LocPtr->RChild = NULL;
        if(Parent == NULL)
            *Root = LocPtr;
        else if(Item < Parent->Data)
            Parent->LChild = LocPtr;
        else
            Parent->RChild = LocPtr;
    }
}

int BSTLevel(BinTreePointer *Root, BinTreeElementType Item){
    BinTreePointer LocPtr;
    int level;

    LocPtr = *Root;
    level = 1;

    while(!EmptyBST(LocPtr)){
        if(Item < LocPtr->Data){
            level++;
            LocPtr = LocPtr->LChild;
        }

        else if(Item > LocPtr->Data){
            level++;
            LocPtr = LocPtr->RChild;
        }
        else
            return level;
    }
    return -1;
}

BinTreeElementType MinBSTValue(BinTreePointer *Root){
    BinTreePointer LocPtr;
    char Min;

    LocPtr = *Root;

    while(!EmptyBST(LocPtr)){
        Min = LocPtr->Data;
        LocPtr = LocPtr->LChild;
    }

    return Min;
}

BinTreeElementType MaxBSTValue(BinTreePointer *Root){
    BinTreePointer LocPtr;
    char Max;

    LocPtr = *Root;

    while(!EmptyBST(LocPtr)){
        Max = LocPtr->Data;
        LocPtr = LocPtr->RChild;
    }

    return Max;
}
