#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "string_matching.h"

int performance_test(){
  static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  srand(time(NULL));   // Initialization, should only be called once.

  int N = 0;
  int M = 400;
  int j = 0;
  int i;
  int average_time = 100;
  clock_t start_n, end_n, start_k, end_k;
  double cpu_time_used_totaln= 0;
  double cpu_time_used_totalk= 0;
  double cpu_time_used_n = 0;
  double cpu_time_used_k = 0;
  double k_n_ratio;
  char* text;
  char* pattern;
  // char *text = malloc(n);
  // char *pattern = malloc(m);

  for(N = 10000; N <= 1000000; N = N + 50000){
    while (j < average_time) {
      // int n = rand() % (N-3) + 3;      // Returns a pseudo-random integer between 3 and N.
      // int m = rand() % M + 1;

      text = malloc(N+1);
      for (i=0; i<N; i++){
      int pos = rand() % (int)(sizeof(charset) -1);
        text[i] = charset[pos];
      }
      text[i] = '\0';

      pattern = malloc(M+1);
      for (i=0; i<M; i++){
      int pos = rand() % (int)(sizeof(charset) -1);
        pattern[i] = charset[pos];
      }
      pattern[i] = '\0';

      //printf("text='%s', pattern='%s'\n", text, pattern);
      start_n = clock();
      string_matching_naive(text, N, pattern, M);
      end_n = clock();
      cpu_time_used_totaln = cpu_time_used_totaln + (double)(end_n - start_n)/CLOCKS_PER_SEC ;

      start_k = clock();
      string_matching_kmp(text, N, pattern, M);
      end_k = clock();
      cpu_time_used_totalk = cpu_time_used_totalk + (double)(end_k - start_k)/CLOCKS_PER_SEC ;


      j++;
    }

    cpu_time_used_n = (double) cpu_time_used_totaln / average_time;
    cpu_time_used_k = (double) cpu_time_used_totalk / average_time;
    k_n_ratio = (double)cpu_time_used_k / cpu_time_used_n;
    printf("N = %d, naive takes %f,  kmp takes %f, k / n is %f\n", N, cpu_time_used_n, cpu_time_used_k, k_n_ratio);
    cpu_time_used_totaln= 0;
    cpu_time_used_totalk= 0;
    j = 0;

  }
  free(text);
  free(pattern);
  return 0 ;
}
