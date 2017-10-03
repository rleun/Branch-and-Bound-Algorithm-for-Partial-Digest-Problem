/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

bool containsMotif(vector<pair<string,int> > &motifs, string l);
void operator<<(ostream & out, vector<pair<string, int> > & v);

int main()
{
    
    
    
    int lmer = 5;
    string input;
    fstream fileStream;
    vector<pair<string,int> > motifs;
    
    
    /* initialize random seed: */
    srand (time(NULL));
    
    //Create
    for(int i = 0; i < 1364109; i++)
    {
        string t = "";
        for(int i = 0; i < 5; i++)
        {
            /* generate secret number between 1 and 10: */
            int iSecret = rand() % 4 + 1;
            
            if(iSecret == 1)
            {
                t.push_back('A');
            }
            else if(iSecret == 2)
            {
                t.push_back('T');
            }
            else if(iSecret == 3)
            {
                t.push_back('C');
            }
            else
            {
                t.push_back('G');
            }
        }
        
        string temp = t;
        
        if(containsMotif(motifs,temp))
        {
        }
        else
        {
            pair<string,int> t(temp,1);
            motifs.push_back(t);
        }
    }
    
    ofstream outputStream;
    outputStream.open("randomresults.txt");
    outputStream << motifs;
    
    return 0;
}

bool containsMotif(vector<pair<string,int> > &motifs, string l)
{
    for(int i = 0; i < motifs.size(); i++)
    {
        if(motifs[i].first == l)
        {
            motifs[i].second = motifs[i].second + 1;
            return true;
        }
    }
    return false;
}

void operator<<(ostream & out, vector<pair<string, int> > & v)
{
    for(int i = 0; i < v.size(); i++)
    {
        out << v.at(i).first << " " << v.at(i).second << endl;
    }
    return;
}