#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/*
ѡ����������
    1��Ѱ����С��������С������������ˣ��򽻻�λ��
    2�������µ�n-1�������ظ�1��֪��ֻʣһ����
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
