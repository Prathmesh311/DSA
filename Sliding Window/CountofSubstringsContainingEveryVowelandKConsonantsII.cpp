class Solution {
public:
    std::string vowels = "aeiou";  // String containing all vowels

    // Function to count substrings with at least k consonants and all vowels present
    long long countAtLeastK(std::string &word, int k) {
        long long result = 0;  // To store the result
        int j = 0;             // Left pointer for the sliding window
        int cnt[6] = {0};      // Array to count vowels and consonants
        int uniqueVowels = 0;  // Count of unique vowels present

        // Iterate through the word with a right pointer
        for (int i = 0; i < word.size(); ++i) {
            int p = vowels.find(word[i]) + 1;  // Find position of character in vowels
            uniqueVowels += (cnt[p]++ == 0 && p); // Increment count of unique vowels if it's the first occurrence
            
            // Check if all vowels are present and consonants count is at least k
            while (uniqueVowels == 5 && cnt[0] >= k) {
                result += (word.size() - i); // Count valid substrings
                int p = vowels.find(word[j++]) + 1; // Move left pointer
                uniqueVowels -= (--cnt[p] == 0 && p); // Decrement unique vowel count if it reaches zero
            }
        }
        return result;  // Return the count of valid substrings
    }

    // Main function to count substrings with exactly k consonants
    long long countOfSubstrings(std::string word, int k) {
        // Count substrings with at least k consonants and subtract those with at least (k + 1) consonants
        return countAtLeastK(word, k) - countAtLeastK(word, k + 1);
    }
};
