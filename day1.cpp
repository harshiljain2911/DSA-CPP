#include<iostream>
#include<vector>
#include<map>

using namespace std;
int main()
{

vector<int> v;
map<int,string> m;


vector<int> v;



v.push_back(1);
cout<<"Capacity->"<<v.capacity()<<" Size->"<<v.size()<<endl;
cout<<"Element at 1 index is->"<<v.at(0)<<endl;
v.push_back(2);
cout<<"Capacity->"<<v.capacity()<<" Size->"<<v.size()<<endl;
cout<<"Element at 2 index is->"<<v.at(1)<<endl;
v.push_back(3);
cout<<"Capacity->"<<v.capacity()<<" Size->"<<v.size()<<endl;
cout<<"Element at 3 index is->"<<v.at(2)<<endl;
v.push_back(4);
cout<<"Capacity->"<<v.capacity()<<" Size->"<<v.size()<<endl;
cout<<"Element at 4 index is->"<<v.at(3)<<endl;
v.push_back(5);
cout<<"Capacity->"<<v.capacity()<<" Size->"<<v.size()<<endl;
cout<<"Element at 5 index is->"<<v.at(4)<<endl;



m[2] = "Harshil";
m[18] = "Love";
m[1] = "Prachi";

m.insert({3,"Jain"});

for(auto i:m)
{
    cout<<i.first<<"-->"<<i.second<<endl; 
}





return 0;

}
