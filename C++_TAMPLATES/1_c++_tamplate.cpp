#include<iostream>
using namespace std;

template<class t>
class vector{
    public:
    t *arr;
    t size;
    vector(t m){
        size=m;
        arr=new t[size];
    }
    t dotProduct(vector &v){
        t d=0;
        for(int i=0;i<size;i++){
            d+=this->arr[i]*v.arr[i];
        }
        return d;
    }
};

int main(){
    vector<float> v1(3);
    v1.arr[0]=1.4;
    v1.arr[1]=3.3;
    v1.arr[2]=.1;
    vector<float> v2(3);
    v2.arr[0]=.1;
    v2.arr[1]=1.9;
    v2.arr[2]=4.1;
    float a =v1.dotProduct(v2);
    cout<<a<<endl;
    
    return 0;
}