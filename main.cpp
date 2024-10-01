#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <vector>

using namespace std;
int SLEEP_TIME = ((2 * 1000) * 60),
    count;

int minsToMicroSeconds(int mins)
{
    return ((mins * 1000) * 60);
}

void runnerBrave(string url)
{
    system("cls");
    cout << "starting brave in private with " + url << endl;
    system(("start brave --incognito " + url).c_str());
    cout << "Waiting for " << SLEEP_TIME / 1000 << " seconds..." << endl;
    cout << "Running Process " << count << " times." << endl;
    Sleep(SLEEP_TIME);

    cout << "Now closing" << endl;
    system("taskkill /IM brave.exe /F");
    cout << "Completed Process " << count << " times." << endl;
    count++;
}
void runnerChrome(string url)
{
    system("cls");
    cout << "starting chrome in private with " + url << endl;
    system(("start chrome --incognito " + url).c_str());
    cout << "Waiting for " << SLEEP_TIME / 1000 << " seconds..." << endl;
    cout << "Running Process " << count << " times." << endl;
    Sleep(SLEEP_TIME);

    cout << "Now closing" << endl;
    system("taskkill /IM chrome.exe /F");
    cout << "Completed Process " << count << " times." << endl;
    count++;
}
void runnerFox(string url)
{
    system("cls");
    cout << "starting firefox in private with " + url << endl;
    system(("start firefox -private-window  " + url).c_str());
    cout << "Waiting for " << SLEEP_TIME / 1000 << " seconds..." << endl;
    cout << "Running Process " << count << " times." << endl;
    Sleep(SLEEP_TIME);

    cout << "Now closing" << endl;
    system("taskkill /IM firefox.exe /F");
    cout << "Completed Process " << count << " times." << endl;
    count++;
}

int main()
{
    system("cls");
    string inputUrl;
    int times, choice;
    vector<string> urls;

    cout << "how many views you want to get from us: => ";
    cin >> times;

    cout << "In which browser you want to get it done" << endl
         << "1) Brave" << endl
         << "2) Chrome" << endl
         << "3) FireFox" << endl
         << "Your choice: --> ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3)
    {
        cout << "Try Again: => ";
        cin >> choice;
    }

    cout << "how many mins of delay you want (min 2 mins) of time delay: => ";
    do
    {
        cin >> SLEEP_TIME;
        if (SLEEP_TIME < 2)
        {
            cout << "Try Again: => ";
        }
    } while (SLEEP_TIME < 2);

    SLEEP_TIME = minsToMicroSeconds(SLEEP_TIME);
    count = 1;
    while (inputUrl != "stop")
    {
        cout << "Enter Url: => (type \"stop\" to stop) ";
        cin >> inputUrl;
        if (inputUrl == "stop")
        {
            break;
        }
        else
        {
            urls.push_back(inputUrl);
            cout << "Total urls length: " << urls.size() << endl;
        }
    }

    switch (choice)
    {
    case 1:
        for (int i = 0; i < times; i++)
        {
            for (const auto &url : urls)
            {
                cout << url << endl;
                if (url == "stop")
                {
                    continue;
                }
                else
                {
                    runnerBrave(url);
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < times; i++)
        {
            for (const auto &url : urls)
            {
                cout << url << endl;
                if (url == "stop")
                {
                    continue;
                }
                else
                {
                    runnerChrome(url);
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < times; i++)
        {
            for (const auto &url : urls)
            {
                cout << url << endl;
                if (url == "stop")
                {
                    continue;
                }
                else
                {
                    runnerFox(url);
                }
            }
        }
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }

    return 0;
}
