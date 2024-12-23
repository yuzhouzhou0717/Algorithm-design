
#include<iostream>
#include<cstring>
using namespace std;
using ll = long long;

const int N = 100010;


int n;
int a[N], b[N], c[N];
int ap[N], cp[N]; // a和c的前缀
int cnt[N], s[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], a[i]++;
    for (int i = 0; i < n; i++) cin >> b[i], b[i]++;
    for (int i = 0; i < n; i++) cin >> c[i], c[i]++;

    // 计数+前缀和
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i++) ap[i] = s[b[i] - 1];

    memset(cnt, 0, sizeof(cnt));
    memset(s, 0, sizeof(s));

    for (int i = 0; i < n; i++) cnt[c[i]]++;
    for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i++) cp[i] = s[N - 1] - s[b[i]];

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += (ll)ap[i] * cp[i];
    cout << ans << '\n';
    return 0;
}