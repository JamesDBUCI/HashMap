// Trung Nguyen
// ID# 14853167
// HashMap.cpp

#include "HashMap.hpp"

namespace
{

	unsigned int defaultHash(const std::string& tempString)
	{
		// prime
		unsigned int A = 54059; 
		unsigned int B = 76963; 
		unsigned int C = 86969; 
		unsigned int h = 31; 
	  
	   for (unsigned int index=0; index < tempString.length(); index++) {
	     h = (h * A) ^ (tempString[index] * B);
	     index++;
	   }
	   return h % C;
	}

}


HashMap::HashMap()
	   : sz{0}, numBucket{initialBucketCount}
{
	hasher = defaultHash;

	arrayBucket = new Node*[numBucket];
	initializeArrayBucket(arrayBucket, numBucket);

}

HashMap::HashMap(HashFunction hasher)
       : sz{0}, numBucket{initialBucketCount}

{
	hasher = hasher;

	arrayBucket = new Node*[numBucket];
	initializeArrayBucket(arrayBucket, numBucket);
}

HashMap::HashMap(const HashMap& hm)
	   :hasher{hm.hasher}, sz{hm.sz}, numBucket{hm.numBucket}
{

	arrayBucket = new Node*[hm.numBucket];
	initializeArrayBucket(arrayBucket, numBucket);
	
	copyArrayBucket(arrayBucket, hm.arrayBucket, hm.numBucket);

}

HashMap::~HashMap()
{

	for (unsigned int i=0; i < numBucket; i++)
	{
		Node* tempPtr = arrayBucket[i];
    
    	/* Traverse the list and delete the node one by one from the head */
    	while (tempPtr != nullptr) 
    	{
	        /* take out the head node */
	        arrayBucket[i] = arrayBucket[i]->next;
	        delete tempPtr;
	        /* update the head node */
	        tempPtr = arrayBucket[i];
    	}
		    
	
	}
	delete[] arrayBucket;

}

HashMap& HashMap::operator=(const HashMap& hm)
{
	if (this != &hm)
	{

		// clean up old array
		this->~HashMap();

        arrayBucket = new Node*[hm.numBucket];
		initializeArrayBucket(arrayBucket, hm.numBucket);
		copyArrayBucket(arrayBucket, hm.arrayBucket, hm.numBucket);

        hasher = hm.hasher;
		sz = hm.sz;
        numBucket = hm.numBucket;

	}
	return *this;
}

void HashMap::add(const std::string& key, const std::string& value)
{
	
	if (!contains(key))
	{
		
		unsigned int index = hasher(key) % numBucket;
		addToTheHead(key, value, arrayBucket[index]);
		sz++;
		

		if (loadFactor() > 0.8)
		{
			unsigned int newNumBucket = numBucket*2 + 1;
			
			Node** newArrayBucket = new Node*[newNumBucket];
			initializeArrayBucket(newArrayBucket, newNumBucket);
			
			
			for (unsigned int i=0; i < numBucket; i++)
			{
				Node* tempPtr = arrayBucket[i];
				while (tempPtr != nullptr)
				{
					index = hasher(tempPtr->key) % newNumBucket;  // get the new index base on the newNumBucket

					addToTheHead(tempPtr->key, tempPtr->value, newArrayBucket[index]);

					tempPtr = tempPtr->next;
				}

			}

			//clean up
			this->~HashMap();
			
			// reassign
			arrayBucket = newArrayBucket;
			numBucket = newNumBucket;

		}				
		
	}
	
}


void HashMap::remove(const std::string& key)
{
	if (contains(key)) 									// check if I already know it's there
	{
		unsigned int index = hasher(key) % numBucket;

		Node* tempPtr;
		Node* previousNode;

		// Determine if the first node is the one to delete.
		if (arrayBucket[index]->key == key)
		{
			tempPtr = arrayBucket[index]->next;
			delete arrayBucket[index];
			arrayBucket[index] = tempPtr;
 
		}
		else
		{
			// Initialize tempPtr to head of linked-list
			tempPtr = arrayBucket[index];

			// Skip all nodes whose not equal to key.
			while (tempPtr != nullptr && tempPtr->key != key)
			{	
				previousNode = tempPtr;
				tempPtr = tempPtr->next;
			}

			// Link the previous node to the node after
			// nodePtr, then delete nodePtr.
			previousNode->next = tempPtr->next;
			delete tempPtr;
		}

		// decrease the size
		sz--;
	}

}


