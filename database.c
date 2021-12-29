#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2560
void insert(char words[][MAX] , int count){
	FILE *fp;
	if(fp = fopen(words[2] , "r")){
		fp = fopen(words[2] , "a");
		for(int i=3; i<count-1 ; i++){
			fprintf(fp ,"%s\t\t" ,words[i]);
		}
		fprintf(fp,"\n");
		
	}
	else{
		
		printf("Table does not exists\n");
		
	}
}
void create(char words[][MAX] , int count){
	FILE *fp;
	if(fp = fopen(words[2] , "r")){
		printf("Table already exists\n");
	}
	else{
		fp = fopen(words[2] , "w");
		for(int i=3; i<count-1 ; i++){
			fprintf(fp ,"%s(%s)\t" ,words[i],words[i++]);
			fputs("\n" , fp);
		}
	}

}
void databasefun(char words[][MAX] , int size){
	for(int i = 0; i<size ; i++){
		if(strcmp(words[i],"create") == 0){
			create(words,size);
		}
		else if(strcmp(words[i],"insert") == 0){
			insert(words,size);
		}
	}
}
void keywords(char str[] , int size){
	char words[MAX][MAX];
	int i,j,k;
	j=0;k=0;
	int count = 0;
	for(i = 0 ; i < size; i++ ){
		if(str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == ',' || str[i] == ';' ||  str[i] == '\n'){
				words[j][k] = '\0';
				j++;
				k = 0;
				count++;
		}
		else{
			words[j][k] = str[i];
			k++;
		}
	}

	databasefun(words,count);	
}
char *inputQuery(FILE *fp,int size){
	char *str;
	int len = 0;
	int ch;
	str = realloc(NULL,sizeof(*str)*size);
	if(!str)
		return str;
	while(EOF != (ch = fgetc(fp)) && ch != '\n'){
		str[len++]=ch;
		if(len == size){
			str = realloc(str,sizeof(*str)*(size += 10));
			if(!str)
				return str;
		}
	}
	str[len++]='\0';
	printf("%s\n", str);
	//return realloc(str,sizeof(*str)*len);
	keywords(str,len);
	
	
}

int main(){
	char *m;
	printf("mysql>");
	m = inputQuery(stdin,20);
	
	//free(m);
}
