#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// trie node struct
struct Trie {
   int count;
   struct Trie *children[26];
};

// initializes a new trie node
struct Trie *newNode(void) {
   struct Trie *node = (struct Trie *) malloc(sizeof(struct Trie));
   node->count = 0;
   for (int i = 0; i < 26; i++) {
       node->children[i] = NULL;
   }
   return node;
}

// inserts a word into the trie
void insert(struct Trie **ppTrie, char *word) {
   if (word == NULL || strlen(word) == 0) {
       return;
   }
   struct Trie *curr = *ppTrie;
   if (curr == NULL) {
       curr = newNode();
       *ppTrie = curr;
   }
   for (int i = 0; i < strlen(word); i++) {
       int index = word[i] - 'a';
       if (curr->children[index] == NULL) {
           curr->children[index] = newNode();
       }
       curr = curr->children[index];
   }
   curr->count++;
}

// finds the number of occurrences of a word in the trie
int numberOfOccurances(struct Trie *pTrie, char *word) {
   if (word == NULL || strlen(word) == 0 || pTrie == NULL) {
       return 0;
   }
   struct Trie *curr = pTrie;
   for (int i = 0; i < strlen(word); i++) {
       int index = word[i] - 'a';
       if (curr->children[index] == NULL) {
           return 0;
       }
       curr = curr->children[index];
   }
   return curr->count;
}

// deallocates the trie
struct Trie *deallocateTrie(struct Trie *pTrie) {
   if (pTrie == NULL) {
       return NULL;
   }
   for (int i = 0; i < 26; i++) {
       if (pTrie->children[i] != NULL) {
           deallocateTrie(pTrie->children[i]);
       }
   }
   free(pTrie);
   return NULL;
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords) {
    FILE* inFile = fopen(filename,"r");
    int numOfWords = 0;
	fscanf(inFile, " %d\n", &numOfWords);
    
    for(int i = 0; i < numOfWords; i++) {
        fscanf(inFile, "%s\n", &pInWords);
    }
    fclose(inFile);
    return numOfWords;
}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = newNode();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}