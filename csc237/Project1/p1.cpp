#include <iostream>
#include <fstream>
#include <iomanip>
#include "WordData.h"
#include <vector>

using namespace std;

// file load prototypes
int parallel_file_load(ifstream &, int[], string[], const int &);
int object_file_load(ifstream &, WordData[], const int &);
void vector_file_load(ifstream &, vector<WordData> &);

// variation print prototypes
void parallel_iterative(const int[], const string[], const int &);
void parallel_recursive(const int[], const string[], const int &, int);
void object_iterative(const WordData[], const int &);
void object_recursive(const WordData[], const int &, int);
void object_pointer(WordData *, const int &);
void vector_indexing(const vector<WordData> &);
void vector_iterator(vector<WordData> &);

// modes
void loop_mode(const int[], const string[], WordData[], vector<WordData> &, const int &);
void batch_mode(const int[], const string[], WordData[], vector<WordData> &, const int &);

int main(int numArgs, char **charArgs)
{
  // variables for file input
  ifstream fileStream;
  string fileChoice;
  const int MAX = 10;
  int filled;
  bool batchMode = false;

  // data structures
  int countArray[MAX];
  string wordArray[MAX];
  WordData objectArray[MAX];
  vector<WordData> wordVector;

  // determine if BATCH or LOOP mode
  if (numArgs == 2)
  {
    fileChoice = charArgs[1];
    batchMode = true;
  }
  else
  {
    cout << "Please input a file name: ";
    cin >> fileChoice;
  }

  // ensure the file is reachable, if not terminate
  fileStream.open(fileChoice);
  if (fileStream.fail())
  {
    cout << "ERROR: FILE NOT FOUND" << endl;
    return 1;
  }

  // load each data structure, close and reopen file as well
  // THIS IS THE PART THAT MIGHT NEED TO BE CHANGED ACCORDING TO THE REQUIREMENTS
  filled = parallel_file_load(fileStream, countArray, wordArray, MAX);
  fileStream.close();
  fileStream.open(fileChoice);

  object_file_load(fileStream, objectArray, MAX);
  fileStream.close();
  fileStream.open(fileChoice);

  vector_file_load(fileStream, wordVector);
  fileStream.close();

  // enter either batch or loop mode
  if (batchMode)
  {
    batch_mode(countArray, wordArray, objectArray, wordVector, filled);
  }
  else
  {
    loop_mode(countArray, wordArray, objectArray, wordVector, filled);
  }
}

/* Description:	batch_mode() | runs all of the prints statements non-interactively.
 * Arguments:	const int countArray[] 		IMPORT, word count array for parallel arrays
 * 		const string wordArray[] 	IMPORT, word string array for parallel arrays
 * 		WordData objectArray[] 		IMPORT/EXPORT, WordData array for object array
 * 		vector<WordData> &wordVector	IMPORT/EXPORT, vector of WordData objects
 * 		const int &filled		IMPORT, number of elements filled by the file, applies to parallel arrays and object arrays
 * Return Val:	void
 */
void batch_mode(const int countArray[], const string wordArray[], WordData objectArray[], vector<WordData> &wordVector, const int &filled)
{
  // parallel arrayprints
  parallel_iterative(countArray, wordArray, filled);
  parallel_recursive(countArray, wordArray, filled, 0);

  // object array prints
  object_iterative(objectArray, filled);
  object_recursive(objectArray, filled, 0);
  object_pointer(objectArray, filled);

  // vector prints
  vector_indexing(wordVector);
  vector_iterator(wordVector);
}

/* Description:	loop_mode()() | prints a menu and chooses which print statement to use based on input.
 * Arguments:	const int countArray[] 		IMPORT, word count array for parallel arrays
 * 		const string wordArray[] 	IMPORT, word string array for parallel arrays
 * 		WordData objectArray[] 		IMPORT/EXPORT, WordData array for object array
 * 		vector<WordData> &wordVector	IMPORT/EXPORT, vector of WordData objects
 * 		const int &filled		IMPORT, number of elements filled by the file, applies to parallel arrays and object arrays
 * Return Val:	void
 */
void loop_mode(const int countArray[], const string wordArray[], WordData objectArray[], vector<WordData> &wordVector, const int &filled)
{
  bool loopMenu = true;
  char menuChoice;

  while (loopMenu)
  {
    cout << "Enter a number, 1-8, to choose from the menu below:" << endl
         << "1. Parallel Iterative" << endl
         << "2. Parallel Recursive" << endl
         << "3. Object Array Iterative" << endl
         << "4. Object Array Recursive" << endl
         << "5. Object Array Pointer Recursive" << endl
         << "6. STL [Object] For Loop" << endl
         << "7. STL [Object] Iterator" << endl
         << "8. Exit" << endl
         << endl
         << "Choice entered: ";
    cin >> menuChoice;

    switch (menuChoice)
    {
    case '1':
      parallel_iterative(countArray, wordArray, filled);
      break;
    case '2':
      parallel_recursive(countArray, wordArray, filled, 0);
      break;
    case '3':
      object_iterative(objectArray, filled);
      break;
    case '4':
      object_recursive(objectArray, filled, 0);
      break;
    case '5':
      object_pointer(objectArray, filled);
      break;
    case '6':
      vector_indexing(wordVector);
      break;
    case '7':
      vector_iterator(wordVector);
      break;
    case '8':
      loopMenu = false;
      break;
    default:
      break;
    }
  }
}

