~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
CSC237 Data Structures/Project1 readme.txt
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

I chose the STL container 'vector' for my project. I chose this container because I felt that it provided a balance of ease of use with the build in method it provided, without having too many methods/functions that I would not make use of.

During my search for the right container for this project, I considered, an 'array', 'vector', 'set', and 'list', and used http://cplusplus.com

~~~~~~~~~~~~~~~~~~~~
Choosing a container
~~~~~~~~~~~~~~~~~~~~
An array is a fixed-size sequence container. I almost immediately decided I was not going to use this container because I wanted my program to be flexible, and able to parse any size file. An array would greater complicate or restrict my choices because I would have to copy/paste an array if I ran out of space, or I would have to make the array super large by default, which is really inefficient for most files.

A vector is like an array that can change its size. It does reallocate every-so-often when new elements are inserted, but it is in amortized constant time, which is very efficient. It contains methods which can get the size of the vector, which is something that is useful for printing out iteratively. It also has indexing and the ability to add elements to the back via push_back(). Finally, it has an iterator, with places at the beginning and end, which I can use for the iteration option.

A set is a container which stores unique elements following a specific order. I don't think that this container is something that I will use, because it uses key-value pairs in order to index, which would make printing it out more complex than it needs to be. I am also not sure how inputting a file into this structure would work.

A list is a sequence container that has constant time insert/erase operation anywhere within the sequence, and iteration in both directions. This container has everything that the vector container has, and more. It would be completely fine to use for this project, but since vector has everything that I need anyway, I would be prefer to use that. I do not want to have too much memory or computational overhead.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Inserting new terms/discovery of duplicate tokens
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
I handled inserting new objects using a while loop, which persists until the file is completely read through. In this loop, I intake a word, and check to make sure a word was actually intook. If it wasn't, I clear the error fail and continue the loop. If the word was intook, then I use a for loop to search for possible matches already in the data structure. If I find a match, then I increment the count of that word. If no match is found, then I add the new word to the data structure if there is space.

~~~~~~~~~~~~~~~~~~~~~~~~
Was my method efficient?
~~~~~~~~~~~~~~~~~~~~~~~~
I think my method was very efficient, however i suspect that there might be ways to create a more efficient method of file parsing. One might be able to intake the next word and check for end of file in the while-loop condition, which would reduce the number of operations that need to be complete.