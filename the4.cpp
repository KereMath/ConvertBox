#include "the4.h"
int dp_sln(char**& arr1, char**& arr2, int nrow, int ncol1, int ncol2, int**& mem){ //dynamic programming
    int i,j;
    mem[0][0]=0;
    for(i=0;i<=ncol1;i++){
        for(j=0;j<=ncol2;j++){
            
    if(i==0){
        
        for(int k=0;k<ncol2;k++){
            int count=0;
            
            for(int l=0;l<nrow;l++){
                if(arr2[l][k]!='-'){
                    count++;
                }
                
                
            }
            mem[0][k+1]=mem[0][k]+count;
        }
    }
    else if(j==0){
        
        for(int k=0;k<ncol1;k++){
            int count=0;
            
            for(int l=0;l<nrow;l++){
                if(arr1[l][k]!='-'){
                    count++;
                }
            }
            mem[k+1][0]=mem[k][0]+count;
        }
    }
    else{ int k1;
                int total = 0; 
                int Delete = 0;
                int Insert = 0;
                for(k1 = 0; k1 < nrow; k1++)
                {
                    if(arr1[k1][i-1] != '-')
                    {
                        Delete++;
                    }
                }
                for(k1 = 0; k1 < nrow; k1++)
                {
                    if(arr2[k1][j-1] != '-')
                    {
                        Insert++;
                    }
                }

                int order;
                int compare = 1;
                int temp1[nrow];
                int temp2[nrow];
             for(int k1=0;k1<nrow;k1++){
                 temp1[k1]=arr1[k1][i-1];
             }
             for(int k1=0;k1<nrow;k1++){
                 temp2[k1]=arr2[k1][j-1];
             }
        
int i1, key, j1;
for (i1 = 1; i1 < nrow; i1++){
    key = temp1[i1];
    j1 = i1 - 1;
    
    while (j1 >= 0 && temp1[j1] > key)
    {
        temp1[j1 + 1] = temp1[j1];
        j1 = j1 - 1;
    }
    temp1[j1 + 1] = key;
}

for (i1 = 1; i1 < nrow; i1++){
key = temp2[i1];
j1 = i1 - 1;

while (j1 >= 0 && temp2[j1] > key)
{
temp2[j1 + 1] = temp2[j1];
j1 = j1 - 1;
}
temp2[j1 + 1] = key;
}

for(k1=0;k1<nrow;k1++){
    if(temp1[k1]!=temp2[k1]){compare=0;}
}      

                if(compare)
                {
                    order = 0;
                    for(k1 = 0; k1 < nrow; k1++)
                    {
                        if(arr1[k1][i-1] != arr2[k1][j-1])
                        {
                            order++;
                        }
                    }
                }
                
                int Replacement = 0;
                for(k1 = 0; k1 < nrow; k1++)
                {
                    if(arr1[k1][i-1] != arr2[k1][j-1])
                    {
                        if(arr1[k1][i-1] == '-' || arr2[k1][j-1] == '-')
                        {
                            Replacement+=2;
                        }
                        else{
                        Replacement+=1;}
                    }
                }
                
                
                
                total = Replacement;
                if(compare)
                {
                    if(order < Replacement)
                    {
                        total = order;
                    }
                }
                
                
                int a,b,c,min;
                a = mem[i-1][j-1] + total;
                b = mem[i-1][j] + Delete;
                c = mem[i][j-1] + Insert;
                min=a;
                if(b<min) min=b;
                if(c<min) min=c;
                mem[i][j] = min;
                
            }
        }
    }

    return mem[i-1][j-1]; 
}