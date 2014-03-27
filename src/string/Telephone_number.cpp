/*
* AmazonStringPermutationVarition.cpp
* run command
* g++ /Algorithm/src/InterviewPreparation/strings/AmazonStringPermutationVarition.cpp -o /usr/build/Main.o
*
* Created on: Nov 6, 2013
* Author: Indresh Gahoi
*/

/* Question :-
given a string or say number .. for e.g. 134 now with each number , as per mobile’s keypad ,
some letters would be associated.
here 1 – > abc , 3->ghi, 4 ->jkl .
So we should print all the permutation such that we take 1 character from each of the number.
input number can be of any arbitrary length.
lets say each digit has m numbers associated , then for the input of length n , we need to generate n^m possible strings.

Took a map of which would return all the letters for the number. solved it using recursion. its quite similar to permutation of string. .
Interviewer seemed quite impressed here
*
*/



#include<iostream>
#include<string>
#include<vector>
using namespace std ;


void premutation(vector< vector<char> > &map ,int index, vector<char> &str){

    if((index+1)==map.size()){

     for(int i = 0 ; i < map[index].size() ; ++i)
     {
     for(int j = 0 ; j < str.size(); ++j)
     cout <<str[j];
     cout<<map[index][i]<<"\n";
     }
    }

    else
    {
     for(int i = 0 ; i < map[index].size() ; ++i ){
     str.push_back(map[index][i]) ;
     premutation(map,index+1,str);
     str.pop_back();
     }

    }

}

int main(){

vector< vector<char> > map ;
vector<char> v1 ;
vector<char> v2 ;
vector<char> v3 ;
    v1.push_back('a');v1.push_back('b');v1.push_back('c');
    v2.push_back('g');v2.push_back('h');v2.push_back('i');
    v3.push_back('j');v3.push_back('k');v3.push_back('l');
    map.push_back(v1);
    map.push_back(v2);
    map.push_back(v3);
    vector<char> str;
    premutation(map,0,str);
    return 0 ;
}
