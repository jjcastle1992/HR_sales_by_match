#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int totalSocks, vector<int> arrayOfSocks) {
    int pairsOfSocks = 0;

    vector <vector<int>> uniqueValueArray;
    //need an algorithm that looks at numbers in an array for pairs (divisible by 2... so count up unique instances
    //of a number and if %2, then a pair. If not % 2, then subtract 1, and add it to the odd "sock pile".

    //Consider making a vector of vectors of ints that holds unique values, ands then the count of duplicates will
    // be in the vector that comes off of each one. Then can call the size function on the sub-vector to determine
    // number of duplicates.

    //Check each element of the unique value array, and do a size of the vector within.
    // Take this size, and add 1 for the unique value. % 2 this value.
    //If  % = 0, then divide total by 2 to and add this to the pairCounter.
    //If % != 1, then add one to lonelySockCount, subtract 1 amount of socks in the color, and check % 2 = 0.
    //If now 0, then use logic for  % 0.
    //This value should give you the number of pairs remaining. Add this value to the pair counter.

    //Return the final number of pairs of socks. Do nothing with loaner sock count for now...
    return pairsOfSocks;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
