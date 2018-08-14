#include<stdio.h>

#include<stdlib.h>
typedef struct node {
    char data;
    struct node*next;
} node;


char puzzle[100][100];
char word[100][100];

int main() {
//Getting puzzle using linked list
char c;
int count1=0;
node* head = NULL;
node* p = NULL;
node* temp = NULL;
    while(1){ 
       c=getchar();
       temp=malloc(sizeof(node));
       temp -> data =c;
       temp -> next =NULL;
       if (head==NULL) {
           head=temp;
       }else{
          p=head;
          while(p -> next != NULL){
             p = p->next;
             }
             p->next = temp;
      }
      count1++;
      if(c == '\n'){
      	if(count1 == 1){
              break;
        }
        count1 = 0;
      }
  }
//puzzle transfer to an array
for(int i=0; i< 100; i++){
        for(int j=0; j< 100; j++){
             puzzle[i][j] = '1';
        }
      }
      int flag = 1;
      for(int i=0; i< 100; i++){
         for(int j=0; j< 100; j++){
                if(head -> next != NULL){
                        puzzle[i][j] = head-> data;
                        head = head-> next;
                        if(head -> data == '\n'){
                                head = head -> next;
                                break;
                        }
                }else{
                        flag = 0;
                        break;
                }
          }
          if(flag = 0){
                break;
          }
       }
//Getting words using linked list
char c1;
int wcount1=0;
node* whead = NULL;
node* wp = NULL;
node* wtemp = NULL;
    while(1){ 
       c1=getchar();
       wtemp=malloc(sizeof(node));
       wtemp -> data =c1;
       wtemp -> next =NULL;
       if (whead==NULL) {
           whead=wtemp;
       }else{
          wp=whead;
          while(wp -> next != NULL){
             wp = wp->next;
             }
             wp->next = wtemp;
      }
      wcount1++;
      if(c1 == '\n'){
          if(wcount1 == 1){
              break;
          }
          wcount1=0;
      }
   }



       for(int i=0; i< 100; i++){
        for(int j=0; j< 100; j++){
             word[i][j] = '1';
        }
      }
      
      
//Words transfer to an array    
      int flag2 = 1;
      for(int i=0; i< 100; i++){
         for(int j=0; j< 100; j++){
                if(whead -> next != NULL){
                        word[i][j] = whead-> data;
                        whead = whead-> next;
                        if(whead -> data == '\n'){
                               whead = whead -> next;
                                break;
                        }
               }else{
                    flag2 = 0;
                    break;
               }
          }
          if(flag2 = 0){
                break;
          }
     }
//simple letters convert to capital letters
    for(int i=0; i< 100; i++){
         for(int j=0; j< 100; j++){
             if(word[i][j] >=97 && word[i][j] <=122){
                     word[i][j] =word[i][j] -32; 
                     
                   }
          }
     }

int count=0,x=0,y=0,z=0;       
   for(int i=0; i< 100; i++){
        for(int c=0; c< 100; c++){
            if(puzzle[i][c] != '*' && puzzle[i][c] != '1'){
             count++;
             
            }
             
         }
         if(count > 1){
         x=count;
         }
         count=0;
        
   }
   
   int vcount=0,x1=0,y1=0,z1=0;       
    for(int i=0; i< 100; i++){
        for(int r=0; r< 100; r++){

         if(puzzle[r][i] != '*' && puzzle[r][i] != '1'){
             vcount++;
             
            }
             
         }
         if(vcount > 1){
         x1=vcount;
         }
         vcount=0;
        
   }
  int x3=0,m2=0;
   for(int k=0; k< 100; k++){
        for(int l=0; l< 100; l++){
           if(word[k][l] == '1' ){
                       break;
            }
            m2++;
            
        }
        if(m2 > 1){
         z=m2;
         }
        
        
        
        m2 =0;
   }
   
   if(x!=z && x1!=z){
      printf("IMPOSSIBLE\n");
   }else{

//filling horizontally
int r = 0, m=0,letterCount=0, f=1, c2 = 0;       
   for(int i=0; i< 100; i++){
        for(int c=0; c< 100; c++){

         if(puzzle[i][c] != '*' && puzzle[i][c] != '1'){
             if(letterCount == 0){
                c2 = c;
             }
             letterCount++;
         }
        }
        
        if(letterCount > 0){
                for(int k=0; k< 100; k++){
                        m=0;
                        for(int l=0; l< 100; l++){
                               if(word[k][l] == '1' || word[k][l] == '3'){
                                 
                                        break;
                                }
                                m++;
                        }
                        if(m==letterCount && letterCount >0){
                                f=0;
                                r = k; 
                                break;      
                        }    
                   }
                 m =0;
                 if(f==0){
                 
                 for(int k = c2; k<(c2+letterCount); k++){                
                    puzzle[i][k] = word[r][m];
                    word[r][m] = '3';
                    m++;
                 }
                     f = 1;
                }
                 letterCount = 0;
        }
   } 
                
    // filling vertically
int r1 = 0, m1=0,letterCount1=0, f1=1, r2 = 0;       
   for(int i=0; i< 100; i++){
        for(int r=0; r< 100; r++){

         if(puzzle[r][i] != '*' && puzzle[r][i] != '1'){
             if(letterCount1 == 0){
                r2 = r;
             }
             letterCount1++;
         }
        }
       
        if(letterCount1 > 0){
                for(int k=0; k< 100; k++){
                        m1=0;
                        for(int l=0; l< 100; l++){
                               if(word[k][l] == '1' || word[k][l] == '3'){
                                 
                                        break;
                                }
                                m1++;
                        }
                        if(m1==letterCount1 && letterCount1 >0){
                                f1=0;
                                r1 = k; 
                                break;      
                        }    
                   }
                 m1 =0;
                 if(f1==0){
                 
                 for(int k = r2; k<(r2+letterCount1); k++){                
                    puzzle[k][i] = word[r1][m1];
                    word[r1][m1] = '3';
                    m1++;
                 }
                     f1 = 1;
                }
                 letterCount1 = 0;
        }
   } 
     //printing puzzzle           
     int f2=0;
     for(int i=0; i< 100; i++){
         for(int j=0; j< 100; j++){
         if(j==0 && puzzle[i][j] == '1'){
         f2 =1;
         break;
         }
         if(puzzle[i][j] != '1' && puzzle[i][j] != '\n'){
             printf("%c",puzzle[i][j]);
             }else{
             break;
             }
         }
         if(f2 != 1){
          printf("\n");
          }else{
          break;
          }
   } 
 }
}




