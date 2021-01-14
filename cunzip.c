#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
        if(argc<2){
                printf("cunzip: file1 [file2 ...]\n");
                exit(1);
        }
        for(int i=1;i<argc;i++){
                FILE *fp =fopen(argv[i], "rb");
                do{

                        int num=0;
                        int readsize=0;
                        readsize=fread(&num,sizeof(int),1,fp);
                        if(readsize==0){
                                break;
                        }
                        char target;
                        fread(&target,sizeof(char),1,fp);
                        for(int i=0;i<num;i++){
                                fwrite(&target,1,sizeof(char),stdout);
                        }
                }while(1);
        }

        return 0;
}
