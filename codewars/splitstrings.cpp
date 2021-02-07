#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s) {
  std::vector<std::string> ans;

  std::string rem = "";
  unsigned i = 0;
  while (s[i]) {
    rem += s[i];
    if (i == s.size() - 1) {
      rem += '_';
      ans.push_back(rem);
      break;
    } else
      rem += s[i + 1];

    ans.push_back(rem);
    rem = "";
    i += 2;
  }

  return ans;
}