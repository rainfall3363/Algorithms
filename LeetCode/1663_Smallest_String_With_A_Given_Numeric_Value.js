/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getSmallestString = function(n, k) {
    var quotient = parseInt((k - n) / 25);
    var remainder = (k - n) % 25;
    var answer = "";
    
    // 뒤쪽 z
    for (let i = 0; i < quotient; i++) {
        answer += 'z';
    }
    
    // 중간 alphabet
    if (remainder > 0) {
        answer = String.fromCharCode(remainder + 97) + answer;
    }
    
    // 앞쪽 a
    while (answer.length < n) {
        answer = 'a' + answer;    
    }   
    
    return answer;
};
