#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/*
shell排序：升序
    分组，从length/2 到 1, 然后插入排序
*/

template<typename T>
void shell_sort(vector<T> &vec){
    int length = vec.size();

    for(int step=length/2; step>=1; step/=2){
        for(int i=step; i<length; i++){
            int j= i;
            while(j-step>=0 && vec[j]<vec[j-step]){
                swap(vec[j], vec[j-step]);
                j -= step;
            }
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

    shell_sort(vec);
    cout<<"Heap sort result is ";
    for(int i=0; i<30; i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;



    return 0;
}
