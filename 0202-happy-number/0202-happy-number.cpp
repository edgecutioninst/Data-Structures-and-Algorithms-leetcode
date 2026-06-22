class Solution {
public:

    int sumOfSquares(int n)
    {   
        int sum = 0;
        while(n)
        {
            int digit = n%10;
            sum += digit * digit;
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int,bool>m;

        while(true)
        {
            if(n == 1) return true;
            
            if(m.find(n) != m.end()) break; 
            
            m[n] = true;
            n = sumOfSquares(n);
        }

        return false;
    }
};