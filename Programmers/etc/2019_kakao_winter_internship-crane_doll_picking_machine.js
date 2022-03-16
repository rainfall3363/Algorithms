function solution(board, moves) {
    var answer = 0;
    var array = [];
    
    for (let i = 0; i < moves.length; i++) {
        var top = topOnBoard(board, moves[i]);
        if (top !== 0) {
            array.push(top);        
        }
        if (array.length > 1) {
            answer += boom(array);
        }
    }
    
    return answer;
}

function boom(array) {
    var cnt = 0;
    for(let i = 0; i < array.length - 1; i++) {
        if (array[i] === array[i + 1]) {
            cnt += 2;
            array.splice(i, 2);
            if (i < 2) {
                i = 0;
            }
            else {
                i -= 2;
            }
        }
    }
    return cnt;
}

function topOnBoard(board, num) {
    var result = 0;
    for (let i = 0; i < board.length; i++) {
        if (board[i][num - 1] !== 0) {
            result = board[i][num - 1];
            board[i][num - 1] = 0;
            break;
        }
    }
    return result;
}
