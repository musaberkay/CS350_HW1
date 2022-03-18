#include <stdio.h>
#include <stdlib.h>

#define THRESHOLD 10

int main(){
	int count;
	char foodArr[5][15]={"Kebab","Burger","Pasta","Lahmacun","Salad or Others"};
	int pointArr[5];
	int temp;

	printf("Enter how many people you are: ");
	scanf("%d", &count);
	printf("Make 5 choices in order of 1-Kebab,2-Burger,3-Pasta,4-Lahmacun,5-Salad or others\n");
	printf("So, please start type your decisions one-by-one\n");

	for(int i = 0; i < count; i++){
		for(int j = 0; j < 5; j++){
			scanf("%d", &temp);
			switch (j){
				case 0: pointArr[temp-1] += 5; break;
				case 1: pointArr[temp-1] += 4; break;
				case 2: pointArr[temp-1] += 3; break;
				case 3: pointArr[temp-1] += 2; break;
				case 4: pointArr[temp-1] += 1; break;
			}
		}
		printf("%dth person finished selection\n",(i+1));
	}

    temp = 0;
    for(int i = 0; i < 5; i++){
        if(pointArr[i]>THRESHOLD){
            printf("%s:%d ",foodArr[i],pointArr[i]);
            temp++;
        }
    }
    printf("\n");

    if(temp==0){
        printf("You are eating at home/dorm today!\n");
        exit(0);
    }


	return 0;
}