#include<stdio.h>
#include<stdlib.h>
struct Object{
    int weight;
    int profit;
    double profitperweight;
};
int compare(const void* x,const void* y){
    struct Object* ratioa=(struct Object*)x; //type casting into void pointer type 
    struct Object* ratiob=(struct Object*)y;
    if(ratioa->profitperweight<ratiob->profitperweight)
    {return 1;}//sort in descending order
    else if(ratioa->profitperweight>ratiob->profitperweight){return -1;}
    else{return 0;}

}
void sort(struct Object obj[],int n){
    for(int i=0;i<n-1;i++){
        int max=i;
        for(int j=i+1;j<n;j++){
             if(compare(&obj[j],&obj[max])==-1){
                max=j;
             }
        }
        if(max!=i){
            struct Object t=obj[i];
            obj[i]=obj[max];
            obj[max]=t;
        }
    }
}
double knapsackfrac(struct Object obj[],int n,int capacity){
    double maxprofit=0.0;
    int currentweight=0;
    sort(obj,n);
    for(int i=0;i<n;i++){
        if(currentweight+obj[i].weight<=capacity){
            maxprofit+=obj[i].profit;
            currentweight+=obj[i].weight;
        }else{
            double remcapacity=capacity-currentweight;
            maxprofit+=(remcapacity/obj[i].weight)*obj[i].profit;
            break;
        }
    }
    return maxprofit;
}
int main(){
    int capacity,n;
    printf("enter the capacity :");
    scanf("%d",&capacity);
    printf("enter the number of objects :");
    scanf("%d",&n);
    struct Object obj[n];
    for(int i=0;i<n;i++){
        printf("enter weight and profit for object %d:",i+1);
        scanf("%d\t%d",&obj[i].weight,&obj[i].profit);
        obj[i].profitperweight=(double)obj[i].profit/obj[i].weight;
    }
    double finalprofit=knapsackfrac(obj,n,capacity);
    printf("Maximum profit : %.2lf\n",finalprofit);
    return 0;
}