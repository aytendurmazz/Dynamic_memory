#include <stdio.h>
#include <stdlib.h>

int search(int lenptr,char *ptr,char *word){ 
    int value=0; // return value

    for(int i = 0 ; i<=(lenptr-strlen(word));i++){
        int j =0;
        while(j<strlen(word) && word[j]==ptr[i+j] ){
            if(j==0 ){
                if(ptr[i+j-1]==' '){
                    j++;
                }
                else{break;}
            }
            else{
                j++;
            }
        }
        if(j==strlen(word)){
            printf("Word : %s | Index : %d  | Word Length : %d \n",word,i,strlen(word));
            value=1;
        }
    }
    return value;

}
int main()
{
    FILE *file;
    char *ptr,*word; //ptr = txt pointer || word = keyword pointer
    char c,ch; // char read
    int lenptr=0; //txt file size


    if((file=fopen("read.txt","r"))!= NULL){ // reading txt 
            while((c = fgetc(file)) != EOF){ //find file size to create dynamic array
                lenptr++;

            }
            ptr=(char*)malloc(lenptr*sizeof(char)); // dynamic array
            lenptr=0;
            rewind(file);
            ptr[lenptr++]=' ';
            while((c = fgetc(file)) != EOF){ // Assign element to txt list
                ptr[lenptr++]=c;
            }
            printf("Keyword : ");
            word=(char*)malloc(lenptr*sizeof(char)); // assumed that the word could be in the maximum file size
            scanf("%s",word);

            if(search(lenptr,ptr,word)==0){
                printf("The searched word could not be found in the text");
            }
            free(ptr);
            free(word);
            fclose(file);

    }else{
         printf(file,"File not Found!");
    }

}
