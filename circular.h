//header for circular linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


//structure for node
typedef struct node{
    int value;
    struct node *next;
}NODE;

//start pointer
NODE *start = NULL;

//functions
//function to append data
void append(int data){
    NODE *curr,*temp;

    //memory allocation
    temp = (NODE *)malloc(sizeof(NODE));

    //if fails
    if(temp == NULL){
        printf("[*]Memory allocation failed");
        getch();
    }
    else{
        temp->value = data;

        //for first time
        if(start == NULL){
            start = temp;
            temp->next = start;
        }
        else{
            curr = start;
            while(curr->next != start)
                curr = curr->next;
            curr->next = temp;
            temp->next = start;
        }
    }
}

//function to display
void display(){
    NODE *curr = start;

    //if empty
    if(start == NULL){
        printf("[*]The List is empty");
        getch();
    }
    else{
        do{
            printf("%d\t",curr->value);
            curr=curr->next;
        }while(curr != start);
    }
}

//function to add at the begining
void add_first(int data){
    NODE *curr,*temp;
    
    //memory allocation
    temp = (NODE *)malloc(sizeof(NODE));

    //if fail
    if(temp == NULL){
        printf("[*]Memory allocation failed");
        getch();
    }

    else{
        temp->value = data;

        //if for first time
        if(start == NULL){
            start = temp;
            temp->next = start;
        }

        else{
            temp->next = start;
            
            //update the last node's memory
            curr = start;
            
            while(curr->next != start)
                curr = curr->next;
            
            curr->next = temp;
            start = temp;

        }


    }
}

//function to return length
int len(){
    NODE *curr = start;
    int count =0;
   
   
   do
   {
       count ++;
       curr = curr->next;
   } while (curr != start);
   

    return count;
}

//function to add at a position
void add_after_node(int pos,int data){
    NODE *curr=start,*temp;

    
    if(pos > len()){
        printf("[*]Position can not be found");
        getch();
    }

    else{
        if(pos == 1)
            add_first(data);
        else if(pos == len())
            append(data);
        else{

            //go upto the pos
            while(pos > 1){
                curr = curr->next;
                pos --;
            }

            //memory allocation
            temp = (NODE *)malloc(sizeof(NODE));

            //if fail
            if(temp == NULL){
                printf("[*]Memory allocation failed");
                getch();
            }

            else{
                temp->value = data;
                temp->next = curr->next;

                curr->next = temp;
            }
        }
    }
}

//function to add after value
void add_after_value(int num,int data){
    NODE *last=start,*curr = start,*temp;

    //if last node's value part matches

    while(last->next != start)
        last = last->next;

    if(last->value == num)
        append(data);
    else{

        //go upto the number
        while((curr->value != num) && (curr->next != last))
            curr = curr->next;
        
        if(curr->next == last){
            printf("[*]Value not present");
            getch();

        }
        else{
            //memory allocation
            temp = (NODE *)malloc(sizeof(NODE));

            //if failed
            if (temp == NULL){
                printf("[*]Memory allocation failed");
                getch();
            }

            else{
                temp->value = data;
                temp->next = curr->next;
                curr->next = temp;
        
            }
            
        }

        
    }

}

//function to search data
void search(int data){
    NODE *curr =start;
    int count =0,flag =0;
    do{
        count ++;
        if(curr->value ==data){
            printf("%d found at--------------------------->%d node",data,count);
            flag=1;
        }
        curr = curr->next;

    }while(curr!=start);

    if(flag == 0)
        printf("[*]Value not present in the linked list");
    
}

//function to delete first node
void del_first(){
    NODE *curr;
    if(start!=NULL){
    //if single value 
        if(start->next == start){
            start = NULL;
            free(start);


        }

        else{
            //update the last node's address
            curr = start;
            while(curr->next != start)
                curr=curr->next;
            
            curr->next = start->next;
            free(start);
            start = curr->next;
        }
    }
    else{
        getch();
    }
    

}

//function to delete last node
void del_last(){
    NODE *curr = start,*temp;

    if(start == NULL)
        getch();
    
    else{
        //if one value is present
        if(start->next == start){
            start=NULL;
            free(start);
        }
        else{
            //go upto the second node
            while(curr->next->next != start)
                curr=curr->next;
            
            temp=curr->next;
            curr->next = start;
            free(temp);
        }
    }

}

//del a node at a position
void del_pos(int pos){
    NODE *curr=start,*temp;
    if(pos > len()){
        printf("[*]Position not found");
        getch();
    }
    else{
        if(pos == 1)
            del_first();
        else if(pos == len())
            del_last();
        else{
            //go upto the (pos-1) th position
            while((pos-1) > 1){
                curr = curr->next;
                pos --;
            }
            
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
    }

}


//del a value
void del_value(int data){
    NODE *last=start,*curr=start,*temp;

    if(start->value == data)
        del_first();
    else{
        while(last->next != start)
            last=last->next;
        
        //if last value
        if(last->value == data)
            del_last();
        
        else{

            //go upto the (n-1)th node
            while((curr->next != last) && (curr->next->value != data))
                curr = curr->next;
            
            //if not present
            if(curr->next == last){
                printf("[*]Value not found");
                getch();
            }

            else{
                temp = curr->next;
                curr->next = temp->next;
                free(temp);
            }
        }
    }
}