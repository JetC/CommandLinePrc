#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void voidFunc (){
    printf("I'm voidFunc\n");
}

char (^charFromInteger) (int) = ^(int integerParam){
    
    return (char)integerParam;
};

typedef char (^CharFromIntegerConverter)(int);

char convertIntegerToChar(int integer, CharFromIntegerConverter charFromIntegerConverter){
    
    return charFromIntegerConverter(integer);
}

char convertIntegerToCharDirectlyUsingBlock(int integer, char(^block)(int integerParam)){
    return (char)block(integer);
}

void callPreviousPractice(){
    
    int (^yesBlock) (int j322) = ^(int param){
        return 1;
    };
    
    
    void (^voidBlock) (void)  = ^(void){
        printf("I'm void\n");
    };
    voidBlock();
    
    
    
    printf("%zd\n",yesBlock(2));
    printf("%c\n",charFromInteger(65));
    printf("convertIntegerToChar:%c\n",convertIntegerToChar(65, charFromInteger));

    typedef char * pStr;
    
    char string[4] = "abc";
    
    const char *p1 = string;
    
    const pStr p2 = string;
    
    p1++;
//ERROR  p2++;
    
    printf("%c\n",convertIntegerToCharDirectlyUsingBlock(65, ^char(int integerParam) {
        return (char)integerParam;
    }));
    
    printf("%c\n",convertIntegerToCharDirectlyUsingBlock(65, charFromInteger));
    
}

//static int maxSubSum(const int A[], int left, int right){
//    int maxLeftSum, maxRightSum;
//    
//}


void toBeMeasured(){
    
    
    
}

void timeMeasuring(){
    clock_t startClock, endClock;
    startClock = clock();
    
    toBeMeasured();
    
    endClock = clock();
    printf("\n");
    printf("%lf",(double)(endClock-startClock)/CLOCKS_PER_SEC);
}


int main(int argc, char **argv)
{
//    callPreviousPractice();
//    timeMeasuring();
    
    
    return 0;
}



