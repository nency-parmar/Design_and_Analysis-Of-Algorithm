class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        new_s = s.split()
        if len(pattern) != len(new_s):
            return False
        char_to_word = {}
        word_to_char = {}
        for c, w in zip(pattern, new_s):
            if c in char_to_word:
                if char_to_word[c] != w:
                    return False
            else:
                if w in word_to_char:
                    return False
                char_to_word[c] = w
                word_to_char[w] = c
        return True



# Input: pattern = "abba", s = "dog cat cat dog"

# Output: true

# Explanation:

# The bijection can be established as:

# 'a' maps to "dog".
# 'b' maps to "cat".