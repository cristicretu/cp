#include <string>

std::vector<std::string> explode(std::string s, char c) {
  std::string cuvant = "";
  std::vector<std::string> rez;
  for (unsigned i = 0; i < s.size(); ++i) {
    if (s[i] != c)
      cuvant += s[i];
    else if (cuvant.size())
      rez.push_back(cuvant), cuvant = "";
  }
  if (cuvant.size()) rez.push_back(cuvant);
  return rez;
}

int score(std::string s) {
  int ans = 0;
  for (char d : s) {
    ans += int(d - 'a' + 1);
  }
  return ans;
}

std::string highestScoringWord(const std::string &str) {
  std::vector<std::string> ans = explode(str, ' ');
  std::string rem;
  int mx = 0;
  for (auto i : ans) {
    if (score(i) > mx) {
      mx = score(i);
      rem = i;
    }
  }
  return rem;
}