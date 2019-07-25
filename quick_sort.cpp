#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/*
������������
    ���������Ϊ��׼����ָ��left, ��ָ��right
    1�����ҵ����ұȻ�׼С��������ֵ��ֵ��left��
    2���������ұȻ�׼���������ֵ��ֵ��right;
    3��ѭ��1��2֪��left == right;
    4���Ե�ǰλ��Ϊ�ָ�㣬�ݹ������������������
*/

template<typename T>
int partion(vector<T> &vec, int left, int right){
    T tmp = vec[left];
    while(left<right){
        while(right>left && vec[right]>=tmp)right--;
        vec[left] = vec[right];
        while(left<right && vec[left]<=tmp)left++;
        vec[right] = vec[left];
    }
    vec[left] = tmp;
    return left;
}
template<typename T>
void sort(vector<T> &vec, int left, int right){
    if(left >= right) return;
    int ind = partion(vec, left, right);

    sort(vec, left, ind-1);
    sort(vec, ind+1, right);
}

template<typename T>
void quick_sort(vector<T> &vec){
    int length = vec.size();

    sort(vec, 0, length-1);
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

    quick_sort(vec);
    cout<<"Heap sort result is ";
    for(int i=0; i<length; i++){
        cout<<vec[i]<<' ';
    }
    cout<<endl;



    return 0;
}
