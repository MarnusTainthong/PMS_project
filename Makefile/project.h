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