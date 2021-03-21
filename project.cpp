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

void mergeSort(int arr[], int n)
{

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
            mergeSort(arr,n);
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


