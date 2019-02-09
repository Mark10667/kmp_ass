#include "string_matching.h"

// int string_matching_naive(char *text, int N, char* pattern, int M){
// 	int score = 0;
// 	int matches = 0;
// 	int i = 0;
// 	int j = 0;
// 	//puts("in string_matching_naive");
// 	while(i < N-M+1){
// 			while(j < M){
// 				//puts("get here 1");
// 				if(text[i+j] == pattern[j]){
// 					score ++;
// 				}else{
// 					//if(score == 0){
// 						//i++;
// 					//}
// 					break;
// 				}
// 				j++;
// 		 	}
// 			//puts("get here 2");
// 			if(score == M){
// 				matches ++;
// 			}
// 		i++;
// 		j = 0;
// 		score = 0;
// 	}
// 	//printf("the matches is %d\n", matches);
// 	return matches;
// }


int string_matching_naive(char *text, int N, char* pattern, int M){
	int count = 0;
	int i = 0;
	int j = 0;
	//puts("in string_matching_naive");

	while(i < N-M+1){
			//printf("i is %d, j is %d", i, j);
			while(j < M){
				//puts("get here 1");
				if(text[i] == pattern[j]){
					i++;
					j++;
				}
				else{
					break;
				}
			}
			//puts("get here 2");
			if(j == M){
				count ++;
			}
		i = i - j + 1;
		j = 0;
	}
	//printf("the matches is %d\n", matches);
	return count;
}
