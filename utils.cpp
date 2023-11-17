#include <bits/stdc++.h>
using namespace std;

vector<string> get_array_from_file(string src)
{
    fstream file(src);

    string word;
    vector<string> words;

    if (!file)
    {
        cerr << "\nCan't Open File " << src << " Some Error Occurred.!\n";
        return words;
    }

    while (!file.eof())
    {
        getline(file, word);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word.size())
            words.push_back(word);
        word = "\0";
    }

    return words;
}

vector<string> linear_search_pre(vector<string> v, string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    vector<string> results;

    auto start = chrono::high_resolution_clock::now();
    

    for (auto s : v)
    {
        bool match = true;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] != s[i])
            {
                match = false;
                break;
            }
        }
        if (match)
            results.push_back(s);
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[32m\n"
         << results.size() << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return results;
}

bool linear_search_exact(vector<string> v, string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    auto start = chrono::high_resolution_clock::now();
    

    bool found = false;
    for (auto s : v)
    {
        if (s == str)
        {
            found = true;
            break;
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[32m\n"
         << found << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return false;
}


vector<string> search(vector<string> v, string pat)
{
    transform(pat.begin(), pat.end(), pat.begin(), ::tolower);
    vector<string> results;

    auto start = chrono::high_resolution_clock::now();

    for (auto str : v)
    {
        bool match = true;
        for(int j=0; j<( str.size()-pat.size() +1);j++)
        {
            for(int i=0; i<pat.size(); i++)
            {
                if(str[j+i] != pat[i])
                {
                    match = false;
                    break;
                }
            }
            if (match) {
                results.push_back(str);
                break;
            }
            match = true;
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[32m\n"
         << results.size() << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return results;
}



