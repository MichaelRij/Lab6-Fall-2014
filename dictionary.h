#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

const int MAX = 100;

typedef bool BOOL;
typedef string WORD;

/*
Author : Michael Rijlaarsdam
Lab #6 Assignment #3 Dictionary3
Purpose : This program creates a list of all the words typed in or in a given text file. cmd ./prog < "text file"
Can only handle a-z and A-Z;
forces all letters to lowercase; 
uses non-alphabetic characters to determine a new word; exception for '
does not spellcheck;
Functions will be in a seperate linked file
Dictionary will be sorted before being printed
Will hold words of any length

Differences from Dictionary(2)
Limit on # of words is arbitrary;
*/


typedef struct entry {

      int count;                  /* frequency count for a particular word */
      WORD w;                     /* the word itself */
      struct entry *nextWord;     /* pointer to next entry */

} ENTRY;


typedef struct dict {

     int maxEntries;	  /* maximum number of entries allowed; this is an artificial limit */
                          /* link lists can be as big as you want. This limit ensures that   */
                          /* this code tries to behave like the previous ones */
                                   

     int numWords;        /* number of words in the dictionary */
     ENTRY *Words;        /* pointer to the entries in the dictionary */

} DICT;


//Prototypes
ENTRY *LocateWord(DICT& , WORD);
BOOL FullDictionary(DICT&);
BOOL InsertWord(DICT&,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT&);
