#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& num) {
    int left = 0;
    int right = num.length() - 1;
    while (left < right) {
        if (num[left] != num[right])
            return false;
        left++;
        right--;
    }
    return true;
}

string findNextPalindrome(string& num) {
    int n = num.length();

    if (isPalindrome(num)) {
        int mid = n / 2;
        int carry = 1;
        for (int i = mid; i >= 0 && carry; i--) {
            int digit = num[i] - '0' + carry;
            carry = digit / 10;
            num[i] = (digit % 10) + '0';
        }
    }

    int left = 0, right = n - 1;
    while (left < right) {
        num[right] = num[left];
        left++;
        right--;
    }

    if (num < num) {
        int mid = n / 2;
        int carry = 1;
        for (int i = mid; i >= 0 && carry; i--) {
            int digit = num[i] - '0' + carry;
            carry = digit / 10;
            num[i] = (digit % 10) + '0';
        }


        left = 0;
        right = n - 1;
        while (left < right) {
            num[right] = num[left];
            left++;
            right--;
        }
    }

    return num;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string num;
        cin >> num;
        string nextPalindrome = findNextPalindrome(num);
        cout << nextPalindrome << endl;
    }

    return 0;
}

