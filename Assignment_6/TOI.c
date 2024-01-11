#include<stdio.h>
void towerofHanoi(int n, char *src,char *dest,char *helper){
    if(n == 1) {
        printf("Moved disc 1 from %s to %s\n",src,dest);
        return;
    }
    towerofHanoi(n-1,src,helper,dest);
    printf("Moved disc %d from %s to %s \n",n,src,dest);
    towerofHanoi(n-1,helper,dest,src);
    
}
int main(){
    int n;
    printf("Enter the number of towers to move : ");
    scanf("%d",&n);
    towerofHanoi(n,"Source","Destination","Helper");
    
    return 0;
}
