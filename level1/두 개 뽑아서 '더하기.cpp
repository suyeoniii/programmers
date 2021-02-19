#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
  vector<int> answer;
  bool isit = false;
  for (int i = 0; i < numbers.size(); i++)
  {
    for (int j = i + 1; j < numbers.size(); j++)
    {
      int ans = numbers[i] + numbers[j];
      isit = false;
      for (int k = 0; k < answer.size(); k++)
      {
        if (answer[k] == ans)
        {
          isit = true;
        }
      }
      if (!isit)
        answer.push_back(ans);
    }
  }
  sort(answer.begin(), answer.end());
  return answer;
}