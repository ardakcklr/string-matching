include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
  
void string_matching(char* wanted_word , char* text) 
{ 
    int word_length = strlen(wanted_word); 
    int text_length = strlen(text); 
  
    
    for (int i = 0; i <= text_length - word_length; i++) { 
        int j; 
  
        
        for (j = 0; j < word_length; j++){ 
            if (text[i + j] != wanted_word[j]) 
                break;
            } 
  
        if (j == word_length){  
            printf("Word found at index %d \n", i);
            }
    } 
}

long int findSize(char file_name[]) 
{ 
     
    FILE* size_pointer = fopen(file_name, "r"); 
  
     
    if (size_pointer == NULL) { 
        printf("File Not Found!\n"); 
        return -1; 
    } 
  
    fseek(size_pointer, 0L, SEEK_END); 
  
     
    long int file_size = ftell(size_pointer); 
  
     
    fclose(size_pointer); 
  
    return file_size; 
}

int main() 
{ 
    FILE* file_pointer;
    char* text;
    char file_name[100];
    char wanted_word[35];
    char currentCharacter;
    
    
    printf ("Enter file name and directory:");
    scanf ("%s",file_name);
    long int file_size = findSize(file_name);
    
    
    
    text=malloc(file_size+1);
    text[file_size]='\0';
    
    if(text==NULL){
        printf("Memory can not be allocated.\n");
        exit(0);
    }
    else{
        if((file_pointer=fopen(file_name,"r"))==NULL){
            printf("File does not exist or can not be found !");
        }
        else{
            printf("Enter the word you want to search for:", wanted_word);
            scanf("%s",wanted_word);
            int i=0;
            while (!feof(file_pointer)){
                currentCharacter=fgetc(file_pointer);
                text[i]=currentCharacter;
                i++;
                
            }
            
            }
        fclose(file_pointer);        
        }
        
    
    string_matching(wanted_word, text);
    return 0;
    
}
