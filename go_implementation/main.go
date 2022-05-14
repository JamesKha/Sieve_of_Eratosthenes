
package main

import (
  "fmt"
  "time"
)

/* This structure named “Node” would have three fields: the “value,” “booleanValue,” and the “nextNode.” The variable named “value” would contain an integer value that the algorithm uses to evaluate if the number was a prime or not. The variable named “booleanValue” would contain a Boolean value, and it would be set as true with the method “enqueue” and may be changed with the method named “setBoolean.” The field named “nextNode” contains the next node that comes after it. This algorithm would be set does the next number that comes after it.   */

type Node struct {
  value        int
  booleanValue bool
  nextNode     *Node
}

func enqueue(frontOfQueue  *Node, value int) {
  var temporary *Node = new(Node)
  var behindOfQueue *Node = frontOfQueue 
  temporary.value = value //This assigns the value to the temporary node
  temporary.booleanValue = true//This assigns the value "true" to the temporary node
  temporary.nextNode = nil//This sets the nextNode to be nil

  if frontOfQueue  == nil {//This “if” statement would determine if the first node within the collection is to be null. If this was to be true then the frontOfQueue  of the note would be assigned the “temporary” node. 
    frontOfQueue  = temporary 
    return
  }

  for behindOfQueue.nextNode != nil {//This "for" loop will iterate until the nextNode is nil
    behindOfQueue = behindOfQueue.nextNode //This will assign the next node as 
  }

  behindOfQueue.nextNode = temporary 
  return

}
/* The method named “toString” would print out all of the prime numbers that resulted from the algorithm. This method has two conditions. The first condition is the node is not null. If this condition were to be true, then the while loop within this method would iterate to the next node, no matter the outcome of the second condition. The second condition would result if the number were to be printed or not. If the variable “booleanValue” were true, it would print out the field “value” within the node. If it were to be false, then it would not be printed.  */
func toString(node *Node) {
  for node != nil {
    if node.booleanValue == true {
      fmt.Printf("%v ", node.value)
    }
    node = node.nextNode
  }
  fmt.Println()
}
/**The method that is named “setBoolean” would set the Node’s variable “booleanValue” as false if it matched the field “value.” Like the method “toString,” it would iterate through the nodes if the nodes were not null.  However, it would also stop iterating if the node’s value is equal to the function call parameters’ value. It would set the “booleanValue” as false to mark that value as not prime. If the node is not null and the node’s value is not equal to the specified value to be reached, it would continue iterating through nextNode. **/
func setBoolean(node *Node, value int) {
  for (node != nil) && (node.value != value) {//This for loop continues to iterate through the queue, until the node was to be null or have the value in the parameter
    node = node.nextNode
  }
  node.booleanValue = false
}

/**The method is named “primeSieve” but takes all of the previous functions listed to create the collection of nodes that would calculate the prime numbers. The first thing that the function would do is take an integer value for its parameter named “endPrimeNumber.” The first “for” loop would enqueue nodes with an integer value between the range of two to the “endPrimeNumber” variable.  The second loop would start at two and iterate through each one until it reaches the integer variable “endPrimeNumber.” All the numbers are calculated or passed to the inner for loop. The inner for loop would take the integer value from the outer loop, find all the multiples of that integer value, and set the node associated with the value as false.  The last thing that this function does is call the function “toString” to print out all the prime values. **/
func primeSieve(endPrimeNumber int) {

  frontOfQueue  := new(Node)
  for i := 2; i <= endPrimeNumber; i++ {
    enqueue(frontOfQueue , i)
  }

  for index := 2; index <= endPrimeNumber; index++ {
    for multiplesOfIndex := index * index; multiplesOfIndex <= endPrimeNumber; multiplesOfIndex += index {
      setBoolean(frontOfQueue , multiplesOfIndex)
    }
  }

}


func main() {
  

  var totalExecutionTime float64; 
  var numberOfIterations int= 20; 
  startTime := time.Now()
  for i := 0; i <= numberOfIterations; i++ { 

  primeSieve(10000)

  }
    executionTime := time.Since(startTime).Seconds()

  totalExecutionTime += executionTime; 

  fmt.Println("This algorithm took", totalExecutionTime, "seconds to iterate ", numberOfIterations," times." )
}
