function solution(left, right) {
  let answer = 0;

  for (let i = left; i <= right; i++) {
    let remainder = 2;
    for (let j = 1; j <= i; j++) {
      if (i % j === 0) remainder += 1;
    }
    if (remainder % 2) {
      // 홀수, 빼기
      answer -= i;
    } else {
      // 짝수, 더하기
      answer += i;
    }
  }

  return answer;
}
