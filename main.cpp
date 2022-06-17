#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sockMerchant' function below. Each unique int in the array is a "Color" of sock.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int totalSocks, vector<int> arrayOfSocks) {
    int pairsOfSocks = 0;
    int lonelySocks = 0;
    vector <int> uniqueValueArray;
    vector <int> duplicateValueCounter;

    //need an algorithm that looks at numbers in an array for pairs (divisible by 2... so count up unique instances
    //of a number and if %2, then a pair. If not % 2, then subtract 1, and add it to the odd "sock pile".

    //What if I make an index-matched array that corresponds to the unique values array, but captures the count of
    //each element in the unique array.
    for (int i = 0; i < arrayOfSocks.size(); i++) {
        int currentColor = 0;
        bool colorExists = false;
        int uniqueIndex = 0;

        currentColor = arrayOfSocks [i];
        //Search for current "Color" in my uniqueValueArray
        while ((!colorExists) && (uniqueIndex < uniqueValueArray.size())) {
            if ((currentColor == uniqueValueArray [uniqueIndex]) && (!uniqueValueArray.empty())) {
                //If the value is already in the uniqueValueArray, then take the current index,
                // find the value currently in the duplicateValueCounter Array, and add 1.
                colorExists = true;
                duplicateValueCounter[uniqueIndex] += 1;
            }
            uniqueIndex++;
        }
        //If the value is not found in the unique array, pushback the currentColor into the uniqueArray.
        //At the same time, pushback '1' into the duplicateValueCounter at the same index as the uniqueArray.
        if (!colorExists) {
            uniqueValueArray.push_back(currentColor);
            duplicateValueCounter.push_back(1);
        }
    }

    //Step through the duplicateValueCounter
    for (int j = 0; j < duplicateValueCounter.size(); j++) {

        //Confirm if there is only 1 sock
        if (duplicateValueCounter [j] == 1) {
            lonelySocks++;
        }

        // % each element by 2. If 0, then take the value in the element, and divide by 2. Add this value to
        //pairsOfSocks.

        else if ((duplicateValueCounter [j] % 2) == 0) {
            pairsOfSocks += ((duplicateValueCounter[j]) / 2 );
        }

        //if % not 0, then increment lonelySockCount,
        // subtract 1 from current element value. % 2. If 0, then
        // divide value by 2 as before, and add this amount to pairsOfSocks.
        else if ((duplicateValueCounter [j] % 2) != 0) {
            int confirmedPairs = 0;
            lonelySocks++;
            confirmedPairs = (duplicateValueCounter [j] - 1);
            if (confirmedPairs % 2 == 0) {
                pairsOfSocks += (confirmedPairs / 2 );
            }
            else {
                std::cout << "ERROR: there's an issue with logic around counting pairs of socks..." << std::endl;
            }
        }
    }

    //Return the final number of pairs of socks. Do nothing with loaner sock count for now...
    return pairsOfSocks;
    //Original Idea:
    //Consider making a vector of vectors of ints that holds unique values, ands then the count of duplicates will
    // be in the vector that comes off of each one. Then can call the size function on the sub-vector to determine
    // number of duplicates.
    //Iterate through array of socks
    //Check if uniqueValueArray has a vector in it that houses our the targetNumber.
    //Check each element of the unique value array, and do a size of the vector within.
    // Take this size, and add 1 for the unique value. % 2 this value.
    //If  % = 0, then divide total by 2 to and add this to the pairCounter.
    //If % != 1, then add one to lonelySockCount, subtract 1 amount of socks in the color, and check % 2 = 0.
    //If now 0, then use logic for  % 0.
    //This value should give you the number of pairs remaining. Add this value to the pair counter.
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
    if (n >= 1 && n <= 100) {
        vector<int> ar(n);

        for (int i = 0; i < n; i++) {
            int ar_item = stoi(ar_temp[i]);
            if (ar_item >= 1 && ar_item <= 100) {
                ar[i] = ar_item;
            }
        }

        int result = sockMerchant(n, ar);

        fout << result << "\n";
    }

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
