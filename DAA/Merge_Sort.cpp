#include<iostream>
using namespace std;
void merge(int a[],int low,int up);
void merg(int a[],int temp[],int l1,int u1,int l2,int u2);
void cpy(int a[],int temp[],int low,int up);
int main(){
int n;
cout<<"Enter size :";
cin>>n;
int a[n];
for(int i=0;i<n;i++){
cin>>a[i];}

int low=0,up=n-1;
merge(a,low,up);
for(int i=0;i<n;i++){
cout<<a[i]<<"\t";}

return 0;}

void merge(int a[],int low,int up){
int mdl;
int temp[10];
if(low<up){
mdl=(low+up)/2;
merge(a,low,mdl);
merge(a,mdl+1,up);


merg(a,temp,low,mdl,mdl+1,up);
cpy(a,temp,low,up);
}}
void merg(int a[],int temp[],int l1,int u1,int l2,int u2){
int i=l1;
int j=l2;
int k=l1;
while((i<=u1)&&(j<=u2)){
if(a[i]<a[j]){
temp[k++]=a[i++];}
else{
temp[k++]=a[j++];}}

while(i<=u1){
temp[k++]=a[i++];}
while(j<=u2){

temp[k++]=a[j++];}}
void cpy(int a[],int temp[],int low,int up){
int i;
for(i=low;i<=up;i++){
a[i]=temp[i];}}





/* OUTPUT :
Enter size :5
                    7
                    3
                    9
                    4
                    6
3 4 6 7 9