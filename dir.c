/* Klaus Dieter Kupper
 * Exibe arquivos e diretórios de um local apontado pelo usuário através de parâmetro de entrada.
 * Exemplo de chamada no terminal ./dir /home/klausdk/Documentos/UFSC teste.c
 * ./dir <local de busca> <nome do arquivo>
 */

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void find(char *name,char *path){
   // printf("find(%s , %s) \n",path,name);
    DIR *folder;
    struct dirent *entry;
    int files = 0;
        
    folder = opendir(path);

    if(folder == NULL)
    {
        perror("Não foi possível abrir o diretório;\n");
        return;
    }

    while( (entry=readdir(folder)) )
    {
        files++;

        if(entry->d_type==DT_DIR){
                if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0){
                        continue;
                }
                
                    char *barra ="/";
                    char buffer[300];
                    //char *buffer = ( char* )malloc(sizeof( path )+sizeof( path ) );
                    strcat(strcpy(buffer, path), barra);
                    strcat(strcpy(buffer, buffer), entry->d_name);
                  
                    find(name,buffer);
         
        }else{
            if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0){
                continue;
            }
            if(strcmp(name,entry->d_name) == 0){
             
                printf("Cópia do arquivo %s em:\n",name);
                printf("%s\n", path);
                printf("\n");
            }
        }
    }

    closedir(folder);

    return;
}

int main(int argc, char** argv){   
    if(argc<3){
        printf("Chamada incorreta \n Uso da função: ./dir <local de busca> <arquivo para encontrar> \n");
        exit(0);
    }  
    
    printf("Buscando por %s em %s \n\n",argv[2],argv[1]);
    
    find(argv[2],argv[1]);
    printf("Busca finalizada \n");
}
