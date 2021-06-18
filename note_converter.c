#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int main(void){
	FILE *fp,*out;
	char temp[128],check[]=",",end[]="e";
	int sp=0,flag=0,amout,strat,spp,t;
	t=time(NULL);
	srand(t);
	redo1:
	printf("入力先のファイル名を入力\n");
	gets(temp);
	if((fp=fopen(temp,"r"))==NULL){
		printf("展開失敗\n");
		goto redo1;
	}
	redo2:
	printf("出力先のファイル名を入力\n");
	gets(temp);
	if((out=fopen(temp,"w"))==NULL){
		printf("展開失敗\n");
		goto redo2;
	}
	fprintf(out,"0,0,0,0,0,0,\n");
	for(;;sp++){
		fseek(fp,sp*1L,SEEK_SET);
		fscanf(fp,"%1s",temp);
		if((strcmp(temp,check))==0){
			if(flag==0){
				flag++;
				spp=sp+1;
			}
			else if(flag==1){
				flag=0;
				amout=sp-spp;
				sp+=2;
				fseek(fp,spp*1L,SEEK_SET);
				switch(amout){
					case 1:
					fscanf(fp,"%1s",temp);
					break;
					case 2:
					fscanf(fp,"%2s",temp);
					break;
					case 3:
					fscanf(fp,"%3s",temp);
					break;
					case 4:
					fscanf(fp,"%4s",temp);
					break;
					case 5:
					fscanf(fp,"%5s",temp);
					break;
					case 6:
					fscanf(fp,"%6s",temp);
					break;
					case 7:
					fscanf(fp,"%7s",temp);
					break;
					case 8:
					fscanf(fp,"%8s",temp);
					break;
					case 9:
					fscanf(fp,"%9s",temp);
					break;
					case 10:
					fscanf(fp,"%10s",temp);
					break;
				}
				printf("%s\n",temp);
				fprintf(out,"1,%d,%s,1,0,0,\n",rand()%7,temp);
			}
		}
		else if(strcmp(temp,end)==0){
			goto end;
		}
	}
	end:
	fprintf(out,"-1,0,0,0,0,0,");
	fclose(fp);
	fclose(out);
	return 0;
}		