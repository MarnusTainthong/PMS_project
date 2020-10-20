#include"project.h"
/// FUNCTION
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