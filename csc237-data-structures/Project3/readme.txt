LINK TO DOXYGEN DOCUMENTATION: https://acad.kutztown.edu/~pscha710/csc237/Project3/html/

I chose the STL container 'list' for my project. I chose this container primarily because it allowed the implementation code to be relatively concise, with many methods that I was able to use for my personal benefit.

During my search for the right container for this project, I considered a 'vector' and a 'list', and used http://cplusplus.com 

A vector is like an array that can change its size. It does reallocate every-so-often when new elements are inserted, but it is in amortized constant time, which is efficient. It also has indexing and the ability to add elements to the back via push_back(). Finally, it has an iterator, with places at the beginning and end, which I can use for the iteration option. However, I would need to implement my own way of manipulating the order of the vector in order to alphabetize the vector of word data objects.

A list is a sequence container that has constant time insert/erase operation anywhere within the sequence, and iteration in both directions. This container has everything that the vector container has, and more. Most importantly to me, a list has a built-in sort function. This allows a more streamlined way of programming, because then I don't have to implement my own way of sorting the list, like I would have to do with a vector.

Because a list has methods which would make coding this project more streamlined and concise when compared to a vector, I chose to use a list for this project. I am not terribly concerned about having the absolute best efficiency, as a list and a vector are pretty close anyways and this is a relatively low scale project.