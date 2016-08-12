#define MAX 26
bool isAnagram(int *count1, int *count2) {
    for(int i = 0; i < MAX; i++) {
        if(count1[i] != count2[i])
            return false;
    }
    return true;
}

int findPair(string str, int start, char *tmp, int n) {
    int len = str.length();
    if(strlen(tmp) > len-start) {
        return 0;
    }

    int *count1 = new int[MAX];
    int *count2 = new int[MAX];
    int cnt = 0;
    int i;
    for(i = 0; i < MAX; i++) {
        count1[i] = 0;
        count2[i] = 0;
    }

    for(i = 0; i < n && (start+i) < len; i++) {
        count1[tmp[i]-'a']++;
        count2[str[start+i]-'a']++;
    }

    int j;
    for(j = start + i; j < len; j++) {
        if(isAnagram(count1, count2)) {
            cnt++;
        }
        count2[str[start]-'a']--;
        count2[str[j]-'a']++;
        start++;
    }
    if(j == len) {
        if(isAnagram(count1, count2)) {
            cnt++;
        }
    }

    delete []count1;
    delete []count2;

    return cnt;
}

int countPairs(string str) {
    int n = str.length();
    if(n < 2) {
        return 0;
    }

    int cnt = 0;
    char *tmp = new char[n];
    for(int i = 0; i < n; i++) {
        int k = 0;
        for(int j = i; j < n; j++) {
            tmp[k] = str[j];
            tmp[k+1] = '\0';

            cnt += findPair(str, i+1, tmp, k+1);
            k++;
        }
    }
    delete []tmp;
    return cnt;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        string str;
        cin>>str;
        cout<<countPairs(str)<<endl;
    }

    return 0;
}
