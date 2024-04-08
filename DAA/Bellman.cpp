#include<iostream>
#include<stdlib.h>
using namespace std;
#define max 100
#define infi 999
#define nil -1
#define TRUE 1
#define FALSE 0

int n;
int adj[max][max];
int pre[max];
int pl[max];
int ispresent[max];
int front ,rear;
int q[max];

void c_graph();
int  bellman(int s);
void iniqueue();
void insertq(int item);
int isemtyq();
int deleteq();
void findpath(int s,int v);

int main(){
int s,v;
c_graph();
cout<<"Enter source vertex";
cin>>s;
bellman(s);

while(1){
cout<<"Enter the destination vertex(-1 to quit): ";
cin>>v;

if(v==-1)
break;
if(v<0 ||v>=n)
cout<<"The vertex does not exist ";
else if (v==s)
cout<<"Source and destination are same ";
else if (pl[v]==infi)
cout<<"There is no path from source to destination ";
else
findpath(s,v);
}
return 0;
}


void c_graph(){
int i,max_edges,o,d,wt;

cout<<"Enter the number of vertices: ";
cin>>n;
max_edges=n*(n-1);
for(i=1;i<=max_edges;i++){
cout<<"Enter the edge (-1 -1 to quit)"<<i<<":";

cin>>o>>d;

if((o==-1)&&(d==-1))
break;
cout<<"Enter the weight for this edge :\n";
cin>>wt;

if(o>=n||d>=n|o<0||d<0){
cout<<"Invalid edge\n";
i--;}
else{
adj[o][d]=wt;
}
}
}

int  bellman(int s){
int k=0,i,curr;
for(i=0;i<n;i++){
pre[i]=nil;
pl[i]=infi;
ispresent[i]=FALSE;
}
iniqueue();
pl[s]=0;
insertq(s);
ispresent[s]=TRUE;

while(!isemtyq()){
curr=deleteq();
ispresent[curr]=FALSE;
for(i=0;i<n;i++){
if(adj[curr][i]!=0)
if(pl[curr]+adj[curr][i]<pl[i])
{
pl[i]=pl[curr]+adj[curr][i];
pre[i]=curr;

if(!ispresent[i]){
insertq(i);
ispresent[i]=TRUE;
}
}
}
}
return 1;
}

void iniqueue(){
int i;
for(i=0;i<n;i++){
q[i]=0;
}
rear=-1;
front=-1;

}

void insertq(int item){
if(rear==max-1){
cout<<"Queue overflow";
exit(1);
}
else{
if(front==-1)
front=0;
rear=rear+1;
q[rear]=item;
}}

int isemtyq(){
if(front==-1 || front>rear)
return 1;
else
return 0;

}

int deleteq(){
int a;
if(front==-1 ||front>rear){
cout<<"queue underflow";
exit(1);}

else{
a=q[front];
front=front+1;
}
return a;}

void findpath(int s,int v){
int i,u;
int path[max];
int shortdist=0;
int count =0;
while(v!=s){
count++;
path[count]=v;
u=pre[v];
shortdist+=adj[u][v];
v=u;

}
count++;
path[count]=s;
cout<<"Shortest path :";
for(i=count;i>=1;i--)
cout<<path[i]<<" ";
cout<<"\n";
cout<<"Shortest distance is: "<<shortdist;

}






/* OUTPUT:
 Enter the number of vertices: 5
Enter the edge (-1 -1 to quit)1:1 0
Enter the weight for this edge :
6
Enter the edge (-1 -1 to quit)2:1 2
Enter the weight for this edge :
5
Enter the edge (-1 -1 to quit)3:2 3
Enter the weight for this edge :
-4
Enter the edge (-1 -1 to quit)4:0 4
Enter the weight for this edge :
8
Enter the edge (-1 -1 to quit)5:2 4
Enter the weight for this edge :
-3
Enter the edge (-1 -1 to quit)6:-1
-1
Enter source vertex1
Enter the destination vertex(-1 to quit): 4
Shortest path :1 2 4
Shortest distance is: 2Enter the destination vertex(-1 to quit): 2
Shortest path :1 2
Shortest distance is: 5Enter the destination vertex(-1 to quit): 3
Shortest path :1 2 3
  */