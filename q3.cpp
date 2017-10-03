#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
    
    fileStream.open("random.txt");
    
    
    
    
    // cout << input << endl;
    
    while(fileStream >> input)
    {
        for(int i = 0; i < input.size() - 5; i++)
        {
            string temp = input.substr(i, 5);
            if(containsMotif(motifs,temp))
            {
            }
            else
            {
                pair<string,int> t(temp,1);
                motifs.push_back(t);
            }
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