/****************************************************************
 *    File:    WordData.cpp            				*
 *    Prepared by: Dr. Spiegel         				*
 *    Description: A WordData object, holds a word and its count*
 ****************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

/* Description: constructor() | constructs a WordData object
 * Arguments:	string wrd	IMPORT/EXPORT, the word
 * 		int cnt		IMPORT/EXPORT, the count of the word
 * Return Val:	NA
 */
WordData::WordData(string wrd, int cnt)
{
	setWordData(wrd, cnt);	
}

/* Description: setWord() | sets the word
 * Arguments:	string wrd	IMPORT/EXPORT, the word to set
 * Return Val:	NA
 */
void WordData::setWord(string wrd)
{
	word = wrd;
}

/* Description: setCount() | sets the count of the word
 * Arguments:	int cnt		IMPORT/EXPORT, the count to set
 * Return Val:	NA
 */
void WordData::setCount(int cnt)
{
	count = cnt;
}

/* Description: setWordData() | sets the word and its count
 * Arguments:	string wrd	IMPORT/EXPORT, the word to set
 * 		int cnt		IMPORT/EXPORT, the count to set
 * Return Val:	NA
 */
void WordData::setWordData(string wrd, int cnt)
{
	setWord(wrd);
	setCount(cnt);
}

/* Description: getWord() | gets the word
 * Arguments:	NA
 * Return Val:	string		EXPORT, the word being counted
 */
string WordData::getWord() const
{
	return(word);
}

/* Description: getCount() | gets the count of the word
 * Arguments:	NA
 * Return Val:	int		EXPORT, the count of the word
 */
int WordData::getCount() const
{
	return(count);
}

/* Description: operator++() | increments the count of the word
 * Arguments:	NA
 * Return Val:	WordData&	EXPORT, the WordData object, enables cascading
 */
WordData& WordData::operator++()	// preincrement
{	setCount(getCount()+1);
	return(*this);
}

/* Description: operator++(int) | increments the count of the word
 * Arguments:	int		(dummy argument)
 * Return Val:	WordData&	EXPORT, the WordData object, enables cascading
 */
WordData WordData::operator++(int)	// postincrement
{	WordData temp;
	setCount(getCount()+1);
	return(temp);
}

