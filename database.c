#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2560
void databasefun(char arr[MAX][MAX]);
/*int len(char str[])
    {
        int i;
        for (i = 0; str[i] != '\0'; ++i);
        return i;
    }*/
void create(char arr[][MAX]){
	FILE *fp;
	if(fp=fopen(arr[2],"r")){
		fp = fopen(arr[2],"a");
		for(int i=3; i<20 ; i++){
			fprintf(fp,"%s(%s)\t", arr[i],arr[i++]);
		}
	printf("\n");
	}
	else{
		fp = fopen(arr[2], "w");
		for(int i=3; i<20 ; i++){
			fprintf(fp,"%s(%s)\t", arr[i],arr[i++]);
		
		}
	printf("\n");
	}
	
}
void databasefun(char arr[][MAX]){
	if(strcmp("create",arr[0]) == 0){
		printf("creating table..\n");
		create(arr);
	}	
	else
		printf("error creating the table..\n");
	
	
}
void keywords(char str[], int len){
	char word[MAX][MAX];
	int i,j,k;
	j=0;k=0;
	for(i = 0 ; i < len; i++ ){
		if(str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == ',' ||  str[i] == '\n'){
			word[j][k] = '\0';
			j++;
			k = 0;
		}
		else{
			word[j][k] = str[i];
			k++;
		}
	}

	databasefun(word);
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
	//printf("%s\n", str);
	//return realloc(str,sizeof(*str)*len);
	keywords(str,len);
	
}

int main(){
	char *m;
	printf("mysql>");
	m = inputQuery(stdin,20);
	//free(m);
}

