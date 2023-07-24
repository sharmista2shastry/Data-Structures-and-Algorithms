void helper(int n, int source, int aux, int dest, vector<vector<int>> &v)
{
    if(n == 0)
    return;

    helper(n-1, source, dest, aux, v);

    vector<int> temp;
    temp.push_back(source);
    temp.push_back(dest);
    v.push_back(temp);

    helper(n-1, aux, source, dest, v);
}

vector<vector<int>> towerOfHanoi(int n)
{
    //    Write your code here.
    vector<vector<int>> v;
    helper(n, 1, 2, 3, v);

    return v;
}
