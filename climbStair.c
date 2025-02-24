/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/
//resoudre ce probleme c'est effectuer le theoreme de fibonacci

int climbStairs(const int n) {
    if(n == 1){
        return n;
    }else if(n == 2){
        return n;
    }
    int t1 = 0,t2 = 1;

    for(int i = 1;i <= n ;i++){
        const int nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return t2;
}