/* Description:	parallel_iterative() | prints out the parallel arrays through iteration.
 * Arguments:	const int countArray[] 		IMPORT, word count array for parallel arrays
 * 		const string wordArray[] 	IMPORT, word string array for parallel arrays
 * 		const int &MAX			IMPORT, number of elements in use, used only to print used elements
 * Return Val:	void
 */
void parallel_iterative(const int countArray[], const string wordArray[], const int &MAX)
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl
       << "Parallel Array Iterative" << endl
       << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl
       << "Word         Occurrences" << endl
       << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  for (int i = 0; i < MAX; i++)
  {
    cout << left << setw(22) << wordArray[i] << right << setw(2) << countArray[i] << endl;
  }
  cout << endl;
}

/* Description:	parallel_recursive() | prints out the parallel arrays through recursion.
 * Arguments:	const int countArray[] 		IMPORT, word count array for parallel arrays
 * 		const string wordArray[]	IMPORT, word string array for parallel arrays
 * 		const int &MAX			IMPORT, number of elements in use, used only to print used elements
 * 		int depth			IMPORT/EXPORT, depth of the recursion, goes from 0 to MAX.
 * Return Val:	void
 */
void parallel_recursive(const int countArray[], const string wordArray[], const int &MAX, int depth)
{
  if (!depth)
  {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << "Parallel Array Recursive" << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << "Word         Occurrences" << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  }
  if (depth < MAX)
  {
    cout << left << setw(22) << wordArray[depth] << right << setw(2) << countArray[depth] << endl;
    parallel_recursive(countArray, wordArray, MAX, depth + 1);
  }
  if (depth == MAX)
  {
    cout << endl;
  }
}

/* Description:	object_iterative() | prints out the object array through iteration.
 * Arguments:	const WordData objectArray[]	IMPORT, WordData array for object array
 * 		const int &MAX			IMPORT, number of elements in use, used only to print used elements
 * Return Val:	void
 */
void object_iterative(const WordData objectArray[], const int &MAX)
{
  cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Object Array Iterative" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Word       Occurrences" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;

  for (int i = 0; i < MAX; i++)
  {
    cout << left << setw(20) << objectArray[i].getWord() << right << setw(2) << objectArray[i].getCount() << endl;
  }
  cout << endl;
}

/* Description:	object_recursive() | prints out the object array through recursion.
 * Arguments:	const WordData objectArray[]	IMPORT, WordData array for object array
 * 		const int &MAX			IMPORT, number of elements in use, used only to print used elements
 * 		int depth			IMPORT/EXPORT, depth of the recursion, goes from 0 to MAX.
 * Return Val:	void
 */
void object_recursive(const WordData objectArray[], const int &MAX, int depth)
{
  if (!depth)
  {
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl
         << "Object Array Recursive" << endl
         << "~~~~~~~~~~~~~~~~~~~~~~" << endl
         << "Word       Occurrences" << endl
         << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
  }
  if (depth < MAX)
  {
    cout << left << setw(20) << objectArray[depth].getWord() << right << setw(2) << objectArray[depth].getCount() << endl;
    object_recursive(objectArray, MAX, depth + 1);
  }
  if (depth == MAX)
  {
    cout << endl;
  }
}

/* Description:	object_pointer() | prints out the object array using pointer arithmetic.
 * Arguments:	WordData *objectArray 		IMPORT/EXPORT, pointer to first element of objectArray
 * 		const int &MAX			IMPORT, number of elements in use, used only to print used elements
 * Return Val:	void
 */
void object_pointer(WordData *objectArray, const int &MAX)
{
  cout << "~~~~~~~~~~~~~~~~~~~~" << endl
       << "Object Array Pointer" << endl
       << "~~~~~~~~~~~~~~~~~~~~" << endl
       << "Word     Occurrences" << endl
       << "~~~~~~~~~~~~~~~~~~~~" << endl;

  for (int i = 0; i < MAX; objectArray++, i++)
  {
    cout << left << setw(18) << objectArray->getWord() << right << setw(2) << objectArray->getCount() << endl;
  }
  cout << endl;
}

/* Description:	vector_indexing() | prints out the vector of WordData objects using iteration.
 * Arguments:	const vector<WordData> &wordVector	IMPORT, vector of WordData objects
 * Return Val:	void
 */
void vector_indexing(const vector<WordData> &wordVector)
{
  cout << "~~~~~~~~~~~~~~~" << endl
       << "Vector Indexing" << endl
       << "~~~~~~~~~~~~~~~" << endl
       << "Word Occurences" << endl
       << "~~~~~~~~~~~~~~~" << endl;

  for (int i = 0; i < wordVector.size(); i++)
  {
    cout << left << setw(13) << wordVector[i].getWord() << right << setw(2) << wordVector[i].getCount() << endl;
  }
  cout << endl;
}

