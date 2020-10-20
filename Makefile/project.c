#include"project.h"
int main(){
  FILE*myfile;
  myfile=fopen("user_log.txt","a"); //open stream
  fprintf(myfile,"*************************\n");// FILE
  fprintf(myfile,"Name\tParking\tProcess\n"); 
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