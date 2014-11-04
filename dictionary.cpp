#include "dictionary.h"


//structure describing a word entry in the dictionary


/*
  note that these are global variables so that they are already initialized to 0
*/

DICT dictionary={MAX,0,0};  // your dictionary       
WORD word;                



void DumpDictionary(DICT &dict) {
/* 
  will display the sorted contents
*/    

    ENTRY *thisentry = dict.Words;

    int tab = 0; 
    cout<<"Word		Frequency\n";
    cout<<"--------------------------\n";

    while(thisentry!=0){

	cout << thisentry->w;

	tab=((23-thisentry->w.length())/8);// 	lines up the counts
	while(tab-->=0)cout << "	";

	cout << thisentry->count<<endl;

	thisentry = thisentry->nextWord;
    }
}




BOOL InsertWord(DICT &dict, WORD word){
/* 
  adds word to dictionary , if word can't be added returns false else returns true
  keeps it sorted
*/

    ENTRY *pos = LocateWord(dict, word);// is 0 if not found

    if(pos!=0){//It is already in dictionary

	pos->count++;// so increment its count
	return 1;
    }else{//It isnt in dictionary

	ENTRY *iterative = dict.Words;
	ENTRY *prev=0;
	pos = new ENTRY;
	pos->count = 1;
	pos->w = word;
	pos->nextWord = 0;
	
	if(FullDictionary(dict))return 0;
	
	for(int i=0; i<dict.numWords+1; i++){

	    if(dict.Words==0){
		dict.Words=pos;
		break;
	    }

	    if((pos->w)<=(iterative->w)){

		if(iterative->nextWord==0){//insert into the tail
		    iterative->nextWord=pos;
		    break;
		}else{//check the next node
		    prev = iterative;
		    iterative = iterative->nextWord;
		}
	    }else{

		if(prev==0){//insert into the front
		    dict.Words=pos;
		    pos->nextWord = iterative;
		    break;
		}else{//insert into the middle
		    prev->nextWord= pos;
		    pos->nextWord= iterative;
		    break;
		}
	    }   

	}
    dict.numWords++;
    }
    return 1;
}



WORD GetNextWord(){
/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or 0 if no more words in input stream
*/
    WORD myString;
    BOOL empty = 1;

    char ch;
    while( cin.good() ){
	ch = cin.get();
	
	if(isalpha(ch)){  
	    if(ch>64 && ch<=90)ch+=32;//	convert A-Z to a-z
	    myString.push_back(ch);
	    empty = 0;
	}else if (ch == 39)continue;// handles apostraphes
	else if(!empty) return myString;

    }
    
    return "";

}

BOOL FullDictionary(DICT &dict) { //if dictionary is full, return 1 else 0 

    if(dict.numWords==MAX)return 1;
    return 0;
}

ENTRY *LocateWord(DICT& dict, WORD word){//
/*
   will determine if dictionary contains word. if found, returns pointer to entry else returns  0
*/

    ENTRY *thisentry = dict.Words;
    while(thisentry!=0){//	sequential search
	if(thisentry->w==word)return thisentry;
	thisentry = thisentry->nextWord;
    }
    return 0;
}
