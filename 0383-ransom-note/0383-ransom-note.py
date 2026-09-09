class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:

        mp = Counter(magazine)

        for char in ransomNote:
            if mp[char] <= 0:
                return False
            mp[char] -= 1

        return True
            