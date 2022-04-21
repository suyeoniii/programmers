function solution(s) {
  let arr = [];

  for (let word of s) {
    if (arr[arr.length - 1] === word) arr.pop();
    else arr.push(word);
  }
  const answer = arr.length === 0 ? 1 : 0;

  return answer;
}
