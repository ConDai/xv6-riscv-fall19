#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    char *sleepTimeStr;
    int sleepTime;
    // Check we have the right number of arguments
    // sleep 10. Thus the number of arguments is 2
    if(argc!=2){
        fprintf(2, "Usage: sleep int\n");
        exit();
    }
    // Number of arguments is correct
    sleepTimeStr = argv[1];
    
    for(int i=0; sleepTimeStr[i] != '\0'; i++)
        if(sleepTimeStr[i] < '0' || sleepTimeStr[i] > '9'){
            fprintf(2, "Usage: sleep int\n");
            exit();
        }
    // argv[1] is a positive integer represented as a string
    sleepTime = atoi(sleepTimeStr);

    sleep(sleepTime);
    exit();
}