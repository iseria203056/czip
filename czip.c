#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
        if(argc<2){
                printf("czip: file1 [file2 ...]\n");
                exit(1);
        }
        char letter=0;
        int count=0;
        for(int i=1;i<argc;i++){
                FILE *fp = fopen(argv[i], "rb");
                char current_char=0;
                int readsize=0;
                do{
                        readsize=fread(&current_char,sizeof(char),1,fp);
                        if(readsize==0){
                                break;
                        }

                        if(letter==current_char){
                                count+=1;
                        }else{
                                if(count>0){
                                fwrite(&count,1,sizeof(int),stdout);
                                fwrite(&letter,1,sizeof(char),stdout);
                                }
                                count=1;
                                letter=current_char;
                        }
                }while(1);
                if(i==(argc-1)){
                        fwrite(&count,1,sizeof(int),stdout);
                        fwrite(&letter,1,sizeof(char),stdout);
                }
        }
        return 0;
}
