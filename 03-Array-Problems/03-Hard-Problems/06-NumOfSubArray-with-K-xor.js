const solve = (A, B) => {
    //  Brute Force
    // let cnt=0;
    //   for(let i=0;i<A.length;i++){
    //       for(let j=i;j<A.length;j++){
    //           let xor=0;
    //           for(let k=i;k<=j;k++){
    //           xor^=A[k];
    //           }
    //           if(xor==B) cnt++;
    //       }
    //   }
    //   return cnt;

    //   Better Approach
    //   let cnt=0;
    //   for(let i=0;i<A.length;i++){
    //       let xor=0;
    //       for(let j=i;j<A.length;j++){
    //           xor^=A[j];
    //           if(xor==B) cnt++;
    //       }
    //   }
    //   return cnt;

    // Optimal Approach
    let cnt = 0;
    let xor = 0;
    let map = new Map();
    map.set(xor, 1);
    for (let i = 0; i < A.length; i++) {
        xor ^= A[i];
        let x = xor ^ B;
        if (map.has(x)) cnt = cnt + map.get(x);
        map.set(xor, (map.get(xor) || 0) + 1);
    }
    return cnt;
}

let arr = [4, 2, 2, 6, 4];
console.log(solve(arr, 6))