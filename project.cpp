#include <bits/stdc++.h>
using namespace std;
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
    cout<<"\n\nAccording to Insertion Sort, sorted data is: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
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


void quickSort(int arr[], int n)
{

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
        cout<<"\nPress 1: Insertion Sort\nPress2: Merge Sort \nPress3: Quick Sort \nPress4: Exit\nChose Your Option==> ";
        cin>>option;
        switch(option)
        {
        case 1:
            insertionSort(arr, n);
            break;
        case 2:
            mergeSort(arr,0,n-1);
            cout<<"\nSorted Data ";
            cout<<"\n\nAccording to Merger Sort, sorted data is: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;;
            break;
        case 3:
            quickSort(arr,n);
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


