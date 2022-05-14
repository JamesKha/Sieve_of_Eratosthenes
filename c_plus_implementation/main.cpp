#include <iostream>
#include <chrono> 
using namespace std;

/* This structure named “Node” would have three fields: the “value,” “booleanValue,” and the “nextNode.” The variable named “value” would contain an integer value that the algorithm uses to evaluate if the number was a prime or not. The variable named “booleanValue” would contain a Boolean value, and it would be set as true with the method “enqueue” and may be changed with the method named “setBoolean.” The field named “nextNode” contains the next node that comes after it. This algorithm would be set does the next number that comes after it.  */
struct Node
{
  int value;
  bool booleanValue;
  struct Node* nextNode;
};

/**This function named “enqueue” has two parameters. The frontOfQueue variable would determine what would be in front of the queue. It would be the starting note that all of the other numbers would link up. The second parameter, “value,” would contain the integer value, which would be applied to the node with the variable name of “temporary.” This method would be used within that “for loop,” located in the “primeSieve” message. **/

void
enqueue(struct Node** frontOfQueue, int value)
{

  struct Node* temporary = new Node; 

  struct Node* behindOfQueue = *frontOfQueue;
  temporary->value = value;
  temporary->booleanValue = true;
  temporary->nextNode = NULL;

  if (*frontOfQueue == NULL)
  {
    *frontOfQueue = temporary;//The temporary node would be assigned to be the front of the queue. 
    return;
  }

  while (behindOfQueue->nextNode != NULL)
    behindOfQueue = behindOfQueue->nextNode;//The assignment statement of the previously last node’s next node to the value of the temporary node.  

  behindOfQueue->nextNode = temporary;// The assignment statement of the previously last node as the value of the temporary node. 
  return;

}

/* The method named “toString” would print out all of the prime numbers that resulted from the algorithm. This method has two conditions. The first condition is the node is not null. If this condition were to be true, then the while loop within this method would iterate to the next node, no matter the second condition's outcome. The second condition would result if the number were to be printed or not. If the variable “booleanValue” were true, it would print out the field “value” within the node. If it were to be false, then it would not be printed. */

void
toString(struct Node* node)
{
  while (node != NULL){ //This WHILE loop continues to iterate through the queue, until the node was to be null.  
  {
    if (node->booleanValue == true) //This if statement checks if the node's booleanValue is to be true before continuing
    {
      cout << node->value << " "; //This prints out the Node's value
    }
    node = node->nextNode; //This next node to be the new Node through iteration
  }

}
}

/**The method that is named “setBoolean” would set the Node’s variable “booleanValue” as false if it matched the field “value.” Like the method “toString,” it would iterate through the nodes if the nodes were not null.  However, it would also stop iterating if the node’s value is equal to the function call parameters’ value. It would set the “booleanValue” as false to mark that value as not prime. If the node is not null and the node’s value is not equal to the specified value to be reached, it would continue iterating through nextNode. **/
void setBoolean(struct Node* node, int value)
{
  while ((node != NULL) && (node->value != value)) //This WHILE loop continues to iterate through the queue, until the node was to be null or have the value in the parameter
  {
    node = node->nextNode;
  }
  node->booleanValue = false;
}
/**The method is named “primeSieve” but takes all of the previous functions listed to create the collection of nodes that would calculate the prime numbers. The first thing that the function would do is take an integer value for its parameter named “endPrimeNumber.” The first “for” loop would enqueue nodes with an integer value between the range of two to the “endPrimeNumber” variable.  The second loop would start at two and iterate through each one until it reaches the integer variable “endPrimeNumber.” All the numbers are calculated or passed to the inner for loop. The inner for loop would take the integer value from the outer loop, find all the multiples of that integer value, and set the node associated with the value as false.  The last thing that this function does is call the function “toString” to print out all the prime values. **/
void primeSieve(int endPrimeNumber) {
  struct Node* startingNode = NULL;

  for (int i = 2; i <= endPrimeNumber; ++i) 
  {
    enqueue(&startingNode, i); // This for loop will enqueue are of the numbers from 2 to the endPrimeNumber
  }

  for (int index = 2; index <= endPrimeNumber; ++index) //This will iterate through all of numbers from 2 to endPrimeNumber
  {
    for (int multiplesOfIndex = index * index; multiplesOfIndex <= endPrimeNumber; multiplesOfIndex += index)//The multipleOfIndex takes all of the numbers from the outer for loop and marks all of the nodes that are multples from it
    {
      setBoolean(startingNode, multiplesOfIndex);
    }
  }

  toString(startingNode); // This prints out all of the nodes
}
/**This is where the analysis of the algorithm takes place. This measures the time of running the algorithm after multiple times. The startTime is before the executions, the endTIme is the time after the executions. The std::chrono::steady_clock::now() would measure the time before and the time after.    The variable executionTime would measure the time that is displaced.**/ 
int
main()
{
  cout <<" Jimmy Kha" << endl; 
  cout << "Assignment #4: Implementation of Sieve of Eratosthenes algorithm " << endl;
  cout << "C++" << endl;
  int numberOfIterations = 1; 
  
  auto startTime = std::chrono::steady_clock::now(); //The time variable before the executions
  for(int i = 0; i <numberOfIterations ; i++){
  primeSieve(10000);
  }
  auto endTime = std::chrono::steady_clock::now();//The time variable after the executions
  
  double executionTime = double(std::chrono::duration_cast<
  std::chrono::duration<double> > (endTime - startTime).count()); //The equation to find the displacement of time 
  
  cout << "\nThis algorithm took " << executionTime << " seconds to iterate " << numberOfIterations << " times";
  return 0;
}
