#include<stdio.h>

#include<semaphore.h>

#include<pthread.h>

#include<unistd.h>



 



 

 

void * philospher(void *num);

void taking(int);

void leaving(int);

void temp(int);

 

 

int state[5];

int phil_num[5]={0,1,2,3,4};

 

 

int main(){

    int i;

    pthread_t pilo[5];

   

 

 

   
    for(i=0;i<5;i++){

        pthread_create(&pilo[i],NULL,philospher,&phil_num[i]);

        printf("Philosopher %d is thinking\n",i+1);
         pthread_join(pilo[i],NULL);

    }

   

       

}

 

 

void *philospher(void *num){

    while(1){

        int *i = num;

        sleep(1);

            taking(*i);

            leaving(*i);

    }

}

 

 

void taking(int ph_num){

   

    state[ph_num] = 1;

        printf("Philosopher %d is Hungry\n",ph_num+1);

    temp(ph_num);


    sleep(1);

}

 

 

void temp(int ph_num){

    if (state[ph_num] == 1 && state[(ph_num+4)%5] != 2 && state[(ph_num+1)%5] != 2){

        state[ph_num] = 2;

        sleep(2);

            printf("Philosopher %d takes fork %d and %d\n",ph_num+1,(ph_num+4)%5+1,ph_num+1);

            printf("Philosopher %d is Eating\n",ph_num+1);

        

    }

}

 

 

void leaving(int ph_num){

    

    state[ph_num] = 0;

        printf("Philosopher %d leave fork %d and %d down\n",ph_num+1,(ph_num+4)%5+1,ph_num+1);

        printf("Philosopher %d is thinking\n",ph_num+1);

    temp((ph_num+4)%5);

    temp((ph_num+1)%5);

  

}