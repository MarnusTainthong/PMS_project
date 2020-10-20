/* Program name: project.c
 * Student: 58160137 Marnus Tainthong
 * Section: 02
*/
/// PARKING SYSTEM ///
#include<stdio.h>
#include<stdlib.h>
void clear_scr();
int state_noti(int row,int col,int sum,int total);
void case1(int row,int col,int platePark[row][col],int statePark[row][col]);
int case2(int row,int col,char*input_name[0],int input_park,int platePark[row][col],int statePark[row][col],int stateP,FILE*myfile,int *pt_sumstate);
int case3(int row,int col,char*input_name[0],int input_park,int platePark[row][col],int statePark[row][col],int stateP,FILE*myfile,int *pt_sumstate);
void case4();
int main(){
  FILE*myfile;
  myfile=fopen("user_log.txt","a"); //open stream
  fprintf(myfile,"*************************\n");// FILE
  fprintf(myfile,"Name\tParking\tPeocess\n"); 
  fprintf(myfile,"*************************\n");
  fclose(myfile);
  
  int*pt_sumstate;
  int sumstate=0;
  pt_sumstate=&sumstate;
  char input_name[10];
  int i,j;
  int numLevel,numZone;
  int total=0;

  printf("Please define level : ");
  scanf("%d",&numLevel);
  //level
  printf("Please define zone : ");
  scanf("%d",&numZone);
  //zone
  
  total=numLevel*numZone;

  int platePark[numLevel][numZone];
  int statePark[numLevel][numZone];
  
  

  for(i=0;i<numLevel;i++){
    for(j=0;j<numZone;j++){
        printf("Please enter parking name |Level:%d Zone:%d| : ",i+1,j+1);
        scanf("%d",&platePark[i][j]);
        statePark[i][j]=0; //set state to free
        // state 0=free ,1=non-free
		sumstate+=statePark[i][j];
    }//for_zone
  }//for_level
  clear_scr();
  int choose;
  int input_park;
  int stateP; //0=success , 1=fail , 2=don't have parking name

  do{
	    
        printf("\n*************** MENU ***************\n");
        state_noti(numLevel,numZone,*pt_sumstate,total);
        printf("************************************\n");
        printf("* 1| Show parking status           *\n");
        printf("* 2| Parking                       *\n");
        printf("* 3| Cancle parking                *\n");
        printf("* 4| Exit                          *\n");
        printf("************************************\n");

        printf("Input your choice : ");
        scanf("%d",&choose);

        switch(choose){
            case 1:{
                    case1(numLevel,numZone,platePark,statePark);
			}//case1
                break;//break1
            case 2:{
				    char*input_name[0];
				    case2(numLevel,numZone,&input_name[0],input_park,platePark,statePark,stateP,myfile,pt_sumstate);
				}//case2
				
                break;//break2
            case 3:{
				    char*input_name[0];
				    case3(numLevel,numZone,&input_name[0],input_park,platePark,statePark,stateP,myfile,pt_sumstate);
			    }//case3
				
                break;//break3
            case 4:{
                    case4();
				}//case4
                break;//break4
        }//switch

  }//do
  while(choose!=4);

  return 0;
}//main
void clear_scr()
{
	int ch;
	char val;
	printf("Press any key to continue..\n");
	scanf("%d",&val);
	ch=scanf("%c",&val);
	if(ch==1){
	system("clear"); // for UNIX    
	} 
}// fn_clear_scr
int state_noti(int row,int col,int sum,int total)
{

		if(sum==total){
			printf("* Parking State :   %d/%d (FULL)     *\n",sum,total);
		}//if
        else{
			printf("* Parking State :   %d/%d (FREE)     *\n",sum,total);
		}//else
}// fn_state_noti
void case1(int row,int col,int platePark[row][col],int statePark[row][col])
{
	int i,j;
    for(i=0;i<row;i++){
		for(j=0;j<col;j++){
            //show parking name
            printf("Parking name : %d",platePark[i][j]);
            //show parking state
            //check status parking
			printf("\t");
            if(statePark[i][j]==1){
                printf("Parking state : Non free");              
            }//if statePark=1 (non-free)               
            else{               
                printf("Parking state : Free");              
            }//else (free)               
				printf("\n");		   
            }//for_zone            
            }//for_level        	
    clear_scr();  	               
}//fn_case1
int case2(int row,int col,char*input_name[0],int input_park,int platePark[row][col],int statePark[row][col],int stateP,FILE*myfile,int *pt_sumstate)
{
	int i,j;
	stateP=2; // 0=success 1=fail 2=no data
					
	printf("Please enter your name  : ");
	scanf("%s",&input_name[0]);
					
    printf("Please enter parking name you want to park : ");
    scanf("%d",&input_park);

	myfile=fopen("user_log.txt","a"); //open stream
/*	if(myfile != 0){
	printf("Open file complete.\n");
	}// complete
    if(myfile == NULL){
	printf("File can't open.\n");
	}// can't open 
*/
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(input_park==platePark[i][j]){
				if(statePark[i][j]==0){
                    statePark[i][j]=1; //set to not free
					stateP=0;
					*pt_sumstate+=statePark[i][j];
					fprintf(myfile,"%s\t%d\tPark\n",&input_name[0],input_park); // FILE
					fclose(myfile);
				}//SUCCESS
				else if(statePark[i][j]==1){
					stateP=1;
				}//FAIL							  
            }//if
        }//for_zone
    }//for_level
    if(stateP==0){
		printf("You are park SUCCESS.");
	}// SUCCESS
	else if(stateP==1){
		printf("SORRY! You can't park this parking.");
	}// FAIL
	else if(stateP==2){
		printf("SORRY! Don't have %d on any parking.",input_park);
	}//NO DATA
	printf("\n");
    clear_scr();
    return 0;
}// fn_case2
int case3(int row,int col,char*input_name[0],int input_park,int platePark[row][col],int statePark[row][col],int stateP,FILE*myfile,int *pt_sumstate)
{
	int i,j;
	*pt_sumstate=0;
	stateP=2; // 0=success 1=fail 2=no data
					
	printf("Please enter your name  : ");
	scanf("%s",&input_name[0]);
					
    printf("Please enter parking name you want to park : ");
    scanf("%d",&input_park);

	myfile=fopen("user_log.txt","a");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(input_park==platePark[i][j]){
				if(statePark[i][j]==1){
                    statePark[i][j]=0; //set to free
					stateP=0;
					fprintf(myfile,"%s\t%d\tCancle\n",&input_name[0],input_park); // FILE
					fclose(myfile);
				}//SUCCESS
				else if(statePark[i][j]==0){
					stateP=1;
				}//FAIL
			}//if
		    *pt_sumstate+=statePark[i][j];
        }//for_zone
    }//for_level
	if(stateP==0){
		printf("You are CANCLE park SUCCESS.");
	}// SUCCESS
	else if(stateP==1){
		printf("SORRY! You can't CANCLE park this parking.");
	}// FAIL
	else if(stateP==2){
		printf("SORRY! Don't have %d on any parking.",input_park);
	}//NO DATA
	printf("\n");
    clear_scr();
	return 0;
}// fn_case3
void case4()
{
	printf("Thank you for serving..");
    printf("\n");
    clear_scr();
}//fn_case4