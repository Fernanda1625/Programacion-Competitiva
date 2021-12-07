// Ejercicio 6: Life Forms
// URL: https://open.kattis.com/problems/lifeforms
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
	vector <int> w;
	int n;
	vector <vector <int>> P;

	SuffixArray(vector <int> &_w) : w(_w), n(w.size()) {
      construct();
  }

	void construct() {
      P.push_back(vector <int>(n, 0)); compress();
      vector <int>  occ(n + 1, 0), s1(n, 0), s2(n, 0);
      for ( int k = 1, cnt = 1; cnt / 2 < n; ++k, cnt *= 2 ) {
          P.push_back(vector <int> (n, 0));
          fill(occ.begin(), occ.end(), 0);
          for ( int i = 0; i < n; ++i )
              occ[i+cnt<n ? P[k-1][i+cnt]+1 : 0]++;

          partial_sum(occ.begin(), occ.end(), occ.begin());

          for ( int i = n - 1; i >= 0; --i)
              s1[--occ[i+cnt<n ? P[k-1][i+cnt]+1 : 0]] = i;

          fill(occ.begin(), occ.end(), 0);

          for ( int i = 0; i < n; ++i )
              occ[P[k-1][s1[i]]]++;

          partial_sum(occ.begin(), occ.end(), occ.begin());

          for ( int i = n - 1; i >= 0; --i )
              s2[--occ[P[k-1][s1[i]]]] = s1[i];

          for ( int i = 1; i < n; ++i ) {
              P[k][s2[i]] = same(s2[i], s2[i - 1], k, cnt)
                  ? P[k][s2[i - 1]] : i;
          }
      }
	}
	void compress() {
      vector <int>  cnt(256, 0);
      for ( int i = 0; i < n; ++i )
          cnt[w[i]]++;
      for  ( int i = 0, mp = 0; i < 256; ++i )
          if (cnt[i] > 0)
              cnt[i] = mp++;
      for ( int i = 0; i < n; ++i )
          P[0][i] = cnt[w[i]];
	}
	bool same(int i, int j, int k, int l) {
		return P[k - 1][i] == P[k - 1][j]
			&& (i + l < n ? P[k - 1][i + l] : -1)
			== (j + l < n ? P[k - 1][j + l] : -1);
	}

	const vector <int>  &get_array() { return P.back(); }
	int lcp(int x, int y) {
		int ret = 0;
		if ( x == y )
        return n - x;
		for ( int k = P.size() - 1; k >= 0 && x < n && y < n; --k )
        if (P[k][x] == P[k][y]) {
            x += 1 << k;
            y += 1 << k;
            ret += 1 << k;
			}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	bool e = false;
	while ( cin >> n  ) {
      if ( n == 0 )
          break;

      if ( e )
          cout << '\n';
      else e = true;

      if ( n == 1 ) {
          string s;
          cin >> s;
          cout << s << "\n";
          continue;
      }

      vector <int>  word, owner;
      int ntok = 26;
      for ( int i = 0; i < n; ++i ) {
        string s;
        cin >> s;
        for ( char c : s )
            word.push_back(c-'a');
        word.push_back(ntok++);
        owner.push_back((int)word.size());
      }

      int S = (int)word.size();

      SuffixArray sa(word);
      const vector <int>  &p = sa.get_array();
      vector <int>  pi(S), po(S);
      for ( int i = 0, o = 0; i < (int)word.size(); ++i ) {
          if ( owner[o] <= i )
              ++o;
          pi[p[i]] = i;
          po[p[i]] = o;
      }

      vector <int>  ans, have(n, 0);
      int len = 0, havet = 0;
      for ( int l = 0, r = 0; r < S; ++r ) {
          if (!have[po[r]])
            ++havet;
          ++have[po[r]];

          while ( l < r && (have[po[l]] > 1 || (havet - 1) > n/2) ) {
              --have[po[l]];
              if (have[po[l]] == 0)
                  --havet;
              l++;
          }

          if ( havet <= n/2 )
              continue;

          int tlen = sa.lcp(pi[l], pi[r]);
          if ( tlen > len )
              len = tlen,
              ans.clear();
          if ( tlen == len && (ans.size() == 0 || (sa.lcp(pi[l], ans.back()) < len )) )
              ans.push_back(pi[l]);
      }

      if ( len == 0 )
          cout << "?\n";
      else {
          for ( int i : ans ) {
              for ( int j = i; j < i+len; ++j )
                  cout << char('a'+word[j]);
            cout << '\n';
        }
      }
	}
	cout << flush;

	return 0;
}
