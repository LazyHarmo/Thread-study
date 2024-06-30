void * simple1(void *);
void * simple2(void *);

#define NUM_THREADS 2
pthread_t tid[NUM_THREADS]; /*array thread id */
sem_t semB;

int main(int argc, char *argv[]){
  int i, ret;
  sem_init(&semB, 0, 1);

  pthread_create(&tid[0], NULL, simple1, NULL);
  pthread_create(&tid[1], NULL, simple2, NULL);

  for (i = 0; i < NUM_THREADS; i++)
    pthread_join(tid[i], NULL);

  printf("\nmain() reporting that all %d threads have terminated\n", i);
} /*main*/

void * simple1(void * parm){
  printf("Thread 1 here, before the barrier.\n");
  sleep(1);
  sem_wait(&semB);
  printf("Thread 1 here, inside the barrier.\n");
  sem_post(&semB);
  printf("Thread 1 after the barrier.\n");
}

void * simple2(void * parm){
  printf("Thread 2 here, before the barrier.\n");
  sem_wait(&semB);
  printf("Thread 2 here, inside the barrier.\n");
  sem_post(&semB);
  printf("Thread 2 after the barrier.\n");
}
