// 1. 单例模式
class A {
public:
	static A& getInstance();
private:
	A();
	A(const A& rhs);
};

A& A::getInstance()
{
	static A a;
	return a;
}
/*******************************************/

// 2

// 3


/*******************************************/
// 4. 1-2走台阶问题，递归和动态规划两种解题方法 

// 递归：
int getWays(int n, vector<int>& res) {
    if (n <= 1) {
        return 1;
    }

    if (-1 == res[n]) {
        res[n] = (getWays(n-1, res) + getWays(n-2,res))%100000007;
    }

    return res[n];
}

int numWays(int n) {
    vector<int> res(n+1, -1);
    return getWays(n, res);
}

// 迭代

int numWays(int n) {
    if (n <= 1) {
        return 1;
    }

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % 100000007;
    }
    return dp[n];
}

/*******************************************/