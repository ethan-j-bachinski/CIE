#include <iostream>
struct node {
int data;
struct node * nextPtr;
};
typedef struct node Node;
typedef struct node * NodePtr;
int doSomething(NodePtr startPtr);
int main(void)
{
NodePtr myStartPtr;
NodePtr myPtr = myStartPtr;
int returnVal = 0;
myStartPtr = (NodePtr) malloc(sizeof(Node));
myPtr = myStartPtr;
myPtr->data = 5;
myPtr->nextPtr = (NodePtr) malloc(sizeof(Node));
myPtr = myPtr->nextPtr;
myPtr->data = 3;
myPtr->nextPtr = NULL;
returnVal = doSomething(myStartPtr);
printf("%d",returnVal)
return 0;
}
int doSomething(NodePtr startPtr)
{
NodePtr currentPtr;
int data = 0;
for (currentPtr = startPtr; currentPtr != NULL; currentPtr = currentPtr->nextPtr)
{
if (currentPtr->data > 2)
{
data = currentPtr->data;
}
}
return data;
}
