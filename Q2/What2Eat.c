#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THRESHOLD 8

int main(){
	int countOfPeople;
	char foodArr[5][15]={"Kebab","Burger","Pasta","Lahmacun","Salad"};
	int pointArr[5];
	int temp;

	printf("ROUND 1 STARTED\n\n");
	printf("Enter how many people you are: ");
	scanf("%d", &countOfPeople);
	printf("Make 5 choices in order of\n1-Kebab\n2-Burger\n3-Pasta\n4-Lahmacun\n5-Salad\n");
	printf("So, please start type your decisions one-by-one\n");

	for(int i = 0; i < countOfPeople; i++){
		printf("%dth person started selection\n",(i+1));
		for(int j = 0; j < 5; j++){
			printf("Enter the id of meal and #%d preference is: ",j+1);
			scanf("%d", &temp);
			switch (j){
				case 0: pointArr[temp-1] += 5; break;
				case 1: pointArr[temp-1] += 4; break;
				case 2: pointArr[temp-1] += 3; break;
				case 3: pointArr[temp-1] += 2; break;
				case 4: pointArr[temp-1] += 1; break;
			}
		}
		printf("%dth person finished selection\n\n",(i+1));
	}

	char shortList[5][15];
    int shortCount = 0;

	printf("Threshold is %d and meals' total points :\n", THRESHOLD);
    for(int i = 0; i < 5; i++){
		printf("%s:%d ",foodArr[i],pointArr[i]);
        if(pointArr[i]>THRESHOLD){
			strcpy(shortList[shortCount], foodArr[i]);
            shortCount++;
        }
    }
    printf("\n");

    if(shortCount==0){
        printf("You are eating at home/dorm today!\n");
        exit(0);
    }

	int secondPointArr[shortCount];
	
	printf("\nROUND 2 STARTED\n\n");
    printf("Please make new selections in short list\n");

	for(int i=0; i < shortCount; i++){
		printf("%d-%s\n",i+1,shortList[i]);
	}
	for(int i = 0; i < countOfPeople; i++){
		printf("%dth person started selection\n",(i+1));
		for(int j = 0; j < shortCount; j++){
			printf("Enter the id of meal and #%d preference is: ",j+1);
			scanf("%d", &temp);
			secondPointArr[temp-1] += shortCount-j;
			}
		printf("%dth person finished selection\n\n",(i+1));
	}
	
	return 0;
}