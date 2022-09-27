#include <iostream>
#include <string>
#include <map>
using namespace std;

int roman_to_int(string s) 
{
    // Build map for Roman Numerals
    map<char, int> roman_numeral_map;
    roman_numeral_map.insert(pair<char, int>('I', 1));
    roman_numeral_map.insert(pair<char, int>('V', 5));
    roman_numeral_map.insert(pair<char, int>('X', 10));
    roman_numeral_map.insert(pair<char, int>('L', 50));
    roman_numeral_map.insert(pair<char, int>('C', 100));
    roman_numeral_map.insert(pair<char, int>('D', 500));
    roman_numeral_map.insert(pair<char, int>('M', 1000));

    // isolate the last character of the string
    // we are going to work from right to left
    auto iterator = roman_numeral_map.find(s.back());
    int answer = iterator->second;

    // start from the second to last character
    // compare to the character on the right
    for (int i = s.length() - 2; i >= 0; i--) 
    {
        // find left number
        iterator = roman_numeral_map.find(s.at(i));
        int left_number = iterator->second;

        // find right number
        iterator = roman_numeral_map.find(s.at(i + 1));
        int right_number = iterator->second;

        // if current char is less than character on right, subtract left number value from answer
        if (left_number < right_number) 
        {
            answer -= left_number;
        }
        // if current character is greater than or equal to character on right, add left number value to answer
        else 
        {
            answer += left_number;
        }
    }
    return answer;
}

int main()
{
    cout << "III : " << roman_to_int("III") << endl;
    cout << "LVIII : " << roman_to_int("LVIII") << endl;
    cout << "MCMXCIV : " << roman_to_int("MCMXCIV") << endl;
    cout << "IV : " << roman_to_int("IV") << endl;
	return 0;
}
