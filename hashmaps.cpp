#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

int main()
{
    // // creation of a map
    // unordered_map<string,int> map;

    // // inserting on map
    // pair<string,int> p = make_pair("Scorpio",9);
    // map.insert(p);

    // pair<string,int> pa;
    // pa.first = "Car";
    // pa.second = 10;
    // map.insert(pa);

    // map["BMW"] = 12;(

    // // access the map

    // cout<<map.at("Scorpio")<<endl;
    // cout<<map.at("Car")<<endl;
    // // cout<<map.at("b")<<endl;         // if their is no key inside the map it will throw an out of range error


    // // searching in the map

    // cout << map.count("Car")<<endl;
    // cout<<map.size()<<endl;


    // if(map.find("Scorpio") != map.end())
    // {
    //     cout<<"present"<<endl;
    // }
    // else
    // {
    //     cout<<"not present"<<endl;
    // }

    map<char,int> m;
    string str = "thrivanthanampuram";

    for(int i = 0; i<str.length(); i++)
    {
        m[str[i]]++;
    }

    for(auto i : m)
    {
        cout<<i.first <<" -> "<<i.second<<endl;
    }



}
