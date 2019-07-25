#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/*
����������̣�
1�������ѣ��Ѷ�����Ϊ0��
2���ѶѶ�Ԫ�������һ��Ԫ�ؽ������ѿռ䳤�ȼ�һ��
3�������ѣ��ظ�2֪���ѿռ䳤��Ϊ1.
*/


template<typename T>
void build_heap(vector<T> &vec){
    int length = vec.size();
    for(int i=length/2-1; i>=0; i--){
        int root = i;
        T tmp = vec[root];
        int child = 2*root + 1;
        while(child < length){
            if(child+1<length && vec[child]<vec[child+1])
                child++;
            if(tmp >= vec[child])
                break;
            vec[root] = vec[child];
            root = child;
            child = 2*root+1;
        }
        vec[root] = tmp;
    }
}

// �ѶѶ�Ԫ��������Ԫ�ؽ���֮����Ҫ������
template<typename T>
void adjust_heap(vector<T> &vec, int length){
    int root = 0;
    T tmp = vec[root];
    int child = 2*root + 1;
    while(child < length){
        if(child+1 < length && vec[child] < vec[child+1])
            child++;
        if(tmp >= vec[child])
            break;
        vec[root] = vec[child];
        root = child;
        child = 2*root + 1;
    }
    vec[root] = tmp;
}

template<typename T>
void heap_sort(vector<T> &vec){
    build_heap(vec);

    int length = vec.size();
    for(int i=length-1; i>0; i--){
        swap(vec[i], vec[0]);
        adjust_heap(vec, i);
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


    heap_sort(vec);

    cout<<"Heap sort result is ";
    for(int i=0; i<30; i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;



    return 0;
}
