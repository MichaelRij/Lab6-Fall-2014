#include "dictionary.h"

extern DICT dictionary;  //your dictionary 
extern WORD word;   

int main (void) {

    ENTRY *pos;


    while (1) {

       word = GetNextWord();

	if ( word.empty() )  {
            DumpDictionary(dictionary);
            break;
	}

	if ((pos = LocateWord(dictionary,word)) >  0 ) pos->count++;
	else if (!InsertWord(dictionary,word)) {
	    cout <<endl<< "dictionary full " << word <<  " cannot be added\n"
	 	<<"Nothing after "<<word<<" will be added to the dictionary or contribute to the frequency " 		 	<<"count"<<endl<<endl;
            DumpDictionary(dictionary);
	    break;
	}
    }
    return 0;
}
