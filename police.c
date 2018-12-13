
// Returns maximum number of thieves that can
// be caught.
int policeThief(char arr[], int n, int k)
{
    int res = 0;
    vector<int> thi;
    vector<int> pol;

    // store indices in the vector
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P')
            pol.push_back(i);
        else if (arr[i] == 'T')
            thi.push_back(i);
    }

    // track lowest current indices of
    // thief: thi[l], police: pol[r]
    int l = 0, r = 0;
    while (l < thi.size() && r < pol.size()) {

        // can be caught
        if (abs(thi[l] - pol[r]) <= k) {
            res++;
            l++;
            r++;
        }

        // increment the minimum index
        else if (thi[l] < pol[r])
            l++;
        else
            r++;
    }

    return res;
}
