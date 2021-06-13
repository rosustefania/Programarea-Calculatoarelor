#include <stdio.h>
#include <string.h>
#include "util/task_helper.h"
#include <stdlib.h>


void uppercase( char *line[] ,int nr, char p[])
{ 	int i,j;
	for(j=0;j<nr;j++){
		 
		 if(line[j][0]>='a' && line[j][0]<='z') {
	  		
			  line[j][0]=line[j][0]-32;
		 }
		 for(i=1;i<strlen(line[j]);i++){

			 if(line[j][i]>='A' && line[j][i]<='Z') {
	  		
			  line[j][i]=line[j][i]+32;
		 }
		 }
	
	}
	strcpy(p,line[0]);
	strcat(p,"\n");
	
    for(int j=1;j<nr;j++){
		
		if(j%4==0){
		  strcat(p,"\n");
		}
    
	strcat(p,line[j]);
	strcat(p,"\n");
    }
	strcat(p,"\0");
}

void trimming(char p[],int count)
{	int i, j,c,t;

    for(c=32;c<=63;c++){
        
		if(c==33 || c==44 || c==46 || c==58 || c==59 || c==63){
		    
			for (i=j=0; p[i] != '\0'; i++) {     
			 	 
					if (p[i] != c){
                       
					    p[j++] = p[i];   
					}
			} 
		
			p[j] = '\0';  
	     } 

		if(c==32){
			j=0;
	 		while(j<count){
    			
                if(p[j]==' ' && (p[j+1]==' ' || p[j-1]==' ')){
					for(t=j;t<count;t++){

               				p[t]=p[t+1];
						}
					 count--;
                 }

	            else j++;
			}
			p[count+1]='\0';
		
		}
	}
	strcat(p,"\n");
}


void silly(char p[],char *line[],int nrl,char *k)
{	int i,j;
    float prob=atof(k);
	
	for(j=0;j<nrl;j++){
		
		for(i=0;i<strlen(line[j]);i++){
			
			if(line[j][i]>='A' && line[j][i]<='Z') {

				float sample = rand() % 100 / 99.0;
				if(sample<prob){
					
					line[j][i]=line[j][i]+32;
				}
		    }
			else if(line[j][i]>='a' && line[j][i]<='z') {

				float sample = rand() % 100 / 99.0;
				if(sample<prob){
					
					line[j][i]=line[j][i]-32;
			    }
		    }
			

		}
	
	}
	strcpy(p,line[0]);
	strcat(p,"\n");
	
    for(int j=1;j<nrl;j++){
	 
	 	if(j%4==0){
		  	
			  strcat(p,"\n");
		}
   
   		strcat(p,line[j]);
		strcat(p,"\n");
	}

	strcat(p,"\0");
}



void print(char p[])
{
	printf("%s",p);
}

int main()
{   srand(42);
	FILE *fp;
	const char *file;
    file=malloc(sizeof(char)*50);
	int j=0;
	char i,p[100000],copie1[1000000],copie2[1000000],p2[1000000];
	char *line[1000];//vector care va retine versurile poeziei;
	char *word[1000];//vector care va retine cuvintele din poezie;
    int nrw=0,nrl=0;//numar de versuri,respectiv numar de cuvinte;
	char *k,*t;
	char comanda[100];
	int flag=0;
	
	strcpy(copie1,"ana");
	while(flag==0){
    
		fgets(comanda,100,stdin);//citesc comanda dorita;
		k=strtok(comanda," \n");
		strcpy(copie1,k);
    	if(strcmp(copie1,"load")==0){

			k=strtok(NULL," \n");
			strcpy(copie1,k);

			load_file(copie1,p);
			strcpy(copie1,p);
			strcpy(copie2,p);


   			t=strtok(copie2,"\n");
    		while(t!=NULL){

        		line[nrl] = malloc(strlen(t) + 1);
        		strcpy(line[nrl],t);
        		t=strtok(NULL,"\n");
        		nrl++;
      		}
		}

		if(strcmp(copie1,"uppercase")==0){

			uppercase(line,nrl,p);
		}

		if(strcmp(copie1,"trimming")==0){
			
			trimming(p,strlen(p));

		}

		if(strcmp(copie1,"make_it_silly")==0){
 
			k=strtok(NULL," \n");
			silly(p,line,nrl,k);
		}

		/*if(strcmp(comanda,"make_it_friendlier")==0){
			
			friendly(p,p2);
			strcpy(p,p2);
		}
		
		if(strcmp(comanda,"make_it_rhyme rhyme-type")==0)
			rhimy();
		*/
		if(strcmp(copie1,"print")==0){

			print(p);
			printf("\n");
		}

		if(strcmp(copie1,"quit")==0){

			flag=1;
		}


	}
	free(file);
	return 0;
}
     