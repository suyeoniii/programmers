function solution(fees, records) {
  let answer = [];
  let result = new Map();
  let parking = new Map();

  // 기본시간, 기본요금, 단위시간, 단위요금
  let defaultTime = fees[0];
  let defaultFee = fees[1];
  let unitTime = fees[2];
  let unitFee = fees[3];

  for (let r of records) {
    let record = r.split(" ");
    let time = record[0];
    let number = record[1];

    let hour = Number(time.split(":")[0]);
    let min = Number(time.split(":")[1]);

    let parkingMinutes = hour * 60 + min;

    // 번호 등록
    if (!Boolean(result.get(number))) result.set(number, 0);

    // 주차되어있지 않으면 (IN)
    if (parking.get(number) === undefined) {
      parking.set(number, parkingMinutes);
    } else {
      //주차되어 있으면 (OUT)
      let parkingTime = parkingMinutes - parking.get(number);

      result.set(number, result.get(number) + parkingTime);
      parking.delete(number);
    }
  }

  // 출차기록이 없다면 23:59분 출차처리
  for (let p of parking) {
    let maxMinute = 23 * 60 + 59;
    let parkingTime = maxMinute - p[1];

    result.set(p[0], result.get(p[0]) + parkingTime);
  }

  // 차량번호가 작은순으로 정렬
  const resultArray = [...result];
  resultArray.sort((a, b) => a[0] - b[0]);

  for (let r of resultArray) {
    let price = 0;
    let parkingTime = r[1];

    // 기본 요금 부과
    price += defaultFee;
    parkingTime -= defaultTime;

    // 추가요금 부과
    if (parkingTime > 0) {
      price += Math.ceil(parkingTime / unitTime) * unitFee;
    }

    answer.push(price);
  }

  return answer;
}
