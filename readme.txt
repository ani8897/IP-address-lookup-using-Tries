------------------Storing IP addresses as tries-----------------

We first convert the Network addresses and Subnet Masks into their binary representation.

Every node of the trie stores the following information:
	1. A pair of strings
	2. Boolean value indicating whether it is the leaf node or not.
	3. Pointers to its children (0 and 1)

We keep a count of the number(c) of ones encountered from the left in the Subnet Mask. While inserting into the trie, we insert only c bits of Network Address and store the strings (Network Address and Subnet Mask) at the leaf node. If it is a 0-bit, then move to the left child; if it does not exist, then create it and read the next byte. Symmetric argument goes for reading in a 1-bit.

Given an IP address, we convert it into its binary representation and traverse in the trie. While traversing the way as mentioned above, if we encounter a node whose boolean value 'isend' is true, then we store the data (pair of strings) into the result and traverse ahead. In this manner we will store the data from the node which matches the maximum with the IP address. The search terminates when we hit a NULL node.

Space complexity: O(exp(2,m)) where m is the max over all the counts of ones in the list of subnet masks
Time complexity for search and insert: O(1) as the number of bits in the binary representation is exactly 32.

