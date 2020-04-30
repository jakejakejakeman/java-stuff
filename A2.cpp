#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;
void heapify(int arr[], int size, int l)
{
    int largest = l;
    int left = 2*l + 1;
    int right = 2*l + 2;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != l)
    {
        swap(arr[l], arr[largest]);
        heapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size)
{
    for (int i = size/2-1; i >= 0; i--)
        heapify(arr, size, i);
    for (int i=size-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void shellSort(int arr[], int size)
{
    for (int gap=size/2; gap>0; gap/=2)
    {
        for (int i=gap; i<size; i++)
        {
            int temp1=arr[i];
            int j;
            for (j=i; j>=gap&&arr[j-gap]>temp1; j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp1;
        }
    }
}
int main() {
    int a1[5000];
    int a2[5000];
    int a3[5000];
    int a4[50000];
    int a5[50000];
    int a6[50000];
    int a7[500000];
    int a8[500000];
    int a9[500000];

    ifstream inputFile;
    inputFile.open("numbers/file1.txt");
    for (int i=0; i<5000; i++)
        inputFile >> a1[i];
    inputFile.close();
    inputFile.open("numbers/file2.txt");
    for (int i=0; i<5000; i++)
        inputFile >> a2[i];
    inputFile.close();
    inputFile.open("numbers/file3.txt");
    for (int i=0; i<5000; i++)
        inputFile >> a3[i];
    inputFile.close();
    inputFile.open("numbers/file4.txt");
    for (int i=0; i<50000; i++)
        inputFile >> a4[i];
    inputFile.close();
    inputFile.open("numbers/file5.txt");
    for (int i=0; i<50000; i++)
        inputFile >> a5[i];
    inputFile.close();
    inputFile.open("numbers/file6.txt");
    for (int i=0; i<50000; i++)
        inputFile >> a6[i];
    inputFile.close();
    inputFile.open("numbers/file7.txt");
    for (int i=0; i<500000; i++)
        inputFile >> a7[i];
    inputFile.close();
    inputFile.open("numbers/file8.txt");
    for (int i=0; i<500000; i++)
        inputFile >> a8[i];
    inputFile.close();
    inputFile.open("numbers/file9.txt");
    for (int i=0; i<500000; i++)
        inputFile >> a9[i];
    inputFile.close();
    auto start=high_resolution_clock::now();
    shellSort(a1, 5000);
    auto stop=high_resolution_clock::now();
    auto duration1=duration_cast<microseconds>(stop-start);
    cout<<"5000 shell best case: "<<duration1.count()<<endl;
    start=high_resolution_clock::now();
    shellSort(a2, 5000);
    stop=high_resolution_clock::now();
    auto duration2=duration_cast<microseconds>(stop-start);
    cout<<"5000 shell worst case: "<<duration2.count()<<endl;
    start=high_resolution_clock::now();
    shellSort(a3, 5000);
    stop=high_resolution_clock::now();
    auto duration3=duration_cast<microseconds>(stop-start);
    cout<<"5000 shell average case: "<<duration3.count()<<endl;
    start=high_resolution_clock::now();
    shellSort(a4, 50000);
    stop=high_resolution_clock::now();
    auto duration4=duration_cast<microseconds>(stop-start);
    cout<<"50000 shell best case: "<<duration4.count()<<endl;
    start=high_resolution_clock::now();
    shellSort(a5, 50000);
    stop=high_resolution_clock::now();
    auto duration5=duration_cast<microseconds>(stop-start);
    cout<<"50000 shell worst case: "<<duration5.count()<<endl;
    start=high_resolution_clock::now();
    shellSort(a6, 50000);
    stop=high_resolution_clock::now();
    auto duration6=duration_cast<microseconds>(stop-start);
    cout<<"50000 shell average case: "<<duration6.count()<<endl;
    start=high_resolution_clock::now();
    shellSort(a7, 500000);
    stop=high_resolution_clock::now();
    auto duration7=duration_cast<microseconds>(stop-start);
    cout<<"500000 shell best case: "<<duration7.count()<<endl;
    start=high_resolution_clock::now();
    shellSort(a8, 500000);
    stop=high_resolution_clock::now();
    auto duration8=duration_cast<microseconds>(stop-start);
    cout<<"500000 shell worst case: "<<duration8.count()<<endl;
    start=high_resolution_clock::now();
    shellSort(a9, 500000);
    stop=high_resolution_clock::now();
    auto duration9=duration_cast<microseconds>(stop-start);
    cout<<"500000 shell average case: "<<duration9.count()<<endl;
    inputFile.open("numbers/file1.txt");
    for (int i=0; i<5000; i++)
        inputFile >> a1[i];
    inputFile.close();
    inputFile.open("numbers/file2.txt");
    for (int i=0; i<5000; i++)
        inputFile >> a2[i];
    inputFile.close();
    inputFile.open("numbers/file3.txt");
    for (int i=0; i<5000; i++)
        inputFile >> a3[i];
    inputFile.close();
    inputFile.open("numbers/file4.txt");
    for (int i=0; i<50000; i++)
        inputFile >> a4[i];
    inputFile.close();
    inputFile.open("numbers/file5.txt");
    for (int i=0; i<50000; i++)
        inputFile >> a5[i];
    inputFile.close();
    inputFile.open("numbers/file6.txt");
    for (int i=0; i<50000; i++)
        inputFile >> a6[i];
    inputFile.close();
    inputFile.open("numbers/file7.txt");
    for (int i=0; i<500000; i++)
        inputFile >> a7[i];
    inputFile.close();
    inputFile.open("numbers/file8.txt");
    for (int i=0; i<500000; i++)
        inputFile >> a8[i];
    inputFile.close();
    inputFile.open("numbers/file9.txt");
    for (int i=0; i<500000; i++)
        inputFile >> a9[i];
    inputFile.close();
    start=high_resolution_clock::now();
    heapSort(a1, 5000);
    stop=high_resolution_clock::now();
    auto durationh1=duration_cast<microseconds>(stop-start);
    cout<<"5000 heap best case: "<<durationh1.count()<<endl;
    start=high_resolution_clock::now();
    heapSort(a2, 5000);
    stop=high_resolution_clock::now();
    auto durationh2=duration_cast<microseconds>(stop-start);
    cout<<"5000 heap worst case: "<<durationh2.count()<<endl;
    start=high_resolution_clock::now();
    heapSort(a3, 5000);
    stop=high_resolution_clock::now();
    auto durationh3=duration_cast<microseconds>(stop-start);
    cout<<"5000 heap average case: "<<durationh3.count()<<endl;
    start=high_resolution_clock::now();
    heapSort(a4, 50000);
    stop=high_resolution_clock::now();
    auto durationh4=duration_cast<microseconds>(stop-start);
    cout<<"50000 heap best case: "<<durationh4.count()<<endl;
    start=high_resolution_clock::now();
    heapSort(a5, 50000);
    stop=high_resolution_clock::now();
    auto durationh5=duration_cast<microseconds>(stop-start);
    cout<<"50000 heap worst case: "<<durationh5.count()<<endl;
    start=high_resolution_clock::now();
    heapSort(a6, 50000);
    stop=high_resolution_clock::now();
    auto durationh6=duration_cast<microseconds>(stop-start);
    cout<<"50000 heap average case: "<<durationh6.count()<<endl;
    start=high_resolution_clock::now();
    heapSort(a7, 500000);
    stop=high_resolution_clock::now();
    auto durationh7=duration_cast<microseconds>(stop-start);
    cout<<"500000 heap best case: "<<durationh7.count()<<endl;
    start=high_resolution_clock::now();
    heapSort(a8, 500000);
    stop=high_resolution_clock::now();
    auto durationh8=duration_cast<microseconds>(stop-start);
    cout<<"500000 heap worst case: "<<durationh8.count()<<endl;
    start=high_resolution_clock::now();
    heapSort(a9, 500000);
    stop=high_resolution_clock::now();
    auto durationh9=duration_cast<microseconds>(stop-start);
    cout<<"500000 heap average case: "<<durationh9.count()<<endl;
    return 0;
}