bool HashMap::contains(const std::string& key) const
{
	unsigned int index = hasher(key) % numBucket;
	Node* tempPtr = arrayBucket[index];
    

    if (tempPtr != nullptr)
    {
    	while (tempPtr->key != key && tempPtr->next != nullptr)
	        tempPtr = tempPtr->next;
	    
	    if (tempPtr->key == key)
	        return true;
	    else
	        return false;
    }
    else
    	return false;

}


std::string HashMap::value(const std::string& key) const
{
	if (contains(key))     // I already know it's there
	{
		unsigned int index = hasher(key) % numBucket;
		Node* tempPtr = arrayBucket[index];

		while (tempPtr->key != key)
        	tempPtr = tempPtr->next;
	    
	    return tempPtr->value;    
	}
	else
		return "";
	
}



unsigned int HashMap::size() const
{
	return sz;
}

unsigned int HashMap::bucketCount() const
{
	return numBucket;
}

double HashMap::loadFactor() const
{

	return (double) size() / bucketCount();
}

unsigned int HashMap::maxBucketSize() const
{
	unsigned int num1 = 0;
	unsigned int num2;

	for (unsigned int i=0; i<numBucket; i++)
	{
		num2 = 0;

		Node* tempPtr = arrayBucket[i];
        while (tempPtr != nullptr)
        {
    		num2++;
        	tempPtr = tempPtr->next;
        }

        if (num2 > num1)
        	num1 = num2;
	}

	return num1;
}


// ==========================================================================
// HELPER FUNCTIONS

void HashMap::initializeArrayBucket(Node** &newArrayBucket, unsigned int size)
{
	for (unsigned int i=0; i < size; i++)
	{
		newArrayBucket[i] = nullptr;     // base on the design , every new bucket initialize to nullptr
	}
}

void HashMap::copyArrayBucket(Node** target, Node** const &source, unsigned int size)
{

    for (unsigned int i = 0; i < size; i++)
    {
        
        Node* currentPtr = source[i];

        if (currentPtr != nullptr)
        {
        	target[i] = new Node;
        	Node* tempPtr = target[i];

        	while (currentPtr != nullptr)
        	{
        		tempPtr->key = currentPtr->key;
        		tempPtr->value = currentPtr->value;

        		if (currentPtr->next != nullptr)
	        	{
	        		tempPtr->next = new Node;
	        		tempPtr = tempPtr->next;
	        	}
	        	else
	        		tempPtr->next = nullptr;

	        	currentPtr = currentPtr->next;        	
        	} 
        }
        

    }

}

// assign a pair/value to a new Node, then add the new Node to the Head of an existence linked list
void HashMap::addToTheHead(const std::string& key, const std::string& value, Node* &headPtr)
{
	// create a new Node
	Node* newNode = new Node;
	newNode->key = key;
	newNode->value = value;
	newNode->next = headPtr;  // push the head of existence Node to the second position

	// add to the begin of the linked-list Node*
	headPtr = newNode;

}

void HashMap::clear()
{
	for (unsigned int i=0; i < numBucket; i++)
	{
		Node* tempPtr = arrayBucket[i];
    
    	/* Traverse the list and delete the node one by one from the head */
    	while (tempPtr != nullptr) 
    	{
	        /* take out the head node */
	        arrayBucket[i] = arrayBucket[i]->next;
	        delete tempPtr;
	        /* update the head node */
	        tempPtr = arrayBucket[i];
    	}
		    
		    /* Reset the node */
		    arrayBucket[i] = nullptr;
	
	}

	sz = 0;
}