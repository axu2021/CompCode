#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string &pat, vector<int> &lps) {
  // length of the previous longest prefix suffix
  int len = 0, M = pat.size();
 
  lps[0] = 0; // lps[0] is always 0
 
  // the loop calculates lps[i] for i = 1 to M-1
  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    }
    else // (pat[i] != pat[len])
    {
      // This is tricky. Consider the example.
      // AAACAAAA and i = 7. The idea is similar
      // to search step.
      if (len != 0) {
        len = lps[len - 1];
 
        // Also, note that we do not increment
        // i here
      }
      else // if (len == 0)
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}
 
// Counts occurrences of pat[] in txt[]
int KMPSearch(string &txt, string &pat)
{
  int N = txt.size();
  int M = pat.size();
  int numMatch = 0;
 
  // create lps[] that will hold the longest prefix suffix
  // values for pattern
  vector<int> lps(M);
 
  // Preprocess the pattern (calculate lps[] array)
  computeLPSArray(pat, lps);
 
  int i = 0; // index for txt[]
  int j = 0; // index for pat[]
  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
 
    if (j == M) {
      // printf("Found pattern at index %d ", i - j);
      numMatch++;
      j = lps[j - 1];
    }
 
    // mismatch after j matches
    else if (i < N && pat[j] != txt[i]) {
      // Do not match lps[0..lps[j-1]] characters,
      // they will match anyway
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
 
  return numMatch;
}
   
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << KMPSearch(s1, s2) << endl;
}