#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/*
冒泡排序：升序
    如果vec[i++]>vec[i], 则交换
    循环N次
*/

template<typename T>
void bubble_sort(vector<T> &vec){
    int length = vec.size();

    for(int i=0; i<length; i++){
        bool exchange = false;
        for(int j=0; j+1<length; j++){
            if(vec[j] > vec[j+1]){
                exchange = true;
                swap(vec[j], vec[j+1]);
            }
        }
        if(exchange == false)break;
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


    bubble_sort(vec);

    cout<<"Heap sort result is ";
    for(int i=0; i<30; i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;



    return 0;
}
