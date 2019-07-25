#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/*
直接插入排序：升序
    把后面的数插入到前面的有序序列里
*/

template<typename T>
void insert_sort(vector<T> &vec){
    int length = vec.size();

    for(int i=1; i<length; i++){
        for(int j=i-1; j>=0; j--){
            if(vec[j+1] >= vec[j])break;
            swap(vec[j], vec[j+1]);
        }
    }

}

int main(){
    srand((unsigned)time(NULL));
    vector<int> vec(30, 0);
    for(int i=0; i<30; i++){
        vec[i] = rand() % 20;
    }
    cout<<"The random array is ";
    for(int i=0; i<30; i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;
    vector<int> vec1(vec.begin(), vec.end());

    sort(vec1.begin(), vec1.end());
    cout<<"Algo sort result is ";
    for(int i=0; i<30; i++){
        cout<<vec1[i]<<' ';
    }
    cout<<endl;

    insert_sort(vec);
    cout<<"Heap sort result is ";
    for(int i=0; i<30; i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;



    return 0;
}
