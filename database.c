#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2560
void insert(char words[][MAX] , int count){
	FILE *fp;
	if(fp = fopen(words[2] , "r")){
		fp = fopen(words[2] , "a");
		fprintf(fp,"\n");
		for(int i=3; i<count-1 ; i++){
			fprintf(fp ,"%s\t\t" ,words[i]);
		}
		fprintf(fp,"\n");
		printf("Inserting values into tables..\n");
		
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
		for(int i=3; i<count-1 ; i++)
		{
			fprintf(fp ,"%s(%s)\t" ,words[i],words[i++]);
		}
		printf("Creating  Table..\n");
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
		if(str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == ',' || str[i] == ';'){
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
int len(char string[]){
	int i;
	for(i =0; string[i] != '\0'; i++);
	return i;
}
void syntaxCheck(char *str){
	int strlen = len(str);
	int flag=0;
	int j,k,i;
	//printf("%d", strlen);
	for(i = 0 ; i<strlen ; i++){
		if(str[i] == '(')
			j = i;
		if(str[i] == ')')
			k = i;
	}
	for(i = j ; i<=k ; i++){
		if(str[i] == ',')
			flag++;
	}
	if(flag == 0)
		printf("Syntax Error!\n");
	else
		keywords(str,strlen);
	
}
void inputQuery(FILE *fp,int size){
	char *str = malloc(sizeof(char) * size);
	int c;
	int len=0;
	while(EOF != (c = fgetc(fp)) && c != '\n'){
		str[len++]=c;
		if(len==size){
			str = realloc(str, sizeof(char) * (size *= 2));
		}
	}
	str[len++]='\0';
	
	if(str[len-2] != ';'){
		
		printf("syntax Error!\n");
	}
		
	else{
		syntaxCheck(str);	
	}
	//printf("%s\n", str);
}


int main(){	
	printf("mysql>");
	inputQuery(stdin,20);	
	//syntaxCheck(m,strlen);
	return 0;

	
}
