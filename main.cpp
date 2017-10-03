#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;

void place(vector<int> & L, vector<int> & x );
void operator<<(ostream & out, vector<int> & v);
int width;
int count = 0;

int main()
{
    int L1t[] ={1,1,1,1,1,1,1,1,1,
                2,2,2,2,2,2,2,2,
                3,3,3,3,3,3,3,
                4,4,4,4,4,4,
                5,5,5,5,5,
                6,6,6,6,
                7,7,7,
                8,8,
                9};
    
    int L2t[] ={1,
                2,
                3,3,
                4,
                5,5,
                6,
                7,
                9,9,
                10,
                12,
                14,
                15};
                        
    int L3t[] ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                3,3,3,3,3,3,3,3,3,3,3,3,3,3,
                4,4,4,4,4,4,4,4,4,4,4,4,4,
                5,5,5,5,5,5,5,5,5,5,5,5,
                6,6,6,6,6,6,6,6,6,6,6,
                7,7,7,7,7,7,7,7,7,7,
                8,8,8,8,8,8,8,8,8,
                9,9,9,9,9,9,9,9,
                10,10,10,10,10,10,10,10,10,
                11,11,11,11,11,11,11,11,
                12,12,12,12,12,12,12,
                13,13,13,13,13,13,
                14,14,14,14,14,
                15,15,15,15,
                16,16,16,
                17,17,
                18};
    
    //Change parameters to test on different sets                    
    vector<int> L (L3t, L3t + sizeof(L3t) / sizeof(int) );
    
    int init[] = {0};
    vector<int> x (init, init + sizeof(init) / sizeof(int) );
    
    
    //Find number of points in the solution
    int c = - 2*L.size();
    int n = (1 + sqrt(1 - (4*1*c)))/2;
    
    //Begin PartialDigest(L)
    //Width = Maximum element in L
    width = L.back();
    //Delete the maximum element
    L.pop_back();
    //Add the maximum element into x
    x.push_back(width);
    //Call Place(L,X)
    place(L,x);
    cout << count << endl;
    return 0;
}

void place(vector<int> & L, vector<int> & x )
{
    //If L is empty
    if(L.empty())
    {
        cout << x;
        cout << endl;
        count++;
        return;
    }
    
    //y <- Maximum element in L
    int y = L.back();
    vector<int> multiset;
    for(int i = 0; i < x.size(); i++)
    {
        multiset.push_back(abs(y - x.at(i)));
    }
    
    //If /_\(y,X) is contained in L
    bool subset = true;
    for(int i = 0; i < multiset.size(); i++)
    {
        bool current = false;
        for(int j = 0; j < L.size(); j++)
        {
            if(multiset.at(i) == L.at(j))
            {
                current = true;
            }
        }
        if(!current)
        {
            subset = false;
            break;
        }
    }
    
    
    if(subset)
    {
        //Keep copy of original x and y
        vector<int> originalX (x);
        vector<int> originalL (L);
        
        //Add y to X and remove lengths (y,X) from L
        x.push_back(y);
        for(vector<int>::iterator it = multiset.begin(); it != multiset.end(); it++)
        {
            for(int j = 0; j < L.size(); )
            {
                if(*it == L.at(j))
                {
                    L.erase(L.begin() + j);
                    j = L.size();
                }
                j++;
            }
        }
        
        place(L, x);
        
        //Undo modifications to restore them for the next recursive call
        x = originalX;
        L = originalL;
    }
    
    int wy = width - y;
    vector<int> multiset2;
    for(int i = 0; i < x.size(); i++)
    {
        multiset2.push_back(abs(wy - x.at(i)));
    }
    
    subset = true;
    for(int i = 0; i < multiset2.size(); i++)
    {
        bool current = false;
        for(int j = 0; j < L.size(); j++)
        {
            if(multiset2.at(i) == L.at(j))
            {
                current = true;
            }
        }
        if(!current)
        {
            subset = false;
            break;
        }
    }
    
    if(subset)
    {
        //Keep copy of original x and y
        vector<int> originalX (x);
        vector<int> originalL (L);
        
        //Add y to X and remove lengths (y,X) from L
        x.push_back(wy);
        for(vector<int>::iterator it = multiset2.begin(); it != multiset2.end(); it++)
        {
            for(int j = 0; j < L.size(); )
            {
                if(*it == L.at(j))
                {
                    L.erase(L.begin() + j);
                    j = L.size();
                }
                j++;
            }
        }
        
        place(L, x);
        
        //Undo modifications to restore them for the next recursive call
        x = originalX;
        L = originalL;
    }
    
    return;
    
}


void operator<<(ostream & out, vector<int> & v)
{
    for(int i = 0; i < v.size(); i++)
    {
        out << v.at(i);
        if(i != (v.size() - 1))
        {
            out << " ";
        }
    }
    return;
}