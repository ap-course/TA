#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool isNumber(string x)
{
    for (int i = 0; i < x.length(); i++)
        if (!(x[i] <= '9' && x[i] >= '0'))
        {
            return false;
        }
    return true;
}

bool isEqual(string ans, string real_ans)
{
    if (real_ans.length() < ans.length())
        return false;

    int index = 0;
    while (ans[index] != '#')
    {
        if (ans[index] != real_ans[index])
            return false;

        index++;
    }
    index = 0;
    while (ans[ans.length() - 1 - index] != '#')
    {
        if (ans[ans.length() - 1 - index] != real_ans[real_ans.length() - 1 - index])
            return false;

        index++;
    }

    return true;
}

void print_real(string first, string second, string ans)
{
    cout << first << " + " << second << " = " << ans << endl;
}

int main()
{
    string first, second, tmp, ans;
    cin >> first >> tmp >> second >> tmp >> ans;

    if (!isNumber(ans))
    {
        string real_ans = to_string(stoi(first) + stoi(second));
        if (isEqual(ans, real_ans))
        {
            print_real(first, second, real_ans);
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else if (!isNumber(first))
    {
        string real_first = to_string(stoi(ans) - stoi(second));
        if (isEqual(first, real_first))
        {
            print_real(real_first, second, ans);
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else if (!isNumber(second))
    {
        string real_second = to_string(stoi(ans) - stoi(first));
        if (isEqual(second, real_second))
        {
            print_real(first, real_second, ans);
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}