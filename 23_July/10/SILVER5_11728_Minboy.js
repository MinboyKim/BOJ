function solution(input) {
  let A, B, N, M;
  N = input[0][0];
  M = input[0][1];
  A = input[1];
  B = input[2];

  const ans = [];
  let aCursor = 0,
    bCursor = 0;
  while (aCursor < N || bCursor < M) {
    if (aCursor < N && bCursor < M) {
      if (A[aCursor] > B[bCursor]) {
        ans.push(B[bCursor]);
        bCursor++;
      } else {
        ans.push(A[aCursor]);
        aCursor++;
      }
    } else {
      if (aCursor < N) {
        ans.push(...A.slice(aCursor));
        aCursor = N;
      } else {
        ans.push(...B.slice(bCursor));
        bCursor = M;
      }
    }
  }
  console.log(ans.join(" "));
}

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let list = [];

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  input.forEach((val) => {
    list.push(val.split(" ").map((el) => parseInt(el)));
  });
  solution(list);
  process.exit();
});
