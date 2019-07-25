#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/*
归并排序：升序
    先一直分组到每组只有1个元素，然后合并。
    因为合并的两组都是有序的，所以按照有序的方式进行合并
*/

template<typename T>
int merge(vector<T> &vec, int left, int mid, int right){
    vector<T> aux;
    for(int k=left; k<=right; k++)
        aux.push_back(vec[k]);

    int i=0, j=mid+1-left, m = mid-left;
    for(int k=left; k<=right; k++){
        if(i>m) vec[k] = aux[j++];
        else if(j>right-left) vec[k] = aux[i++];
        else if(aux[i]<=aux[j]) vec[k] = aux[i++];
        else vec[k] = aux[j++];
    }
}
template<typename T>
void sort(vector<T> &vec, int left, int right){
    if(left >= right) return;

    int mid = left + (right-left) / 2;
    sort(vec, left, mid);
    sort(vec, mid+1, right);

    merge(vec, left, mid, right);
}

template<typename T>
void merge_sort(vector<T> &vec){
    int length = vec.size();

    sort(vec, 0, length-1);
}

int main(){
    int length =30;
    srand((unsigned)time(NULL));
    vector<int> vec(length, 0);
    for(int i=0; i<length; i++){
        vec[i] = rand() % 20;
    }
    cout<<"The random array is ";
    for(int i=0; i<length; i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;
    vector<int> vec1(vec.begin(), vec.end());

    sort(vec1.begin(), vec1.end());
    cout<<"Algo sort result is ";
    for(int i=0; i<length; i++){
        cout<<vec1[i]<<' ';
    }
    cout<<endl;

    merge_sort(vec);
    cout<<"Heap sort result is ";
    for(int i=0; i<length; i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;

    return 0;
}