/* Description:	vecto_iterator() | prints out the vector of WordData object using its iterator.
 * Arguments:	vector<WordData> &wordVector	IMPORT/EXPORT, vector of WordData objects
 * Return Val:	void
 */
void vector_iterator(vector<WordData> &wordVector)
{
  cout << "~~~~~~~~~~~~~~~" << endl
       << "Vector Iterator" << endl
       << "~~~~~~~~~~~~~~~" << endl
       << "Word Occurences" << endl
       << "~~~~~~~~~~~~~~~" << endl;

  /*code inspired from: https://cplusplus.com/reference/vector/vector/begin/
   */
  for (vector<WordData>::iterator it = wordVector.begin(); it != wordVector.end(); it++)
  {
    cout << left << setw(13) << it->getWord() << right << setw(2) << it->getCount() << endl;
  }
  cout << endl;
}

/* Description:	parallel_file_load() | loads the file into parallel arrays.
 * Arguments:	ifstream &fileStream		IMPORT/EXPORT, file stream extracting the file
 * 		int countArray[] 		IMPORT/EXPORT, word count array for parallel arrays
 * 		string wordArray[] 		IMPORT/EXPORT, word string array for parallel arrays
 * 		const int &MAX			IMPORT, size of the array(s)
 * Return Val:	int				EXPORT, number of elements filled by the file
 */
int parallel_file_load(ifstream &fileStream, int countArray[], string wordArray[], const int &MAX)
{
  // variables
  int fillCount = 1;
  string word;
  bool matched;

  // repeat while file has contents remaining
  while (!fileStream.eof())
  {
    matched = false;
    fileStream >> word; // load next word
    if (fileStream.fail())
    {
      fileStream.clear();
      fileStream.ignore(1, '\n');
    } // if no word was loaded, clear
    else
    { // word loaded properly
      // go through list of current words to look for a match
      for (int i = 0; i < fillCount && matched == false; i++)
      {
        if (word == wordArray[i])
        {
          countArray[i]++;
          matched = true;
        }
      }
      // no match was found and there is room in array for new words, add it
      if (!matched && fillCount <= MAX)
      {
        countArray[fillCount - 1] = 1;
        wordArray[fillCount - 1] = word;
        fillCount++;
      }
    }
  }
  return fillCount - 1;
}

/* Description:	object_file_load() | loads the file into WordData object arrays.
 * Arguments:	ifstream &fileStream		IMPORT/EXPORT, file stream extracting the file
 * 		WordData objectArray[] 		IMPORT/EXPORT, WordData array for object array
 * 		const int &MAX			IMPORT, size of the array(s)
 * Return Val:	int				EXPORT, number of elements filled by the file
 */
int object_file_load(ifstream &fileStream, WordData objectArray[], const int &MAX)
{
  // variables
  int fillCount = 1;
  string word;
  bool matched;

  // repeat while file has contents remaining
  while (!fileStream.eof())
  {
    matched = false;
    fileStream >> word; // load next word
    if (fileStream.fail())
    {
      fileStream.clear();
      fileStream.ignore(1, '\n');
    } // if no word was loaded, clear
    else
    { // word loaded properly
      // go through list of current words to look for a match
      for (int i = 0; i < fillCount && matched == false; i++)
      {
        // match found, increase count there
        if (word == objectArray[i].getWord())
        {
          objectArray[i]++;
          matched = true;
        }
      }
      // no match was fonud and there is room in array for new words, add it
      if (!matched && fillCount <= MAX)
      {
        objectArray[fillCount - 1].setCount(1);
        objectArray[fillCount - 1].setWord(word);
        fillCount++;
      }
    }
  }
  return fillCount - 1;
}

/* Description:	vector_file_load() | loads the file into STL vector of WordData objects.
 * Arguments:	ifstream &fileStream		IMPORT/EXPORT, file stream extracting the file
 * 		vector<WordData> &wordVector	IMPORT/EXPORT, vector of WordData objects
 * Return Val:	void
 */
void vector_file_load(ifstream &fileStream, vector<WordData> &wordVector)
{
  // variables
  string word;
  bool matched;

  // repeat while filestream has contents remaining
  while (!fileStream.eof())
  {
    matched = false;
    fileStream >> word; // load next word
    if (fileStream.fail())
    {
      fileStream.clear();
      fileStream.ignore(1, '\n');
    }
    // if no word was loaded, clear^
    else
    { // word loaded properly, go through vector of current words to look for a match
      for (int i = 0; i < wordVector.size() && matched == false; i++)
      {
        if (word == wordVector[i].getWord())
        {
          wordVector[i]++;
          matched = true;
        }
      }
      // went through entire vector without finding the word
      if (!matched)
      {
        wordVector.push_back(WordData(word, 1));
      }
    }
  }
}
