#include <bits/stdc++.h>
#include<windows.h>
#include "trie.cpp"
#include "utils.cpp"
using namespace std;

int main(int argc, char **argv)
{
    string filename;
    Trie T;
    vector<string> data;

    // if File provided in Arguments.
    if (argc > 1)
    {
        filename = argv[1];
        data = get_array_from_file(filename);
    }
    else
    {
        menu:
            cout << "Enter File name to load data from. ( music | movies ) :\n";
            cin >> filename;
            
            data = get_array_from_file(filename + ".txt");

            if (data.empty()) {
                system("cls");
                system("color 04");

                cout<<"There was a problem loading the file: "<<filename<<endl;
                cout << "press any key to retry."<<endl;
                getchar();
                getchar();

                system("cls");
                system("color 07");
                goto menu;
            }
        
        cout<<"\033[32m"<<"Succcessfully loaded!"<<"\033[0m"<<endl;
        Sleep(1000);
        

        system("cls");


    }

    for (string word : data)
    {
        // cout << word << "\n";
        T.insert(word);
    }

    int choice;

    // If pattern in Arguments.
    if (argc > 2)
    {
        string pattern = argv[2];
        for (string w : search(data, pattern))
        {
            cout << w << "\n";
        }
        return 0;
    }

    do
    {

        cout << "------------------------\n";
        transform(filename.begin(), filename.end(), filename.begin(), ::toupper);
        cout << "\033[35m" << "SEARCH "<< filename << "\033[0m" << endl;
        cout << "1. Exact Search.\n";
        cout << "2. Prefix Search.\n";
        cout << "3. Universal Search.\n";
        cout << "0. Exit.\n";

        cin >> choice;
        getchar(); // get the new line character

        string pattern;

        if (choice)
        {
            cout << "Enter Search Text (leave empty to list all) : ";
            getline(cin, pattern);
        }

        switch (choice)
        {
        case 1:
            if (T.search_exact(pattern))
            {
                cout << "String Exists.\n";
            }
            else
            {
                cout << "NOT Found.\n";
            }
            break;
        case 2:
            for (string w : T.search_pre(pattern))
            {
                cout << w << "\n";
            }
            break;

        case 3:
            for (string w : search(data, pattern))
            {
                cout << w << "\n";
            }
            break;

        default:
            break;
        }

        cout << "\n\npress any key to continue.";
        getchar();
        system("cls");

    } while (choice);

    // cout << "LINEAR Search.";
    // for (string w : linear_search_pre(data, "The G"))
    // {
    //     // cout << w << "\n";
    // }

    // T.search_exact("The Gold Rush (1925)");
    // linear_search_exact(data, "The Gold Rush (1925)");

    // T.draw(NULL);

    return 0;
}
