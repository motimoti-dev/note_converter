#include<stdio.h>
#include<string.h>
#include<conio.h>
int main(void){
	int f=0,sp,flag,key;
	char check1[]=",",check2[]=".",end[]="e",temp[9999];
	FILE *fp;
	redo:
	printf("�`�F�b�N����t�@�C���������\n");
	gets(temp);
	if((fp=fopen(temp,"r"))==NULL){
		printf("�W�J���s\n");
		goto redo;
	}
	recheck:
	flag=0;
	for(sp=0;;sp++){
		if(f==0){
			fseek(fp,sp*1L,SEEK_SET);
			fscanf(fp,"%1s",temp);
			printf("%s",temp);
			if((strcmp(temp,check1)!=0)&&(strcmp(temp,check2)!=0)&&(strcmp(temp,end)!=0)&&(strcmp(temp,"0")!=0)&&(strcmp(temp,"1")!=0)&&(strcmp(temp,"2")!=0)&&(strcmp(temp,"3")!=0)&&(strcmp(temp,"4")!=0)&&(strcmp(temp,"5")!=0)&&(strcmp(temp,"6")!=0)&&(strcmp(temp,"7")!=0)&&(strcmp(temp,"8")!=0)&&(strcmp(temp,"9")!=0)){
				printf("\nERROR!\n�C��������A�Z�[�u��ENTER���N���b�N\n");
				f=1;
			}
			else if((strcmp(temp,check1))==0){
				if(flag==0){
					flag++;
				}
				else if(flag==1){
					flag++;
					printf("\nERROR!\n�C��������A�Z�[�u��ENTER���N���b�N\n");
					f=1;
				}
				else if(flag==2){
					flag=0;
					sp+=2;
					printf("\n");
				}
			}
			else if((strcmp(temp,check2))==0){
				if(flag==0){
					flag++;
					printf("\nERROR!\n�C��������A�Z�[�u��ENTER���N���b�N\n");
					f=1;
				}
				else if(flag==1){
					flag++;
				}
				else if(flag==2){
					printf("\nERROR!\n�C��������A�Z�[�u��ENTER���N���b�N\n");
					f=1;
					flag=0;
					printf("\n");
				}
			}
			else if(strcmp(temp,end)==0){
				goto end;
			}
		}
		else{
			if(kbhit()){
				key=getch();
				if(key==13){
					f=0;
					goto recheck;
				}
			}
		}
	}
	end:
	printf("\n�~�X�͔�������܂���ł���\n");
	return 0;
}
