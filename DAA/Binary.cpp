#include<iostream>
using namespace std;
int main()
{ int n;
cout<<"Enter size: ";
cin>>n;
    int array[n],i,search;
    cout<<"Enter array elements :"<<endl;
    for(i=0;i<n;i++)
    {
       cin>>array[i];
    }
    cout<<"Enter element you want to search :";
    cin>>search;
    int l=0;
    int up=9;
    int mid=(l+up)/2;
   
    while(l<=up)
    {
        if(search>array[mid])
        {
            l=mid+1;
        }
        else if(search==array[mid])
        {
            cout<<"Element found"<<endl;
            break;
        }
        else{
            up=mid-1;
        }
     mid=(l+up)/2;
    }
    if(l>up)
    {
        cout<<"Not found"<<endl;
    }
   
       return 0;
}

  /* OUTPUT:
     Enter size: 5
Enter array elements :
2
3
5
8
9
Enter element you want to search :5
Element found

*/
