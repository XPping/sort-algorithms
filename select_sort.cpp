#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/*
选择排序：升序
    1、寻找最小的数，最小的数不在最左端，则交换位置
    2、从余下的n-1个数，重复1，知道只剩一个数
*/


template<typename T>
void select_sort(vector<T> &vec){
    int length = vec.size();

    for(int i=0; i<length; i++){
        int ind = i;
        for(int j=i+1; j<length; j++){
            if(vec[j]<vec[ind]) ind = j;
        }
        if(ind != i)
            swap(vec[ind], vec[i]);
    }
}

int main(){
    int length = 30;
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

    select_sort(vec);
    cout<<"Heap sort result is ";
    for(int i=0; i<length; i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;



    return 0;
}
