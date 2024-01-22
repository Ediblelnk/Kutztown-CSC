/*******************************************************************/
/*    Author:        Dr. Spiegel		                   */
/*    Course:        CSC237                                        */
/*    Filename:      WordData.h                                    */
/*    Purpose:       This simple object is designed to hold a      */
/*                   string and an int. The string is meant to hold*/
/*                   a word and the int is meant to hold the number*/
/*                   of occurences of the word in a file. The int  */
/*                   and the string can be retrieved and set both  */
/*                   on their own as well as at the same time. The */
/*                   object also has the ability to increment the  */
/*                   word's counter.                               */
/*******************************************************************/


#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;

class WordData {
	
 public:  //PUBLIC FUNCTIONS

  /*****************************************************************/
  /*    Function name:   constructor                               */
  /*                                                               */
  /*    Description:     Will construct a default word data object.*/
  /*                     Default values are an empty string zero as*/
  /*                     the count.				   */
  /*                                                               */
  /*    Parameters:      string wrd - Word to be placed in object  */
  /*                     int cnt - Value to be placed in counter   */
  /*                                                               */
  /*    Member Type:     MUTATOR                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/  
  WordData(string wrd = "", int cnt = 0);
  
  //SETS
  //
  /*****************************************************************/
  /*    Function name:   setWord                                   */
  /*                                                               */
  /*    Description:     Will set the object's string.             */
  /*                                                               */
  /*    Parameters:      string wrd - Word to be placed in object  */
  /*                                                               */
  /*    Member Type:     MUTATOR                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
  void setWord(string wrd);

  /*****************************************************************/
  /*    Function name:   setCount                                  */
  /*                                                               */
  /*    Description:     Will set the occurence counter.           */
  /*                                                               */
  /*    Parameters:      int cnt - Value to be placed in counter   */
  /*                                                               */
  /*    Member Type:     MUTATOR                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
  void setCount(int cnt);

  /*****************************************************************/
  /*    Function name:   setWordData                               */  
  /*                                                               */
  /*    Description:     Will set both the object's string and the */
  /*                     object's occurence count.                 */
  /*                                                               */
  /*    Parameters:      string wrd - Word to be placed in object  */
  /*                     int cnt - Value to be placed in counter   */
  /*                                                               */
  /*    Member Type:     MUTATOR                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
  void setWordData(string,int);

  //GETS
  //
  /*****************************************************************/
  /*    Function name:   getWord                                   */
  /*                                                               */
  /*    Description:     Will retrieve the object's string.        */
  /*                                                               */
  /*    Parameters:      none                                      */
  /*                                                               */
  /*    Member Type:     INSPECTOR                                 */
  /*                                                               */
  /*    Return Value:    string                                    */
  /*****************************************************************/
  string getWord() const;

  /*****************************************************************/
  /*    Function name:   getCount                                  */
  /*                                                               */
  /*    Description:     Will retrieve the occurence counter.      */
  /*                                                               */
  /*    Parameters:      none                                      */
  /*                                                               */
  /*    Member Type:     INSPECTOR                                 */
  /*                                                               */
  /*    Return Value:    int                                       */
  /*****************************************************************/  
  int getCount() const;
  
  /*****************************************************************/
  /*    Function name:   operator ++                               */
  /*                                                               */
  /*    Description:     Will increment the occurrence counter.    */
  /*                                                               */
  /*    Parameters:      int inc - Value to be incremented by      */
  /*                                                               */
  /*    Member Type:     INSPECTOR                                 */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
  WordData& operator++();	// preincrement
  WordData operator++(int);	// postincrement

 private: //PRIVATE VARIABLES
  
  string word;  //Object's word
  int count;    //Object's occurrence counter

};

/*****************************************************************/
/*    Function name:   operator <<                               */
/*                                                               */
/*    Description:     Associated stream-insertion operator      */
/*                                                               */
/*    Parameters:      ostream &output - output stream	         */
/*		       const WordData &word  - object to print   */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/
ostream &operator<< ( ostream &output, const WordData &word);

#endif
