import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        ArrayList<Integer> sums = new ArrayList<Integer>();
        ArrayList<Integer> answerAL = new ArrayList<Integer>();
        
        // 전체 탐색 후 모든 합 구하기
        for (int i = 0; i < numbers.length - 1; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                sums.add(numbers[i] + numbers[j]);                   
            }
        }
        
        // 중복 제거
        for (int i = 0; i < sums.size(); i++) {
            if (!answerAL.contains(sums.get(i))) {
                answerAL.add(sums.get(i));
            }
        }
        // 라이브러리 사용해서 오름차순 정렬
        Collections.sort(answerAL);
        
        // 자료형 변환
        answer = new int[answerAL.size()];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = answerAL.get(i);
        }        
            
        return answer;
    }
}
