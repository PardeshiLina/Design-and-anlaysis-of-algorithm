#include<iostream>
using namespace std;
#define Max 100
#define temp 0
#define perm 1
#define infinity 99999
#define nil -1
void find_path(int s,int v);

void create_graph();
int min_temp();
void  Dijkstra(int s);

int n;
int adj[Max][Max];
int predec[Max];
int pathlen[Max];
int status[Max];
int main(){
int s,v;
create_graph();
cout<<"Enter the source vertex:";
cin>>s;
Dijkstra(s);

while(1){
cout<<"\nEnter destination vertex (-1 to quit) :";
cin>>v;
if(v==-1)
break;
if(v<0||v>=n)
cout<<"This vertex does not exist \n";
else if (v==s)
cout<<"\nSource and destination vertices are same\n";
else if (pathlen[v]==infinity)
cout<<"There is no path from source to destination vertex \n";
else
find_path(s,v);

}
return 0;}


void Dijkstra(int s){
int i,curr;
for(i=0;i<n;i++){
predec[i]=nil;
pathlen[i]=infinity;
status[i]=temp;
}
pathlen[s]=0;
while(1){
curr=min_temp();
if(curr==nil)
return;
status[curr]=perm;

for(i=0;i<n;i++){
if(adj[curr][i]!=0 && status[i]==temp)
if(pathlen[curr]+adj[curr][i]<pathlen[i]){
predec[i]=curr;
pathlen[i]=pathlen[curr]+adj[curr][i];}}}

}

int min_temp(){
int i;
int min=infinity;
int k=nil;
for(i=0;i<n;i++){
if(status[i]==temp && pathlen[i]<min){

min=pathlen[i];
k=i;
}}
return k;}

void find_path(int s,int v){
int i,u;
int path[Max];
int shortdist=0;
int count =0;
while(v!=s){
count++;
path[count]=v;
u=predec[v];
shortdist+=adj[u][v];
v=u;

}
count++;
path[count]=s;
printf("Shortest path is: ");
for(i=count;i>=1;i--)
cout<<path[i]<<" ";
cout<<"Shortest distance is :"<<shortdist;

}

void create_graph(){
int i,max_edges,o,d,wt;

cout<<"Enter the number of vertices: ";
cin>>n;
max_edges=n*(n-1);
for(i=1;i<=max_edges;i++){
cout<<"Enter the edge "<<i<<"(-1 -1 to quit): ";
cin>>o>>d;

if((o==-1)&&(d==-1))
break;
cout<<"Enter the weight for this edge :";
cin>>wt;

if(o>=n||d>=n|o<0||d<0){
cout<<"Invalid edge\n";
i--;}
else{
adj[o][d]=wt;
}
}
}




/* OUTPUT:
  Enter the number of vertices: 5
Enter the edge 1(-1 -1 to quit): 0
1
Enter the weight for this edge :8
Enter the edge 2(-1 -1 to quit): 2
1
Enter the weight for this edge :2
Enter the edge 3(-1 -1 to quit): 2
4
Enter the weight for this edge :3
Enter the edge 4(-1 -1 to quit): 3
4
Enter the weight for this edge :7
Enter the edge 5(-1 -1 to quit): 0
3
Enter the weight for this edge :6
Enter the edge 6(-1 -1 to quit): 0
4
Enter the weight for this edge :14
Enter the edge 7(-1 -1 to quit): 0
2
Enter the weight for this edge :5
Enter the edge 8(-1 -1 to quit): -1
-1
Enter the source vertex:0

Enter destination vertex (-1 to quit) :4
Shortest path is: 0 2 4 Shortest distance is :8
*/