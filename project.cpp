#include <bits/stdc++.h>
using namespace std;

///For Insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout<<"\n\nAccording to Insertion Sort, sorted data are: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

///For Merge sort
void Merge(int arr[], int l, int h, int m)
{

    int i, j, k, temp[h-l+1];
    i = l;
    k = 0;
    j = m + 1;

    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= m)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= h)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }


    for (i = l; i <= h; i++)
    {
        arr[i] = temp[i-l];
    }
}
void mergeSort(int arr[], int l, int h)
{
    int m;
    if (l < h)
    {
        m=(l+h)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, h);


        Merge(arr, l, h, m);
    }
}


///For Quick sort
int partition(int arr[],int left,int right)
{
    int pivot=arr[right];

    int P_index=left;
    int i,tamp;
    for(i=left; i<right; i++)
    {
        if(arr[i]<=pivot)
        {
            tamp=arr[i];
            arr[i]=arr[P_index];
            arr[P_index]=tamp;
            P_index++;
        }
    }

    tamp=arr[right];
    arr[right]=arr[P_index];
    arr[P_index]=tamp;


    return P_index;
}
void quickSort(int arr[],int left,int right)
{
    if(left<right)
    {
        int P_index=partition(arr,left,right);
        quickSort(arr,left,P_index-1);
        quickSort(arr,P_index+1,right);
    }
}

int main()
{
    int s;
    cout<<"Enter the size of array :";
    cin>>s;
    int arr[s];
    int n =s,option;
    char ch;
    cout<<"Array Values are : ";
    for(int i=0; i<s; i++)
    {
        cin>>arr[i];
    }
    do
    {
        cout<<"\nPress 1: Insertion Sort\nPress2: Merge Sort \nPress3: Quick Sort \nPress4: Exit\n\nChose Your Option==> ";
        cin>>option;
        switch(option)
        {
        case 1:
            insertionSort(arr, n);
            break;
        case 2:
            mergeSort(arr,0,n-1);
            cout<<"\n\nAccording to Merger Sort, sorted data are: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 3:
            quickSort(arr,0,n-1);
            cout<<"\n\nAccording to Quick Sort, sorted data are:";
            for(int i=0; i<n; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout << endl;
            break;
        case 4:
            exit(0);
        default:
            cout<<"Please Enter right number..Thank you\n";
            break;

        }
        cout<<"\nYou want more sort result y/n?";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');


    return 0;
}


