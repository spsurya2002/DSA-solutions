class Solution {
public:
    int josephus(int n, int k) {
        if (n == 1)
            return 0; // base case: the last person is the winner (index 0)
        return (josephus(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {
         return josephus(n, k) + 1;
    }
};
5
2
6
5
3
1
3
1
5
