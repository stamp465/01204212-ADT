#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
  item_t *table;
  int    size;
  int    hash_key;
} hash_t;

// Write your code here
/*item_t* newnode(char str[]){
	item_t* data = (item_t*)malloc(sizeof(item_t));
	data->text = (char*)malloc(TEXTSIZE);
	strcpy(data->text, str);
	data->next = NULL;
	return data;
}*/

hash_t* init_hashtable(int m,int hash_key){
	hash_t* hhhhash = (hash_t *)malloc(sizeof (hash_t));
	hhhhash->table = (item_t*)malloc(sizeof(item_t *) * m);
	for(int i=0;i<m;i++){
		hhhhash->table[i] = NULL;
	}
	hhhhash->hash_key = hash_key;
	hhhhash->size = m;
	return hhhhash;
}

void insert(hash_t* hashtable,char text[]){
	
	unsigned int hash_value = text[0];
	for (int i=1; i<strlen(text); i++)
		hash_value = (hashtable->hash_key)*hash_value + text[i];
	hash_value = hash_value%(hashtable->size);

	for(int i=0;i<hashtable->size;i++){
		unsigned int hash = (hash_value + (i+i*i)/2)%(hashtable->size);
		if( hashtable->table[hash] == NULL ){
			hashtable->table[hash] = (char*)malloc(TEXTSIZE);
			strcpy(hashtable->table[hash], text);
			//printf("insert %d\n",hash_value + (i+i*i)/2);
			break;
		}
	}
}

unsigned int search(hash_t* hashtable,char text[]){
	
	unsigned int hash_value = text[0];
	for (int i=1; i<strlen(text); i++)
		hash_value = (hashtable->hash_key)*hash_value + text[i];
	hash_value = hash_value%(hashtable->size);
	
	for(int i=0;i<hashtable->size;i++){
		//printf("%d\n",i);
		unsigned int hash = (hash_value + (i+i*i)/2)%(hashtable->size);
		if( hashtable->table[hash]!=NULL && strcmp(hashtable->table[hash],text) == 0 ){
			return hash;
		}
	}
	return -1;
	
}
// ...

int main(void) {
  hash_t *hashtable = NULL;
  char   *text = NULL;
  int    m, n, i, hash_key;
  int    command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);

  for (i=0; i<n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
      case 1:
        insert(hashtable, text);
        break;
      case 2:
        printf("%d\n", search(hashtable, text));
        break;
      }
  }
  return 0;
}
